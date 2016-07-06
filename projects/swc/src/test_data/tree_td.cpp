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
#include "neurite/swc/test_data/tree_td.hpp"

namespace {

neurite::swc::node
create_neurite_swc_node(const unsigned int position) {
    return neurite::swc::node_generator::create(position);
}

}

namespace neurite {
namespace swc {

tree_generator::tree_generator() : position_(0) { }

void tree_generator::
populate(const unsigned int position, result_type& v) {
    v.root(create_neurite_swc_node(position + 0));
}

tree_generator::result_type
tree_generator::create(const unsigned int position) {
    tree r;
    tree_generator::populate(position, r);
    return r;
}

tree_generator::result_type*
tree_generator::create_ptr(const unsigned int position) {
    tree* p = new tree();
    tree_generator::populate(position, *p);
    return p;
}

tree_generator::result_type
tree_generator::operator()() {
    return create(position_++);
}

} }
