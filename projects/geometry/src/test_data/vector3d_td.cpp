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
#include "neurite/geometry/test_data/vector3d_td.hpp"

namespace {

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace neurite {
namespace geometry {

vector3d_generator::vector3d_generator() : position_(0) { }

void vector3d_generator::
populate(const unsigned int position, result_type& v) {
    v.x(create_double(position + 0));
    v.y(create_double(position + 1));
    v.z(create_double(position + 2));
}

vector3d_generator::result_type
vector3d_generator::create(const unsigned int position) {
    vector3d r;
    vector3d_generator::populate(position, r);
    return r;
}

vector3d_generator::result_type*
vector3d_generator::create_ptr(const unsigned int position) {
    vector3d* p = new vector3d();
    vector3d_generator::populate(position, *p);
    return p;
}

vector3d_generator::result_type
vector3d_generator::operator()() {
    return create(position_++);
}

} }
