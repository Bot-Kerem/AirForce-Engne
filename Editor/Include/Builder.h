// project: AirForce
// created by: Bot-Kerem
// create date: 07.09.2022
// updated: 07.09.2022

#ifndef AIRFORCE_EDITOR_BUILDER_H
#define AIRFORCE_EDITOR_BUILDER_H

#include <string>

struct WindowSettings
{
  std::string Title;
};

struct Project_Settings
{
  std::string ProjectPath;
  std::string ProjectName;
  std::string Path;
  WindowSettings Window;
};


class Builder
{
  private:
    void generateSource();
  public:
    Builder();
    void Load(std::string ProjectPath);
    void Build();
    Project_Settings Settings{};
};



#endif // AIRFORCE_EDITOR_BUILDER_H
