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
#include "neurite/geometry/test_data/union_node_td.hpp"

namespace {

neurite::geometry::node*
create_neurite_geometry_node_ptr(const unsigned int position) {
    return neurite::geometry::node_generator::create_ptr(position);
}

boost::shared_ptr<neurite::geometry::node>
create_boost_shared_ptr_neurite_geometry_node(unsigned int position) {
    boost::shared_ptr<neurite::geometry::node> r(
        create_neurite_geometry_node_ptr(position));
    return r;
}

std::list<boost::shared_ptr<neurite::geometry::node> > create_std_list_boost_shared_ptr_neurite_geometry_node_(unsigned int position) {
    std::list<boost::shared_ptr<neurite::geometry::node> > r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_boost_shared_ptr_neurite_geometry_node(position + i));
    }
    return r;
}

}

namespace neurite {
namespace geometry {

union_node_generator::union_node_generator() : position_(0) { }

void union_node_generator::
populate(const unsigned int position, result_type& v) {
    neurite::geometry::node_generator::populate(position, v);
    v.operands(create_std_list_boost_shared_ptr_neurite_geometry_node_(position + 0));
}

union_node_generator::result_type
union_node_generator::create(const unsigned int position) {
    union_node r;
    union_node_generator::populate(position, r);
    return r;
}

union_node_generator::result_type*
union_node_generator::create_ptr(const unsigned int position) {
    union_node* p = new union_node();
    union_node_generator::populate(position, *p);
    return p;
}

union_node_generator::result_type
union_node_generator::operator()() {
    return create(position_++);
}

} }
