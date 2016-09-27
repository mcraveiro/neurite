/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2016 Marco Craveiro <marco.craveiro@gmail.com>
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
#include <cmath>
#include <iostream>
#include "neurite/utility/log/logger.hpp"
#include "neurite/utility/log/life_cycle_manager.hpp"
#include "neurite/trig/math.hpp"
#include "png++/png.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("trig"));

const std::string log_file_prefix("log/neurite.trig.");

}

void initialise_logging(const std::string& name, const bool verbose) {
    const auto sev(verbose ? severity_level::debug : severity_level::info);
    const auto log_file_name = log_file_prefix + name + ".log";
    life_cycle_manager lcm;
    lcm.initialise(log_file_name, sev);
}

int main(const int /*argc*/, const char* /*argv*/[]) {
    using namespace neurite::trig;
    initialise_logging("test", true);
    BOOST_LOG_SEV(lg, debug) << "pi radians in degrees: "
                             << radians_to_degrees(pi);
    BOOST_LOG_SEV(lg, debug) << "1/2 * pi radians in degrees: "
                             << radians_to_degrees(1.0f/2.0f * pi);

    BOOST_LOG_SEV(lg, debug) << "180 degrees in radians: "
                             << degrees_to_radians(180);
    BOOST_LOG_SEV(lg, debug) << "90 degrees in radians: "
                             << degrees_to_radians(90);

    BOOST_LOG_SEV(lg, debug) << "wrap_radians(2 * pi): "
                             << wrap_radians(2 * pi);
    BOOST_LOG_SEV(lg, debug) << "wrap_radians(4 * pi): "
                             << wrap_radians(4 * pi);
    BOOST_LOG_SEV(lg, debug) << "wrap_radians(6 * pi): "
                             << wrap_radians(6 * pi);


    const int dim_x = 400, dim_y = 400;
    std::array<std::array<int, dim_x>, dim_y> matrix;
    for (int i = 0; i < 400; ++i) {
        for (int j = 0; j < 400; ++j) {
            matrix[i][j] = 0;
        }
    }

    int skip = 1;
    const int max_r = 130;
    const int colour_jump = std::ceil(255.0 / double(max_r)) * skip;
    int colour = 255;
    for (int r = 1; r < max_r; r += skip) {
        int radius = r;
        double inc = 0.0;
        int circum = 2 * M_PI * radius;
        BOOST_LOG_SEV(lg, debug) << "circum: " << circum;
        int count = 2 * circum;
        double total = M_PI * 2 / count;
        for (int i = 0; i < count; ++i) {
            BOOST_LOG_SEV(lg, debug) << "i/M_PI: " << i/M_PI;
            BOOST_LOG_SEV(lg, debug) << "inc: " << inc;
            BOOST_LOG_SEV(lg, debug) << "cos: " << std::cos(inc) * radius
                                     << " sin: " << std::sin(inc) * radius;

            // BOOST_LOG_SEV(lg, debug) << "cos: " << std::cos(i/M_PI) * 100
            //                          << " sin: " << std::sin(i/M_PI) * 100;
            int x = std::cos(inc) * radius + 150;
            int y = std::sin(inc) * radius + 150;
            matrix[x][dim_y - y] = colour;
            inc += total;
        }
        int x = std::cos(inc) * 100 + 300;
        int y = std::sin(inc) * 100 + 300;
        matrix[x][dim_y - y] = colour;
        if (colour > colour_jump) colour -= colour_jump;
        BOOST_LOG_SEV(lg, debug) << "colour: " << colour
                                 << " colour_jump: " << colour_jump;
    }
    BOOST_LOG_SEV(lg, debug) << "colour: " << colour
                             << " colour_jump: " << colour_jump;
/*
    int scalar_trans= 100;
    int scalar_scale= 2;
    for (int i = 1; i < 100; ++i) {
        double scalar = i / 100.0;
        double a_scaled = 50 * scalar;
        double b_scaled = 50 * scalar;
        int a_scaled_int = int(a_scaled);
        int b_scaled_int = int(b_scaled);
        matrix[(a_scaled_int + scalar_trans) * scalar_scale][(b_scaled_int + scalar_trans) * scalar_scale] = 0;
    }
*/
    // matrix[50][50] = true;
    // matrix[10][10] = true;
    png::image<png::rgb_pixel> img(400, 400);
    for (int i = 0; i < 400; ++i) {
        for (int j = 0; j < 400; ++j) {
            int g = matrix[i][j];
            png::rgb_pixel pixel(0, g, 0);
            img.set_pixel(i, j, pixel);
        }
    }
/*    
    png::image<png::rgb_pixel> img(400, 400);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 255; j++) {
            if (i < 10) {
                png::rgb_pixel pixel(j, 0, 0);
                img.set_pixel(j, i, pixel);
            } else if (i < 20) {
                png::rgb_pixel pixel(0, j, 0);
                img.set_pixel(j, i, pixel);
            } else {
                png::rgb_pixel pixel(0, 0, j);
                img.set_pixel(j, i, pixel);
            }
        }
    }
*/
    //Write png to file
    img.write("image.png");
    return 0;
}
