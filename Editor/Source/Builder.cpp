#include <Builder.h>
#include <Platform.h>

#include <ProjectFolder.h>
extern Folder ProjectFolder;

#include <fstream>
#include <iostream>
#include <tuple>
#include <string_view>

// TODO: ADD TO REGEX
auto Split(std::string_view str, char seperator)
{
  std::string s1{}, s2{};
  for(size_t i = 0; i < str.size(); i++)
  {
    if(str[i] == seperator)
    {
      s2 = std::string{&(str[i+1])};
      break;
    }
    s1 += str[i];
  }
  return std::tuple(s1, s2);
}

Builder::Builder()
{
}

void Builder::Load(std::string ProjectPath)
{
  if(ProjectPath.empty())
  {
    OpenFolderDialog(Settings["path"]);
    Settings["path"].pop_back();
  }
  else
  {
    Settings["path"] = ProjectPath;
  }
  LoadCache();
}

void Builder::generateSource()
{
  std::ofstream Project_SOURCE(Settings["path"] + "/Game.cpp");

  Project_SOURCE << "#include <iostream>\n";
  Project_SOURCE << "int main(){std::cout << \"Hello World\n\";return 0;}\n";

  Project_SOURCE.close();
}

void Builder::Build()
{
  generateSource();
  std::ofstream Project_CMAKE(Settings["path"] + "/CMakeLists.txt");

  Project_CMAKE << "cmake_minimum_required(VERSION 3.23.3)\n";
  Project_CMAKE << "add_subdirectory(./../../ AirForce)\n";
  Project_CMAKE << "project(" << Settings["ProjectName"] << ")\n";
  Project_CMAKE << "set(PROJECT_SOURCES Game.cpp)\n";
  Project_CMAKE << "add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})\n";
  Project_CMAKE << "target_link_libraries(${PROJECT_NAME} AirForce)\n";

  Project_CMAKE.close();
}

void Builder::LoadCache()
{
  std::ifstream file(Settings["path"] + "/.proj");
    if(!file.is_open()){
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
      if(line[0] == '~')
      {
        continue;
      }
      auto [key, val] = Split(line, ':');
      Settings[key] = val;
    }
    file.close();

}