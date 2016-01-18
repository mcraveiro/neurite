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
#include "neurite/swc/hash/header_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

}

namespace neurite {
namespace swc {

std::size_t header_hasher::hash(const header& v) {
    std::size_t seed(0);

    combine(seed, v.original_source());
    combine(seed, v.creature());
    combine(seed, v.region());
    combine(seed, v.field_or_layer());
    combine(seed, v.type());
    combine(seed, v.contributor());
    combine(seed, v.reference());
    combine(seed, v.raw());
    combine(seed, v.extras());
    combine(seed, v.soma_area());
    combine(seed, v.shrinkage_correction());
    combine(seed, v.version_number());
    combine(seed, v.version_date());
    combine(seed, v.scale());

    return seed;
}

} }
