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
#include "neurite/swc/types/point.hpp"

namespace neurite {
namespace swc {

point::point()
    : x_(static_cast<double>(0)),
      y_(static_cast<double>(0)),
      z_(static_cast<double>(0)),
      radius_(static_cast<double>(0)) { }

point::point(
    const double x,
    const double y,
    const double z,
    const double radius)
    : x_(x),
      y_(y),
      z_(z),
      radius_(radius) { }

void point::swap(point& other) noexcept {
    using std::swap;
    swap(x_, other.x_);
    swap(y_, other.y_);
    swap(z_, other.z_);
    swap(radius_, other.radius_);
}

bool point::operator==(const point& rhs) const {
    return x_ == rhs.x_ &&
        y_ == rhs.y_ &&
        z_ == rhs.z_ &&
        radius_ == rhs.radius_;
}

point& point::operator=(point other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

double point::x() const {
    return x_;
}

void point::x(const double v) {
    x_ = v;
}

double point::y() const {
    return y_;
}

void point::y(const double v) {
    y_ = v;
}

double point::z() const {
    return z_;
}

void point::z(const double v) {
    z_ = v;
}

double point::radius() const {
    return radius_;
}

void point::radius(const double v) {
    radius_ = v;
}

} }
