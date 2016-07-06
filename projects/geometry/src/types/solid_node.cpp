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
#include "neurite/geometry/io/solid_io.hpp"
#include "neurite/geometry/types/solid.hpp"
#include "neurite/geometry/types/solid_node.hpp"
#include "neurite/geometry/io/abstract_node_io.hpp"

namespace boost {

inline std::ostream& operator<<(std::ostream& s, const boost::shared_ptr<neurite::geometry::solid>& v) {
    s << "{ " << "\"__type__\": " << "\"boost::shared_ptr\"" << ", "
      << "\"memory\": " << "\"" << static_cast<void*>(v.get()) << "\"" << ", ";

    if (v)
        s << "\"data\": " << *v;
    else
        s << "\"data\": ""\"<empty>\"";
    s << " }";
    return s;
}

}

namespace boost {

inline bool operator==(const boost::shared_ptr<neurite::geometry::solid>& lhs,
const boost::shared_ptr<neurite::geometry::solid>& rhs) {
    return (!lhs && !rhs) ||(lhs && rhs && (*lhs == *rhs));
}

}

namespace neurite {
namespace geometry {

solid_node::solid_node(const boost::shared_ptr<neurite::geometry::solid>& solid)
    : neurite::geometry::abstract_node(),
      solid_(solid) { }

void solid_node::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::solid_node\"" << ", "
      << "\"__parent_0__\": ";
    abstract_node::to_stream(s);
    s << ", "
      << "\"solid\": " << solid_
      << " }";
}

void solid_node::swap(solid_node& other) noexcept {
    abstract_node::swap(other);

    using std::swap;
    swap(solid_, other.solid_);
}

bool solid_node::equals(const neurite::geometry::abstract_node& other) const {
    const solid_node* const p(dynamic_cast<const solid_node* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool solid_node::operator==(const solid_node& rhs) const {
    return abstract_node::compare(rhs) &&
        solid_ == rhs.solid_;
}

solid_node& solid_node::operator=(solid_node other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const boost::shared_ptr<neurite::geometry::solid>& solid_node::solid() const {
    return solid_;
}

boost::shared_ptr<neurite::geometry::solid>& solid_node::solid() {
    return solid_;
}

void solid_node::solid(const boost::shared_ptr<neurite::geometry::solid>& v) {
    solid_ = v;
}

void solid_node::solid(const boost::shared_ptr<neurite::geometry::solid>&& v) {
    solid_ = std::move(v);
}

} }
