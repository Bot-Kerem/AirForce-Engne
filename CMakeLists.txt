cmake_minimum_required(VERSION 3.23.3)

project(Editor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Core Sources
set(AF_EDITOR_SOURCES 
    Editor//Editor.cpp
    )

add_subdirectory("AirForce")

add_executable(Editor ${AF_EDITOR_SOURCES})

target_link_libraries(Editor AirForce)

target_include_directories(AirForce PUBLIC Editor/Include/)

target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)