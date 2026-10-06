add_executable (MyApplication main.cpp)

# Подключаем библиотеку
target_include_directories (MyApplication PRIVATE ../RootFinder/include)
target_link_libraries (MyApplication PRIVATE RootFinder)

# Подключаем БИБЛИОТЕКУ НАПАРНИКА (SDK)
target_include_directories (MyApplication PRIVATE ../FunctionAnalysis_SDK/include)
target_link_directories (MyApplication PRIVATE ../FunctionAnalysis_SDK/lib)
target_link_libraries (MyApplication PRIVATE FunctionAnalysis)