// project: AirForce
// created by: Bot-Kerem
// create date: 07.09.2022
// updated: 07.09.2022

#ifndef AIRFORCE_EDITOR_BUILDER_H
#define AIRFORCE_EDITOR_BUILDER_H

#include <string>
#include <map>

class Builder
{
  private:
    void generateSource();
  public:
    Builder();
    void Load(std::string ProjectPath);
    void Build();
    void LoadCache();
    std::map<std::string, std::string> Settings{};
};



#endif // AIRFORCE_EDITOR_BUILDER_H
