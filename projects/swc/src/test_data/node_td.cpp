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
#include "neurite/swc/test_data/node_td.hpp"
#include "neurite/swc/test_data/sample_td.hpp"

namespace {

neurite::swc::sample
create_neurite_swc_sample(const unsigned int position) {
    return neurite::swc::sample_generator::create(position);
}

neurite::swc::node*
create_neurite_swc_node_ptr(const unsigned int) {
    return nullptr;
}

boost::shared_ptr<neurite::swc::node>
create_boost_shared_ptr_neurite_swc_node(unsigned int position) {
    boost::shared_ptr<neurite::swc::node> r(
        create_neurite_swc_node_ptr(position));
    return r;
}

std::list<boost::shared_ptr<neurite::swc::node> > create_std_list_boost_shared_ptr_neurite_swc_node_(unsigned int position) {
    std::list<boost::shared_ptr<neurite::swc::node> > r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_boost_shared_ptr_neurite_swc_node(position + i));
    }
    return r;
}

}

namespace neurite {
namespace swc {

node_generator::node_generator() : position_(0) { }

void node_generator::
populate(const unsigned int position, result_type& v) {
    v.content(create_neurite_swc_sample(position + 0));
    v.parent(create_boost_shared_ptr_neurite_swc_node(position + 1));
    v.children(create_std_list_boost_shared_ptr_neurite_swc_node_(position + 2));
}

node_generator::result_type
node_generator::create(const unsigned int position) {
    node r;
    node_generator::populate(position, r);
    return r;
}

node_generator::result_type*
node_generator::create_ptr(const unsigned int position) {
    node* p = new node();
    node_generator::populate(position, *p);
    return p;
}

node_generator::result_type
node_generator::operator()() {
    return create(position_++);
}

} }
