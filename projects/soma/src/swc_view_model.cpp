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
#include <vtkCubeSource.h>
#include <vtkRenderer.h>
#include <QVTKWidget.h>
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/types/hydrator.hpp"
#include "neurite/swc/io/point_io.hpp"
#include "neurite/swc/io/file_io.hpp"
#include "swc_view_model.h"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("swc_view_model"));

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
    // const auto soma(neurite::swc::structure_identifier_types::soma);

    std::vector<vtkSmartPointer<vtkCylinderSource>> sources;
    sources.reserve(f.points().size());
    for (const auto& p : f.points()) {
        // if (p.parent_sample() == -1 &&
        //     p.structure_identifier() == soma) {
        //     auto sphereSource(vtkSmartPointer<vtkSphereSource>::New());
        //     sphereSource->Update();
        // }
        
        auto s(vtkSmartPointer<vtkCylinderSource>::New());
        s->SetCenter(p.x(), p.y(), p.z());
        s->SetRadius(p.radius());
        s->SetHeight(1.0);
        s->SetResolution(100);
        sources.push_back(s);
        BOOST_LOG_SEV(lg, debug) << "Created point: " << p;
    }

    std::vector<vtkSmartPointer<vtkPolyDataMapper>> mappers;
    mappers.reserve(f.points().size());
    for (unsigned long i(0); i < f.points().size(); ++i) {
        auto m(vtkSmartPointer<vtkPolyDataMapper>::New());
        m->SetInputConnection(sources[i]->GetOutputPort());
        BOOST_LOG_SEV(lg, debug) << "Created mapper: " << i;
        mappers.push_back(m);
    }
    
    std::vector<vtkSmartPointer<vtkActor>> actors;
    actors.reserve(f.points().size());
    for (unsigned long i(0); i < f.points().size(); ++i) {
        auto a(vtkSmartPointer<vtkActor>::New());
        a->SetMapper(mappers[i]);
        actors.push_back(a);
        BOOST_LOG_SEV(lg, debug) << "Created actor: " << i;
    }

    auto renderer(vtkSmartPointer<vtkRenderer>::New());
    for (unsigned long i(0); i < f.points().size(); ++i) {
        renderer->AddActor(actors[i]);
        BOOST_LOG_SEV(lg, debug) << "Added actor to renderer: " << i;
    }

    QVTKWidget* r(new QVTKWidget);
    r->GetRenderWindow()->AddRenderer(renderer);
    return r;
}
