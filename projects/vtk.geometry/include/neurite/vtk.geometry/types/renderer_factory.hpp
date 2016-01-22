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
#ifndef NEURITE_VTK_GEOMETRY_TYPES_RENDERER_FACTORY_HPP
#define NEURITE_VTK_GEOMETRY_TYPES_RENDERER_FACTORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include "neurite/geometry/types/plane.hpp"

namespace neurite {
namespace vtk {
namespace geometry {

class renderer_factory {
public:
    vtkSmartPointer<vtkRenderer> make(const neurite::geometry::plane& p) const;
};

} } }

#endif
