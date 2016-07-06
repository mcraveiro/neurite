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
#ifndef NEURITE_GEOMETRY_SERIALIZATION_ALL_SER_HPP
#define NEURITE_GEOMETRY_SERIALIZATION_ALL_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "neurite/geometry/serialization/tree_ser.hpp"
#include "neurite/geometry/serialization/solid_ser.hpp"
#include "neurite/geometry/serialization/sphere_ser.hpp"
#include "neurite/geometry/serialization/polygon_ser.hpp"
#include "neurite/geometry/serialization/nef_node_ser.hpp"
#include "neurite/geometry/serialization/vector3d_ser.hpp"
#include "neurite/geometry/serialization/registrar_ser.hpp"
#include "neurite/geometry/serialization/polyhedron_ser.hpp"
#include "neurite/geometry/serialization/solid_node_ser.hpp"
#include "neurite/geometry/serialization/union_node_ser.hpp"
#include "neurite/geometry/serialization/abstract_node_ser.hpp"
#include "neurite/geometry/serialization/nef_polyhedron_ser.hpp"
#include "neurite/geometry/serialization/truncated_cone_ser.hpp"
#include "neurite/geometry/serialization/polyhedron_node_ser.hpp"
#include "neurite/geometry/serialization/affine_transformation_ser.hpp"
#include "neurite/geometry/serialization/affine_transformation_node_ser.hpp"
#include "neurite/geometry/serialization/affine_transformation_types_ser.hpp"
#include "neurite/geometry/serialization/affine_transformation_injector_ser.hpp"

#endif
