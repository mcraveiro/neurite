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
#include <boost/throw_exception.hpp>
#include "neurite/utility/log/logger.hpp"
#include "neurite/geometry/types/building_error.hpp"
#include "neurite/geometry/types/colour_factory.hpp"

namespace neurite {
namespace geometry {

namespace {

using namespace neurite::utility::log;
auto lg(logger_factory("geometry.coulour_factory"));

colour red(0xFF, 0, 0);
colour blue(0, 0, 0xFF);
colour gray(0x69, 0x69, 0x69);

const std::string unsupported_color("Colour is not supported: ");

}

colour  colour_factory::make(const colour_names n) const {
    switch (n) {
    case colour_names::red: return red;
    case colour_names::blue: return blue;
    case colour_names::gray: return gray;
    default:
        BOOST_LOG_SEV(lg, error) << unsupported_color;
        BOOST_THROW_EXCEPTION(building_error(unsupported_color));
    }
}

} }
