#include <ProjectFolder.h>

#include <Builder.h>
extern Builder builder;

#include <filesystem>

Folder ProjectFolder;

std::string getFolderPath(Folder& folder);

void LoadFaF()
{
  LoadDIR(builder.Settings.ProjectPath, ProjectFolder);
  ProjectFolder.Name = builder.Settings.ProjectName;
} // void LoadFaF()

void LoadDIR(const std::string& Path, Folder& folder)
{
    for(auto& p : std::filesystem::directory_iterator(Path))
    {
        if (p.is_directory())
        {
          folder.Folders.push_back(Folder{&folder, p.path().filename()});
        }
        else
        {
          folder.Files.push_back(File{std::string(p.path().filename()), &folder});
        }
    }
    std::string FolderPath = getFolderPath(folder);
    for(auto& _folder: folder.Folders)
    {
      LoadDIR(FolderPath + "/" + _folder.Name, _folder);
    }
} // void LoadDIR(const std::string& Path, Folder& folder)

std::string getFolderPath(Folder& folder)
{
    if(folder.Parent == nullptr)
    {
      return builder.Settings.ProjectPath + "/" +  folder.Name;
    }
    return getFolderPath(*folder.Parent) + "/" + folder.Name;
} // std::string getFolderPath(Folder& folder)
