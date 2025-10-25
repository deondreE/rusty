cmake_minimum_required(VERSION 3.22)
project(cpu_profiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(profiler
    src/ProfilerRegistry.cpp
        include/profiler/FixedString.hpp
        include/profiler/ProfileScope.hpp
)
target_include_directories(profiler PUBLIC include)

add_executable(profiler_example examples/main.cpp)
target_link_libraries(profiler_example PRIVATE profiler)