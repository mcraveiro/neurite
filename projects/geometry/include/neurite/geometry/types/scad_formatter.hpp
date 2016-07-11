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
#ifndef NEURITE_GEOMETRY_TYPES_SCAD_FORMATTER_HPP
#define NEURITE_GEOMETRY_TYPES_SCAD_FORMATTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <sstream>
#include "neurite/geometry/types/node.hpp"
#include "neurite/geometry/types/node_visitor.hpp"
#include "neurite/geometry/types/solid_visitor.hpp"

namespace neurite {
namespace geometry {

class scad_formatter : public node_visitor, public solid_visitor {
public:
    scad_formatter();

private:
    void indent();

public:
    using solid_visitor::visit;
    void visit(const sphere& s) override;
    void visit(const truncated_cone& s) override;

public:
    using node_visitor::visit;
    void visit(const affine_transformation_node& n) override;
    void visit(const nef_node& n) override;
    void visit(const polyhedron_node& n) override;
    void visit(const solid_node& n) override;
    void visit(const union_node& n) override;

public:
    std::string format(const node& n);

private:
    std::ostringstream stream_;
    unsigned int indentation_level_;
};

} }

#endif
