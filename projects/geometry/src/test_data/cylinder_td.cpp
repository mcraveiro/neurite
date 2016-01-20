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
#include "neurite/geometry/test_data/cylinder_td.hpp"

namespace {

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace neurite {
namespace geometry {

cylinder_generator::cylinder_generator() : position_(0) { }

void cylinder_generator::
populate(const unsigned int position, result_type& v) {
    neurite::geometry::object_generator::populate(position, v);
    v.radius(create_double(position + 0));
    v.height(create_double(position + 1));
}

cylinder_generator::result_type
cylinder_generator::create(const unsigned int position) {
    cylinder r;
    cylinder_generator::populate(position, r);
    return r;
}

cylinder_generator::result_type*
cylinder_generator::create_ptr(const unsigned int position) {
    cylinder* p = new cylinder();
    cylinder_generator::populate(position, *p);
    return p;
}

cylinder_generator::result_type
cylinder_generator::operator()() {
    return create(position_++);
}

} }
