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
#include "neurite/geometry/types/solid.hpp"

namespace neurite {
namespace geometry {

solid::solid()
    : first_radius_(static_cast<double>(0)),
      second_radius_(static_cast<double>(0)),
      height_(static_cast<double>(0)),
      type_(static_cast<neurite::geometry::solid_types>(0)) { }

solid::solid(
    const neurite::geometry::vector3d& centre,
    const double first_radius,
    const double second_radius,
    const double height,
    const neurite::geometry::solid_types type)
    : centre_(centre),
      first_radius_(first_radius),
      second_radius_(second_radius),
      height_(height),
      type_(type) { }

void solid::swap(solid& other) noexcept {
    using std::swap;
    swap(centre_, other.centre_);
    swap(first_radius_, other.first_radius_);
    swap(second_radius_, other.second_radius_);
    swap(height_, other.height_);
    swap(type_, other.type_);
}

bool solid::operator==(const solid& rhs) const {
    return centre_ == rhs.centre_ &&
        first_radius_ == rhs.first_radius_ &&
        second_radius_ == rhs.second_radius_ &&
        height_ == rhs.height_ &&
        type_ == rhs.type_;
}

solid& solid::operator=(solid other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::geometry::vector3d& solid::centre() const {
    return centre_;
}

neurite::geometry::vector3d& solid::centre() {
    return centre_;
}

void solid::centre(const neurite::geometry::vector3d& v) {
    centre_ = v;
}

void solid::centre(const neurite::geometry::vector3d&& v) {
    centre_ = std::move(v);
}

double solid::first_radius() const {
    return first_radius_;
}

void solid::first_radius(const double v) {
    first_radius_ = v;
}

double solid::second_radius() const {
    return second_radius_;
}

void solid::second_radius(const double v) {
    second_radius_ = v;
}

double solid::height() const {
    return height_;
}

void solid::height(const double v) {
    height_ = v;
}

neurite::geometry::solid_types solid::type() const {
    return type_;
}

void solid::type(const neurite::geometry::solid_types v) {
    type_ = v;
}

} }
