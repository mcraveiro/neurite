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
#include "neurite/geometry/test_data/truncated_cone_td.hpp"

namespace {

neurite::geometry::vector3d
create_neurite_geometry_vector3d(const unsigned int position) {
    return neurite::geometry::vector3d_generator::create(position);
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace neurite {
namespace geometry {

truncated_cone_generator::truncated_cone_generator() : position_(0) { }

void truncated_cone_generator::
populate(const unsigned int position, result_type& v) {
    neurite::geometry::solid_generator::populate(position, v);
    v.first(create_neurite_geometry_vector3d(position + 0));
    v.first_radius(create_double(position + 1));
    v.second_radius(create_double(position + 2));
    v.second(create_neurite_geometry_vector3d(position + 3));
}

truncated_cone_generator::result_type
truncated_cone_generator::create(const unsigned int position) {
    truncated_cone r;
    truncated_cone_generator::populate(position, r);
    return r;
}

truncated_cone_generator::result_type*
truncated_cone_generator::create_ptr(const unsigned int position) {
    truncated_cone* p = new truncated_cone();
    truncated_cone_generator::populate(position, *p);
    return p;
}

truncated_cone_generator::result_type
truncated_cone_generator::operator()() {
    return create(position_++);
}

} }
