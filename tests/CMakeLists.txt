set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY ${BINARY}_lib)
set(TEST ${BINARY}_Test)

file(GLOB_RECURSE TEST_SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/tests "*.cpp")

add_executable(${TEST} ${TEST_SOURCES})

target_link_libraries(${TEST} PRIVATE gtest_main ${LIBRARY})

target_include_directories(${TEST} PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_test(NAME ${TEST} COMMAND ${TEST})