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
#include <boost/make_shared.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/types/node.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/union_node.hpp"
#include "neurite/geometry/types/solid_node.hpp"
#include "neurite/geometry/types/truncated_cone.hpp"
#include "neurite/geometry.swc/types/transformer.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("geometry.swc.transformer"));

const std::string indent_unit("    ");

}


namespace neurite {
namespace geometry {
namespace swc {

boost::shared_ptr<geometry::solid>
transformer::creare_sphere(const neurite::swc::sample& s) const {
    BOOST_LOG_SEV(lg, debug) << "Creating sphere.";
    auto r(boost::make_shared<geometry::sphere>());
    r->centre(transform(s.position()));
    r->radius(s.radius());
    return r;
}

boost::shared_ptr<geometry::solid> transformer::creare_truncated_cone(
    const neurite::swc::sample& s1, const neurite::swc::sample& s2) const {
    BOOST_LOG_SEV(lg, debug) << "Creating truncated cone.";
    auto r(boost::make_shared<geometry::truncated_cone>());

    r->first(transform(s1.position()));
    r->first_radius(s1.radius());
    r->second(transform(s2.position()));
    r->second_radius(s2.radius());

    return r;
}

geometry::vector3d transformer::transform(const neurite::swc::point& p) const {
    BOOST_LOG_SEV(lg, debug) << "Transforming point.";
    geometry::vector3d r;
    r.x(p.x());
    r.y(p.y());
    r.z(p.z());
    return r;
}

boost::shared_ptr<node> transformer::
transform(const neurite::swc::node& parent, const neurite::swc::node& n) const {
    BOOST_LOG_SEV(lg, debug) << "Transforming two nodes.";
    const auto lambda([&]() {
            auto r(boost::make_shared<solid_node>());
            r->solid(creare_truncated_cone(parent.content(), n.content()));
            return r;
        });

    if (n.children().empty())
        return lambda();

    auto r(boost::make_shared<union_node>());
    r->operands().push_back(lambda());

    for (const auto& c : n.children()) {
        r->operands().push_back(transform(n, c));
    }
    return r;
}

boost::shared_ptr<node> transformer::
transform(const neurite::swc::node& n) const {
    BOOST_LOG_SEV(lg, debug) << "Transforming single node.";
    const auto soma(neurite::swc::structure_identifier_types::soma);
    const bool is_soma(n.content().structure_identifier() == soma);
    const auto first_sample_number(1);
    const bool is_root(n.content().number() == first_sample_number);

    const auto lambda([&]() {
            auto r(boost::make_shared<solid_node>());
            r->solid(creare_sphere(n.content()));
            return r;
        });

    if (n.children().empty()) {
        /*
         * If I do not have children and I'm not the root soma, there
         * is nothing to be done.
         */
        if (!is_soma || !is_root) {
            BOOST_LOG_SEV(lg, debug) << "Not creating sphere for soma."
                                     << " is soma: " << is_soma
                                     << " is root: " << is_root;
            return boost::shared_ptr<node>();
        }

        /*
         * Create a sphere for the root soma.
         */
        BOOST_LOG_SEV(lg, debug) << "Creating sphere for soma.";
        return lambda();
    }

    auto r(boost::make_shared<union_node>());
    if (is_soma && is_root) {
        BOOST_LOG_SEV(lg, debug) << "Creating sphere for soma.";

        /*
         * Create a sphere for the root soma.
         */
        r->operands().push_back(lambda());
    } else {
        BOOST_LOG_SEV(lg, debug) << "Not creating sphere for soma."
                                 << " is soma: " << is_soma
                                 << " is root: " << is_root;
    }

    for (const auto& c : n.children()) {
        r->operands().push_back(transform(n, c));
    }
    return r;
}

geometry::tree transformer::transform(const neurite::swc::tree& t) const {
    geometry::tree r;
    r.root(transform(t.root()));
    return r;
}

} } }
