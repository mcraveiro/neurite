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
#include <boost/throw_exception.hpp>
#include <vtkTransform.h>
#include <vtkSphereSource.h>
#include <vtkCylinderSource.h>
#include <vtkTransformPolyDataFilter.h>
#include "neurite/utility/log/logger.hpp"
#include "neurite/vtk.geometry/types/transformation_error.hpp"
#include "neurite/vtk.geometry/types/transformer.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("vtk.geometry.transformer"));

const std::string unsupported_transformation(
    "Transformation is not supported: ");

}

namespace neurite {
namespace vtk {
namespace geometry {

vtkSmartPointer<vtkPolyDataAlgorithm>
transformer::transform(const neurite::geometry::cylinder& c) {
    BOOST_LOG_SEV(lg, debug) << "Creating cylinder: " << c.id();

    auto cylinder(vtkSmartPointer<vtkCylinderSource>::New());
    cylinder->SetCenter(c.centre().x(), c.centre().y(), c.centre().z());
    cylinder->SetRadius(c.radius());
    cylinder->SetHeight(10.0);
    cylinder->SetResolution(100);

    if (!c.transformation())
        return cylinder;

    switch (c.transformation()->type()) {
    case neurite::geometry::transformation_types::translation: {
        auto transform(vtkSmartPointer<vtkTransform>::New());
        transform->Translate(c.transformation()->x(),
            c.transformation()->y(), c.transformation()->z());

        auto filter(vtkSmartPointer<vtkTransformPolyDataFilter>::New());
        filter->SetInputConnection(cylinder->GetOutputPort());
        filter->SetTransform(transform);
        filter->Update();
        return filter;
    } case neurite::geometry::transformation_types::rotation: {
          auto transform(vtkSmartPointer<vtkTransform>::New());
          const auto center(cylinder->GetCenter());
          transform->Translate(-center[0], -center[1], -center[2]);
          transform->PostMultiply();
          transform->RotateX(c.transformation()->x());
          transform->RotateY(c.transformation()->y());
          transform->RotateZ(c.transformation()->z());
          transform->Translate(+center[0], +center[1], +center[2]);

          auto filter(vtkSmartPointer<vtkTransformPolyDataFilter>::New());
          filter->SetInputConnection(cylinder->GetOutputPort());
          filter->SetTransform(transform);
          filter->Update();
          return filter;
      } default:
        BOOST_LOG_SEV(lg, error) << unsupported_transformation;
        BOOST_THROW_EXCEPTION(transformation_error(unsupported_transformation));
    }
}

vtkSmartPointer<vtkPolyDataAlgorithm>
transformer::transform(const neurite::geometry::sphere& s) {
    auto r(vtkSmartPointer<vtkSphereSource>::New());
    r->SetCenter(s.centre().x(), s.centre().y(), s.centre().z());
    r->SetRadius(s.radius());
    r->SetThetaResolution(20);
    r->SetPhiResolution(20);

    BOOST_LOG_SEV(lg, debug) << "Created sphere: " << s.id();
    return r;
}

} } }
