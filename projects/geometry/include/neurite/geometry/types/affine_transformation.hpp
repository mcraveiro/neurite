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
#ifndef NEURITE_GEOMETRY_TYPES_AFFINE_TRANSFORMATION_HPP
#define NEURITE_GEOMETRY_TYPES_AFFINE_TRANSFORMATION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/geometry/types/vector3d.hpp"
#include "neurite/geometry/types/affine_transformation_types.hpp"
#include "neurite/geometry/serialization/affine_transformation_fwd_ser.hpp"

namespace neurite {
namespace geometry {

/**
 * @brief Represents an affine transformation to apply to an object.
 */
class affine_transformation final {
public:
    affine_transformation(const affine_transformation&) = default;
    affine_transformation(affine_transformation&&) = default;
    ~affine_transformation() = default;

public:
    affine_transformation();

public:
    affine_transformation(
        const neurite::geometry::vector3d& arguments,
        const neurite::geometry::affine_transformation_types type);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::affine_transformation& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::affine_transformation& v, unsigned int version);

public:
    const neurite::geometry::vector3d& arguments() const;
    neurite::geometry::vector3d& arguments();
    void arguments(const neurite::geometry::vector3d& v);
    void arguments(const neurite::geometry::vector3d&& v);

    neurite::geometry::affine_transformation_types type() const;
    void type(const neurite::geometry::affine_transformation_types v);

public:
    bool operator==(const affine_transformation& rhs) const;
    bool operator!=(const affine_transformation& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(affine_transformation& other) noexcept;
    affine_transformation& operator=(affine_transformation other);

private:
    neurite::geometry::vector3d arguments_;
    neurite::geometry::affine_transformation_types type_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::affine_transformation& lhs,
    neurite::geometry::affine_transformation& rhs) {
    lhs.swap(rhs);
}

}

#endif
