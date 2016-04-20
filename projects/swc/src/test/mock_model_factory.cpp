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

namespace {

const int orphan(-1);

}

namespace neurite {
namespace swc {
namespace test {

namespace {

sample make_sample(const unsigned int sample_number,
    const structure_identifier_types id, const int parent) {
    sample r;
    r.number(sample_number);
    r.unparsed_structure_identifier(static_cast<int>(id));
    r.structure_identifier(id);
    r.position().x(0).y(0).z(0);
    r.radius(10);
    r.parent(parent);
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

    const auto st(structure_identifier_types::soma);
    r.samples().push_back(make_sample(1, st, orphan));

    return r;
}

model mock_model_factory::make_model_with_two_levels() const {
    model r;
    r.name("simple soma");

    const auto st(structure_identifier_types::soma);
    r.samples().push_back(make_sample(1, st, orphan));
    r.samples().push_back(make_sample(2, st, 1));
    r.samples().push_back(make_sample(3, st, 1));
    return r;
}

model mock_model_factory::make_model_with_three_levels() const {
    model r;
    r.name("three levels");

    const auto st(structure_identifier_types::soma);
    r.samples().push_back(make_sample(1, st, orphan));
    r.samples().push_back(make_sample(2, st, 1));
    r.samples().push_back(make_sample(3, st, 2));
    return r;
}

} } }
