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
#include "neurite/geometry/test_data/solid_node_td.hpp"
#include "neurite/geometry/test_data/union_node_td.hpp"
#include "neurite/geometry/test_data/polyhedron_node_td.hpp"
#include "neurite/geometry/test_data/affine_transformation_node_td.hpp"

namespace neurite {
namespace geometry {

void node_generator::
populate(const unsigned int /*position*/, result_type& /*v*/) {
}

node_generator::result_type*
node_generator::create_ptr(const unsigned int position) {
    if ((position % 4) == 0)
        return neurite::geometry::nef_node_generator::create_ptr(position);
    if ((position % 4) == 1)
        return neurite::geometry::polyhedron_node_generator::create_ptr(position);
    if ((position % 4) == 2)
        return neurite::geometry::solid_node_generator::create_ptr(position);
    if ((position % 4) == 3)
        return neurite::geometry::union_node_generator::create_ptr(position);
    return neurite::geometry::affine_transformation_node_generator::create_ptr(position);
}

} }
