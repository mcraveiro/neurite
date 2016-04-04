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
#include <ostream>
#include <boost/io/ios_state.hpp>
#include "neurite/swc/io/point_io.hpp"
#include "neurite/swc/io/sample_io.hpp"
#include "neurite/swc/io/structure_identifier_types_io.hpp"

namespace neurite {
namespace swc {

std::ostream& operator<<(std::ostream& s, const sample& v) {
    boost::io::ios_flags_saver ifs(s);
    s.setf(std::ios_base::boolalpha);
    s.setf(std::ios::fixed, std::ios::floatfield);
    s.precision(6);
    s.setf(std::ios::showpoint);

    s << " { "
      << "\"__type__\": " << "\"neurite::swc::sample\"" << ", "
      << "\"number\": " << v.number() << ", "
      << "\"unparsed_structure_identifier\": " << v.unparsed_structure_identifier() << ", "
      << "\"structure_identifier\": " << v.structure_identifier() << ", "
      << "\"position\": " << v.position() << ", "
      << "\"radius\": " << v.radius() << ", "
      << "\"parent\": " << v.parent() << ", "
      << "\"line_number\": " << v.line_number()
      << " }";
    return(s);
}

} }
