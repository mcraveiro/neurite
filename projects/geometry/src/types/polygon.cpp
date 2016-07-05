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
#include "neurite/geometry/types/polygon.hpp"

namespace neurite {
namespace geometry {

polygon::polygon(const std::vector<neurite::geometry::vector3d>& vertices)
    : vertices_(vertices) { }

void polygon::swap(polygon& other) noexcept {
    using std::swap;
    swap(vertices_, other.vertices_);
}

bool polygon::operator==(const polygon& rhs) const {
    return vertices_ == rhs.vertices_;
}

polygon& polygon::operator=(polygon other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::vector<neurite::geometry::vector3d>& polygon::vertices() const {
    return vertices_;
}

std::vector<neurite::geometry::vector3d>& polygon::vertices() {
    return vertices_;
}

void polygon::vertices(const std::vector<neurite::geometry::vector3d>& v) {
    vertices_ = v;
}

void polygon::vertices(const std::vector<neurite::geometry::vector3d>&& v) {
    vertices_ = std::move(v);
}

} }
