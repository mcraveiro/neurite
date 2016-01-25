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
#include "neurite/geometry/types/plane.hpp"
#include "neurite/geometry/types/object.hpp"

namespace boost {

inline bool operator==(const boost::shared_ptr<neurite::geometry::object>& lhs,
const boost::shared_ptr<neurite::geometry::object>& rhs) {
    return (!lhs && !rhs) ||(lhs && rhs && (*lhs == *rhs));
}

}

namespace neurite {
namespace geometry {

plane::plane()
    : id_(static_cast<int>(0)) { }

plane::plane(
    const int id,
    const std::string& name,
    const std::list<boost::shared_ptr<neurite::geometry::object> >& objects,
    const std::string& colour)
    : id_(id),
      name_(name),
      objects_(objects),
      colour_(colour) { }

void plane::swap(plane& other) noexcept {
    using std::swap;
    swap(id_, other.id_);
    swap(name_, other.name_);
    swap(objects_, other.objects_);
    swap(colour_, other.colour_);
}

bool plane::operator==(const plane& rhs) const {
    return id_ == rhs.id_ &&
        name_ == rhs.name_ &&
        objects_ == rhs.objects_ &&
        colour_ == rhs.colour_;
}

plane& plane::operator=(plane other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int plane::id() const {
    return id_;
}

void plane::id(const int v) {
    id_ = v;
}

const std::string& plane::name() const {
    return name_;
}

std::string& plane::name() {
    return name_;
}

void plane::name(const std::string& v) {
    name_ = v;
}

void plane::name(const std::string&& v) {
    name_ = std::move(v);
}

const std::list<boost::shared_ptr<neurite::geometry::object> >& plane::objects() const {
    return objects_;
}

std::list<boost::shared_ptr<neurite::geometry::object> >& plane::objects() {
    return objects_;
}

void plane::objects(const std::list<boost::shared_ptr<neurite::geometry::object> >& v) {
    objects_ = v;
}

void plane::objects(const std::list<boost::shared_ptr<neurite::geometry::object> >&& v) {
    objects_ = std::move(v);
}

const std::string& plane::colour() const {
    return colour_;
}

std::string& plane::colour() {
    return colour_;
}

void plane::colour(const std::string& v) {
    colour_ = v;
}

void plane::colour(const std::string&& v) {
    colour_ = std::move(v);
}

} }
