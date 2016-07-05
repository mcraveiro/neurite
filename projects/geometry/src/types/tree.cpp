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
#include "neurite/geometry/types/tree.hpp"
#include "neurite/geometry/types/abstract_node.hpp"

namespace boost {

inline bool operator==(const boost::shared_ptr<neurite::geometry::abstract_node>& lhs,
const boost::shared_ptr<neurite::geometry::abstract_node>& rhs) {
    return (!lhs && !rhs) ||(lhs && rhs && (*lhs == *rhs));
}

}

namespace neurite {
namespace geometry {

tree::tree(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& root)
    : root_(root) { }

void tree::swap(tree& other) noexcept {
    using std::swap;
    swap(root_, other.root_);
}

bool tree::operator==(const tree& rhs) const {
    return root_ == rhs.root_;
}

tree& tree::operator=(tree other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& tree::root() const {
    return root_;
}

std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& tree::root() {
    return root_;
}

void tree::root(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& v) {
    root_ = v;
}

void tree::root(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >&& v) {
    root_ = std::move(v);
}

} }
