// project: AirForce
// created by: Bot-Kerem
// create date: 07.09.2022
// updated: 07.09.2022

#ifndef AIRFORCE_EDITOR_BUILDER_H
#define AIRFORCE_EDITOR_BUILDER_H

#include <string_view>
#include <string>

struct WindowSettings
{
  std::string_view Title;
};

struct Project_Settings
{
  std::string_view ProjectName;
  std::string Path;
  WindowSettings Window;
};


class Builder
{
  private:
    void generateSource();
  public:
    Builder(std::string_view ProjectName);
    void Build(std::string path);
    Project_Settings Settings{};
};



#endif // AIRFORCE_EDITOR_BUILDER_H
