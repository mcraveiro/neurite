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
#ifndef NEURITE_GEOMETRY_TYPES_ALL_HPP
#define NEURITE_GEOMETRY_TYPES_ALL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "neurite/geometry/types/tree.hpp"
#include "neurite/geometry/types/solid.hpp"
#include "neurite/geometry/types/mesher.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/polygon.hpp"
#include "neurite/geometry/types/geometry.hpp"
#include "neurite/geometry/types/nef_node.hpp"
#include "neurite/geometry/types/vector3d.hpp"
#include "neurite/geometry/types/workflow.hpp"
#include "neurite/geometry/types/polyhedron.hpp"
#include "neurite/geometry/types/solid_node.hpp"
#include "neurite/geometry/types/union_node.hpp"
#include "neurite/geometry/types/nef_factory.hpp"
#include "neurite/geometry/types/tessellator.hpp"
#include "neurite/geometry/types/abstract_node.hpp"
#include "neurite/geometry/types/nef_evaluator.hpp"
#include "neurite/geometry/types/solid_visitor.hpp"
#include "neurite/geometry/types/nef_polyhedron.hpp"
#include "neurite/geometry/types/scad_evaluator.hpp"
#include "neurite/geometry/types/truncated_cone.hpp"
#include "neurite/geometry/types/polyhedron_node.hpp"
#include "neurite/geometry/types/abstract_node_visitor.hpp"
#include "neurite/geometry/types/affine_transformation.hpp"
#include "neurite/geometry/types/tessellation_executor.hpp"
#include "neurite/geometry/types/nef_conversion_executor.hpp"
#include "neurite/geometry/types/affine_transformation_node.hpp"
#include "neurite/geometry/types/affine_transformation_types.hpp"
#include "neurite/geometry/types/affine_transformation_executor.hpp"
#include "neurite/geometry/types/affine_transformation_injector.hpp"

#endif
