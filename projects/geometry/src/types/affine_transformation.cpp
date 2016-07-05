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
#include "neurite/geometry/types/affine_transformation.hpp"

namespace neurite {
namespace geometry {

affine_transformation::affine_transformation()
    : type_(static_cast<neurite::geometry::affine_transformation_types>(0)) { }

affine_transformation::affine_transformation(
    const neurite::geometry::vector3d& arguments,
    const neurite::geometry::affine_transformation_types type)
    : arguments_(arguments),
      type_(type) { }

void affine_transformation::swap(affine_transformation& other) noexcept {
    using std::swap;
    swap(arguments_, other.arguments_);
    swap(type_, other.type_);
}

bool affine_transformation::operator==(const affine_transformation& rhs) const {
    return arguments_ == rhs.arguments_ &&
        type_ == rhs.type_;
}

affine_transformation& affine_transformation::operator=(affine_transformation other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const neurite::geometry::vector3d& affine_transformation::arguments() const {
    return arguments_;
}

neurite::geometry::vector3d& affine_transformation::arguments() {
    return arguments_;
}

void affine_transformation::arguments(const neurite::geometry::vector3d& v) {
    arguments_ = v;
}

void affine_transformation::arguments(const neurite::geometry::vector3d&& v) {
    arguments_ = std::move(v);
}

neurite::geometry::affine_transformation_types affine_transformation::type() const {
    return type_;
}

void affine_transformation::type(const neurite::geometry::affine_transformation_types v) {
    type_ = v;
}

} }
