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
#include "neurite/geometry/io/point_io.hpp"
#include "neurite/geometry/io/colour_io.hpp"
#include "neurite/geometry/types/object.hpp"
#include "neurite/geometry/io/transformation_io.hpp"

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::list<neurite::geometry::transformation>& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace neurite {
namespace geometry {

object::object()
    : id_(static_cast<int>(0)),
      parent_id_(static_cast<int>(0)) { }

object::object(
    const int id,
    const int parent_id,
    const neurite::geometry::point& centre,
    const neurite::geometry::colour& colour,
    const std::list<neurite::geometry::transformation>& transformations)
    : id_(id),
      parent_id_(parent_id),
      centre_(centre),
      colour_(colour),
      transformations_(transformations) { }

void object::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::object\"" << ", "
      << "\"id\": " << id_ << ", "
      << "\"parent_id\": " << parent_id_ << ", "
      << "\"centre\": " << centre_ << ", "
      << "\"colour\": " << colour_ << ", "
      << "\"transformations\": " << transformations_
      << " }";
}

void object::swap(object& other) noexcept {
    using std::swap;
    swap(id_, other.id_);
    swap(parent_id_, other.parent_id_);
    swap(centre_, other.centre_);
    swap(colour_, other.colour_);
    swap(transformations_, other.transformations_);
}

bool object::compare(const object& rhs) const {
    return id_ == rhs.id_ &&
        parent_id_ == rhs.parent_id_ &&
        centre_ == rhs.centre_ &&
        colour_ == rhs.colour_ &&
        transformations_ == rhs.transformations_;
}

int object::id() const {
    return id_;
}

void object::id(const int v) {
    id_ = v;
}

int object::parent_id() const {
    return parent_id_;
}

void object::parent_id(const int v) {
    parent_id_ = v;
}

const neurite::geometry::point& object::centre() const {
    return centre_;
}

neurite::geometry::point& object::centre() {
    return centre_;
}

void object::centre(const neurite::geometry::point& v) {
    centre_ = v;
}

void object::centre(const neurite::geometry::point&& v) {
    centre_ = std::move(v);
}

const neurite::geometry::colour& object::colour() const {
    return colour_;
}

neurite::geometry::colour& object::colour() {
    return colour_;
}

void object::colour(const neurite::geometry::colour& v) {
    colour_ = v;
}

void object::colour(const neurite::geometry::colour&& v) {
    colour_ = std::move(v);
}

const std::list<neurite::geometry::transformation>& object::transformations() const {
    return transformations_;
}

std::list<neurite::geometry::transformation>& object::transformations() {
    return transformations_;
}

void object::transformations(const std::list<neurite::geometry::transformation>& v) {
    transformations_ = v;
}

void object::transformations(const std::list<neurite::geometry::transformation>&& v) {
    transformations_ = std::move(v);
}

} }
