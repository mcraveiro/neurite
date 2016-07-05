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
#include "neurite/geometry/types/vector3d.hpp"

namespace neurite {
namespace geometry {

vector3d::vector3d()
    : x_(static_cast<double>(0)),
      y_(static_cast<double>(0)),
      z_(static_cast<double>(0)) { }

vector3d::vector3d(
    const double x,
    const double y,
    const double z)
    : x_(x),
      y_(y),
      z_(z) { }

void vector3d::swap(vector3d& other) noexcept {
    using std::swap;
    swap(x_, other.x_);
    swap(y_, other.y_);
    swap(z_, other.z_);
}

bool vector3d::operator==(const vector3d& rhs) const {
    return x_ == rhs.x_ &&
        y_ == rhs.y_ &&
        z_ == rhs.z_;
}

vector3d& vector3d::operator=(vector3d other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

double vector3d::x() const {
    return x_;
}

void vector3d::x(const double v) {
    x_ = v;
}

double vector3d::y() const {
    return y_;
}

void vector3d::y(const double v) {
    y_ = v;
}

double vector3d::z() const {
    return z_;
}

void vector3d::z(const double v) {
    z_ = v;
}

} }
