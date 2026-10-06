add_library (RootFinder SHARED src/RootFinder.cpp)

target_include_directories (RootFinder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features (RootFinder PUBLIC cxx_std_20)

# ЕКСПОРТ лише при збірці самої бібліотеки (PRIVATE).
target_compile_definitions (RootFinder PRIVATE ROOTFINDER_EXPORTS)

# Правила формування SDK
install (TARGETS RootFinder
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
install (FILES include/RootFinder.h DESTINATION include)