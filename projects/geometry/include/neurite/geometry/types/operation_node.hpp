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
#ifndef NEURITE_GEOMETRY_TYPES_OPERATION_NODE_HPP
#define NEURITE_GEOMETRY_TYPES_OPERATION_NODE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <iosfwd>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include "neurite/geometry/types/operation.hpp"
#include "neurite/geometry/types/abstract_node.hpp"
#include "neurite/geometry/types/abstract_node_fwd.hpp"
#include "neurite/geometry/serialization/operation_node_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class operation_node final : public neurite::geometry::abstract_node {
public:
    operation_node() = default;
    operation_node(const operation_node&) = default;
    operation_node(operation_node&&) = default;

    virtual ~operation_node() noexcept { }

public:
    operation_node(
        const neurite::geometry::operation& operation,
        const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& children);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::geometry::operation_node& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::geometry::operation_node& v, unsigned int version);

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
    const neurite::geometry::operation& operation() const;
    neurite::geometry::operation& operation();
    void operation(const neurite::geometry::operation& v);
    void operation(const neurite::geometry::operation&& v);

    const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& children() const;
    std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& children();
    void children(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >& v);
    void children(const std::list<boost::shared_ptr<neurite::geometry::abstract_node> >&& v);

public:
    bool operator==(const operation_node& rhs) const;
    bool operator!=(const operation_node& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const neurite::geometry::abstract_node& other) const override;

public:
    void swap(operation_node& other) noexcept;
    operation_node& operator=(operation_node other);

private:
    neurite::geometry::operation operation_;
    std::list<boost::shared_ptr<neurite::geometry::abstract_node> > children_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::operation_node& lhs,
    neurite::geometry::operation_node& rhs) {
    lhs.swap(rhs);
}

}

#endif
