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
#include <boost/algorithm/string/predicate.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include "neurite/utility/test/logging.hpp"
#include "neurite/utility/test/exception_checkers.hpp"
#include "neurite/swc/types/hydration_error.hpp"
#include "neurite/swc/types/hydrator.hpp"
#include "neurite/swc/types/file.hpp"
#include "neurite/swc/io/file_io.hpp"

namespace {

const std::string empty;
const std::string test_module("swc");
const std::string test_suite("hydrator_spec");

const std::string one_line_input(" 1 2 3.087 7.342 -21.875 8.209  -1 ");
const std::string missing_fields_input(" 1 2 3.087 7.342 -21.875 8.209");
const std::string bad_radius_input(" 1 2 3.087 7.342 -21.875 BAD_RADIUS  -1 ");

const std::string invalid_file_name("INVALID_FILE_NAME");

const std::string missing_fields("Not enough fields");
const std::string file_not_found("Failed to open file");

}

using neurite::swc::hydration_error;
using neurite::utility::test::contains_checker;

BOOST_AUTO_TEST_SUITE(hydrator)

BOOST_AUTO_TEST_CASE(hydrating_non_existing_file_throws) {
    SETUP_TEST_LOG_SOURCE("hydrating_non_existing_file_throws");

    neurite::swc::hydrator h;
    contains_checker<hydration_error> c(file_not_found);
    BOOST_CHECK_EXCEPTION(h.hydrate(invalid_file_name), hydration_error, c);
}

BOOST_AUTO_TEST_CASE(hydrating_missing_fields_input_throws) {
    SETUP_TEST_LOG_SOURCE("hydrating_missing_fields_input_throws");

    neurite::swc::hydrator h;
    std::istringstream is(missing_fields_input);
    contains_checker<hydration_error> c(missing_fields);
    BOOST_CHECK_EXCEPTION(h.hydrate(is), hydration_error, c);
}

BOOST_AUTO_TEST_CASE(hydrating_one_line_input_results_in_expected_file) {
    SETUP_TEST_LOG_SOURCE("hydrating_one_line_input_results_in_expected_file");

    neurite::swc::hydrator h;
    std::istringstream is(one_line_input);
    const auto f(h.hydrate(is));

    BOOST_LOG_SEV(lg, debug) << "File:" << f;
    BOOST_CHECK(!f.header());
    BOOST_REQUIRE(f.points().size() == 1);

    const auto p(f.points().front());
    BOOST_CHECK(p.sample_number() == 1);
    BOOST_CHECK(p.unparsed_structure_identifier() == 2);

    using neurite::swc::structure_identifier_types;
    BOOST_CHECK(p.structure_identifier() == structure_identifier_types::axon);
    BOOST_REQUIRE_CLOSE(p.x(), 3.087, 0.000001);
    BOOST_REQUIRE_CLOSE(p.y(), 7.342, 0.000001);
    BOOST_REQUIRE_CLOSE(p.z(), -21.875, 0.000001);
    BOOST_REQUIRE_CLOSE(p.radius(), 8.209, 0.000001);

    BOOST_CHECK(p.parent_sample() == -1);
    BOOST_CHECK(p.line_number() == 0);
}

BOOST_AUTO_TEST_CASE(hydrating_bad_radius_input_throws) {
    SETUP_TEST_LOG_SOURCE("hydrating_bad_radius_input_throws");

    neurite::swc::hydrator h;
    std::istringstream is(bad_radius_input);
    try {
        h.hydrate(is);
    } catch(const neurite::swc::hydration_error& he) {
        BOOST_CHECK(boost::starts_with("xxx", he.what()));

        // const auto ln(boost::get_error_info<neurite::swc::error_in_line>(he));
        // BOOST_CHECK(ln == 0);

        // const auto fn(boost::get_error_info<neurite::swc::error_in_field>(he));
        // BOOST_CHECK(fn == 6);
    }
    contains_checker<hydration_error> c(missing_fields);
    BOOST_CHECK_EXCEPTION(, hydration_error, c);
}

BOOST_AUTO_TEST_CASE(hydrating_empty_stream_results_in_empty_file) {
    SETUP_TEST_LOG_SOURCE("hydrating_empty_stream_results_in_empty_file");
    /*
    neurite::swc::hydrator h;
    auto sf(h.hydrate("a/b/c.swc"));
    BOOST_LOG_SEV(lg, debug) << sf;
    */
}

BOOST_AUTO_TEST_SUITE_END()
