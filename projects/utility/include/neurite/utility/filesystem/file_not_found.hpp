/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
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
#ifndef NEURITE_UTILITY_FILESYSTEM_FILE_NOT_FOUND_HPP
#define NEURITE_UTILITY_FILESYSTEM_FILE_NOT_FOUND_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "neurite/utility/exception/utility_exception.hpp"

namespace neurite {
namespace utility {
namespace filesystem {

/**
 * @brief The exception thrown when an enum has an unexpected value.
 *
 * This exception should be thrown only when:
 *
 * @li the current value of an enumeration is not part of its domain,
 * .e.g. an int was cast into an enumeration with a value which is not
 * valid; or
 *
 * @li a given valid value on an enumeration is not supported in a
 * given context.
 *
 */
class file_not_found : public neurite::utility::exception::exception {
public:
    /**
     * @param message Error message. Must be a string literal.
     */
    file_not_found(std::string message);
    file_not_found() { }

    virtual ~file_not_found() throw() {}
};

} } }

#endif
