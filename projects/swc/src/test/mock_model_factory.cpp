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
#include "neurite/swc/test/mock_model_factory.hpp"

namespace neurite {
namespace swc {
namespace test {

namespace {

sample make_soma() {
    sample r;
    r.number(1);
    r.unparsed_structure_identifier(1);
    r.structure_identifier(structure_identifier_types::soma);
    r.position().x(0).y(0).z(0);
    r.radius(10);
    r.parent(-1);
    r.line_number(1);
    return r;
}

}

model mock_model_factory::make_empty_model() const {
    model r;
    r.name("empty");
    return r;
}

model mock_model_factory::make_model_with_simple_soma() const {
    model r;
    r.name("simple soma");
    r.samples().push_back(make_soma());
    return r;
}

} } }
