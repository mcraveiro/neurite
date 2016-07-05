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
#ifndef NEURITE_GEOMETRY_TYPES_AFFINE_TRANSFORMATION_INJECTOR_HPP
#define NEURITE_GEOMETRY_TYPES_AFFINE_TRANSFORMATION_INJECTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/geometry/serialization/affine_transformation_injector_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class affine_transformation_injector final {
public:
    affine_transformation_injector() = default;
    affine_transformation_injector(const affine_transformation_injector&) = default;
    affine_transformation_injector(affine_transformation_injector&&) = default;
    ~affine_transformation_injector() = default;
    affine_transformation_injector& operator=(const affine_transformation_injector&) = default;

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::affine_transformation_injector& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::affine_transformation_injector& v, unsigned int version);

public:
    bool operator==(const affine_transformation_injector& rhs) const;
    bool operator!=(const affine_transformation_injector& rhs) const {
        return !this->operator==(rhs);
    }

};

} }

#endif
