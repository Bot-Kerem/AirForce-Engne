#include <Editor.h>
// int argc, char const *argv[]
int main()
{
  Editor editor{};
  editor.Run();

  editor.Terminate();
  return 0;
}
