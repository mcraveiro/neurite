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
#ifndef NEURITE_GEOMETRY_TYPES_UNION_NODE_HPP
#define NEURITE_GEOMETRY_TYPES_UNION_NODE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <iosfwd>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include "neurite/geometry/types/node.hpp"
#include "neurite/geometry/types/node_fwd.hpp"
#include "neurite/geometry/serialization/union_node_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class union_node final : public neurite::geometry::node {
public:
    union_node() = default;
    union_node(const union_node&) = default;
    union_node(union_node&&) = default;

    virtual ~union_node() noexcept { }

public:
    explicit union_node(const std::list<boost::shared_ptr<neurite::geometry::node> >& operands);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::union_node& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::union_node& v, unsigned int version);

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
    const std::list<boost::shared_ptr<neurite::geometry::node> >& operands() const;
    std::list<boost::shared_ptr<neurite::geometry::node> >& operands();
    void operands(const std::list<boost::shared_ptr<neurite::geometry::node> >& v);
    void operands(const std::list<boost::shared_ptr<neurite::geometry::node> >&& v);

public:
    bool operator==(const union_node& rhs) const;
    bool operator!=(const union_node& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const neurite::geometry::node& other) const override;

public:
    void swap(union_node& other) noexcept;
    union_node& operator=(union_node other);

private:
    std::list<boost::shared_ptr<neurite::geometry::node> > operands_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::union_node& lhs,
    neurite::geometry::union_node& rhs) {
    lhs.swap(rhs);
}

}

#endif
