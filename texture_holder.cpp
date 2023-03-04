#include "texture_holder.hpp"
#include <memory>
#include <utility>

// Takes in an identifier (key for the resource in the map) and a filename
void TextureHolder::LoadResource(Textures::ID id, const std::string& filename)
{
  std::unique_ptr<sf::Texture> texture (new sf::Texture());
  texture->loadFromFile(filename);

  mTextureMap.insert(std::make_pair(id, std::move(texture)));
}
