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
#include <boost/filesystem/fstream.hpp>
#include <vtkCylinderSource.h>
#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkQtTableView.h>
#include <vtkNamedColors.h>
#include <vtkCubeSource.h>
#include <vtkTransform.h>
#include <vtkRenderer.h>
#include <vtkProperty.h>
#include <QVTKWidget.h>
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/types/hydrator.hpp"
#include "neurite/swc/io/point_io.hpp"
#include "neurite/swc/io/file_io.hpp"
#include "swc_view_model.h"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("soma.swc_view_model"));

}

SwcViewModel::SwcViewModel(const std::string& path) : path_(path) { }

neurite::swc::file SwcViewModel::LoadSwcFile() const {
    boost::filesystem::path p(path_);
    neurite::swc::hydrator h;
    boost::filesystem::ifstream s(p);
    const auto r(h.hydrate(s));
    BOOST_LOG_SEV(lg, debug) << r;
    return r;
}

QWidget* SwcViewModel::Bind() const {
    const auto f(LoadSwcFile());
    const auto soma(neurite::swc::structure_identifier_types::soma);
    auto colors(vtkSmartPointer<vtkNamedColors>::New());
    auto renderer(vtkSmartPointer<vtkRenderer>::New());

    for (const auto& p : f.points()) {
        BOOST_LOG_SEV(lg, debug) << "Processing point: " << p;

        double rgba[4];
        const auto sn(p.sample_number());
        auto m(vtkSmartPointer<vtkPolyDataMapper>::New());
        if (p.parent_sample() == -1 && p.structure_identifier() == soma) {
            auto s(vtkSmartPointer<vtkSphereSource>::New());
            s->SetCenter(p.x(), p.y(), p.z());
            s->SetRadius(p.radius());
            s->SetThetaResolution(20);
            s->SetPhiResolution(20);
            BOOST_LOG_SEV(lg, debug) << "Created sphere: " << sn;

            colors->GetColor("Red", rgba);

            m->SetInputConnection(s->GetOutputPort());
            BOOST_LOG_SEV(lg, debug) << "Created mapper for point: " << sn;
        } else {
            auto s(vtkSmartPointer<vtkCylinderSource>::New());
            s->SetCenter(p.x(), p.y(), p.z());
            s->SetRadius(p.radius());
            s->SetHeight(10.0);
            s->SetResolution(100);
            BOOST_LOG_SEV(lg, debug) << "Created cylinder: " << sn;

            colors->GetColor("Blue", rgba);
            
            m->SetInputConnection(s->GetOutputPort());
            BOOST_LOG_SEV(lg, debug) << "Created mapper for point: " << sn;
        }

        auto a(vtkSmartPointer<vtkActor>::New());
        a->SetMapper(m);        
        a->GetProperty()->SetColor(rgba[0], rgba[1], rgba[2]);
        if (sn == 2) {
            auto t(vtkSmartPointer<vtkTransform>::New());
            // t->PostMultiply();
            t->Translate(0.0, -5.0, 0.0);
            a->SetUserTransform(t);
            BOOST_LOG_SEV(lg, debug) << "rotating: " << sn;
            // t->Translate(10.0, 0.0, 0.0);
            // a->RotateX(90.0);
            // a->RotateY(-90.0);
        }

        BOOST_LOG_SEV(lg, debug) << "Created actor for point: " << sn;
        
        renderer->AddActor(a);
        colors->GetColor("Gray", rgba);
        renderer->SetBackground(rgba[0], rgba[1], rgba[2]);
        BOOST_LOG_SEV(lg, debug) << "Added actor to renderer: " << sn;
    }

    QVTKWidget* r(new QVTKWidget);
    r->GetRenderWindow()->AddRenderer(renderer);
    r->update();
    return r;
}
