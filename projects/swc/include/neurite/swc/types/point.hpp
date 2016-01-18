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
#include "neurite/swc/types/structure_identifier_types.hpp"

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
        const unsigned int sample_number,
        const int unparsed_structure_identifier,
        const neurite::swc::structure_identifier_types structure_identifier,
        const double x,
        const double y,
        const double z,
        const double radius,
        const int parent_sample,
        const unsigned int line_number);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const point& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, point& v, unsigned int version);

public:
    unsigned int sample_number() const;
    void sample_number(const unsigned int v);

    /**
     * @brief Structure identifier as it appeared in file. Identifies the brain structure.
     */
    /**@{*/
    int unparsed_structure_identifier() const;
    void unparsed_structure_identifier(const int v);
    /**@}*/

    /**
     * @brief Structure identifier mapped to known enums, if any available.
     *
     * Identifies the brain structure.
     */
    /**@{*/
    neurite::swc::structure_identifier_types structure_identifier() const;
    void structure_identifier(const neurite::swc::structure_identifier_types v);
    /**@}*/

    /**
     * @brief x spatial co-ordinate, given in micrometers.
     */
    /**@{*/
    double x() const;
    void x(const double v);
    /**@}*/

    /**
     * @brief y spatial co-ordinate, given in micrometers.
     */
    /**@{*/
    double y() const;
    void y(const double v);
    /**@}*/

    /**
     * @brief z spatial co-ordinate, given in micrometers.
     */
    /**@{*/
    double z() const;
    void z(const double v);
    /**@}*/

    /**
     * @brief 'radius' is half the dendrite thickness, also given in micrometers (note this is
     * one of the few formats which use radius instead of diameter).
     */
    /**@{*/
    double radius() const;
    void radius(const double v);
    /**@}*/

    /**
     * @brief The sample number. Connectivity is expressed with this value.
     *
     * Parent samples should appear before any child samples.
     */
    /**@{*/
    int parent_sample() const;
    void parent_sample(const int v);
    /**@}*/

    /**
     * @brief Number of the line of the file from which this point was read out.
     */
    /**@{*/
    unsigned int line_number() const;
    void line_number(const unsigned int v);
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
    unsigned int sample_number_;
    int unparsed_structure_identifier_;
    neurite::swc::structure_identifier_types structure_identifier_;
    double x_;
    double y_;
    double z_;
    double radius_;
    int parent_sample_;
    unsigned int line_number_;
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
