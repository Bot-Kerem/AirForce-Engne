cmake_minimum_required(VERSION 3.23.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


project(glad)

set(THIRD_PARTY_GLAD_SOURCE
    "./../third_party/glad/src/glad.c"
)

set(THIRD_PARTY_GLAD_INCLUDE
    "./../third_party/glad/include"
)

add_library(glad STATIC ${THIRD_PARTY_GLAD_SOURCE})

target_include_directories(glad PUBLIC ${THIRD_PARTY_GLAD_INCLUDE})


project(AirForce)

# Core Sources
set(AF_CORE_SOURCES
    Source/Core/Game.cpp
    Source/Core/Window.cpp
    )

set(AF_GRAPHICS_SOURCES
    Source/Graphics/Renderer.cpp
    )

set(AF_INCLUDES
    ./Include
)
message("includes ${AF_INCLUDES}")

add_library(AirForce STATIC ${AF_CORE_SOURCES} ${AF_GRAPHICS_SOURCES})

if(WIN32)
    add_subdirectory("./../third_party/glfw")
    set(THIRD_PARTY_GLAD_INCLUDE ${THIRD_PARTY_GLAD_INCLUDE} ./../third_party/glfw/include)
else()
    find_package(glfw3 REQUIRED)
    message("FIND GLFW AT: ${glfw3_DIR}")
endif(WIN32)

target_link_libraries(AirForce PRIVATE glfw glad)

target_include_directories(AirForce PUBLIC ${AF_INCLUDES} ${AF_THIRD_PARTY_INCLUDES})

target_compile_options(AirForce PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
