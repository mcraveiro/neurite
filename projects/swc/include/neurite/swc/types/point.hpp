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
#ifndef NEURITE_SWC_TYPES_POINT_HPP
#define NEURITE_SWC_TYPES_POINT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "neurite/swc/serialization/point_fwd_ser.hpp"

namespace neurite {
namespace swc {

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
        const double z,
        const double radius);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const point& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, point& v, unsigned int version);

public:
    /**
     * @brief x spatial co-ordinate, given in micrometers.
     */
    /**@{*/
    double x() const;
    point& x(const double v);
    /**@}*/

    /**
     * @brief y spatial co-ordinate, given in micrometers.
     */
    /**@{*/
    double y() const;
    point& y(const double v);
    /**@}*/

    /**
     * @brief z spatial co-ordinate, given in micrometers.
     */
    /**@{*/
    double z() const;
    point& z(const double v);
    /**@}*/

    /**
     * @brief Half the dendrite thickness, given in micrometers.
     */
    /**@{*/
    double radius() const;
    point& radius(const double v);
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
    double radius_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::swc::point& lhs,
    neurite::swc::point& rhs) {
    lhs.swap(rhs);
}

}

#endif
