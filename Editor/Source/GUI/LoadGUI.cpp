#include <GUI.h>

#include <Graphics/Texture.h>
extern Icon* FileIcon;

namespace GUI
{
  void LoadIcons()
  {
    FileIcon = new Icon{"./../Resources/File.jpg"};
  } // void LoadIcons()

  void FreeIcons()
  {
    delete FileIcon;
  }
} // namespace GUI
