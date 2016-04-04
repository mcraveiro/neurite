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
#include <unordered_map>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/math/constants/constants.hpp>
#include <CGAL/Simple_cartesian.h>
#include "neurite/utility/log/logger.hpp"
#include "neurite/swc/io/sample_io.hpp"
#include "neurite/geometry/types/space.hpp"
#include "neurite/geometry/io/space_io.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/cylinder.hpp"
#include "neurite/geometry/types/transformation.hpp"
#include "neurite/geometry.swc/types/workflow.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("geometry.swc.workflow"));

}

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point_3;
typedef Kernel::Vector_3 Vector_3;
// typedef Kernel::Segment_3 Segment_3;

namespace neurite {
namespace geometry {
namespace swc {

geometry::space workflow::execute(const neurite::swc::model& m) const {
    /*Point p1, p2, p3; 
    Vector v1 = p1-p2; 
    v1 = v1 / std::sqrt( v1 * v1); 
    Vector v2 = p3-p2; 
    v2 = v2 / std::sqrt( v2 * v2); 
    */
    /*{
        Point_2 p(1,1), q(10,10);
        BOOST_LOG_SEV(lg, debug) <<  "p = " << p;
        BOOST_LOG_SEV(lg, debug) <<  "q = " << q.x() << " " << q.y();
        BOOST_LOG_SEV(lg, debug) <<  "sqdist(p,q) = " 
                                 << CGAL::squared_distance(p,q);
  
        Segment_2 s(p,q);
        Point_2 m(5, 9);
  
        BOOST_LOG_SEV(lg, debug) <<  "m = " << m;
        BOOST_LOG_SEV(lg, debug) <<  "sqdist(Segment_2(p,q), m) = "
                                 << CGAL::squared_distance(s,m);
        BOOST_LOG_SEV(lg, debug) <<  "p, q, and m ";
        switch (CGAL::orientation(p,q,m)){
        case CGAL::COLLINEAR: 
            BOOST_LOG_SEV(lg, debug) <<  "are collinear\n";
            break;
        case CGAL::LEFT_TURN:
            BOOST_LOG_SEV(lg, debug) <<  "make a left turn\n";
            break;
        case CGAL::RIGHT_TURN: 
            BOOST_LOG_SEV(lg, debug) <<  "make a right turn\n";
            break;
        }
        BOOST_LOG_SEV(lg, debug) <<  " midpoint(p,q) = " << CGAL::midpoint(p,q);
        }*/
    
    geometry::space r;
    r.colour("Gray");

    const double cylinder_height(10);
    std::unordered_map<int, neurite::swc::sample> id_to_sample;
    for (const auto& s : m.samples())
      id_to_sample[s.number()] = s;
    
    const auto soma(neurite::swc::structure_identifier_types::soma);
    for (const auto& s : m.samples()) {
        BOOST_LOG_SEV(lg, debug) << "Processing sample: " << s;

        const auto sn(s.number());
        const auto& p(s.position());
        if (s.parent() == -1 && s.structure_identifier() == soma) {
            auto s(boost::make_shared<neurite::geometry::sphere>());
            s->centre().x(p.x());
            s->centre().y(p.y());
            s->centre().z(p.z());
            s->radius(p.radius());
            s->colour("Red");
            BOOST_LOG_SEV(lg, debug) << "Created sphere: " << sn;
            r.objects().push_back(s);
        } else {
            Point_3 point(p.x(), p.y(), p.z());
            BOOST_LOG_SEV(lg, debug) <<  "point = " << point;

            Point_3 other(p.x(), p.y() + cylinder_height, p.z());
            BOOST_LOG_SEV(lg, debug) <<  "other = " << other;

            Vector_3 v1(other - point);
            v1 = v1 / std::sqrt(v1 * v1);
            BOOST_LOG_SEV(lg, debug) <<  "vector 1 = " << v1;

            const auto i(id_to_sample.find(s.parent()));
            if (i != id_to_sample.end()) {
                const auto& parent_position(i->second.position());
                Point_3 parent(parent_position.x(), parent_position.y(),
                    parent_position.z());
                BOOST_LOG_SEV(lg, debug) <<  "parent = " << parent;

                Vector_3 v2(parent - point);
                v2 = v2 / std::sqrt(v2 * v2);
                BOOST_LOG_SEV(lg, debug) << "vector 2 = " << v2;

                const double pi(boost::math::constants::pi<double>());
                auto angle(std::acos(v2 * v1) * 180.0 / pi);
                BOOST_LOG_SEV(lg, debug) << "angle = " << angle;
            }
          
            auto c(boost::make_shared<neurite::geometry::cylinder>());
            c->centre().x(p.x());
            c->centre().y(p.y());
            c->centre().z(p.z());
            c->radius(p.radius());
            c->height(cylinder_height);
            c->colour("Blue");
            r.objects().push_back(c);
            BOOST_LOG_SEV(lg, debug) << "Created cylinder: " << sn;

            if (sn == 2) {
                neurite::geometry::transformation t;
                t.type(neurite::geometry::transformation_types::translation);
                t.x(0.0);
                t.y(-5.0);
                t.z(0.0);
                c->transformation(t);
                BOOST_LOG_SEV(lg, debug) << "translating point: " << sn;
            } else if (sn == 3) {
                neurite::geometry::transformation t;
                t.type(neurite::geometry::transformation_types::translation);
                t.x(0.0);
                t.y(5.0);
                t.z(0.0);
                c->transformation(t);
                BOOST_LOG_SEV(lg, debug) << "translating point: " << sn;
            } else if (sn == 4 || sn == 5) {
                neurite::geometry::transformation t;
                t.type(neurite::geometry::transformation_types::rotation);
                t.x(0.0);
                t.y(0.0);
                t.z(90.0);
                c->transformation(t);
                BOOST_LOG_SEV(lg, debug) << "rotating point: " << sn;
            } else {
                BOOST_LOG_SEV(lg, debug) << "point untouched: " << sn;
            }

            BOOST_LOG_SEV(lg, debug) << "Created mapper for point: " << sn;
        }
    }
    BOOST_LOG_SEV(lg, debug) << "Space: " << r;
    return r;
}

} } }
