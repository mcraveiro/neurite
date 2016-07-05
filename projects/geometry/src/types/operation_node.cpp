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
#include "neurite/geometry/io/operation_io.hpp"
#include "neurite/geometry/io/abstract_node_io.hpp"
#include "neurite/geometry/types/abstract_node.hpp"
#include "neurite/geometry/types/operation_node.hpp"

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

operation_node::operation_node(
    const neurite::geometry::operation& operation,
    const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& children)
    : neurite::geometry::abstract_node(),
      operation_(operation),
      children_(children) { }

void operation_node::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::operation_node\"" << ", "
      << "\"__parent_0__\": ";
    abstract_node::to_stream(s);
    s << ", "
      << "\"operation\": " << operation_ << ", "
      << "\"children\": " << children_
      << " }";
}

void operation_node::swap(operation_node& other) noexcept {
    abstract_node::swap(other);

    using std::swap;
    swap(operation_, other.operation_);
    swap(children_, other.children_);
}

bool operation_node::equals(const neurite::geometry::abstract_node& other) const {
    const operation_node* const p(dynamic_cast<const operation_node* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool operation_node::operator==(const operation_node& rhs) const {
    return abstract_node::compare(rhs) &&
        operation_ == rhs.operation_ &&
        children_ == rhs.children_;
}

operation_node& operation_node::operator=(operation_node other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::geometry::operation& operation_node::operation() const {
    return operation_;
}

neurite::geometry::operation& operation_node::operation() {
    return operation_;
}

void operation_node::operation(const neurite::geometry::operation& v) {
    operation_ = v;
}

void operation_node::operation(const neurite::geometry::operation&& v) {
    operation_ = std::move(v);
}

const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& operation_node::children() const {
    return children_;
}

std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& operation_node::children() {
    return children_;
}

void operation_node::children(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& v) {
    children_ = v;
}

void operation_node::children(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >&& v) {
    children_ = std::move(v);
}

} }
