set(ohms_law_files "")
file(GLOB_RECURSE ohms_law_files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(ohms_law ${ohms_law_files})
set(binary_name "neurite_ohms_law")
set_target_properties(ohms_law PROPERTIES OUTPUT_NAME ${binary_name})

target_link_libraries(ohms_law
    ${Wt_LIBRARY}
    ${Wt_HTTP_LIBRARY}
    ${Wt_EXT_LIBRARY}
    ${Boost_LIBRARIES})

install(TARGETS ohms_law RUNTIME DESTINATION bin COMPONENT applications)

add_custom_target(run_ohms_law
    COMMAND ./neurite_ohms_law --docroot . --http-address 0.0.0.0 --http-port 8080
    WORKING_DIRECTORY ${stage_bin_dir}
    DEPENDS ohms_law)
