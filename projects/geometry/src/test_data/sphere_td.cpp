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
#include "neurite/geometry/test_data/object_td.hpp"
#include "neurite/geometry/test_data/sphere_td.hpp"

namespace {

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace neurite {
namespace geometry {

sphere_generator::sphere_generator() : position_(0) { }

void sphere_generator::
populate(const unsigned int position, result_type& v) {
    neurite::geometry::object_generator::populate(position, v);
    v.radius(create_double(position + 0));
}

sphere_generator::result_type
sphere_generator::create(const unsigned int position) {
    sphere r;
    sphere_generator::populate(position, r);
    return r;
}

sphere_generator::result_type*
sphere_generator::create_ptr(const unsigned int position) {
    sphere* p = new sphere();
    sphere_generator::populate(position, *p);
    return p;
}

sphere_generator::result_type
sphere_generator::operator()() {
    return create(position_++);
}

} }
