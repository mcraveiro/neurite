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
#include "neurite/swc/types/node.hpp"

namespace boost {

inline bool operator==(const boost::shared_ptr<neurite::swc::node>& lhs,
const boost::shared_ptr<neurite::swc::node>& rhs) {
    return (!lhs && !rhs) ||(lhs && rhs && (*lhs == *rhs));
}

}

namespace neurite {
namespace swc {

node::node(
    const neurite::swc::sample& content,
    const boost::shared_ptr<neurite::swc::node>& parent,
    const std::list<boost::shared_ptr<neurite::swc::node> >& children)
    : content_(content),
      parent_(parent),
      children_(children) { }

void node::swap(node& other) noexcept {
    using std::swap;
    swap(content_, other.content_);
    swap(parent_, other.parent_);
    swap(children_, other.children_);
}

bool node::operator==(const node& rhs) const {
    return content_ == rhs.content_ &&
        parent_ == rhs.parent_ &&
        children_ == rhs.children_;
}

node& node::operator=(node other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::swc::sample& node::content() const {
    return content_;
}

neurite::swc::sample& node::content() {
    return content_;
}

void node::content(const neurite::swc::sample& v) {
    content_ = v;
}

void node::content(const neurite::swc::sample&& v) {
    content_ = std::move(v);
}

const boost::shared_ptr<neurite::swc::node>& node::parent() const {
    return parent_;
}

boost::shared_ptr<neurite::swc::node>& node::parent() {
    return parent_;
}

void node::parent(const boost::shared_ptr<neurite::swc::node>& v) {
    parent_ = v;
}

void node::parent(const boost::shared_ptr<neurite::swc::node>&& v) {
    parent_ = std::move(v);
}

const std::list<boost::shared_ptr<neurite::swc::node> >& node::children() const {
    return children_;
}

std::list<boost::shared_ptr<neurite::swc::node> >& node::children() {
    return children_;
}

void node::children(const std::list<boost::shared_ptr<neurite::swc::node> >& v) {
    children_ = v;
}

void node::children(const std::list<boost::shared_ptr<neurite::swc::node> >&& v) {
    children_ = std::move(v);
}

} }
