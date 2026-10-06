cmake_minimum_required (VERSION 3.20)
project (RootFinderProject LANGUAGES CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(RootFinder)
add_subdirectory(App)