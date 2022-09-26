#include <Core/Platform.h>

#include <Core/Types.h>

#include <fstream>
#include <stdio.h>

void AirForce::Debug(const char* log, int color)
{
  printf("\033[1;%im[DEBUG] \033[0m%s\n", color, log);
}

void OpenFolderDialog(std::string& Path)
{
  #ifdef __unix__
    char name[1024];
    FILE *file = popen("zenity --file-selection --directory", "r");
    fgets(name, 1024, file);
    Path = std::string(name);
  #endif
} // void OpenFolderDialog(std::string& Path)

std::string OpenFile(std::string& Path)
{
  std::fstream File(Path);
  if(!File.is_open())
  {
    AirForce::Debug(std::string("::[SHADER] File Does not exists: " + Path).c_str(), ERROR);
    return "";
  }
  return std::string((std::istreambuf_iterator<char>(File)), std::istreambuf_iterator<char>());
}
