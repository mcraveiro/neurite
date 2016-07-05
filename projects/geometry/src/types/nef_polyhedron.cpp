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
#include "neurite/geometry/types/nef_polyhedron.hpp"

namespace neurite {
namespace geometry {

nef_polyhedron::nef_polyhedron(const std::string& polygons)
    : polygons_(polygons) { }

void nef_polyhedron::swap(nef_polyhedron& other) noexcept {
    using std::swap;
    swap(polygons_, other.polygons_);
}

bool nef_polyhedron::operator==(const nef_polyhedron& rhs) const {
    return polygons_ == rhs.polygons_;
}

nef_polyhedron& nef_polyhedron::operator=(nef_polyhedron other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::string& nef_polyhedron::polygons() const {
    return polygons_;
}

std::string& nef_polyhedron::polygons() {
    return polygons_;
}

void nef_polyhedron::polygons(const std::string& v) {
    polygons_ = v;
}

void nef_polyhedron::polygons(const std::string&& v) {
    polygons_ = std::move(v);
}

} }
