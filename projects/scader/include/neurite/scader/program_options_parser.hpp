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
#ifndef NEURITE_SCADER_PROGRAM_OPTIONS_PARSER_HPP
#define NEURITE_SCADER_PROGRAM_OPTIONS_PARSER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <vector>
#include <utility>
#include <boost/optional.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/program_options.hpp>

namespace neurite {
namespace scader {

class program_options_parser {
private:
    boost::program_options::options_description options_factory() const;

private:
    boost::optional<boost::program_options::variables_map>
    variables_map_factory(const std::vector<std::string>& arguments) const;

private:
    void help(const boost::program_options::options_description od) const;
    void version() const;

private:
    std::pair<boost::filesystem::path, boost::filesystem::path>
    transform_options(const boost::program_options::variables_map& vm) const;

public:
    boost::optional<std::pair<boost::filesystem::path, boost::filesystem::path>>
    parse(const int argc, const char* argv[]) const;
};

} }

#endif
