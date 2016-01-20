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

#include "neurite/geometry/serialization/plane_ser.hpp"
#include "neurite/geometry/serialization/point_ser.hpp"
#include "neurite/geometry/serialization/colour_ser.hpp"
#include "neurite/geometry/serialization/object_ser.hpp"
#include "neurite/geometry/serialization/sphere_ser.hpp"
#include "neurite/geometry/serialization/cylinder_ser.hpp"
#include "neurite/geometry/serialization/registrar_ser.hpp"
#include "neurite/geometry/serialization/transformation_ser.hpp"
#include "neurite/geometry/serialization/transformation_types_ser.hpp"

#endif