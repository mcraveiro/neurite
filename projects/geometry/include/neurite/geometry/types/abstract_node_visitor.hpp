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
#ifndef NEURITE_GEOMETRY_TYPES_ABSTRACT_NODE_VISITOR_HPP
#define NEURITE_GEOMETRY_TYPES_ABSTRACT_NODE_VISITOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "neurite/geometry/types/nef_node_fwd.hpp"
#include "neurite/geometry/types/solid_node_fwd.hpp"
#include "neurite/geometry/types/union_node_fwd.hpp"
#include "neurite/geometry/types/polyhedron_node_fwd.hpp"
#include "neurite/geometry/types/affine_transformation_node_fwd.hpp"

namespace neurite {
namespace geometry {

/**
 * @brief Visitor for abstract_node
 */
class abstract_node_visitor {
public:
    virtual ~abstract_node_visitor() noexcept = 0;

public:
    /**
     * @brief Accept visits for type neurite::geometry::affine_transformation_node
     */
    /**@{*/
    virtual void visit(const neurite::geometry::affine_transformation_node&) const { }
    virtual void visit(const neurite::geometry::affine_transformation_node&) { }
    virtual void visit(neurite::geometry::affine_transformation_node&) const { }
    virtual void visit(neurite::geometry::affine_transformation_node&) { }
    /**@}*/

    /**
     * @brief Accept visits for type neurite::geometry::nef_node
     */
    /**@{*/
    virtual void visit(const neurite::geometry::nef_node&) const { }
    virtual void visit(const neurite::geometry::nef_node&) { }
    virtual void visit(neurite::geometry::nef_node&) const { }
    virtual void visit(neurite::geometry::nef_node&) { }
    /**@}*/

    /**
     * @brief Accept visits for type neurite::geometry::polyhedron_node
     */
    /**@{*/
    virtual void visit(const neurite::geometry::polyhedron_node&) const { }
    virtual void visit(const neurite::geometry::polyhedron_node&) { }
    virtual void visit(neurite::geometry::polyhedron_node&) const { }
    virtual void visit(neurite::geometry::polyhedron_node&) { }
    /**@}*/

    /**
     * @brief Accept visits for type neurite::geometry::solid_node
     */
    /**@{*/
    virtual void visit(const neurite::geometry::solid_node&) const { }
    virtual void visit(const neurite::geometry::solid_node&) { }
    virtual void visit(neurite::geometry::solid_node&) const { }
    virtual void visit(neurite::geometry::solid_node&) { }
    /**@}*/

    /**
     * @brief Accept visits for type neurite::geometry::union_node
     */
    /**@{*/
    virtual void visit(const neurite::geometry::union_node&) const { }
    virtual void visit(const neurite::geometry::union_node&) { }
    virtual void visit(neurite::geometry::union_node&) const { }
    virtual void visit(neurite::geometry::union_node&) { }
    /**@}*/
};

inline abstract_node_visitor::~abstract_node_visitor() noexcept { }

} }

#endif
