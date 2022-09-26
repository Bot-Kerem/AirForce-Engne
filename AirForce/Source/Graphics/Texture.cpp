#include <Graphics/Texture.h>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <iostream>

namespace AirForce
{
  Texture::Texture()
  {
    glGenTextures(1, &m_Texture);
  }

  Texture::Texture(std::string_view Path)
  {
    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int Width, Height, nrChannels;

    unsigned char *data = stbi_load(Path.data(), &Width, &Height, &nrChannels, 4);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
      std::cout << "Path does not exists: " << Path << '\n';
    }
    stbi_image_free(data);
  } // Texture::Texture(std::string_view Path)

  Texture::~Texture()
  {
    glDeleteTextures(1 , &m_Texture);
  } // Texture::~Texture()

  void Texture::Bind()
  {
    glBindTexture(GL_TEXTURE_2D, m_Texture);
  }
} // AirForce
