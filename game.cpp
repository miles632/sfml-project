#include "helper_functions.hpp"
#include "game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Game::Game()

   :mWindow(sf::VideoMode(800, 600), "SFML APPLICATION")
    ,mPlayer()
    ,mTexture()
{
    std::string currentDir = GetCurrentDirectory();
    if (!mTexture.loadFromFile(currentDir + "/spaceship.png"))
        std::cerr << "Error Loading sprite" << std::endl;
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setScale(2.0f, 2.0f);
}

/* Checks for key presses */
void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
     }
 }

// Only public function
void Game::run()
{
    sf::Time timeSinceLastUpdate = sf::Time::Zero;    
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    sf::Clock clock;

    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

/* Updates position of mPlayer object based on key presses,
 * speed can be changed in the PlayerSpeed float, 
 * It works by multiplying the vector with the time that has passed
 * since the last frame was drawn */
void Game::update(sf::Time deltaTime)
{
    const float playerSpeed = 300;
    sf::Vector2f movement (0.f, 0.f);

    if (mIsMovingUp)
        movement.y -= playerSpeed;
    if (mIsMovingDown)
        movement.y += playerSpeed;
    if (mIsMovingRight)
        movement.x += playerSpeed;
    if (mIsMovingLeft)
        movement.x -= playerSpeed;
    
    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

/* Handles Input for key presses */
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W) 
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
}

