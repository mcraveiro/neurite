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
#include <boost/test/unit_test.hpp>
#include "neurite/utility/test/logging.hpp"
#include "neurite/utility/test/exception_checkers.hpp"
#include "neurite/swc/types/hydration_error.hpp"
#include "neurite/swc/types/hydrator.hpp"
#include "neurite/swc/types/standardised_file.hpp"
#include "neurite/swc/io/standardised_file_io.hpp"

namespace {

const std::string empty;
const std::string test_module("swc");
const std::string test_suite("hydrator_spec");

const std::string invalid_file_name("INVALID_FILE_NAME");
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

BOOST_AUTO_TEST_CASE(hydrating_empty_stream_results_in_empty_file) {
    SETUP_TEST_LOG_SOURCE("hydrating_empty_stream_results_in_empty_file");
    /*
    neurite::swc::hydrator h;
    auto sf(h.hydrate("a/b/c.swc"));
    BOOST_LOG_SEV(lg, debug) << sf;
    */
}

BOOST_AUTO_TEST_SUITE_END()
