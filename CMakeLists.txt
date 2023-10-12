cmake_minimum_required(VERSION 3.22)

project(jg-headers CXX)

add_library(jg-headers INTERFACE)
target_include_directories(jg-headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
add_library(jg::headers ALIAS jg-headers)

add_custom_target(jg-source_version_source
    COMMAND ${CMAKE_COMMAND}
    -D C_IN=${CMAKE_CURRENT_LIST_DIR}/source_version.in.cpp -D C_OUT=${CMAKE_CURRENT_BINARY_DIR}/source_version.cpp
    -P ${CMAKE_CURRENT_LIST_DIR}/Configure.cmake
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/source_version.cpp
)

add_library(jg-source_version OBJECT)
target_sources(jg-source_version PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/source_version.cpp
)
target_include_directories(jg-source_version PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(jg-source_version PUBLIC jg::headers)
add_dependencies(jg-source_version jg-source_version_source)
add_library(jg::source_version ALIAS jg-source_version)
