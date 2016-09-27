# -*- mode: cmake; cmake-tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2015-2016 Marco Craveiro <marco.craveiro@gmail.com>
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
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# enable ctest support
enable_testing()

project(neurite)

# options
option(WITH_DEBUG "Build the project with debug symbols" off)
option(WITH_UI "Build the user interface. Requires VTK and Qt" on)
option(WITH_CODEGEN "Build the user interface. Requires VTK and Qt" on)
option(WITH_LATEX "Build LaTeX documents. Requires pdflatex and beamer." off)

# add our own modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build/cmake)

# threads
find_package(Threads REQUIRED)

# boost
add_definitions(-DBOOST_ALL_DYN_LINK)
find_package(Boost 1.59 REQUIRED COMPONENTS
    system
    exception
    serialization
    thread
    log
    filesystem
    program_options)

if(Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif()

# cgal
find_package(CGAL 4.7 REQUIRED)

# libxml
find_package(LibXml2 REQUIRED)
if(LIBXML2_FOUND)
    include_directories(SYSTEM ${LIBXML2_INCLUDE_DIR})
    set(LIBS ${LIBS} ${LIBXML2_LIBRARY_DIR})
endif()

if(WITH_UI)
    # note: we find the UI packages quietly to avoid noise on the
    # build machine.

    # vtk
    find_package(VTK QUIET)
    if(VTK_FOUND)
        message("Found VTK. Version:" ${VTK_VERSION}. VTK_DIR: ${VTK_DIR})
        include(${VTK_USE_FILE})
    else()
        message(STATUS "VTK not found.")
        set(WITH_UI off)
    endif()

    # qt
    find_package(Qt5Core QUIET)
    if(Qt5Core_FOUND)
        # Find includes in corresponding build directories
        set(CMAKE_INCLUDE_CURRENT_DIR ON)

        # Instruct CMake to run moc automatically when needed.
        SET(CMAKE_AUTOUIC ON)
        set(CMAKE_AUTOMOC ON)

        find_package(Qt5Gui REQUIRED)
        find_package(Qt5Widgets REQUIRED)
    else()
        message(STATUS "Qt not found.")
    endif()
endif()

if(WITH_UI)
    message(STATUS "Building UI...")
else()
    message(STATUS "NOT Building UI...")
endif()

#
# setup git
#
find_program(GIT_COMMAND NAMES git)
if(GIT_COMMAND)
    message(STATUS "Found git (${GIT_COMMAND})...")
else()
    message(FATAL_ERROR "git not found.")
endif()

# hash of the top commit
execute_process(COMMAND ${GIT_COMMAND} rev-list -n 1 HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    ERROR_VARIABLE git_error
    OUTPUT_VARIABLE CURRENT_GIT_COMMIT
    RESULT_VARIABLE ret_var
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# commit count
execute_process(
    COMMAND ${GIT_COMMAND} rev-list --count HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    ERROR_VARIABLE git_error
    OUTPUT_VARIABLE GIT_COMMIT_COUNT
    RESULT_VARIABLE ret_var
    OUTPUT_STRIP_TRAILING_WHITESPACE)

#
# setup dogen knitter
# set CMAKE_PROGRAM_PATH accordingly
#
find_program(DOGEN_KNITTER_COMMAND NAMES dogen.knitter)
if(DOGEN_KNITTER_COMMAND)
    execute_process(
        COMMAND ${DOGEN_KNITTER_COMMAND} --version
        COMMAND grep ^Dogen
        COMMAND cut -b15-
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        ERROR_VARIABLE git_error
        OUTPUT_VARIABLE DOGEN_KNITTER_VERSION
        RESULT_VARIABLE ret_var
        OUTPUT_STRIP_TRAILING_WHITESPACE)

      set(knitter "${DOGEN_KNITTER_VERSION} (${DOGEN_KNITTER_COMMAND})")
      message(STATUS "Found dogen knitter: ${knitter}...")
else()
    set(WITH_CODEGEN off)
    message(STATUS "Dogen Knitter not found, code generation disabled.")
endif()

#
# setup pdflatex
#
if(WITH_LATEX)
    find_program(PDFLATEX_COMMAND NAMES pdflatex)
    if(PDFLATEX_COMMAND)
        message(STATUS "Found pdflatex (${PDFLATEX_COMMAND})...")
        message(STATUS "Building latex documents.")
    else()
        message(STATUS "pdflatex not found, disabling latex documents.")
        set(WITH_LATEX "off")
    endif()
endif()

## Link libraries
find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

#
# useful vars
#
# staging directory
set(stage_dir ${CMAKE_BINARY_DIR}/stage)
set(stage_bin_dir ${stage_dir}/bin)
set(stage_pkg_dir ${stage_dir}/pkg)
set(stage_lib_dir ${stage_dir}/lib)
set(stage_inc_dir ${stage_dir}/include)
set(stage_test_data_dir ${stage_dir}/test_data)
set(stage_doc_dir ${stage_dir}/doc)
set(stage_doxygen_dir ${stage_dir}/doxygen)

# ensure cmake dumps binaries in the right places
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${stage_bin_dir})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${stage_bin_dir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${stage_bin_dir})

# version info
set(NEURITE_MAJOR_VERSION 0)
set(NEURITE_MINOR_VERSION 11)
set(NEURITE_PATCH_VERSION ${GIT_COMMIT_COUNT})
set(NEURITE_VERSION "${NEURITE_MAJOR_VERSION}")
set(NEURITE_VERSION "${NEURITE_VERSION}.${NEURITE_MINOR_VERSION}")
set(NEURITE_VERSION "${NEURITE_VERSION}.${NEURITE_PATCH_VERSION}")

if(WITH_DEBUG)
    message(STATUS "Building WITH DEBUG symbols...")
    set(NEURITE_VERSION "${NEURITE_VERSION}d")
else()
    message(STATUS "Building WITHOUT DEBUG symbols...")
endif()
message(STATUS "Product version: ${NEURITE_VERSION}")

#
# Top-level knitter targets.
#
add_custom_target(run_all_specs)
if(WITH_CODEGEN)
    add_custom_target(knit_all)
endif()

#
# include all sub directories
#
add_subdirectory(${CMAKE_SOURCE_DIR}/build)
add_subdirectory(${CMAKE_SOURCE_DIR}/diagrams)
add_subdirectory(${CMAKE_SOURCE_DIR}/projects)
add_subdirectory(${CMAKE_SOURCE_DIR}/doc)
