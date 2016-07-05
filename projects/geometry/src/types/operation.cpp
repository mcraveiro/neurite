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
#include "neurite/geometry/types/operation.hpp"

namespace neurite {
namespace geometry {

operation::operation()
    : type_(static_cast<neurite::geometry::operation_types>(0)) { }

operation::operation(const neurite::geometry::operation_types type)
    : type_(type) { }

void operation::swap(operation& other) noexcept {
    using std::swap;
    swap(type_, other.type_);
}

bool operation::operator==(const operation& rhs) const {
    return type_ == rhs.type_;
}

operation& operation::operator=(operation other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

neurite::geometry::operation_types operation::type() const {
    return type_;
}

void operation::type(const neurite::geometry::operation_types v) {
    type_ = v;
}

} }
