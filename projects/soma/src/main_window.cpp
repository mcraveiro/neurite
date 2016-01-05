/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2015 Marco Craveiro <marco.craveiro@gmail.com>
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
#include <QVTKWidget.h>
#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkSmartPointer.h>
#include "main_window.hpp"

main_window::main_window() {
    // this->setupUi(this);

    // Sphere
    vtkSmartPointer<vtkSphereSource> sphereSource =
        vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->Update();
    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
    vtkSmartPointer<vtkActor> sphereActor =
        vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);

    // Cube
    vtkSmartPointer<vtkCubeSource> cubeSource =
        vtkSmartPointer<vtkCubeSource>::New();
    cubeSource->Update();
    vtkSmartPointer<vtkPolyDataMapper> cubeMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    cubeMapper->SetInputConnection(cubeSource->GetOutputPort());
    vtkSmartPointer<vtkActor> cubeActor =
        vtkSmartPointer<vtkActor>::New();
    cubeActor->SetMapper(cubeMapper);

    // VTK Renderer
    vtkSmartPointer<vtkRenderer> leftRenderer =
        vtkSmartPointer<vtkRenderer>::New();
    leftRenderer->AddActor(sphereActor);

    vtkSmartPointer<vtkRenderer> rightRenderer =
        vtkSmartPointer<vtkRenderer>::New();

    // Add Actor to renderer
    rightRenderer->AddActor(cubeActor);

    QVTKWidget *widget = new QVTKWidget;
    this->setCentralWidget(widget);
    widget->GetRenderWindow()->AddRenderer(leftRenderer);

    // VTK/Qt wedded
    // this->qvtkWidgetLeft->GetRenderWindow()->AddRenderer(leftRenderer);
    // this->qvtkWidgetRight->GetRenderWindow()->AddRenderer(rightRenderer);

    // Set up action signals and slots
    // connect(this->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

void main_window::slotExit() {
    // qApp->exit();
}
