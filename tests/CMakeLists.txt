set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY ${BINARY}_lib)
set(TEST ${BINARY}_Test)

# Collect all the test source files
file(GLOB_RECURSE TEST_SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/tests "*.cpp")

# Add your test executable
add_executable(${TEST} ${TEST_SOURCES})

# Link your test executable against the main library and Google Test
target_link_libraries(${TEST} PRIVATE gtest_main src)

# Include the Google Test headers
target_include_directories(${TEST} PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add tests to the project
add_test(NAME ${TEST} COMMAND ${TEST}
)