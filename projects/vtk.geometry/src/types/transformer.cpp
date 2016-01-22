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
#include "neurite/utility/log/logger.hpp"
#include "neurite/vtk.geometry/types/transformer.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("vtk.geometry.transformer"));

}

namespace neurite {
namespace vtk {
namespace geometry {

vtkSmartPointer<vtkCylinderSource> transformer::transform(const neurite::geometry::cylinder& c) {
    auto r(vtkSmartPointer<vtkCylinderSource>::New());
    r->SetCenter(c.centre().x(), c.centre().y(), c.centre().z());
    r->SetRadius(c.radius());
    r->SetHeight(10.0);
    r->SetResolution(100);

    BOOST_LOG_SEV(lg, debug) << "Created cylinder: " << c.id();
    return r;
}

vtkSmartPointer<vtkSphereSource> transformer::transform(const neurite::geometry::sphere& s) {
    auto r(vtkSmartPointer<vtkSphereSource>::New());
    r->SetCenter(s.centre().x(), s.centre().y(), s.centre().z());
    r->SetRadius(s.radius());
    r->SetThetaResolution(20);
    r->SetPhiResolution(20);

    BOOST_LOG_SEV(lg, debug) << "Created sphere: " << s.id();
    return r;
}

} } }
