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
    /* the Map maps the Textures::ID enumeration to the unique ptr       *
     * each sf::Texture is loaded into the map with the corresponding ID */
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

    void LoadResource(Textures::ID id, const std::string& filename);

};
