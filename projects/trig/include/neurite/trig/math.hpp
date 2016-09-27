/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
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
#ifndef NEURITE_TRIG_MATH_HPP
#define NEURITE_TRIG_MATH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

namespace neurite {
namespace trig {

/**
 * Pi is the ratio of the circumference to the diameter of a circle.
 */
extern double pi;

/**
 * A degree is obtained by dividing a circle in 360 parts. One degree
 * is 1/360th of the circle, 360 degrees is a full circle, 180 degrees
 * is half a circle, 90 degrees is a quarter of a circle and so forth.
 *
 * A radian is a measure based on the radius of the circle: 1 radian
 * is obtained by travelling up the circle (counterclockwise) the
 * lenght of the radius. Given that pi is the ratio of the
 * circumference to the diameter, we need to travel pi * r to get to
 * half a circle. So half a circle has pi radians and a full circle
 * has 2 pi radians (e.g. the circumference).
 *
 * To convert between degrees and radians we can take the equality of
 * 2 pi equals 360 and pi equals 180. If we divide pi by 180, we get
 * one degree. Thus to go from degrees to radians we need to multiply
 * by 180 / pi. To go from radians to degrees we need to multiply by
 * pi / 180.
 */
double radians_to_degrees(double radians);
double degrees_to_radians(double degrees);

/**
 * Given any angle in radians greater than 2 * pi, wraps it to an
 * angle smaller than 2 * pi. There are lots of edge cases to take
 * into account as per:
 *
 * http://stackoverflow.com/questions/4633177/c-how-to-wrap-a-float-to-the-interval-pi-pi
 */
double wrap_radians(double r);


} }

#endif
