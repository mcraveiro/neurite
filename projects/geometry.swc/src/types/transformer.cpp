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
#include <boost/math/constants/constants.hpp>
#include <CGAL/Simple_cartesian.h>
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/types/node.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/union_node.hpp"
#include "neurite/geometry/types/affine_transformation_node.hpp"
#include "neurite/geometry/types/solid_node.hpp"
#include "neurite/geometry/types/truncated_cone.hpp"
#include "neurite/geometry/io/truncated_cone_io.hpp"
#include "neurite/geometry.swc/types/transformer.hpp"

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point_3;
typedef Kernel::Vector_3 Vector_3;

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

boost::shared_ptr<geometry::truncated_cone> transformer::creare_truncated_cone(
    const neurite::swc::sample& s1, const neurite::swc::sample& s2) const {
    BOOST_LOG_SEV(lg, debug) << "Creating truncated cone.";
    auto r(boost::make_shared<geometry::truncated_cone>());

    r->first(transform(s1.position()));
    r->first_radius(s1.radius());
    r->second(transform(s2.position()));
    r->second_radius(s2.radius());

    Point_3 p(r->first().x(), r->first().y(), r->first().z());
    BOOST_LOG_SEV(lg, debug) <<  "p = " << p;

    Point_3 q(r->second().x(), r->second().y(), r->second().z());
    BOOST_LOG_SEV(lg, debug) <<  "q = " << q;

    const auto sd(CGAL::squared_distance(p,q));
    BOOST_LOG_SEV(lg, debug) <<  "Squared distance: " << sd;

    r->height(std::sqrt(sd));
    BOOST_LOG_SEV(lg, debug) <<  "Height: " << r->height();

    BOOST_LOG_SEV(lg, debug) << "Truncated cone: " << *r;

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
            auto sn(boost::make_shared<solid_node>());
            const auto tc(creare_truncated_cone(parent.content(), n.content()));
            sn->solid(tc);

            affine_transformation rot;
            rot.type(affine_transformation_types::rotation);

            Point_3 p1(n.content().position().x(),
                n.content().position().y(),
                n.content().position().z());
            BOOST_LOG_SEV(lg, debug) <<  "p1 = " << p1;

            Point_3 p2(parent.content().position().x(),
                parent.content().position().y(),
                parent.content().position().z());
            BOOST_LOG_SEV(lg, debug) <<  "p2 = " << p2;

            Point_3 p3(n.content().position().x(),
                n.content().position().y() + tc->height(),
                n.content().position().z());
            BOOST_LOG_SEV(lg, debug) <<  "p3 = " << p3;

            Vector_3 v1(p1 - p2);
            v1 = v1 / std::sqrt(v1 * v1);
            BOOST_LOG_SEV(lg, debug) <<  "v1 = " << v1;

            Vector_3 v2(p3 - p2);
            v2 = v2 / std::sqrt(v2 * v2);
            BOOST_LOG_SEV(lg, debug) <<  "v2 = " << v2;

            const double pi(boost::math::constants::pi<double>());
            auto angle(std::acos(v1 * v2) * 180.0 / pi);
            BOOST_LOG_SEV(lg, debug) << "angle = " << angle;

            rot.arguments(geometry::vector3d(angle, 0, 0));

            auto rn(boost::make_shared<affine_transformation_node>());
            rn->transformation(rot);
            rn->children().push_back(sn);

            affine_transformation trans;
            trans.type(affine_transformation_types::translation);
            trans.arguments(transform(n.content().position()));
            auto r(boost::make_shared<affine_transformation_node>());
            r->transformation(trans);
            r->children().push_back(rn);

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
        if (c.content().structure_identifier() == soma &&
            c.content().number() < 4) {
            BOOST_LOG_SEV(lg, debug) << "Skipping cylinders of a 3-point soma.";
            continue;
        }

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
