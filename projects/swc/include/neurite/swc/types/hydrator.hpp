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
#ifndef DOGEN_SWC_TYPES_HYDRATOR_HPP
#define DOGEN_SWC_TYPES_HYDRATOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <iosfwd>
#include <boost/filesystem/path.hpp>
#include "neurite/swc/types/point.hpp"
#include "neurite/swc/types/model.hpp"

namespace neurite {
namespace swc {

/**
 * @brief Provides line number information on errors.
 */
typedef boost::error_info<struct tag_file_name, std::string> error_in_file;
typedef boost::error_info<struct tag_line_number, unsigned int> error_in_line;
typedef boost::error_info<struct tag_field_number, unsigned int> error_in_field;

class hydrator {
private:
    structure_identifier_types to_structure_identifier_type(const int i) const;
    point process_point_line(const std::string& s,
        const unsigned int line_number) const;

public:
    model hydrate(std::istream& is) const;
    model hydrate(const boost::filesystem::path& p) const;
};

} }

#endif
