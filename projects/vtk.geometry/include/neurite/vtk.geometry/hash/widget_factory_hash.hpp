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
#ifndef NEURITE_VTK_GEOMETRY_HASH_WIDGET_FACTORY_HASH_HPP
#define NEURITE_VTK_GEOMETRY_HASH_WIDGET_FACTORY_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "neurite/vtk.geometry/types/widget_factory.hpp"

namespace neurite {
namespace vtk {
namespace geometry {

struct widget_factory_hasher {
public:
    static std::size_t hash(const widget_factory& v);
};

} } }

namespace std {

template<>
struct hash<neurite::vtk::geometry::widget_factory> {
public:
    size_t operator()(const neurite::vtk::geometry::widget_factory& v) const {
        return neurite::vtk::geometry::widget_factory_hasher::hash(v);
    }
};

}
#endif
