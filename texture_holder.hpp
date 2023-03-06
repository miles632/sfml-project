#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

/* Class to hold the loaded textures before drawing them */

namespace Textures
{
    enum class ID {Landscape, Spaceship, Missile};
}

class TextureHolder
{
private:
    // Map where all textures managed with the uniqueptr are stored with their respective ID
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

public:
    sf::Texture& GetTexture(Textures::ID id);
    sf::Texture& GetTexture(Textures::ID id) const

    void LoadResource(Textures::ID id, const std::string& filename);
};
