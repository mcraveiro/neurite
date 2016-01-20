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
#include "neurite/geometry/test_data/point_td.hpp"
#include "neurite/geometry/test_data/colour_td.hpp"
#include "neurite/geometry/test_data/object_td.hpp"
#include "neurite/geometry/test_data/sphere_td.hpp"
#include "neurite/geometry/test_data/cylinder_td.hpp"
#include "neurite/geometry/test_data/transformation_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return position;
}

neurite::geometry::point
create_neurite_geometry_point(const unsigned int position) {
    return neurite::geometry::point_generator::create(position);
}

neurite::geometry::colour
create_neurite_geometry_colour(const unsigned int position) {
    return neurite::geometry::colour_generator::create(position);
}

neurite::geometry::transformation
create_neurite_geometry_transformation(const unsigned int position) {
    return neurite::geometry::transformation_generator::create(position);
}

std::list<neurite::geometry::transformation> create_std_list_neurite_geometry_transformation(unsigned int position) {
    std::list<neurite::geometry::transformation> r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_neurite_geometry_transformation(position + i));
    }
    return r;
}

}

namespace neurite {
namespace geometry {

void object_generator::
populate(const unsigned int position, result_type& v) {
    v.id(create_int(position + 0));
    v.parent_id(create_int(position + 1));
    v.centre(create_neurite_geometry_point(position + 2));
    v.colour(create_neurite_geometry_colour(position + 3));
    v.transformations(create_std_list_neurite_geometry_transformation(position + 4));
}

object_generator::result_type*
object_generator::create_ptr(const unsigned int position) {
    if ((position % 1) == 0)
        return neurite::geometry::sphere_generator::create_ptr(position);
    return neurite::geometry::cylinder_generator::create_ptr(position);
}

} }
