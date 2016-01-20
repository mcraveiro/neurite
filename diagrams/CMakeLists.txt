# -*- mode: cmake; tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2015 Marco Craveiro <marco.craveiro@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#
set(target swc)
add_custom_target(knit_${target}
    COMMENT "Knitting SWC model" VERBATIM
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${DOGEN_KNITTER_COMMAND}
    --target ${CMAKE_SOURCE_DIR}/diagrams/${target}.dia,neurite
    --cpp-project-dir ${CMAKE_SOURCE_DIR}/projects/
    --cpp-disable-cmakelists
    --ignore-files-matching-regex .*/CMakeLists.txt
    --ignore-files-matching-regex .*/test/.*
    --ignore-files-matching-regex .*/spec/.*
    --verbose
    --delete-extra-files)
add_dependencies(knit_all knit_${target})

set(target geometry)
add_custom_target(knit_${target}
    COMMENT "Knitting Geometry model" VERBATIM
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${DOGEN_KNITTER_COMMAND}
    --target ${CMAKE_SOURCE_DIR}/diagrams/${target}.dia,neurite
    --cpp-project-dir ${CMAKE_SOURCE_DIR}/projects/
    --cpp-disable-cmakelists
    --ignore-files-matching-regex .*/CMakeLists.txt
    --ignore-files-matching-regex .*/test/.*
    --ignore-files-matching-regex .*/spec/.*
    --verbose
    --delete-extra-files)
add_dependencies(knit_all knit_${target})

set(target geometry_swc)
add_custom_target(knit_${target}
    COMMENT "Knitting Geometry SWC model" VERBATIM
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${DOGEN_KNITTER_COMMAND}
    --target ${CMAKE_SOURCE_DIR}/diagrams/geometry.swc.dia,neurite
    --reference ${CMAKE_SOURCE_DIR}/diagrams/geometry.dia,neurite
    --reference ${CMAKE_SOURCE_DIR}/diagrams/swc.dia,neurite
    --cpp-project-dir ${CMAKE_SOURCE_DIR}/projects/
    --cpp-disable-cmakelists
    --ignore-files-matching-regex .*/CMakeLists.txt
    --ignore-files-matching-regex .*/test/.*
    --ignore-files-matching-regex .*/spec/.*
    --verbose
    --delete-extra-files)
add_dependencies(knit_all knit_${target})

set(target vtk_geometry)
add_custom_target(knit_${target}
    COMMENT "Knitting SWC model" VERBATIM
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${DOGEN_KNITTER_COMMAND}
    --target ${CMAKE_SOURCE_DIR}/diagrams/vtk.geometry.dia,neurite
    --reference ${CMAKE_SOURCE_DIR}/diagrams/geometry.dia,neurite
    --cpp-project-dir ${CMAKE_SOURCE_DIR}/projects/
    --cpp-disable-cmakelists
    --ignore-files-matching-regex .*/CMakeLists.txt
    --ignore-files-matching-regex .*/test/.*
    --ignore-files-matching-regex .*/spec/.*
    --verbose
    --delete-extra-files)
add_dependencies(knit_all knit_${target})
