#include <SFML/Graphics.hpp>
#include "texture_holder.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <stdexcept>

int main()
{
  sf::RenderWindow window (sf::VideoMode(1280,1080), "Resources");
  window.setFramerateLimit(60);

  TextureHolder textures;
  try
  {
    textures.LoadResource(Textures::ID::Spaceship, "~/Projects/smfl-project-c2/Spaceship.png");
    textures.LoadResource(Textures::ID::Landscape, "~/Projects/smfl-project-c2/Space.png");
    textures.LoadResource(Textures::ID::Missile, "~/Projects/smfl-project-c2/Missile.png");
  }
  catch (std::runtime_error& e)
  {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  // Access resources
  sf::Sprite landscape(textures.GetTexture(Textures::ID::Landscape));
  sf::Sprite spaceship(textures.GetTexture(Textures::ID::Spaceship));
  sf::Sprite missile(textures.GetTexture(Textures::ID::Missile));

  while (window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed || event.type == sf::Event::Closed)
        return 0;
    }
  }
}
