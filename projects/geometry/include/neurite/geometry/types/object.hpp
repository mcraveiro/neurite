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
#ifndef NEURITE_GEOMETRY_TYPES_OBJECT_HPP
#define NEURITE_GEOMETRY_TYPES_OBJECT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <string>
#include <algorithm>
#include <boost/optional.hpp>
#include "neurite/geometry/types/point.hpp"
#include "neurite/geometry/types/object_visitor.hpp"
#include "neurite/geometry/types/transformation.hpp"
#include "neurite/geometry/serialization/object_fwd_ser.hpp"

namespace neurite {
namespace geometry {

class object {
public:
    object(const object&) = default;

public:
    object();

    virtual ~object() noexcept = 0;

public:
    object(object&& rhs);

public:
    object(
        const int id,
        const int parent_id,
        const neurite::geometry::point& centre,
        const std::string& colour,
        const boost::optional<neurite::geometry::transformation>& transformation);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const object& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, object& v, unsigned int version);

public:
    virtual void accept(const object_visitor& v) const = 0;
    virtual void accept(object_visitor& v) const = 0;
    virtual void accept(const object_visitor& v) = 0;
    virtual void accept(object_visitor& v) = 0;

public:
    virtual void to_stream(std::ostream& s) const;

public:
    /**
     * @brief Identifies an object within a plane.
     */
    /**@{*/
    int id() const;
    void id(const int v);
    /**@}*/

    /**
     * @brief Identity of the parent of the object.
     */
    /**@{*/
    int parent_id() const;
    void parent_id(const int v);
    /**@}*/

    const neurite::geometry::point& centre() const;
    neurite::geometry::point& centre();
    void centre(const neurite::geometry::point& v);
    void centre(const neurite::geometry::point&& v);

    const std::string& colour() const;
    std::string& colour();
    void colour(const std::string& v);
    void colour(const std::string&& v);

    const boost::optional<neurite::geometry::transformation>& transformation() const;
    boost::optional<neurite::geometry::transformation>& transformation();
    void transformation(const boost::optional<neurite::geometry::transformation>& v);
    void transformation(const boost::optional<neurite::geometry::transformation>&& v);

protected:
    bool compare(const object& rhs) const;
public:
    virtual bool equals(const object& other) const = 0;

protected:
    void swap(object& other) noexcept;

private:
    int id_;
    int parent_id_;
    neurite::geometry::point centre_;
    std::string colour_;
    boost::optional<neurite::geometry::transformation> transformation_;
};

inline object::~object() noexcept { }

inline bool operator==(const object& lhs, const object& rhs) {
    return lhs.equals(rhs);
}

} }

#endif
