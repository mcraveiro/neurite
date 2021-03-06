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
#ifndef NEURITE_GEOMETRY_HASH_NEF_POLYHEDRON_HASH_HPP
#define NEURITE_GEOMETRY_HASH_NEF_POLYHEDRON_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/geometry/types/nef_polyhedron.hpp"

namespace neurite {
namespace geometry {

struct nef_polyhedron_hasher {
public:
    static std::size_t hash(const nef_polyhedron& v);
};

} }

namespace std {

template<>
struct hash<neurite::geometry::nef_polyhedron> {
public:
    size_t operator()(const neurite::geometry::nef_polyhedron& v) const {
        return neurite::geometry::nef_polyhedron_hasher::hash(v);
    }
};

}
#endif
