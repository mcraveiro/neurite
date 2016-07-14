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
#include <boost/throw_exception.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/geometry/types/sphere.hpp"
#include "neurite/geometry/types/truncated_cone.hpp"
#include "neurite/geometry/types/union_node.hpp"
#include "neurite/geometry/types/solid_node.hpp"
#include "neurite/geometry/types/evaluation_error.hpp"
#include "neurite/geometry/types/affine_transformation_node.hpp"
#include "neurite/geometry/types/scad_formatter.hpp"

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("geometry.scad_formatter"));

const std::string indent_unit("    ");

}

namespace neurite {
namespace geometry {

scad_formatter::scad_formatter() : indentation_level_(0) { }

void scad_formatter::indent() {
    for (unsigned int i(0); i < indentation_level_; ++i)
        stream_ << indent_unit;
}

void scad_formatter::visit(const sphere& s) {
    BOOST_LOG_SEV(lg, debug) << "Found spehere solid.";

    indent();
    stream_ << "sphere(r=" << s.radius() << ");"
            << std::endl;
}

void scad_formatter::visit(const truncated_cone& s) {
    BOOST_LOG_SEV(lg, debug) << "Found truncated cone solid.";

    indent();
    stream_ << "cylinder("
            << "h=" << 15 << ", "
            << "r1=" << s.first_radius() << ", "
            << "r2=" << s.second_radius() << ", "
            << "center=false"
            << ");"
            << std::endl;
}

void scad_formatter::visit(const affine_transformation_node& n) {
    BOOST_LOG_SEV(lg, debug) << "Found affine transformation node.";
    indent();
    const auto& t(n.transformation());
    stream_ << "translate(["
            << t.arguments().x() << ", "
            << t.arguments().y() << ", "
            << t.arguments().z() << "]) {"
            << std::endl;

    ++indentation_level_;
    for (const auto& ptr : n.children()) {
        const auto& op(*ptr);
        op.accept(*this);
    }

    --indentation_level_;
    indent();
    stream_ << "}" << std::endl;
}

void scad_formatter::visit(const nef_node& /*n*/) {
    BOOST_LOG_SEV(lg, debug) << "Found nef node.";
}

void scad_formatter::visit(const polyhedron_node& /*n*/) {
    BOOST_LOG_SEV(lg, debug) << "Found polyhedron node.";
}

void scad_formatter::visit(const solid_node& n) {
    BOOST_LOG_SEV(lg, debug) << "Found solid node.";
    const auto& solid(*n.solid());
    solid.accept(*this);
}

void scad_formatter::visit(const union_node& n) {
    BOOST_LOG_SEV(lg, debug) << "Found union node.";
    indent();
    stream_ << "union() {" << std::endl;
    ++indentation_level_;

    for (const auto& ptr : n.operands()) {
        const auto& op(*ptr);
        op.accept(*this);
    }

    --indentation_level_;
    indent();
    stream_ << "}" << std::endl;
}

std::string scad_formatter::format(const node& n) {
    BOOST_LOG_SEV(lg, debug) << "Started formatting.";
    stream_.str("");
    n.accept(*this);
    BOOST_LOG_SEV(lg, debug) << "Finished formatting.";
    return stream_.str();
}

} }
