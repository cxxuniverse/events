cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(
    CXC_EVENTS
    VERSION 0.1
    DESCRIPTION "Event Listener"
    LANGUAGES CXX
)

include_directories(include)

add_library(events STATIC src/events.cpp)
target_include_directories(events PRIVATE include)
set_target_properties(events PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(main src/main.cpp)
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

target_link_libraries(main events)
target_compile_features(main PRIVATE cxx_std_20)
target_compile_options(main PRIVATE -g -Wall)