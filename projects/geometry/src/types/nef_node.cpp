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
#include "neurite/geometry/types/nef_node.hpp"
#include "neurite/geometry/io/abstract_node_io.hpp"
#include "neurite/geometry/io/nef_polyhedron_io.hpp"

namespace neurite {
namespace geometry {

nef_node::nef_node(const neurite::geometry::nef_polyhedron& polyhedron)
    : neurite::geometry::abstract_node(),
      polyhedron_(polyhedron) { }

void nef_node::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::nef_node\"" << ", "
      << "\"__parent_0__\": ";
    abstract_node::to_stream(s);
    s << ", "
      << "\"polyhedron\": " << polyhedron_
      << " }";
}

void nef_node::swap(nef_node& other) noexcept {
    abstract_node::swap(other);

    using std::swap;
    swap(polyhedron_, other.polyhedron_);
}

bool nef_node::equals(const neurite::geometry::abstract_node& other) const {
    const nef_node* const p(dynamic_cast<const nef_node* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool nef_node::operator==(const nef_node& rhs) const {
    return abstract_node::compare(rhs) &&
        polyhedron_ == rhs.polyhedron_;
}

nef_node& nef_node::operator=(nef_node other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::geometry::nef_polyhedron& nef_node::polyhedron() const {
    return polyhedron_;
}

neurite::geometry::nef_polyhedron& nef_node::polyhedron() {
    return polyhedron_;
}

void nef_node::polyhedron(const neurite::geometry::nef_polyhedron& v) {
    polyhedron_ = v;
}

void nef_node::polyhedron(const neurite::geometry::nef_polyhedron&& v) {
    polyhedron_ = std::move(v);
}

} }
