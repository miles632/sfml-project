#include "texture_holder.hpp"
#include <memory>
#include <utility>
#include <cassert>

// Takes in an identifier (key for the resource in the map) and a filename
void TextureHolder::LoadResource(Textures::ID id, const std::string& filename)
{
  // Creates a new Texture object on the heap
  std::unique_ptr<sf::Texture> texture (new sf::Texture());
  // loads the image to the texture
  if (!texture->loadFromFile(filename))
    throw std::runtime_error ("TextureHolder::load - Failed to load " + filename);

  // Inserts Texture into map
  auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
  std::move(texture);
  assert(inserted.second); // Checks for value, remove after debugging
}

// Returns a reference to a texture and dereferences the unique ptr
sf::Texture& TextureHolder::GetTexture(Textures::ID id)
{
  auto found = mTextureMap.find(id);
  assert(found != mTextureMap.end());

  return *found->second; // the "second" statement returns the value of the kv pair
}
sf::Texture& TextureHolder::GetTexture(Textures::ID id) const
{ 
  auto found = mTextureMap.find(id);
  assert(found != mTextureMap.end());

  return *found->second;
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
  void load (Identifier id, const std:;string& filename);
  Resource& get(Identifier id);

}
