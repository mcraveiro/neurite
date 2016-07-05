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
#ifndef NEURITE_SWC_TYPES_NODE_HPP
#define NEURITE_SWC_TYPES_NODE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include "neurite/swc/types/sample.hpp"
#include "neurite/swc/types/node_fwd.hpp"
#include "neurite/swc/serialization/node_fwd_ser.hpp"

namespace neurite {
namespace swc {

class node final {
public:
    node() = default;
    node(const node&) = default;
    node(node&&) = default;
    ~node() = default;

public:
    node(
        const neurite::swc::sample& content,
        const boost::shared_ptr<neurite::swc::node>& parent,
        const std::list<boost::shared_ptr<neurite::swc::node> >& children);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const neurite::swc::node& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, neurite::swc::node& v, unsigned int version);

public:
    const neurite::swc::sample& content() const;
    neurite::swc::sample& content();
    void content(const neurite::swc::sample& v);
    void content(const neurite::swc::sample&& v);

    const boost::shared_ptr<neurite::swc::node>& parent() const;
    boost::shared_ptr<neurite::swc::node>& parent();
    void parent(const boost::shared_ptr<neurite::swc::node>& v);
    void parent(const boost::shared_ptr<neurite::swc::node>&& v);

    const std::list<boost::shared_ptr<neurite::swc::node> >& children() const;
    std::list<boost::shared_ptr<neurite::swc::node> >& children();
    void children(const std::list<boost::shared_ptr<neurite::swc::node> >& v);
    void children(const std::list<boost::shared_ptr<neurite::swc::node> >&& v);

public:
    bool operator==(const node& rhs) const;
    bool operator!=(const node& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(node& other) noexcept;
    node& operator=(node other);

private:
    neurite::swc::sample content_;
    boost::shared_ptr<neurite::swc::node> parent_;
    std::list<boost::shared_ptr<neurite::swc::node> > children_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::swc::node& lhs,
    neurite::swc::node& rhs) {
    lhs.swap(rhs);
}

}

#endif
