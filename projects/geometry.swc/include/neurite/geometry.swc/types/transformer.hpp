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
#ifndef NEURITE_GEOMETRY_SWC_TYPES_TRANSFORMER_HPP
#define NEURITE_GEOMETRY_SWC_TYPES_TRANSFORMER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/shared_ptr.hpp>
#include "neurite/swc/types/tree.hpp"
#include "neurite/swc/types/point.hpp"
#include "neurite/swc/types/sample.hpp"
#include "neurite/geometry/types/tree.hpp"
#include "neurite/geometry/types/solid.hpp"
#include "neurite/geometry/types/vector3d.hpp"
#include "neurite/geometry/types/node.hpp"

namespace neurite {
namespace geometry {
namespace swc {

class transformer {
private:
    boost::shared_ptr<geometry::solid>
    creare_sphere(const neurite::swc::sample& s) const;

    boost::shared_ptr<geometry::truncated_cone> creare_truncated_cone(
        const neurite::swc::sample& s1, const neurite::swc::sample& s2) const;

    geometry::vector3d transform(const neurite::swc::point& p) const;


private:
    boost::shared_ptr<node> transform(const neurite::swc::node& parent,
        const neurite::swc::node& n) const;

    boost::shared_ptr<node> transform(const neurite::swc::node& n) const;

public:
    geometry::tree transform(const neurite::swc::tree& t) const;
};

} } }

#endif
