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
#ifndef NEURITE_GEOMETRY_TYPES_CYLINDER_HPP
#define NEURITE_GEOMETRY_TYPES_CYLINDER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "neurite/geometry/types/object.hpp"
#include "neurite/geometry/serialization/cylinder_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class cylinder final : public neurite::geometry::object {
public:
    cylinder(const cylinder&) = default;
    cylinder(cylinder&&) = default;

public:
    cylinder();

    virtual ~cylinder() noexcept { }

public:
    cylinder(
        const int id,
        const int parent_id,
        const neurite::geometry::point& centre,
        const std::string& colour,
        const std::list<neurite::geometry::transformation>& transformations,
        const double radius,
        const double height);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cylinder& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cylinder& v, unsigned int version);

public:
    virtual void accept(const object_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(object_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const object_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(object_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    double radius() const;
    void radius(const double v);

    double height() const;
    void height(const double v);

public:
    bool operator==(const cylinder& rhs) const;
    bool operator!=(const cylinder& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const neurite::geometry::object& other) const override;

public:
    void swap(cylinder& other) noexcept;
    cylinder& operator=(cylinder other);

private:
    double radius_;
    double height_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::cylinder& lhs,
    neurite::geometry::cylinder& rhs) {
    lhs.swap(rhs);
}

}

#endif
