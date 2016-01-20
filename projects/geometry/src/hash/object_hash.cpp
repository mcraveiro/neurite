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
#include "neurite/geometry/hash/point_hash.hpp"
#include "neurite/geometry/hash/colour_hash.hpp"
#include "neurite/geometry/hash/object_hash.hpp"
#include "neurite/geometry/hash/transformation_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_std_list_neurite_geometry_transformation(const std::list<neurite::geometry::transformation>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

}

namespace neurite {
namespace geometry {

std::size_t object_hasher::hash(const object& v) {
    std::size_t seed(0);

    combine(seed, v.id());
    combine(seed, v.parent_id());
    combine(seed, v.centre());
    combine(seed, v.colour());
    combine(seed, hash_std_list_neurite_geometry_transformation(v.transformations()));

    return seed;
}

} }
