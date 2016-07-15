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
#include "neurite/geometry/io/vector3d_io.hpp"
#include "neurite/geometry/types/truncated_cone.hpp"

namespace neurite {
namespace geometry {

truncated_cone::truncated_cone()
    : first_radius_(static_cast<double>(0)),
      second_radius_(static_cast<double>(0)),
      height_(static_cast<double>(0)) { }

truncated_cone::truncated_cone(
    const neurite::geometry::vector3d& first,
    const double first_radius,
    const double second_radius,
    const neurite::geometry::vector3d& second,
    const double height)
    : neurite::geometry::solid(),
      first_(first),
      first_radius_(first_radius),
      second_radius_(second_radius),
      second_(second),
      height_(height) { }

void truncated_cone::to_stream(std::ostream& s) const {
    boost::io::ios_flags_saver ifs(s);
    s.setf(std::ios_base::boolalpha);
    s.setf(std::ios::fixed, std::ios::floatfield);
    s.precision(6);
    s.setf(std::ios::showpoint);

    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::truncated_cone\"" << ", "
      << "\"__parent_0__\": ";
    solid::to_stream(s);
    s << ", "
      << "\"first\": " << first_ << ", "
      << "\"first_radius\": " << first_radius_ << ", "
      << "\"second_radius\": " << second_radius_ << ", "
      << "\"second\": " << second_ << ", "
      << "\"height\": " << height_
      << " }";
}

void truncated_cone::swap(truncated_cone& other) noexcept {
    solid::swap(other);

    using std::swap;
    swap(first_, other.first_);
    swap(first_radius_, other.first_radius_);
    swap(second_radius_, other.second_radius_);
    swap(second_, other.second_);
    swap(height_, other.height_);
}

bool truncated_cone::equals(const neurite::geometry::solid& other) const {
    const truncated_cone* const p(dynamic_cast<const truncated_cone* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool truncated_cone::operator==(const truncated_cone& rhs) const {
    return solid::compare(rhs) &&
        first_ == rhs.first_ &&
        first_radius_ == rhs.first_radius_ &&
        second_radius_ == rhs.second_radius_ &&
        second_ == rhs.second_ &&
        height_ == rhs.height_;
}

truncated_cone& truncated_cone::operator=(truncated_cone other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::geometry::vector3d& truncated_cone::first() const {
    return first_;
}

neurite::geometry::vector3d& truncated_cone::first() {
    return first_;
}

void truncated_cone::first(const neurite::geometry::vector3d& v) {
    first_ = v;
}

void truncated_cone::first(const neurite::geometry::vector3d&& v) {
    first_ = std::move(v);
}

double truncated_cone::first_radius() const {
    return first_radius_;
}

void truncated_cone::first_radius(const double v) {
    first_radius_ = v;
}

double truncated_cone::second_radius() const {
    return second_radius_;
}

void truncated_cone::second_radius(const double v) {
    second_radius_ = v;
}

const neurite::geometry::vector3d& truncated_cone::second() const {
    return second_;
}

neurite::geometry::vector3d& truncated_cone::second() {
    return second_;
}

void truncated_cone::second(const neurite::geometry::vector3d& v) {
    second_ = v;
}

void truncated_cone::second(const neurite::geometry::vector3d&& v) {
    second_ = std::move(v);
}

double truncated_cone::height() const {
    return height_;
}

void truncated_cone::height(const double v) {
    height_ = v;
}

} }
