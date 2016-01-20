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
#include "neurite/geometry/test_data/plane_td.hpp"
#include "neurite/geometry/test_data/object_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return position;
}

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

neurite::geometry::object*
create_neurite_geometry_object_ptr(const unsigned int position) {
    return neurite::geometry::object_generator::create_ptr(position);
}

boost::shared_ptr<neurite::geometry::object>
create_boost_shared_ptr_neurite_geometry_object(unsigned int position) {
    boost::shared_ptr<neurite::geometry::object> r(
        create_neurite_geometry_object_ptr(position));
    return r;
}

std::list<boost::shared_ptr<neurite::geometry::object> > create_std_list_boost_shared_ptr_neurite_geometry_object_(unsigned int position) {
    std::list<boost::shared_ptr<neurite::geometry::object> > r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_boost_shared_ptr_neurite_geometry_object(position + i));
    }
    return r;
}

}

namespace neurite {
namespace geometry {

plane_generator::plane_generator() : position_(0) { }

void plane_generator::
populate(const unsigned int position, result_type& v) {
    v.id(create_int(position + 0));
    v.name(create_std_string(position + 1));
    v.objects(create_std_list_boost_shared_ptr_neurite_geometry_object_(position + 2));
}

plane_generator::result_type
plane_generator::create(const unsigned int position) {
    plane r;
    plane_generator::populate(position, r);
    return r;
}

plane_generator::result_type*
plane_generator::create_ptr(const unsigned int position) {
    plane* p = new plane();
    plane_generator::populate(position, *p);
    return p;
}

plane_generator::result_type
plane_generator::operator()() {
    return create(position_++);
}

} }
