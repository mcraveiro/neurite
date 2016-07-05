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
#ifndef NEURITE_GEOMETRY_TYPES_ABSTRACT_NODE_HPP
#define NEURITE_GEOMETRY_TYPES_ABSTRACT_NODE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "neurite/geometry/types/abstract_node_visitor.hpp"
#include "neurite/geometry/serialization/abstract_node_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class abstract_node {
public:
    abstract_node() = default;
    abstract_node(const abstract_node&) = default;
    abstract_node(abstract_node&&) = default;
    abstract_node& operator=(const abstract_node&) = default;

    virtual ~abstract_node() noexcept = 0;

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::abstract_node& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::abstract_node& v, unsigned int version);

public:
    virtual void accept(const abstract_node_visitor& v) const = 0;
    virtual void accept(abstract_node_visitor& v) const = 0;
    virtual void accept(const abstract_node_visitor& v) = 0;
    virtual void accept(abstract_node_visitor& v) = 0;

public:
    virtual void to_stream(std::ostream& s) const;

protected:
    bool compare(const abstract_node& rhs) const;
public:
    virtual bool equals(const abstract_node& other) const = 0;

protected:
    void swap(abstract_node& other) noexcept;

};

inline abstract_node::~abstract_node() noexcept { }

inline bool operator==(const abstract_node& lhs, const abstract_node& rhs) {
    return lhs.equals(rhs);
}

} }

#endif
