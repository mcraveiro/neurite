/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2016 Marco Craveiro <marco.craveiro@gmail.com>
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
#include <iostream>
#include "neurite/swc/types/hydrator.hpp"
#include "neurite/swc/types/tree_factory.hpp"
#include "neurite/geometry/types/scad_evaluator.hpp"
#include "neurite/scader/program_options_parser.hpp"
#include "neurite/scader/parser_validation_error.hpp"

namespace {

const std::string more_information(
    "Try `neurite.scader --help' for more information.");
const std::string usage_error_msg("Usage error: ");

}

int main(const int argc, const char* argv[]) {
    try {
        neurite::scader::program_options_parser p;
        const auto o(p.parse(argc, argv));

        /* can only happen if the options are valid but do not
         * require any action.
         */
        if (!o)
            return 0;
    } catch (const neurite::scader::parser_validation_error& e) {
        std::cerr << usage_error_msg << e.what() << std::endl
                  << more_information << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;;
        return 1;
    } catch(...) {
        std::cerr << "A fatal error occurred during the conversion: ";
        return 1;
    }

    return 0;
}
