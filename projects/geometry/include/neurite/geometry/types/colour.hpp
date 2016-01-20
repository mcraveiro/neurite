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
#ifndef NEURITE_GEOMETRY_TYPES_COLOUR_HPP
#define NEURITE_GEOMETRY_TYPES_COLOUR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/geometry/serialization/colour_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class colour final {
public:
    colour(const colour&) = default;
    colour(colour&&) = default;
    ~colour() = default;

public:
    colour();

public:
    colour(
        const int red,
        const int green,
        const int blue);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const colour& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, colour& v, unsigned int version);

public:
    int red() const;
    void red(const int v);

    int green() const;
    void green(const int v);

    int blue() const;
    void blue(const int v);

public:
    bool operator==(const colour& rhs) const;
    bool operator!=(const colour& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(colour& other) noexcept;
    colour& operator=(colour other);

private:
    int red_;
    int green_;
    int blue_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::colour& lhs,
    neurite::geometry::colour& rhs) {
    lhs.swap(rhs);
}

}

#endif
