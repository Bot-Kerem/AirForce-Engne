#include <GUI.h>

#include <Graphics/Texture.h>
extern Icon* FileIcon;
extern Icon* FolderIcon;

namespace GUI
{
  void LoadIcons()
  {
    FileIcon = new Icon{"./../Resources/File.png"};
    FolderIcon = new Icon{"./../Resources/Folder.png"};
  } // void LoadIcons()

  void FreeIcons()
  {
    delete FileIcon;
  }
} // namespace GUI
