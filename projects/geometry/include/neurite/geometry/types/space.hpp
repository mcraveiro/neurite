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
#ifndef NEURITE_GEOMETRY_TYPES_SPACE_HPP
#define NEURITE_GEOMETRY_TYPES_SPACE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <string>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include "neurite/geometry/types/object_fwd.hpp"
#include "neurite/geometry/serialization/space_fwd_ser.hpp"

namespace neurite {
namespace geometry {

/**
 * @brief Container for objects.
 */
class space final {
public:
    space(const space&) = default;
    space(space&&) = default;
    ~space() = default;

public:
    space();

public:
    space(
        const int id,
        const std::string& name,
        const std::list<boost::shared_ptr<neurite::geometry::object> >& objects,
        const std::string& colour);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const space& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, space& v, unsigned int version);

public:
    /**
     * @brief Identity of the space. Always the same for all spaces.
     */
    /**@{*/
    int id() const;
    void id(const int v);
    /**@}*/

    const std::string& name() const;
    std::string& name();
    void name(const std::string& v);
    void name(const std::string&& v);

    const std::list<boost::shared_ptr<neurite::geometry::object> >& objects() const;
    std::list<boost::shared_ptr<neurite::geometry::object> >& objects();
    void objects(const std::list<boost::shared_ptr<neurite::geometry::object> >& v);
    void objects(const std::list<boost::shared_ptr<neurite::geometry::object> >&& v);

    const std::string& colour() const;
    std::string& colour();
    void colour(const std::string& v);
    void colour(const std::string&& v);

public:
    bool operator==(const space& rhs) const;
    bool operator!=(const space& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(space& other) noexcept;
    space& operator=(space other);

private:
    int id_;
    std::string name_;
    std::list<boost::shared_ptr<neurite::geometry::object> > objects_;
    std::string colour_;
};

} }

namespace std {

template<>
inline void swap(
    neurite::geometry::space& lhs,
    neurite::geometry::space& rhs) {
    lhs.swap(rhs);
}

}

#endif
