#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
public:

    Game();
    void run();

private:
    void processEvents(); // handles user input
    void update(sf::Time deltaTime);        // updates game logic
    void render();        // just draws already existing shit to the screen
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;

    bool mIsMovingLeft;
    bool mIsMovingRight;
    bool mIsMovingUp;
    bool mIsMovingDown;
};
