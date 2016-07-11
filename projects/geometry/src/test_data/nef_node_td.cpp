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
#include "neurite/geometry/test_data/node_td.hpp"
#include "neurite/geometry/test_data/nef_node_td.hpp"
#include "neurite/geometry/test_data/nef_polyhedron_td.hpp"

namespace {

neurite::geometry::nef_polyhedron
create_neurite_geometry_nef_polyhedron(const unsigned int position) {
    return neurite::geometry::nef_polyhedron_generator::create(position);
}

}

namespace neurite {
namespace geometry {

nef_node_generator::nef_node_generator() : position_(0) { }

void nef_node_generator::
populate(const unsigned int position, result_type& v) {
    neurite::geometry::node_generator::populate(position, v);
    v.polyhedron(create_neurite_geometry_nef_polyhedron(position + 0));
}

nef_node_generator::result_type
nef_node_generator::create(const unsigned int position) {
    nef_node r;
    nef_node_generator::populate(position, r);
    return r;
}

nef_node_generator::result_type*
nef_node_generator::create_ptr(const unsigned int position) {
    nef_node* p = new nef_node();
    nef_node_generator::populate(position, *p);
    return p;
}

nef_node_generator::result_type
nef_node_generator::operator()() {
    return create(position_++);
}

} }
