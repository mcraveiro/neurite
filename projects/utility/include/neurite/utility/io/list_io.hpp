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
#ifndef NEURITE_UTILITY_IO_LIST_IO_HPP
#define NEURITE_UTILITY_IO_LIST_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <ostream>
#include "neurite/utility/io/jsonify_io.hpp"

namespace std {

template<typename Containee>
inline ostream& operator<<(ostream& stream, const list<Containee>& list) {
    stream << "[ ";
    for(typename std::list<Containee>::const_iterator i(list.begin());
        i != list.end();
        ++i) {
        if (i != list.begin()) stream << ", ";
        stream << neurite::utility::streaming::jsonify(*i);
    }
    stream << " ]";
    return(stream);
}

}

#endif
