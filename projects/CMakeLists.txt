# compiler and linker flags
if (CMAKE_CXX_COMPILER MATCHES ".*clang")
    set(CMAKE_COMPILER_IS_CLANGXX 1)
endif ()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
    # enable as many warnings as possible
    set(warning_flags "-Wall -Wextra")

    if (CMAKE_COMPILER_IS_CLANGXX)
        # disable mismatched tags as there are STL inconsistencies that
        # make it a bit useless.
        set(warning_flags "${warning_flags} -Wno-mismatched-tags")
    endif()

    # issue all the warnings demanded by strict iso c and iso c++
    set(warning_flags "${warning_flags} -pedantic")

    # treat warnings as errors
    set(warning_flags "${warning_flags} -Werror")

    # definition shadows another
    # FIXME: causes too many problems.
    # set(warning_flags "${warning_flags} -Wshadow")

    # do not issue warnings for system headers
    set(warning_flags "${warning_flags} -Wno-system-headers")

    # overloaded virtual function has a different signature
    set(warning_flags "${warning_flags} -Woverloaded-virtual")

    # make string constants const char*
    set(warning_flags "${warning_flags} -Wwrite-strings")

    # debug flags
    if(WITH_DEBUG)
        set(optimisation_flags "-g -O0")
    else()
        set(optimisation_flags "-O3")
    endif()

    if(WITH_PROFILING)
        # enable code profiling options
        set(profiling_flags "-fprofile-arcs -ftest-coverage")

        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
            # FIXME: profiling flags appear not to be used during
            # compilation so disable the warning. bit of a hack, for now.
            set(profiling_flags "${profiling_flags} -Qunused-arguments")

            set(profiling_flags "${profiling_flags} --coverage")
            set(profiling_flags "${profiling_flags} -Xclang -coverage-cfg-checksum")
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-no-function-names-in-data")

            # 407 for gcc 4.7 compatibility of the gcov format.
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-version='407*'")
        endif()
    endif()

    # enable RTTI
    # -fvisibility=hidden
    if (WIN32)
        set(other_flags "-std=gnu++14")
    else()
        set(other_flags "-std=c++14")
    endif()
    set(other_flags "${other_flags} -frtti -fvisibility-inlines-hidden")
    set(other_flags "${other_flags} -fvisibility=default")
    set(other_flags "${other_flags} -fPIC")

    # set the flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${optimisation_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warning_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${profiling_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${other_flags}")

    # ignore fuzzy link errors
    if (WIN32)
        set(CMAKE_EXE_LINKER_FLAGS
            "${CMAKE_EXE_LINKER_FLAGS} -Wl,-enable-stdcall-fixup")
        set(CMAKE_SHARED_LINKER_FLAGS
            "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-enable-stdcall-fixup")
    endif()
endif()

# parameters for boost tests
set(boost_test_parameters "")

# user includes
include_directories(
    # third party
    ${Wt_INCLUDE_DIR}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
  
    # generated header files
    ${stage_inc_dir}/

    # real code
    # ${CMAKE_SOURCE_DIR}/projects/ohms_law/include
    ${CMAKE_SOURCE_DIR}/projects/swc/include
    ${CMAKE_SOURCE_DIR}/projects/soma/include
    ${CMAKE_SOURCE_DIR}/projects/utility/include
    )

#
# add all other projects
#
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ohms_law/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/swc)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/soma)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utility/src)
