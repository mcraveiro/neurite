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
#ifndef NEURITE_GEOMETRY_TYPES_SOLID_VISITOR_HPP
#define NEURITE_GEOMETRY_TYPES_SOLID_VISITOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "neurite/geometry/types/sphere_fwd.hpp"
#include "neurite/geometry/types/truncated_cone_fwd.hpp"

namespace neurite {
namespace geometry {

/**
 * @brief Visitor for solid
 */
class solid_visitor {
public:
    virtual ~solid_visitor() noexcept = 0;

public:
    /**
     * @brief Accept visits for type neurite::geometry::sphere
     */
    /**@{*/
    virtual void visit(const neurite::geometry::sphere&) const { }
    virtual void visit(const neurite::geometry::sphere&) { }
    virtual void visit(neurite::geometry::sphere&) const { }
    virtual void visit(neurite::geometry::sphere&) { }
    /**@}*/

    /**
     * @brief Accept visits for type neurite::geometry::truncated_cone
     */
    /**@{*/
    virtual void visit(const neurite::geometry::truncated_cone&) const { }
    virtual void visit(const neurite::geometry::truncated_cone&) { }
    virtual void visit(neurite::geometry::truncated_cone&) const { }
    virtual void visit(neurite::geometry::truncated_cone&) { }
    /**@}*/
};

inline solid_visitor::~solid_visitor() noexcept { }

} }

#endif
