#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

/* Class to hold the loaded textures before drawing them */

namespace Textures
{
    enum class ID { Landscape, Spaceship, Missile};
}

class TextureHolder
{

private:

    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

    void LoadResource(Textures::ID id, const std::string& filename);

    sf::Texture& GetTexture(Textures::ID id);
    sf::Texture& GetTexture(Textures::ID id) const;

};
