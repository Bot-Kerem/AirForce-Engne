// project: AirForce
// created by: Bot-Kerem
// create date: 18.09.2022
// updated: 18.09.2022

#ifndef AIRFORCE_GRAPHICS_TEXTURE
#define AIRFORCE_GRAPHICS_TEXTURE

#include <string_view>

namespace AirForce
{
  class Texture
  {
    private:
      unsigned int m_Texture{0};

    public:
      Texture(std::string_view Path);
      Texture();
      ~Texture();

    inline unsigned int GetTexture() const{return m_Texture;}

      void Bind();
  }; // class Texture
} // AirForce

typedef AirForce::Texture Icon;

#endif // AIRFORCE_GRAPHICS_TEXTURE
