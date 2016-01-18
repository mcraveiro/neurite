/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2015-2016 Marco Craveiro <marco.craveiro@gmail.com>
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
#include <string>
#include <ostream>
#include <stdexcept>
#include "neurite/swc/io/structure_identifier_types_io.hpp"

namespace neurite {
namespace swc {

std::ostream& operator<<(std::ostream& s, const structure_identifier_types& v) {
    s << "{ " << "\"__type__\": " << "\"structure_identifier_types\", " << "\"value\": ";

    std::string attr;
    switch (v) {
    case structure_identifier_types::invalid:
        attr = "\"invalid\"";
        break;
    case structure_identifier_types::soma:
        attr = "\"soma\"";
        break;
    case structure_identifier_types::axon:
        attr = "\"axon\"";
        break;
    case structure_identifier_types::basal_dendrite:
        attr = "\"basal_dendrite\"";
        break;
    case structure_identifier_types::apical_dendrite:
        attr = "\"apical_dendrite\"";
        break;
    case structure_identifier_types::fork_point:
        attr = "\"fork_point\"";
        break;
    case structure_identifier_types::end_point:
        attr = "\"end_point\"";
        break;
    case structure_identifier_types::custom:
        attr = "\"custom\"";
        break;
    default:
        throw std::invalid_argument("Invalid value for structure_identifier_types");
    }
    s << attr << " }";
    return s;
}

} }
