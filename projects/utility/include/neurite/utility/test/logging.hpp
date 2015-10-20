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
#ifndef NEURITE_UTILITY_TEST_LOGGING_HPP
#define NEURITE_UTILITY_TEST_LOGGING_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <sstream>
#include <boost/test/results_collector.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/utility/log/scoped_life_cycle_manager.hpp"

namespace neurite {
namespace utility {
namespace test {

inline void log_if_test_has_failed() {
    using namespace neurite::utility::log;
    logger lg(logger_factory("utility.test"));

    namespace ut = boost::unit_test;
    auto test_id(ut::framework::current_test_case().p_id);
    if (!ut::results_collector.results(test_id).passed())
        BOOST_LOG_SEV(lg, error) << "test failed.";
}

inline neurite::utility::log::scoped_life_cycle_manager
scoped_life_cycle_manager_factory(std::string test_module,
    std::string test_suite,
    std::string function_name) {
    std::ostringstream stream;

    stream << "log/" << test_module << "/" << test_suite
           << "/" << function_name;

    using namespace neurite::utility::log;
    return scoped_life_cycle_manager(stream.str());
}

} } }

#ifdef SETUP_TEST_LOG
#undef SETUP_TEST_LOG
#endif
#define SETUP_TEST_LOG(function_name)                                   \
    BOOST_TEST_CHECKPOINT(function_name);                               \
    auto sl(neurite::utility::test::scoped_life_cycle_manager_factory(    \
            test_module, test_suite, function_name));

#ifdef SETUP_TEST_LOG_SOURCE
#undef SETUP_TEST_LOG_SOURCE
#endif
#define SETUP_TEST_LOG_SOURCE(function_name)                            \
    BOOST_TEST_CHECKPOINT(function_name);                               \
    neurite::utility::log::logger lg(                                     \
        neurite::utility::log::logger_factory(test_suite));               \
    using namespace neurite::utility::log;                                \
    auto sl(neurite::utility::test::scoped_life_cycle_manager_factory(    \
            test_module, test_suite, function_name));

#endif
