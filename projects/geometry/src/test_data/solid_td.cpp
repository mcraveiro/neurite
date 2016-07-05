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
#include "neurite/geometry/test_data/solid_td.hpp"
#include "neurite/geometry/test_data/vector3d_td.hpp"
#include "neurite/geometry/test_data/solid_types_td.hpp"

namespace {

neurite::geometry::vector3d
create_neurite_geometry_vector3d(const unsigned int position) {
    return neurite::geometry::vector3d_generator::create(position);
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

neurite::geometry::solid_types
create_neurite_geometry_solid_types(const unsigned int position) {
    return neurite::geometry::solid_types_generator::create(position);
}

}

namespace neurite {
namespace geometry {

solid_generator::solid_generator() : position_(0) { }

void solid_generator::
populate(const unsigned int position, result_type& v) {
    v.centre(create_neurite_geometry_vector3d(position + 0));
    v.first_radius(create_double(position + 1));
    v.second_radius(create_double(position + 2));
    v.height(create_double(position + 3));
    v.type(create_neurite_geometry_solid_types(position + 4));
}

solid_generator::result_type
solid_generator::create(const unsigned int position) {
    solid r;
    solid_generator::populate(position, r);
    return r;
}

solid_generator::result_type*
solid_generator::create_ptr(const unsigned int position) {
    solid* p = new solid();
    solid_generator::populate(position, *p);
    return p;
}

solid_generator::result_type
solid_generator::operator()() {
    return create(position_++);
}

} }
