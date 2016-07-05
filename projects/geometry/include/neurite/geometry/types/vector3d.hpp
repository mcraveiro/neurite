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
#ifndef NEURITE_GEOMETRY_TYPES_VECTOR3D_HPP
#define NEURITE_GEOMETRY_TYPES_VECTOR3D_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/geometry/serialization/vector3d_fwd_ser.hpp"

namespace neurite {
namespace geometry {

/**
 * @brief FIXME: temporary replacement for Eigen::Vector3d
 */
class vector3d final {
public:
    vector3d(const vector3d&) = default;
    vector3d(vector3d&&) = default;
    ~vector3d() = default;

public:
    vector3d();

public:
    vector3d(
        const double x,
        const double y,
        const double z);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::vector3d& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::vector3d& v, unsigned int version);

public:
    double x() const;
    void x(const double v);

    double y() const;
    void y(const double v);

    double z() const;
    void z(const double v);

public:
    bool operator==(const vector3d& rhs) const;
    bool operator!=(const vector3d& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(vector3d& other) noexcept;
    vector3d& operator=(vector3d other);

private:
    double x_;
    double y_;
    double z_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::vector3d& lhs,
    neurite::geometry::vector3d& rhs) {
    lhs.swap(rhs);
}

}

#endif
