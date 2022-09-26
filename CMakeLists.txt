cmake_minimum_required(VERSION 3.23.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


add_subdirectory("AirForce")


set(THIRD_PARTY_IMGUI_SOURCES
"./third_party/imgui/imgui.cpp"
  "./third_party/imgui/imgui_demo.cpp"
  "./third_party/imgui/imgui_draw.cpp"
  "./third_party/imgui/imgui_tables.cpp"
  "./third_party/imgui/imgui_widgets.cpp"
  "./third_party/imgui/misc/cpp/imgui_stdlib.cpp"
  "./third_party/imgui/backends/imgui_impl_glfw.cpp"
  "./third_party/imgui/backends/imgui_impl_opengl3.cpp"
)

add_library(imgui STATIC ${THIRD_PARTY_IMGUI_SOURCES})

set(THIRD_PARTY_IMGUI_INCLUDES
    "./third_party/imgui"
    "./third_party/imgui/backends"
    "./third_party/imgui/misc/cpp/"
)

target_include_directories(imgui PUBLIC ${THIRD_PARTY_IMGUI_INCLUDES})

project(Editor)

# Core Sources
set(AF_EDITOR_SOURCES
    Editor/Main.cpp
    Editor/Source/Editor.cpp
    Editor/Source/Builder.cpp
    Editor/Source/Platform.cpp
    Editor/Source/ProjectFolder.cpp

    # GUI Elements
    Editor/Source/GUI/DockSpace.cpp
    Editor/Source/GUI/MenuBar.cpp
    Editor/Source/GUI/ProjectSettings.cpp
    Editor/Source/GUI/ProjectExplorer.cpp
    Editor/Source/GUI/SceneEditor.cpp
    Editor/Source/GUI/SceneEdit.cpp

    Editor/Source/GUI/GUI.cpp
    Editor/Source/GUI/LoadGUI.cpp
    )

add_executable(Editor ${AF_EDITOR_SOURCES})

target_link_libraries(Editor imgui AirForce)

target_include_directories(AirForce PUBLIC ./Editor/Include)

target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
