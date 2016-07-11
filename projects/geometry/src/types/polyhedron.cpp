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
#include "neurite/geometry/types/polyhedron.hpp"

namespace neurite {
namespace geometry {

polyhedron::polyhedron(const std::vector<neurite::geometry::polygon>& polygons)
    : polygons_(polygons) { }

void polyhedron::swap(polyhedron& other) noexcept {
    using std::swap;
    swap(polygons_, other.polygons_);
}

bool polyhedron::operator==(const polyhedron& rhs) const {
    return polygons_ == rhs.polygons_;
}

polyhedron& polyhedron::operator=(polyhedron other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::vector<neurite::geometry::polygon>& polyhedron::polygons() const {
    return polygons_;
}

std::vector<neurite::geometry::polygon>& polyhedron::polygons() {
    return polygons_;
}

void polyhedron::polygons(const std::vector<neurite::geometry::polygon>& v) {
    polygons_ = v;
}

void polyhedron::polygons(const std::vector<neurite::geometry::polygon>&& v) {
    polygons_ = std::move(v);
}

} }