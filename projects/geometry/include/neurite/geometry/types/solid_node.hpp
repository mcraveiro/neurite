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
#ifndef NEURITE_GEOMETRY_TYPES_SOLID_NODE_HPP
#define NEURITE_GEOMETRY_TYPES_SOLID_NODE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "neurite/geometry/types/solid.hpp"
#include "neurite/geometry/types/abstract_node.hpp"
#include "neurite/geometry/serialization/solid_node_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class solid_node final : public neurite::geometry::abstract_node {
public:
    solid_node() = default;
    solid_node(const solid_node&) = default;
    solid_node(solid_node&&) = default;

    virtual ~solid_node() noexcept { }

public:
    explicit solid_node(const neurite::geometry::solid& solid);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::solid_node& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::solid_node& v, unsigned int version);

public:
    using abstract_node::accept;

    virtual void accept(const abstract_node_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(abstract_node_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const abstract_node_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(abstract_node_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    const neurite::geometry::solid& solid() const;
    neurite::geometry::solid& solid();
    void solid(const neurite::geometry::solid& v);
    void solid(const neurite::geometry::solid&& v);

public:
    bool operator==(const solid_node& rhs) const;
    bool operator!=(const solid_node& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const neurite::geometry::abstract_node& other) const override;

public:
    void swap(solid_node& other) noexcept;
    solid_node& operator=(solid_node other);

private:
    neurite::geometry::solid solid_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::solid_node& lhs,
    neurite::geometry::solid_node& rhs) {
    lhs.swap(rhs);
}

}

#endif
