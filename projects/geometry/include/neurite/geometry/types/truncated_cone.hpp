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
#ifndef NEURITE_GEOMETRY_TYPES_TRUNCATED_CONE_HPP
#define NEURITE_GEOMETRY_TYPES_TRUNCATED_CONE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "neurite/geometry/types/solid.hpp"
#include "neurite/geometry/types/vector3d.hpp"
#include "neurite/geometry/serialization/truncated_cone_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class truncated_cone final : public neurite::geometry::solid {
public:
    truncated_cone(const truncated_cone&) = default;
    truncated_cone(truncated_cone&&) = default;

public:
    truncated_cone();

    virtual ~truncated_cone() noexcept { }

public:
    truncated_cone(
        const neurite::geometry::vector3d& first,
        const double first_radius,
        const double second_radius,
        const neurite::geometry::vector3d& second,
        const double height);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::truncated_cone& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::truncated_cone& v, unsigned int version);

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
    const neurite::geometry::vector3d& first() const;
    neurite::geometry::vector3d& first();
    void first(const neurite::geometry::vector3d& v);
    void first(const neurite::geometry::vector3d&& v);

    double first_radius() const;
    void first_radius(const double v);

    double second_radius() const;
    void second_radius(const double v);

    const neurite::geometry::vector3d& second() const;
    neurite::geometry::vector3d& second();
    void second(const neurite::geometry::vector3d& v);
    void second(const neurite::geometry::vector3d&& v);

    double height() const;
    void height(const double v);

public:
    bool operator==(const truncated_cone& rhs) const;
    bool operator!=(const truncated_cone& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const neurite::geometry::solid& other) const override;

public:
    void swap(truncated_cone& other) noexcept;
    truncated_cone& operator=(truncated_cone other);

private:
    neurite::geometry::vector3d first_;
    double first_radius_;
    double second_radius_;
    neurite::geometry::vector3d second_;
    double height_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::truncated_cone& lhs,
    neurite::geometry::truncated_cone& rhs) {
    lhs.swap(rhs);
}

}

#endif
