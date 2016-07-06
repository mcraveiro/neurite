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
#include <ostream>
#include <boost/io/ios_state.hpp>
#include "neurite/geometry/io/solid_io.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/io/vector3d_io.hpp"

namespace neurite {
namespace geometry {

sphere::sphere()
    : radius_(static_cast<double>(0)) { }

sphere::sphere(
    const neurite::geometry::vector3d& centre,
    const double radius)
    : neurite::geometry::solid(),
      centre_(centre),
      radius_(radius) { }

void sphere::to_stream(std::ostream& s) const {
    boost::io::ios_flags_saver ifs(s);
    s.setf(std::ios_base::boolalpha);
    s.setf(std::ios::fixed, std::ios::floatfield);
    s.precision(6);
    s.setf(std::ios::showpoint);

    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::sphere\"" << ", "
      << "\"__parent_0__\": ";
    solid::to_stream(s);
    s << ", "
      << "\"centre\": " << centre_ << ", "
      << "\"radius\": " << radius_
      << " }";
}

void sphere::swap(sphere& other) noexcept {
    solid::swap(other);

    using std::swap;
    swap(centre_, other.centre_);
    swap(radius_, other.radius_);
}

bool sphere::equals(const neurite::geometry::solid& other) const {
    const sphere* const p(dynamic_cast<const sphere* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool sphere::operator==(const sphere& rhs) const {
    return solid::compare(rhs) &&
        centre_ == rhs.centre_ &&
        radius_ == rhs.radius_;
}

sphere& sphere::operator=(sphere other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::geometry::vector3d& sphere::centre() const {
    return centre_;
}

neurite::geometry::vector3d& sphere::centre() {
    return centre_;
}

void sphere::centre(const neurite::geometry::vector3d& v) {
    centre_ = v;
}

void sphere::centre(const neurite::geometry::vector3d&& v) {
    centre_ = std::move(v);
}

double sphere::radius() const {
    return radius_;
}

void sphere::radius(const double v) {
    radius_ = v;
}

} }
