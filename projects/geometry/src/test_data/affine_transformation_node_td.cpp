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
#include "neurite/geometry/test_data/abstract_node_td.hpp"
#include "neurite/geometry/test_data/affine_transformation_td.hpp"
#include "neurite/geometry/test_data/affine_transformation_node_td.hpp"

namespace {

neurite::geometry::affine_transformation
create_neurite_geometry_affine_transformation(const unsigned int position) {
    return neurite::geometry::affine_transformation_generator::create(position);
}

neurite::geometry::abstract_node*
create_neurite_geometry_abstract_node_ptr(const unsigned int position) {
    return neurite::geometry::abstract_node_generator::create_ptr(position);
}

boost::shared_ptr<neurite::geometry::abstract_node>
create_boost_shared_ptr_neurite_geometry_abstract_node(unsigned int position) {
    boost::shared_ptr<neurite::geometry::abstract_node> r(
        create_neurite_geometry_abstract_node_ptr(position));
    return r;
}

std::list<boost::shared_ptr<neurite::geometry::abstract_node> > create_std_list_boost_shared_ptr_neurite_geometry_abstract_node_(unsigned int position) {
    std::list<boost::shared_ptr<neurite::geometry::abstract_node> > r;
    for (unsigned int i(0); i < 4; ++i) {
        r.push_back(create_boost_shared_ptr_neurite_geometry_abstract_node(position + i));
    }
    return r;
}

}

namespace neurite {
namespace geometry {

affine_transformation_node_generator::affine_transformation_node_generator() : position_(0) { }

void affine_transformation_node_generator::
populate(const unsigned int position, result_type& v) {
    neurite::geometry::abstract_node_generator::populate(position, v);
    v.transformation(create_neurite_geometry_affine_transformation(position + 0));
    v.children(create_std_list_boost_shared_ptr_neurite_geometry_abstract_node_(position + 1));
}

affine_transformation_node_generator::result_type
affine_transformation_node_generator::create(const unsigned int position) {
    affine_transformation_node r;
    affine_transformation_node_generator::populate(position, r);
    return r;
}

affine_transformation_node_generator::result_type*
affine_transformation_node_generator::create_ptr(const unsigned int position) {
    affine_transformation_node* p = new affine_transformation_node();
    affine_transformation_node_generator::populate(position, *p);
    return p;
}

affine_transformation_node_generator::result_type
affine_transformation_node_generator::operator()() {
    return create(position_++);
}

} }
