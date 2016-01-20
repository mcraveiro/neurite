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
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/io/point_io.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/cylinder.hpp"
#include "neurite/geometry/types/transformation.hpp"
#include "neurite/geometry.swc/types/workflow.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("geometry.swc"));

}

namespace neurite {
namespace geometry {
namespace swc {

geometry::plane workflow::execute(const neurite::swc::model& m) const {
    geometry::plane r;

    const auto soma(neurite::swc::structure_identifier_types::soma);
    for (const auto& p : m.points()) {
        BOOST_LOG_SEV(lg, debug) << "Processing point: " << p;

        const auto sn(p.sample_number());
        if (p.parent_sample() == -1 && p.structure_identifier() == soma) {
            auto s(boost::make_shared<neurite::geometry::sphere>());
            s->centre().x(p.x());
            s->centre().y(p.y());
            s->centre().z(p.z());
            s->radius(p.radius());
            BOOST_LOG_SEV(lg, debug) << "Created sphere: " << sn;

            // colors->GetColor("Red", rgba);
            r.objects().push_back(s);
        } else {
            auto c(boost::make_shared<neurite::geometry::cylinder>());
            c->centre().x(p.x());
            c->centre().y(p.y());
            c->centre().z(p.z());
            c->radius(p.radius());
            c->height(10.0);
            r.objects().push_back(c);
            BOOST_LOG_SEV(lg, debug) << "Created cylinder: " << sn;

            // colors->GetColor("Blue", rgba);

            if (sn == 2) {
                neurite::geometry::transformation t;
                t.type(neurite::geometry::transformation_types::translation);
                t.x(0.0);
                t.y(-5.0);
                t.z(0.0);
                BOOST_LOG_SEV(lg, debug) << "translating point: " << sn;
            } else if (sn == 3) {
                neurite::geometry::transformation t;
                t.type(neurite::geometry::transformation_types::translation);
                t.x(0.0);
                t.y(5.0);
                t.z(0.0);
                BOOST_LOG_SEV(lg, debug) << "translating point: " << sn;
            } else if (sn == 4 || sn == 5) {
                neurite::geometry::transformation t;
                t.type(neurite::geometry::transformation_types::rotation);
                t.x(0.0);
                t.y(5.0);
                t.z(0.0);
                BOOST_LOG_SEV(lg, debug) << "rotating point: " << sn;
            } else {
                BOOST_LOG_SEV(lg, debug) << "point untouched: " << sn;
            }

            BOOST_LOG_SEV(lg, debug) << "Created mapper for point: " << sn;
        }
    }    
    return r;
}

} } }
