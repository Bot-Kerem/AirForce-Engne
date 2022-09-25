#include <GUI.h>

#include <Graphics/Texture.h>
extern Icon* FileIcon;
extern Icon* FolderIcon;
extern Icon* ParentFolderIcon;

namespace GUI
{
  void LoadIcons()
  {
    FileIcon = new Icon{"./../Resources/File.png"};
    FolderIcon = new Icon{"./../Resources/Folder.png"};
    ParentFolderIcon = new Icon{"./../Resources/ParentFolder.png"};
  } // void LoadIcons()

  void FreeIcons()
  {
    delete FileIcon;
    delete FolderIcon;
    delete ParentFolderIcon;
  }
} // namespace GUI
