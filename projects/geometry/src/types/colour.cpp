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
#include "neurite/geometry/types/colour.hpp"

namespace neurite {
namespace geometry {

colour::colour()
    : red_(static_cast<int>(0)),
      green_(static_cast<int>(0)),
      blue_(static_cast<int>(0)) { }

colour::colour(
    const int red,
    const int green,
    const int blue)
    : red_(red),
      green_(green),
      blue_(blue) { }

void colour::swap(colour& other) noexcept {
    using std::swap;
    swap(red_, other.red_);
    swap(green_, other.green_);
    swap(blue_, other.blue_);
}

bool colour::operator==(const colour& rhs) const {
    return red_ == rhs.red_ &&
        green_ == rhs.green_ &&
        blue_ == rhs.blue_;
}

colour& colour::operator=(colour other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int colour::red() const {
    return red_;
}

void colour::red(const int v) {
    red_ = v;
}

int colour::green() const {
    return green_;
}

void colour::green(const int v) {
    green_ = v;
}

int colour::blue() const {
    return blue_;
}

void colour::blue(const int v) {
    blue_ = v;
}

} }
