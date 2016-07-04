cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# enable ctest support
enable_testing()

project(neurite)

# options
option(WITH_DEBUG "Build the project with debug symbols" off)
option(WITH_LATEX "Build all LaTeX documents. Requires pdflatex and beamer." off)

# add our own modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build/cmake)
# list(APPEND CMAKE_MODULE_PATH $ENV{CMAKE_EXTERNAL_MODULE_PATH})

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
    program_options
    iostreams)

if(Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif()

# cgal
find_package(CGAL 4.7 REQUIRED)

# catch
# find_package(Catch REQUIRED)

# wt
# find_package(Wt REQUIRED)

# vtk
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# qt

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
SET(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# libxml
find_package(LibXml2 REQUIRED)
if(LIBXML2_FOUND)
    include_directories(SYSTEM ${LIBXML2_INCLUDE_DIR})
    set(LIBS ${LIBS} ${LIBXML2_LIBRARY_DIR})
endif()

#
# setup git
#
find_program(GIT_COMMAND NAMES git)
if(NOT DEFINED GIT_COMMAND)
    message(FATAL_ERROR "git not found.")
endif()
message(STATUS "Found git (${GIT_COMMAND})...")

# hash of the top commit
execute_process(COMMAND ${GIT_COMMAND} rev-list -n 1 HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    ERROR_VARIABLE git_error
    OUTPUT_VARIABLE CURRENT_GIT_COMMIT
    RESULT_VARIABLE ret_var
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# commit count
execute_process(
    COMMAND ${GIT_COMMAND} rev-list master
    COMMAND wc -l
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    ERROR_VARIABLE git_error
    OUTPUT_VARIABLE GIT_COMMIT_COUNT
    RESULT_VARIABLE ret_var
    OUTPUT_STRIP_TRAILING_WHITESPACE)
string(STRIP ${GIT_COMMIT_COUNT} GIT_COMMIT_COUNT)

#
# setup dogen knitter
# set CMAKE_PROGRAM_PATH accordingly
#
find_program(DOGEN_KNITTER_COMMAND NAMES dogen.knitter)
if(NOT DEFINED DOGEN_KNITTER_COMMAND)
    message(FATAL_ERROR "dogen knitter not found.")
endif()
message(STATUS "Found dogen knitter (${DOGEN_KNITTER_COMMAND})...")

#
# setup pdflatex
#
find_program(PDFLATEX_COMMAND NAMES pdflatex)
if(NOT DEFINED PDFLATEX_COMMAND)
    message(STATUS "pdflatex not found, disabling latex documents.")
    set(WITH_LATEX "off")
else()
    message(STATUS "Found pdflatex (${PDFLATEX_COMMAND})...")
endif()

if(WITH_LATEX)
    message(STATUS "Building latex documents...")
else()
    message(STATUS "NOT building latex documents...")
endif()

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
set(NEURITE_MINOR_VERSION 9)
set(NEURITE_PATCH_VERSION 134)
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
# Top-level knitter target.
#
add_custom_target(knit_all)
add_custom_target(run_all_specs)

#
# include all sub directories
#
add_subdirectory(${CMAKE_SOURCE_DIR}/build)
add_subdirectory(${CMAKE_SOURCE_DIR}/diagrams)
add_subdirectory(${CMAKE_SOURCE_DIR}/projects)
add_subdirectory(${CMAKE_SOURCE_DIR}/doc)
