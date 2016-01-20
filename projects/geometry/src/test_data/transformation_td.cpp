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
#include "neurite/geometry/test_data/transformation_td.hpp"
#include "neurite/geometry/test_data/transformation_types_td.hpp"

namespace {

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

neurite::geometry::transformation_types
create_neurite_geometry_transformation_types(const unsigned int position) {
    return neurite::geometry::transformation_types_generator::create(position);
}

}

namespace neurite {
namespace geometry {

transformation_generator::transformation_generator() : position_(0) { }

void transformation_generator::
populate(const unsigned int position, result_type& v) {
    v.x(create_double(position + 0));
    v.y(create_double(position + 1));
    v.z(create_double(position + 2));
    v.type(create_neurite_geometry_transformation_types(position + 3));
}

transformation_generator::result_type
transformation_generator::create(const unsigned int position) {
    transformation r;
    transformation_generator::populate(position, r);
    return r;
}

transformation_generator::result_type*
transformation_generator::create_ptr(const unsigned int position) {
    transformation* p = new transformation();
    transformation_generator::populate(position, *p);
    return p;
}

transformation_generator::result_type
transformation_generator::operator()() {
    return create(position_++);
}

} }
