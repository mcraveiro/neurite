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
#include "neurite/geometry/io/polyhedron_io.hpp"
#include "neurite/geometry/io/abstract_node_io.hpp"
#include "neurite/geometry/types/polyhedron_node.hpp"

namespace neurite {
namespace geometry {

polyhedron_node::polyhedron_node(const neurite::geometry::polyhedron& polyhedron)
    : neurite::geometry::abstract_node(),
      polyhedron_(polyhedron) { }

void polyhedron_node::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::polyhedron_node\"" << ", "
      << "\"__parent_0__\": ";
    abstract_node::to_stream(s);
    s << ", "
      << "\"polyhedron\": " << polyhedron_
      << " }";
}

void polyhedron_node::swap(polyhedron_node& other) noexcept {
    abstract_node::swap(other);

    using std::swap;
    swap(polyhedron_, other.polyhedron_);
}

bool polyhedron_node::equals(const neurite::geometry::abstract_node& other) const {
    const polyhedron_node* const p(dynamic_cast<const polyhedron_node* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool polyhedron_node::operator==(const polyhedron_node& rhs) const {
    return abstract_node::compare(rhs) &&
        polyhedron_ == rhs.polyhedron_;
}

polyhedron_node& polyhedron_node::operator=(polyhedron_node other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::geometry::polyhedron& polyhedron_node::polyhedron() const {
    return polyhedron_;
}

neurite::geometry::polyhedron& polyhedron_node::polyhedron() {
    return polyhedron_;
}

void polyhedron_node::polyhedron(const neurite::geometry::polyhedron& v) {
    polyhedron_ = v;
}

void polyhedron_node::polyhedron(const neurite::geometry::polyhedron&& v) {
    polyhedron_ = std::move(v);
}

} }
