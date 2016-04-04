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
#include "neurite/swc/test_data/point_td.hpp"
#include "neurite/swc/test_data/sample_td.hpp"
#include "neurite/swc/test_data/structure_identifier_types_td.hpp"

namespace {

unsigned int create_unsigned_int(const unsigned int position) {
    return static_cast<unsigned int>(position);
}

int create_int(const unsigned int position) {
    return position;
}

neurite::swc::structure_identifier_types
create_neurite_swc_structure_identifier_types(const unsigned int position) {
    return neurite::swc::structure_identifier_types_generator::create(position);
}

neurite::swc::point
create_neurite_swc_point(const unsigned int position) {
    return neurite::swc::point_generator::create(position);
}

double create_double(const unsigned int position) {
    return static_cast<double>(position);
}

}

namespace neurite {
namespace swc {

sample_generator::sample_generator() : position_(0) { }

void sample_generator::
populate(const unsigned int position, result_type& v) {
    v.number(create_unsigned_int(position + 0));
    v.unparsed_structure_identifier(create_int(position + 1));
    v.structure_identifier(create_neurite_swc_structure_identifier_types(position + 2));
    v.position(create_neurite_swc_point(position + 3));
    v.radius(create_double(position + 4));
    v.parent(create_int(position + 5));
    v.line_number(create_unsigned_int(position + 6));
}

sample_generator::result_type
sample_generator::create(const unsigned int position) {
    sample r;
    sample_generator::populate(position, r);
    return r;
}

sample_generator::result_type*
sample_generator::create_ptr(const unsigned int position) {
    sample* p = new sample();
    sample_generator::populate(position, *p);
    return p;
}

sample_generator::result_type
sample_generator::operator()() {
    return create(position_++);
}

} }
