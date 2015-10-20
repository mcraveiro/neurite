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
#ifndef NEURITE_UTILITY_LOG_LIFE_CYCLE_MANAGER_HPP
#define NEURITE_UTILITY_LOG_LIFE_CYCLE_MANAGER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem/path.hpp>
#include "neurite/utility/log/severity_level.hpp"

namespace neurite {
namespace utility {
namespace log {

class life_cycle_manager {
private:
    void create_file_backend(boost::filesystem::path file_name,
        const severity_level severity);

    void create_console_backend(const severity_level severity);

public:
    void initialise(const boost::filesystem::path& file_name,
        const severity_level severity = severity_level::debug,
        const bool log_to_console = false);

    void shutdown();
};

} } }

#endif
