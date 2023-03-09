#include "entity.hpp"
#include <SFML/System/Vector2.hpp>

void Entity::SetVelocity(sf::Vector2f velocity)
{
  mVelocity = velocity;
}
void Entity::SetVelocity(float vx, float vy)
{
  mVelocity.x = vx;
  mVelocity.y = vy;
}

sf::Vector2f Entity::GetVelocity() const
{
  return mVelocity;
}

// constructor
// the mtype will be set to type during construction
Aircraft::Aircraft(Type type) : mType(type)
{

}
