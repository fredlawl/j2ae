#include <Game/Components/PhysicsComponent.h>

namespace J2AE
{
	sf::Vector2f PhysicsComponent::calculateNextPosition(const sf::Vector2f& currentPosition, const sf::FloatRect& objectBounds) const
	{
		return sf::Vector2f {
			currentPosition.x + (objectBounds.width * getSpeedAcceleration() * convertDirection(direction.x)),
			currentPosition.y + (objectBounds.height * getSpeedAcceleration() * convertDirection(direction.y))
		};
	}

	void PhysicsComponent::setDirection(Direction x, Direction y)
	{
		direction.x = x;
		direction.y = y;
	}

	void PhysicsComponent::setDirection(const sf::Vector2<Direction>& direction)
	{
		setDirection(direction.x, direction.y);
	}
}