cmake_minimum_required(VERSION 3.23.3)

project(AirForce)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Core Sources
set(AF_CORE_SOURCES 
    Source/Core/Game.cpp
    )

add_library(AirForce STATIC ${AF_CORE_SOURCES})

target_include_directories(AirForce PUBLIC Include)

target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)