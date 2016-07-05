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
#include <sstream>
#include "neurite/geometry/test_data/nef_polyhedron_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

}

namespace neurite {
namespace geometry {

nef_polyhedron_generator::nef_polyhedron_generator() : position_(0) { }

void nef_polyhedron_generator::
populate(const unsigned int position, result_type& v) {
    v.polygons(create_std_string(position + 0));
}

nef_polyhedron_generator::result_type
nef_polyhedron_generator::create(const unsigned int position) {
    nef_polyhedron r;
    nef_polyhedron_generator::populate(position, r);
    return r;
}

nef_polyhedron_generator::result_type*
nef_polyhedron_generator::create_ptr(const unsigned int position) {
    nef_polyhedron* p = new nef_polyhedron();
    nef_polyhedron_generator::populate(position, *p);
    return p;
}

nef_polyhedron_generator::result_type
nef_polyhedron_generator::operator()() {
    return create(position_++);
}

} }
