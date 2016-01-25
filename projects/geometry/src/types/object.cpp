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
#include <boost/algorithm/string.hpp>
#include "neurite/geometry/io/point_io.hpp"
#include "neurite/geometry/types/object.hpp"
#include "neurite/geometry/io/transformation_io.hpp"

inline std::string tidy_up_string(std::string s) {
    boost::replace_all(s, "\r\n", "<new_line>");
    boost::replace_all(s, "\n", "<new_line>");
    boost::replace_all(s, "\"", "<quote>");
    return s;
}

namespace boost {

inline std::ostream& operator<<(std::ostream& s, const boost::optional<neurite::geometry::transformation>& v) {
    s << "{ " << "\"__type__\": " << "\"boost::optional\"" << ", ";

    if (v)
        s << "\"data\": " << *v;
    else
        s << "\"data\": ""\"<empty>\"";
    s << " }";
    return s;
}

}

namespace neurite {
namespace geometry {

object::object()
    : id_(static_cast<int>(0)),
      parent_id_(static_cast<int>(0)) { }

object::object(object&& rhs)
    : id_(std::move(rhs.id_)),
      parent_id_(std::move(rhs.parent_id_)),
      centre_(std::move(rhs.centre_)),
      colour_(std::move(rhs.colour_)),
      transformation_(std::move(rhs.transformation_)) { }

object::object(
    const int id,
    const int parent_id,
    const neurite::geometry::point& centre,
    const std::string& colour,
    const boost::optional<neurite::geometry::transformation>& transformation)
    : id_(id),
      parent_id_(parent_id),
      centre_(centre),
      colour_(colour),
      transformation_(transformation) { }

void object::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"neurite::geometry::object\"" << ", "
      << "\"id\": " << id_ << ", "
      << "\"parent_id\": " << parent_id_ << ", "
      << "\"centre\": " << centre_ << ", "
      << "\"colour\": " << "\"" << tidy_up_string(colour_) << "\"" << ", "
      << "\"transformation\": " << transformation_
      << " }";
}

void object::swap(object& other) noexcept {
    using std::swap;
    swap(id_, other.id_);
    swap(parent_id_, other.parent_id_);
    swap(centre_, other.centre_);
    swap(colour_, other.colour_);
    swap(transformation_, other.transformation_);
}

bool object::compare(const object& rhs) const {
    return id_ == rhs.id_ &&
        parent_id_ == rhs.parent_id_ &&
        centre_ == rhs.centre_ &&
        colour_ == rhs.colour_ &&
        transformation_ == rhs.transformation_;
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

const std::string& object::colour() const {
    return colour_;
}

std::string& object::colour() {
    return colour_;
}

void object::colour(const std::string& v) {
    colour_ = v;
}

void object::colour(const std::string&& v) {
    colour_ = std::move(v);
}

const boost::optional<neurite::geometry::transformation>& object::transformation() const {
    return transformation_;
}

boost::optional<neurite::geometry::transformation>& object::transformation() {
    return transformation_;
}

void object::transformation(const boost::optional<neurite::geometry::transformation>& v) {
    transformation_ = v;
}

void object::transformation(const boost::optional<neurite::geometry::transformation>&& v) {
    transformation_ = std::move(v);
}

} }
