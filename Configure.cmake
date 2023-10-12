execute_process(
    COMMAND git describe --tags
    OUTPUT_VARIABLE GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND git status --porcelain
    OUTPUT_VARIABLE GIT_STATUS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(MAJOR 0)
set(MINOR 0)
set(REVISION 0)
set(TAG "")
set(MODIFIED false)

if(${GIT_TAG} MATCHES "v([0-9]+)\\.([0-9]+)\\.([0-9]+)\\-(.+)")
    set(MAJOR ${CMAKE_MATCH_1})
    set(MINOR ${CMAKE_MATCH_2})
    set(REVISION ${CMAKE_MATCH_3})
    set(TAG ${CMAKE_MATCH_4})
elseif(${GIT_TAG} MATCHES "v([0-9]+)\\.([0-9]+)\\.([0-9]+)")
    set(MAJOR ${CMAKE_MATCH_1})
    set(MINOR ${CMAKE_MATCH_2})
    set(REVISION ${CMAKE_MATCH_3})
elseif(${GIT_TAG} MATCHES "v([0-9]+)\\.([0-9]+)\\-(.+)")
    set(MAJOR ${CMAKE_MATCH_1})
    set(MINOR ${CMAKE_MATCH_2})
    set(TAG ${CMAKE_MATCH_3})
elseif(${GIT_TAG} MATCHES "v([0-9]+)\\.([0-9]+)")
    set(MAJOR ${CMAKE_MATCH_1})
    set(MINOR ${CMAKE_MATCH_2})
else()
    set(TAG ${GIT_TAG})
endif()

if(NOT ${GIT_STATUS} STREQUAL "")
    set(MODIFIED true)
endif()

message(STATUS "Version detected: ${MAJOR}.${MINOR}.${REVISION}-${TAG}-${MODIFIED}")

configure_file(${C_IN} ${C_OUT} @ONLY)
