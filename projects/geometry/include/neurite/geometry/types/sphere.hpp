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
#ifndef NEURITE_GEOMETRY_TYPES_SPHERE_HPP
#define NEURITE_GEOMETRY_TYPES_SPHERE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "neurite/geometry/types/solid.hpp"
#include "neurite/geometry/types/vector3d.hpp"
#include "neurite/geometry/serialization/sphere_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class sphere final : public neurite::geometry::solid {
public:
    sphere(const sphere&) = default;
    sphere(sphere&&) = default;

public:
    sphere();

    virtual ~sphere() noexcept { }

public:
    sphere(
        const neurite::geometry::vector3d& centre,
        const double radius);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::sphere& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::sphere& v, unsigned int version);

public:
    using solid::accept;

    virtual void accept(const solid_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(solid_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const solid_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(solid_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    const neurite::geometry::vector3d& centre() const;
    neurite::geometry::vector3d& centre();
    void centre(const neurite::geometry::vector3d& v);
    void centre(const neurite::geometry::vector3d&& v);

    double radius() const;
    void radius(const double v);

public:
    bool operator==(const sphere& rhs) const;
    bool operator!=(const sphere& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const neurite::geometry::solid& other) const override;

public:
    void swap(sphere& other) noexcept;
    sphere& operator=(sphere other);

private:
    neurite::geometry::vector3d centre_;
    double radius_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::sphere& lhs,
    neurite::geometry::sphere& rhs) {
    lhs.swap(rhs);
}

}

#endif
