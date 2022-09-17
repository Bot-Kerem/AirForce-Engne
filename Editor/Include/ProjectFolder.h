// project: AirForce
// created by: Bot-Kerem
// create date: 17.09.2022
// updated: 17.09.2022

#ifndef AIRFORCE_EDITOR_PROJECT_FOLDER
#define AIRFORCE_EDITOR_PROJECT_FOLDER

#include <string>
#include <vector>

struct File;

struct Folder
{
  Folder* Parent = nullptr;
  std::string Name;
  std::vector<Folder> Folders{};
  std::vector<File> Files{};
};

struct File
{
  std::string Name;
  Folder* Parent = nullptr;
};

void LoadFaF(); // Load Folders And Files

void LoadDIR(const std::string& Path, Folder& folder);

#endif // AIRFORCE_EDITOR_PROJECT_FOLDER
