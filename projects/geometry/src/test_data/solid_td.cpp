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
#include "neurite/geometry/test_data/solid_td.hpp"
#include "neurite/geometry/test_data/sphere_td.hpp"
#include "neurite/geometry/test_data/truncated_cone_td.hpp"

namespace neurite {
namespace geometry {

void solid_generator::
populate(const unsigned int /*position*/, result_type& /*v*/) {
}

solid_generator::result_type*
solid_generator::create_ptr(const unsigned int position) {
    if ((position % 1) == 0)
        return neurite::geometry::truncated_cone_generator::create_ptr(position);
    return neurite::geometry::sphere_generator::create_ptr(position);
}

} }
