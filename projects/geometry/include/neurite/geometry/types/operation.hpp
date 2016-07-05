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
#ifndef NEURITE_GEOMETRY_TYPES_OPERATION_HPP
#define NEURITE_GEOMETRY_TYPES_OPERATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/geometry/types/operation_types.hpp"
#include "neurite/geometry/serialization/operation_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class operation final {
public:
    operation(const operation&) = default;
    operation(operation&&) = default;
    ~operation() = default;

public:
    operation();

public:
    explicit operation(const neurite::geometry::operation_types type);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::operation& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::operation& v, unsigned int version);

public:
    neurite::geometry::operation_types type() const;
    void type(const neurite::geometry::operation_types v);

public:
    bool operator==(const operation& rhs) const;
    bool operator!=(const operation& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(operation& other) noexcept;
    operation& operator=(operation other);

private:
    neurite::geometry::operation_types type_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::operation& lhs,
    neurite::geometry::operation& rhs) {
    lhs.swap(rhs);
}

}

#endif
