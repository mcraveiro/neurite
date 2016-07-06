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
#include "neurite/geometry/types/union_node.hpp"
#include "neurite/geometry/io/abstract_node_io.hpp"
#include "neurite/geometry/types/abstract_node.hpp"

namespace boost {

inline std::ostream& operator<<(std::ostream& s, const boost::shared_ptr<neurite::geometry::abstract_node>& v) {
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

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace boost {

inline bool operator==(const boost::shared_ptr<neurite::geometry::abstract_node>& lhs,
const boost::shared_ptr<neurite::geometry::abstract_node>& rhs) {
    return (!lhs && !rhs) ||(lhs && rhs && (*lhs == *rhs));
}

}

namespace neurite {
namespace geometry {

union_node::union_node(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& operands)
    : neurite::geometry::abstract_node(),
      operands_(operands) { }

void union_node::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::union_node\"" << ", "
      << "\"__parent_0__\": ";
    abstract_node::to_stream(s);
    s << ", "
      << "\"operands\": " << operands_
      << " }";
}

void union_node::swap(union_node& other) noexcept {
    abstract_node::swap(other);

    using std::swap;
    swap(operands_, other.operands_);
}

bool union_node::equals(const neurite::geometry::abstract_node& other) const {
    const union_node* const p(dynamic_cast<const union_node* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool union_node::operator==(const union_node& rhs) const {
    return abstract_node::compare(rhs) &&
        operands_ == rhs.operands_;
}

union_node& union_node::operator=(union_node other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& union_node::operands() const {
    return operands_;
}

std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& union_node::operands() {
    return operands_;
}

void union_node::operands(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& v) {
    operands_ = v;
}

void union_node::operands(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >&& v) {
    operands_ = std::move(v);
}

} }
