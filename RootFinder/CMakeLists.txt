add_library (RootFinder STATIC src/RootFinder.cpp)
target_include_directories (RootFinder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features (RootFinder PUBLIC cxx_std_20)
target_compile_definitions (RootFinder PUBLIC ROOTFINDER_STATIC)