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
#ifndef NEURITE_GEOMETRY_TYPES_POLYHEDRON_NODE_HPP
#define NEURITE_GEOMETRY_TYPES_POLYHEDRON_NODE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "neurite/geometry/types/node.hpp"
#include "neurite/geometry/types/polyhedron.hpp"
#include "neurite/geometry/serialization/polyhedron_node_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class polyhedron_node final : public neurite::geometry::node {
public:
    polyhedron_node() = default;
    polyhedron_node(const polyhedron_node&) = default;
    polyhedron_node(polyhedron_node&&) = default;

    virtual ~polyhedron_node() noexcept { }

public:
    explicit polyhedron_node(const neurite::geometry::polyhedron& polyhedron);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::polyhedron_node& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::polyhedron_node& v, unsigned int version);

public:
    using node::accept;

    virtual void accept(const node_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(node_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const node_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(node_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    const neurite::geometry::polyhedron& polyhedron() const;
    neurite::geometry::polyhedron& polyhedron();
    void polyhedron(const neurite::geometry::polyhedron& v);
    void polyhedron(const neurite::geometry::polyhedron&& v);

public:
    bool operator==(const polyhedron_node& rhs) const;
    bool operator!=(const polyhedron_node& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const neurite::geometry::node& other) const override;

public:
    void swap(polyhedron_node& other) noexcept;
    polyhedron_node& operator=(polyhedron_node other);

private:
    neurite::geometry::polyhedron polyhedron_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::polyhedron_node& lhs,
    neurite::geometry::polyhedron_node& rhs) {
    lhs.swap(rhs);
}

}

#endif
