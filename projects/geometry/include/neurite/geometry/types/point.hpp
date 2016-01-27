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
#ifndef NEURITE_GEOMETRY_TYPES_POINT_HPP
#define NEURITE_GEOMETRY_TYPES_POINT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/geometry/serialization/point_fwd_ser.hpp"

namespace neurite {
namespace geometry {

/**
 * @brief Point in a 3D space.
 */
class point final {
public:
    point(const point&) = default;
    point(point&&) = default;
    ~point() = default;

public:
    point();

public:
    point(
        const double x,
        const double y,
        const double z);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const point& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, point& v, unsigned int version);

public:
    /**
     * @brief Angle of rotation for the X dimension.
     */
    /**@{*/
    double x() const;
    void x(const double v);
    /**@}*/

    /**
     * @brief Angle of rotation for the Y dimension.
     */
    /**@{*/
    double y() const;
    void y(const double v);
    /**@}*/

    /**
     * @brief Angle of rotation for the Z dimension.
     */
    /**@{*/
    double z() const;
    void z(const double v);
    /**@}*/

public:
    bool operator==(const point& rhs) const;
    bool operator!=(const point& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(point& other) noexcept;
    point& operator=(point other);

private:
    double x_;
    double y_;
    double z_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::point& lhs,
    neurite::geometry::point& rhs) {
    lhs.swap(rhs);
}

}

#endif
