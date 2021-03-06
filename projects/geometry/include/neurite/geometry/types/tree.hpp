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
#ifndef NEURITE_GEOMETRY_TYPES_TREE_HPP
#define NEURITE_GEOMETRY_TYPES_TREE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <boost/shared_ptr.hpp>
#include "neurite/geometry/types/node_fwd.hpp"
#include "neurite/geometry/serialization/tree_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class tree final {
public:
    tree() = default;
    tree(const tree&) = default;
    tree(tree&&) = default;
    ~tree() = default;

public:
    explicit tree(const boost::shared_ptr<neurite::geometry::node>& root);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::tree& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::tree& v, unsigned int version);

public:
    const boost::shared_ptr<neurite::geometry::node>& root() const;
    boost::shared_ptr<neurite::geometry::node>& root();
    void root(const boost::shared_ptr<neurite::geometry::node>& v);
    void root(const boost::shared_ptr<neurite::geometry::node>&& v);

public:
    bool operator==(const tree& rhs) const;
    bool operator!=(const tree& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(tree& other) noexcept;
    tree& operator=(tree other);

private:
    boost::shared_ptr<neurite::geometry::node> root_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::tree& lhs,
    neurite::geometry::tree& rhs) {
    lhs.swap(rhs);
}

}

#endif
