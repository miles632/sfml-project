#include "texture_holder.hpp"
#include <memory>
#include <utility>

// Takes in an identifier (key for the resource in the map) and a filename
void TextureHolder::LoadResource(Textures::ID id, const std::string& filename)
{
  // Creates a new Texture object on the heap
  std::unique_ptr<sf::Texture> texture (new sf::Texture());
  // loads the image to the texture
  if (!texture->loadFromFile(filename))
    throw std::runtime_error ("TextureHolder::load - Failed to load " + filename);
  // Inserts Texture into map
  mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

// Returns a reference to a texture and dereferences the unique ptr
sf::Texture& TextureHolder::GetTexture(Textures::ID id)
{
  auto found = mTextureMap.find(id);
  return *found->second; // the "second" statement returns the value of the kv pair
}
sf::Texture& TextureHolder::GetTexture(Textures::ID id) const
{ 
  auto found = mTextureMap.find(id);
  return *found->second; 
}
