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
#ifndef NEURITE_GEOMETRY_TYPES_NEF_POLYHEDRON_HPP
#define NEURITE_GEOMETRY_TYPES_NEF_POLYHEDRON_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include "neurite/geometry/serialization/nef_polyhedron_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class nef_polyhedron final {
public:
    nef_polyhedron() = default;
    nef_polyhedron(const nef_polyhedron&) = default;
    nef_polyhedron(nef_polyhedron&&) = default;
    ~nef_polyhedron() = default;

public:
    explicit nef_polyhedron(const std::string& polygons);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::nef_polyhedron& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::nef_polyhedron& v, unsigned int version);

public:
    /**
     * @brief FIXME: CGAL::Nef_polyhedron_3<CGAL::Cartesian<NT3>>
     */
    /**@{*/
    const std::string& polygons() const;
    std::string& polygons();
    void polygons(const std::string& v);
    void polygons(const std::string&& v);
    /**@}*/

public:
    bool operator==(const nef_polyhedron& rhs) const;
    bool operator!=(const nef_polyhedron& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(nef_polyhedron& other) noexcept;
    nef_polyhedron& operator=(nef_polyhedron other);

private:
    std::string polygons_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::nef_polyhedron& lhs,
    neurite::geometry::nef_polyhedron& rhs) {
    lhs.swap(rhs);
}

}

#endif
