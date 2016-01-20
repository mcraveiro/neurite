/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2015 Marco Craveiro <marco.craveiro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/utility/io/vector_io.hpp"
#include "neurite/swc/types/hydration_error.hpp"
#include "neurite/swc/types/hydrator.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("swc.hydrator"));

const unsigned long minimum_number_of_point_fields(7);
// const char hash('#');

const std::string invalid_field_value("Field value is not valid");
const std::string failed_to_open_file("Failed to open file: ");
const std::string missing_fields("Not enough fields");

inline unsigned int stoui(const std::string& str) {
    unsigned long result = std::stoul(str, 0/*idx*/, 10/*base*/);
    if (result > std::numeric_limits<unsigned int>::max())
        throw std::out_of_range("stoui");
    return result;
}

}

namespace neurite {
namespace swc {

structure_identifier_types hydrator::
to_structure_identifier_type(const int i) const {
    switch (i) {
    case 0: return structure_identifier_types::invalid; // FIXME
    case 1: return structure_identifier_types::soma;
    case 2: return structure_identifier_types::axon;
    case 3: return structure_identifier_types::basal_dendrite;
    case 4: return structure_identifier_types::apical_dendrite;
    case 5: return structure_identifier_types::fork_point;
    case 6: return structure_identifier_types::end_point;
    default: return structure_identifier_types::custom;
    }
}


point hydrator::
process_point_line(const std::string& s, const unsigned int line_number) const {
    std::vector<std::string> tokens;
    const auto trimmed(boost::trim_copy(s));
    boost::split(tokens, trimmed, boost::is_space(), boost::token_compress_on);
    BOOST_LOG_SEV(lg, debug) << "Parsing line with tokens: " << tokens;

    if (tokens.size() < minimum_number_of_point_fields) {
        BOOST_LOG_SEV(lg, error) << missing_fields << ". Expected: "
                                 << minimum_number_of_point_fields
                                 << " Actual: " << tokens.size();
        BOOST_THROW_EXCEPTION(hydration_error(missing_fields));
    }

    unsigned int field_number(0);
    try {
        point r;
        r.sample_number(stoui(tokens[field_number]));

        const auto usi(stoi(tokens[++field_number]));
        r.unparsed_structure_identifier(usi);
        r.structure_identifier(to_structure_identifier_type(usi));

        r.x(stod(tokens[++field_number]));
        r.y(stod(tokens[++field_number]));
        r.z(stod(tokens[++field_number]));
        r.radius(stod(tokens[++field_number]));
        r.parent_sample(stoi(tokens[++field_number]));
        r.line_number(line_number);
        return r;
    } catch (const std::invalid_argument& e) {
        BOOST_LOG_SEV(lg, error) << "Conversion error. Field " << field_number
                                 << ". Value: '" << tokens[field_number] << "'";

        hydration_error he(invalid_field_value);
        he << error_in_field(field_number);
        throw he;
    } catch (const std::out_of_range& e) {
        BOOST_LOG_SEV(lg, error) << "Conversion error. Field " << field_number
                                 << ". Value: '" << tokens[field_number] << "'";

        hydration_error he(invalid_field_value);
        he << error_in_field(field_number);
        throw he;
    }
}

model hydrator::hydrate(std::istream& is) const {
    model r;

    std::string input_line;
    unsigned int line_number(0);
    try {
        while (std::getline(is, input_line)) {
            if (input_line.empty()){
                BOOST_LOG_SEV(lg, debug) << "Ignoring empty line. Line number: "
                                         << line_number;
            }

            /*
              const auto c(input_line[0]);
              if (c == hash && in_header) {
              process_header_line()
              }
            */
            r.points().push_back(process_point_line(input_line, line_number));
            ++line_number;
        }
    } catch(boost::exception& e) {
        BOOST_LOG_SEV(lg, error) << "Failed to parse line: " << line_number;
        e << error_in_line(line_number);
        throw;
    }
    return r;
}

model hydrator::hydrate(const boost::filesystem::path& p) const {
    const auto gs(p.generic_string());
    BOOST_LOG_SEV(lg, debug) << "Parsing file: " << gs;
    boost::filesystem::ifstream s(p);

    if (s.fail()) {
        BOOST_LOG_SEV(lg, error) << failed_to_open_file << ": " << gs;
        BOOST_THROW_EXCEPTION(hydration_error(failed_to_open_file + gs));
    }

    try {
        const auto r(hydrate(s));
        BOOST_LOG_SEV(lg, debug) << "Parsed file successfully.";
        return r;
    } catch(boost::exception& e) {
        const auto s(p.generic_string());
        BOOST_LOG_SEV(lg, error) << "Failed to parse file: " << s;
        e << error_in_file(s);
        throw;
    }
}

} }
