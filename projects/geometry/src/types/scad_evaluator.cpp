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
#include <sstream>
#include <boost/throw_exception.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/geometry/io/tree_io.hpp"
#include "neurite/geometry/types/node.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/union_node.hpp"
#include "neurite/geometry/types/solid_node.hpp"
#include "neurite/geometry/types/node_visitor.hpp"
#include "neurite/geometry/types/solid_visitor.hpp"
#include "neurite/geometry/types/evaluation_error.hpp"
#include "neurite/geometry/types/scad_formatter.hpp"
#include "neurite/geometry/types/scad_evaluator.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("geometry.scad_evaluator"));

const std::string indent_unit("    ");

}

namespace neurite {
namespace geometry {

std::string scad_evaluator::evaluate(const tree& t) const {
    BOOST_LOG_SEV(lg, debug) << "Starting evaluation at root.";
    BOOST_LOG_SEV(lg, debug) << "Tree contents: " << t;
    scad_formatter sf;
    const auto r(sf.format(*t.root()));
    BOOST_LOG_SEV(lg, debug) << "Finished evaluation. Result: " << r;
    return r;
}

} }
