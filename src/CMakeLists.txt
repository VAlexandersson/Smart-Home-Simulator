set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY ${BINARY}_lib)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/src "*.cpp")

add_library(${LIBRARY} ${SOURCES})

target_include_directories(${LIBRARY} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE ${LIBRARY})