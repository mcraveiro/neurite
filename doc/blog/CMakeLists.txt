if (WITH_LATEX)
    if(NOT IS_DIRECTORY ${stage_doc_dir})
        file(MAKE_DIRECTORY ${stage_doc_dir})
    endif()

    set(blog_dir ${stage_doc_dir}/blog)
    if(NOT IS_DIRECTORY ${blog_dir})
        file(MAKE_DIRECTORY ${blog_dir})
    endif()
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images DESTINATION ${blog_dir}/)
endif()
