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
#include "neurite/swc/types/file.hpp"

namespace neurite {
namespace swc {

file::file(file&& rhs)
    : header_(std::move(rhs.header_)),
      points_(std::move(rhs.points_)) { }

file::file(
    const boost::optional<neurite::swc::header>& header,
    const std::list<neurite::swc::point>& points)
    : header_(header),
      points_(points) { }

void file::swap(file& other) noexcept {
    using std::swap;
    swap(header_, other.header_);
    swap(points_, other.points_);
}

bool file::operator==(const file& rhs) const {
    return header_ == rhs.header_ &&
        points_ == rhs.points_;
}

file& file::operator=(file other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const boost::optional<neurite::swc::header>& file::header() const {
    return header_;
}

boost::optional<neurite::swc::header>& file::header() {
    return header_;
}

void file::header(const boost::optional<neurite::swc::header>& v) {
    header_ = v;
}

void file::header(const boost::optional<neurite::swc::header>&& v) {
    header_ = std::move(v);
}

const std::list<neurite::swc::point>& file::points() const {
    return points_;
}

std::list<neurite::swc::point>& file::points() {
    return points_;
}

void file::points(const std::list<neurite::swc::point>& v) {
    points_ = v;
}

void file::points(const std::list<neurite::swc::point>&& v) {
    points_ = std::move(v);
}

} }
