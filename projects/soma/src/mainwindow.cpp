/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2014 Marco Craveiro <marco.craveiro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include <boost/filesystem/fstream.hpp>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/types/hydrator.hpp"
#include "neurite/swc/io/point_io.hpp"
#include "neurite/swc/io/model_io.hpp"
#include "neurite/geometry.swc/types/workflow.hpp"
#include "neurite/vtk.geometry/types/widget_factory.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("soma.main_window"));

}

neurite::swc::model load_swc_model(const boost::filesystem::path p) {
    neurite::swc::hydrator h;
    boost::filesystem::ifstream s(p);
    const auto r(h.hydrate(s));
    BOOST_LOG_SEV(lg, debug) << r;
    return r;
}

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    BOOST_LOG_SEV(lg, debug) << "Started Soma.";

    const std::string p(
        "/home/marco/Development/phd/neurite/test_data/swc/ball_and_stick.swc");
    const auto m(load_swc_model(p));
    
    neurite::geometry::swc::workflow w;
    const auto plane(w.execute(m));
    
    neurite::vtk::geometry::widget_factory f;
    auto widget(f.make(plane));

    this->setCentralWidget(widget);
    this->repaint();
}

MainWindow::~MainWindow() {
    BOOST_LOG_SEV(lg, debug) << "Finished Soma";
    delete ui;
}
