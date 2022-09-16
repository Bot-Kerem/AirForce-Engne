#include <Builder.h>
#include <fstream>

#include <Platform.h>

Builder::Builder()
{
}

void Builder::Load(std::string ProjectPath)
{
  if(ProjectPath.empty())
  {
     OpenFolderDialog(Settings.ProjectPath);
  }
  else
  {
    Settings.ProjectPath = ProjectPath;
  }
}

void Builder::generateSource()
{
  std::ofstream Project_SOURCE(Settings.Path + "/Game.cpp");

  Project_SOURCE << "#include <iostream>\n";
  Project_SOURCE << "int main(){std::cout << \"Hello World\n\";return 0;}\n";

  Project_SOURCE.close();
}

void Builder::Build()
{
  generateSource();
  std::ofstream Project_CMAKE(Settings.Path + "/CMakeLists.txt");

  Project_CMAKE << "cmake_minimum_required(VERSION 3.23.3)\n";
  Project_CMAKE << "add_subdirectory(./../../ AirForce)\n";
  Project_CMAKE << "project(" << Settings.ProjectName << ")\n";
  Project_CMAKE << "set(PROJECT_SOURCES Game.cpp)\n";
  Project_CMAKE << "add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})\n";
  Project_CMAKE << "target_link_libraries(${PROJECT_NAME} AirForce)\n";

  Project_CMAKE.close();
}
