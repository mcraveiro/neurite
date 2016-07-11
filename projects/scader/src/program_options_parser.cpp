/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
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
#include "neurite/config/version.hpp"
#include "neurite/scader/parser_validation_error.hpp"
#include "neurite/scader/program_options_parser.hpp"

namespace {

const std::string empty;
const std::string comma(",");
const std::string missing_source("Mandatory parameter source is missing. ");
const std::string missing_destination(
    "Mandatory parameter destination is missing. ");

const std::string scader_product("Neurite Scader v" NEURITE_VERSION);
const std::string source_arg("source");
const std::string destination_arg("destination");
const std::string help_arg("help");
const std::string version_arg("version");
const std::string verbose_arg("verbose");

}

namespace neurite {
namespace scader {

boost::program_options::options_description
program_options_parser::options_factory() const {
    using boost::program_options::value;

    boost::program_options::options_description go("General options");
    go.add_options()
        ("help,h", "Display this help and exit.")
        ("verbose,v", "Output additional diagnostic information.")
        ("version", "Output version information and exit.");

    boost::program_options::options_description fo("File options");
    fo.add_options()
        ("source,s", value<std::string>(), "Source SWC file.")
        ("destination,d", value<std::string>(), "Output SCAD script.");

    boost::program_options::options_description r;
    r.add(go);
    r.add(fo);
    return r;
}

boost::optional<boost::program_options::variables_map> program_options_parser::
variables_map_factory(const std::vector<std::string>& arguments) const {
    const auto options(options_factory());

    using namespace boost::program_options;
    variables_map r;
    try {
        basic_command_line_parser<char> parser(arguments);
        store(parser.options(options).run(), r);
        notify(r);
    } catch (const boost::program_options::error& e) {
        BOOST_THROW_EXCEPTION(parser_validation_error(e.what()));
    }

    if (r.count(help_arg)) {
        help(options);
        return boost::optional<boost::program_options::variables_map>();
    }

    if (r.count(version_arg)) {
        version();
        return boost::optional<boost::program_options::variables_map>();
    }

    return r;
}

void program_options_parser::
help(const boost::program_options::options_description od) const {
    std::cout << "Neurite Scader." << std::endl
              << "Generates a SCAD script representation from a SWC file."
              << std::endl << std::endl << od << std::endl;
}

void program_options_parser::version() const {
    std::cout << scader_product << std::endl
              << "Copyright (C) 2016 Marco Craveiro." << std::endl
              << "License: GPLv3 - GNU GPL version 3 or later "
              << "<http://gnu.org/licenses/gpl.html>."
              << std::endl;

}

std::pair<boost::filesystem::path, boost::filesystem::path>
program_options_parser::
transform_options(const boost::program_options::variables_map& vm) const {
    if (!vm.count(source_arg))
        BOOST_THROW_EXCEPTION(parser_validation_error(missing_source));

    if (!vm.count(destination_arg))
        BOOST_THROW_EXCEPTION(parser_validation_error(missing_destination));

    std::pair<boost::filesystem::path, boost::filesystem::path> r;
    r.first = vm[source_arg].as<std::string>();
    r.second = vm[destination_arg].as<std::string>();

    return r;
}

std::string program_options_parser::product() const {
    return scader_product;
}

boost::optional<std::pair<boost::filesystem::path, boost::filesystem::path>>
program_options_parser::parse(const int argc, const char* argv[]) const {
    const std::vector<std::string> args(argv + 1, argv + argc);
    const auto o(variables_map_factory(args));
    if (!o) {
        return boost::optional<
            std::pair<boost::filesystem::path, boost::filesystem::path>
        >();
    }
    return transform_options(*o);
}

} }
