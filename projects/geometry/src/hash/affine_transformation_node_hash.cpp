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
#include "neurite/geometry/hash/abstract_node_hash.hpp"
#include "neurite/geometry/hash/affine_transformation_hash.hpp"
#include "neurite/geometry/hash/affine_transformation_node_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_boost_shared_ptr_neurite_geometry_abstract_node(const boost::shared_ptr<neurite::geometry::abstract_node>& v) {
    std::size_t seed(0);
    combine(seed, *v);
    return seed;
}

inline std::size_t hash_std_list_boost_shared_ptr_neurite_geometry_abstract_node_(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, hash_boost_shared_ptr_neurite_geometry_abstract_node(i));
    }
    return seed;
}

}

namespace neurite {
namespace geometry {

std::size_t affine_transformation_node_hasher::hash(const affine_transformation_node& v) {
    std::size_t seed(0);

    combine(seed, dynamic_cast<const neurite::geometry::abstract_node&>(v));

    combine(seed, v.transformation());
    combine(seed, hash_std_list_boost_shared_ptr_neurite_geometry_abstract_node_(v.children()));

    return seed;
}

} }
