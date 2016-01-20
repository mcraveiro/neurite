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
#include "neurite/geometry/types/transformation.hpp"

namespace neurite {
namespace geometry {

transformation::transformation()
    : x_(static_cast<double>(0)),
      y_(static_cast<double>(0)),
      z_(static_cast<double>(0)),
      type_(static_cast<neurite::geometry::transformation_types>(0)) { }

transformation::transformation(
    const double x,
    const double y,
    const double z,
    const neurite::geometry::transformation_types type)
    : x_(x),
      y_(y),
      z_(z),
      type_(type) { }

void transformation::swap(transformation& other) noexcept {
    using std::swap;
    swap(x_, other.x_);
    swap(y_, other.y_);
    swap(z_, other.z_);
    swap(type_, other.type_);
}

bool transformation::operator==(const transformation& rhs) const {
    return x_ == rhs.x_ &&
        y_ == rhs.y_ &&
        z_ == rhs.z_ &&
        type_ == rhs.type_;
}

transformation& transformation::operator=(transformation other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

double transformation::x() const {
    return x_;
}

void transformation::x(const double v) {
    x_ = v;
}

double transformation::y() const {
    return y_;
}

void transformation::y(const double v) {
    y_ = v;
}

double transformation::z() const {
    return z_;
}

void transformation::z(const double v) {
    z_ = v;
}

neurite::geometry::transformation_types transformation::type() const {
    return type_;
}

void transformation::type(const neurite::geometry::transformation_types v) {
    type_ = v;
}

} }
