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
#include "neurite/swc/test_data/model_td.hpp"
#include "neurite/swc/test_data/point_td.hpp"
#include "neurite/swc/test_data/header_td.hpp"

namespace {

neurite::swc::header
create_neurite_swc_header(const unsigned int position) {
    return neurite::swc::header_generator::create(position);
}

boost::optional<neurite::swc::header>
create_boost_optional_neurite_swc_header(unsigned int position) {
    boost::optional<neurite::swc::header> r(
        create_neurite_swc_header(position));
    return r;
}

neurite::swc::point
create_neurite_swc_point(const unsigned int position) {
    return neurite::swc::point_generator::create(position);
}

std::list<neurite::swc::point> create_std_list_neurite_swc_point(unsigned int position) {
    std::list<neurite::swc::point> r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_neurite_swc_point(position + i));
    }
    return r;
}

}

namespace neurite {
namespace swc {

model_generator::model_generator() : position_(0) { }

void model_generator::
populate(const unsigned int position, result_type& v) {
    v.header(create_boost_optional_neurite_swc_header(position + 0));
    v.points(create_std_list_neurite_swc_point(position + 1));
}

model_generator::result_type
model_generator::create(const unsigned int position) {
    model r;
    model_generator::populate(position, r);
    return r;
}

model_generator::result_type*
model_generator::create_ptr(const unsigned int position) {
    model* p = new model();
    model_generator::populate(position, *p);
    return p;
}

model_generator::result_type
model_generator::operator()() {
    return create(position_++);
}

} }
