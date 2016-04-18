/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2015 Marco Craveiro <marco.craveiro@gmail.com>
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
#include <boost/test/unit_test.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include "neurite/utility/test/logging.hpp"
#include "neurite/utility/test/asserter.hpp"
#include "neurite/utility/test/exception_checkers.hpp"
#include "neurite/swc/types/building_error.hpp"
#include "neurite/swc/types/tree_factory.hpp"
#include "neurite/swc/test/mock_model_factory.hpp"
#include "neurite/swc/types/node.hpp"
#include "neurite/swc/types/model.hpp"
#include "neurite/swc/io/tree_io.hpp"
#include "neurite/swc/io/sample_io.hpp"
#include "neurite/swc/types/tree_factory.hpp"

namespace {

const std::string empty;
const std::string test_module("swc");
const std::string test_suite("tree_factory_spec");

}

using neurite::utility::test::asserter;
using neurite::utility::test::contains_checker;

BOOST_AUTO_TEST_SUITE(tree_factory)

BOOST_AUTO_TEST_CASE(empty_model_generates_empty_tree) {
    SETUP_TEST_LOG_SOURCE("empty_model_generates_empty_tree");

    neurite::swc::test::mock_model_factory mf;
    const auto m(mf.make_empty_model());

    neurite::swc::tree_factory tf;
    const auto t(tf.build(m));
    BOOST_CHECK(t.root() == nullptr);
}

BOOST_AUTO_TEST_CASE(model_with_simple_soma_generates_expected_tree) {
    SETUP_TEST_LOG_SOURCE("model_with_simple_soma_generates_expected_tree");

    neurite::swc::test::mock_model_factory mf;
    const auto m(mf.make_model_with_simple_soma());

    neurite::swc::tree_factory tf;
    const auto t(tf.build(m));
    BOOST_REQUIRE(t.root() != nullptr);

    const auto& e(m.samples().front());
    const auto& a(t.root()->content());
    BOOST_CHECK(asserter::assert_object(e, a));
}

BOOST_AUTO_TEST_SUITE_END()
