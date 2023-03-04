#include <map>

/* Class to hold the loaded textures before drawing them */

namespace Textures
{
    enum class ID { Landscape, Spaceship, Missile};
}

class TextureHolder
{
private:
    // map maps the Textures::ID enumeration to the unique ptr
    std::map<Textures::ID, std::unique_ptr<sf::Textures>> mTextureMap;
}