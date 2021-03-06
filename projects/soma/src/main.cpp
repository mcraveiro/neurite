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
#include "mainwindow.h"
#include <QApplication>
#include "neurite/utility/log/life_cycle_manager.hpp"
#include "neurite/utility/log/logger.hpp"

namespace {

const std::string log_file_name("log/neurite_soma.log");

}

void initialise_logging_activity() {
  using namespace neurite::utility::log;
  life_cycle_manager lcm;
  lcm.initialise(log_file_name, severity_level::debug);
}


int main(int argc, char *argv[])
{
    initialise_logging_activity();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
