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
#ifndef NEURITE_GEOMETRY_TYPES_POLYGON_HPP
#define NEURITE_GEOMETRY_TYPES_POLYGON_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <vector>
#include <algorithm>
#include "neurite/geometry/types/vector3d.hpp"
#include "neurite/geometry/serialization/polygon_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class polygon final {
public:
    polygon() = default;
    polygon(const polygon&) = default;
    polygon(polygon&&) = default;
    ~polygon() = default;

public:
    explicit polygon(const std::vector<neurite::geometry::vector3d>& vertices);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::polygon& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::polygon& v, unsigned int version);

public:
    const std::vector<neurite::geometry::vector3d>& vertices() const;
    std::vector<neurite::geometry::vector3d>& vertices();
    void vertices(const std::vector<neurite::geometry::vector3d>& v);
    void vertices(const std::vector<neurite::geometry::vector3d>&& v);

public:
    bool operator==(const polygon& rhs) const;
    bool operator!=(const polygon& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(polygon& other) noexcept;
    polygon& operator=(polygon other);

private:
    std::vector<neurite::geometry::vector3d> vertices_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::polygon& lhs,
    neurite::geometry::polygon& rhs) {
    lhs.swap(rhs);
}

}

#endif
