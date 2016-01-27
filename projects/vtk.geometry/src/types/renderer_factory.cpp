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
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkNamedColors.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include "neurite/utility/log/logger.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/cylinder.hpp"
#include "neurite/geometry/types/object_visitor.hpp"
#include "neurite/vtk.geometry/types/transformer.hpp"
#include "neurite/vtk.geometry/types/renderer_factory.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("vtk.geometry.renderer_factory"));

}

namespace neurite {
namespace vtk {
namespace geometry {

class actor_factory final : public neurite::geometry::object_visitor {
 public:
    explicit actor_factory(vtkNamedColors& palette) : palette_(palette) { }
private:
    void setup_actor(const neurite::geometry::object& o,
        vtkSmartPointer<vtkPolyDataAlgorithm> a);

public:
    using neurite::geometry::object_visitor::visit;
    virtual void visit(const neurite::geometry::cylinder& c) override;
    virtual void visit(const neurite::geometry::sphere& s) override;

public:
    vtkSmartPointer<vtkActor> make(const neurite::geometry::object& o);

private:
    vtkNamedColors& palette_;
    vtkSmartPointer<vtkActor> actor_;
};

void actor_factory::setup_actor(const neurite::geometry::object& o,
    vtkSmartPointer<vtkPolyDataAlgorithm> a) {

    auto m(vtkSmartPointer<vtkPolyDataMapper>::New());
    m->SetInputConnection(a->GetOutputPort());
    BOOST_LOG_SEV(lg, debug) << "Created mapper for object: " << o.id();

    double rgba[4];
    palette_.GetColor(o.colour(), rgba);
    actor_->GetProperty()->SetColor(rgba[0], rgba[1], rgba[2]);
    actor_->SetMapper(m);
    BOOST_LOG_SEV(lg, debug) << "Setup actor for object: " << o.id();
}

void actor_factory::visit(const neurite::geometry::cylinder& c) {
    transformer t;
    setup_actor(c, t.transform(c));
}

void actor_factory::visit(const neurite::geometry::sphere& s) {
    transformer t;
    setup_actor(s, t.transform(s));
}

vtkSmartPointer<vtkActor>
actor_factory::make(const neurite::geometry::object& o) {
    actor_ = vtkSmartPointer<vtkActor>::New();
    o.accept(*this);
    return actor_;
}

vtkSmartPointer<vtkRenderer>
renderer_factory::make(const neurite::geometry::space& s) const {
    auto r(vtkSmartPointer<vtkRenderer>::New());
    BOOST_LOG_SEV(lg, debug) << "Setting renderer background colour: "
                             << s.colour();

    auto palette(vtkSmartPointer<vtkNamedColors>::New());
    double rgba[4];
    palette->GetColor(s.colour(), rgba);
    r->GradientBackgroundOn();
    r->SetBackground(rgba[0], rgba[1], rgba[2]);
    r->SetBackground2(0, 0, 0);

    actor_factory f(*palette);
    for (const auto& o : s.objects())
        r->AddActor(f.make(*o));

    return r;
}

} } }
