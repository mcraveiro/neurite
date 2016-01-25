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
#include "neurite/geometry/io/object_io.hpp"
#include "neurite/geometry/types/cylinder.hpp"

namespace neurite {
namespace geometry {

cylinder::cylinder()
    : radius_(static_cast<double>(0)),
      height_(static_cast<double>(0)) { }

cylinder::cylinder(
    const int id,
    const int parent_id,
    const neurite::geometry::point& centre,
    const std::string& colour,
    const std::list<neurite::geometry::transformation>& transformations,
    const double radius,
    const double height)
    : neurite::geometry::object(
      id,
      parent_id,
      centre,
      colour,
      transformations),
      radius_(radius),
      height_(height) { }

void cylinder::to_stream(std::ostream& s) const {
    boost::io::ios_flags_saver ifs(s);
    s.setf(std::ios_base::boolalpha);
    s.setf(std::ios::fixed, std::ios::floatfield);
    s.precision(6);
    s.setf(std::ios::showpoint);

    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::cylinder\"" << ", "
      << "\"__parent_0__\": ";
    object::to_stream(s);
    s << ", "
      << "\"radius\": " << radius_ << ", "
      << "\"height\": " << height_
      << " }";
}

void cylinder::swap(cylinder& other) noexcept {
    object::swap(other);

    using std::swap;
    swap(radius_, other.radius_);
    swap(height_, other.height_);
}

bool cylinder::equals(const neurite::geometry::object& other) const {
    const cylinder* const p(dynamic_cast<const cylinder* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool cylinder::operator==(const cylinder& rhs) const {
    return object::compare(rhs) &&
        radius_ == rhs.radius_ &&
        height_ == rhs.height_;
}

cylinder& cylinder::operator=(cylinder other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

double cylinder::radius() const {
    return radius_;
}

void cylinder::radius(const double v) {
    radius_ = v;
}

double cylinder::height() const {
    return height_;
}

void cylinder::height(const double v) {
    height_ = v;
}

} }
