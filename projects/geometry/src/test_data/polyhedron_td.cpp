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
#include "neurite/geometry/test_data/polygon_td.hpp"
#include "neurite/geometry/test_data/polyhedron_td.hpp"

namespace {

neurite::geometry::polygon
create_neurite_geometry_polygon(const unsigned int position) {
    return neurite::geometry::polygon_generator::create(position);
}

std::vector<neurite::geometry::polygon> create_std_vector_neurite_geometry_polygon(unsigned int position) {
    std::vector<neurite::geometry::polygon> r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_neurite_geometry_polygon(position + i));
    }
    return r;
}

}

namespace neurite {
namespace geometry {

polyhedron_generator::polyhedron_generator() : position_(0) { }

void polyhedron_generator::
populate(const unsigned int position, result_type& v) {
    v.polygons(create_std_vector_neurite_geometry_polygon(position + 0));
}

polyhedron_generator::result_type
polyhedron_generator::create(const unsigned int position) {
    polyhedron r;
    polyhedron_generator::populate(position, r);
    return r;
}

polyhedron_generator::result_type*
polyhedron_generator::create_ptr(const unsigned int position) {
    polyhedron* p = new polyhedron();
    polyhedron_generator::populate(position, *p);
    return p;
}

polyhedron_generator::result_type
polyhedron_generator::operator()() {
    return create(position_++);
}

} }
