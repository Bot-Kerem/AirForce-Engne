#include <Platform.h>

void OpenFolderDialog(std::string& Path)
{
  #ifdef __unix__
    char name[1024];
    FILE *file = popen("zenity --file-selection --directory", "r");
    fgets(name, 1024, file);
    Path = std::string(name);
  #endif
} // void OpenFolderDialog(std::string& Path)
