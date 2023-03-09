#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Entity
{
public:
  void SetVelocity(sf::Vector2f velocity);
  void SetVelocity(float vx, float vy);
  sf::Vector2f GetVelocity() const;

private:
  sf::Vector2f mVelocity;
};

class Aircraft : public Entity
{
public:
  enum class Type
  {
    Eagle,
    Raptor
  };
public:
  explicit Aircraft(Type type);
private:
  Type mType;

};
