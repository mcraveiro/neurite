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
#ifndef NEURITE_GEOMETRY_TYPES_SOLID_HPP
#define NEURITE_GEOMETRY_TYPES_SOLID_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/geometry/types/vector3d.hpp"
#include "neurite/geometry/types/solid_types.hpp"
#include "neurite/geometry/serialization/solid_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class solid final {
public:
    solid(const solid&) = default;
    solid(solid&&) = default;
    ~solid() = default;

public:
    solid();

public:
    solid(
        const neurite::geometry::vector3d& centre,
        const double first_radius,
        const double second_radius,
        const double height,
        const neurite::geometry::solid_types type);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::solid& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::solid& v, unsigned int version);

public:
    const neurite::geometry::vector3d& centre() const;
    neurite::geometry::vector3d& centre();
    void centre(const neurite::geometry::vector3d& v);
    void centre(const neurite::geometry::vector3d&& v);

    double first_radius() const;
    void first_radius(const double v);

    double second_radius() const;
    void second_radius(const double v);

    double height() const;
    void height(const double v);

    neurite::geometry::solid_types type() const;
    void type(const neurite::geometry::solid_types v);

public:
    bool operator==(const solid& rhs) const;
    bool operator!=(const solid& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(solid& other) noexcept;
    solid& operator=(solid other);

private:
    neurite::geometry::vector3d centre_;
    double first_radius_;
    double second_radius_;
    double height_;
    neurite::geometry::solid_types type_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::solid& lhs,
    neurite::geometry::solid& rhs) {
    lhs.swap(rhs);
}

}

#endif
