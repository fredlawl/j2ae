#include <Game/PlayerBall/PlayerBallPhysics.h>
#include <Engine/GameObject.h>
#include <iostream>
#include <cmath>

namespace J2AE
{
	PlayerBallPhysics::PlayerBallPhysics()
	{

	}

	void PlayerBallPhysics::init()
	{
		PhysicsComponent::init();
		speed = 0.3;
	}

	// todo: the "world" needs to be of type map to get correct boundaries...
	void PlayerBallPhysics::update(GameObject& gameObject, const MapSystem& map)
	{
		float width = 16;
		float height = 16;
		auto position = gameObject.getPosition();
		float x = position.x;
		float y = position.y;

		const sf::Rect<unsigned>& mapBoundaries = map.getBoundaries();

		x += (int) calculateNextXPosition(width);
		y += (int) calculateNextYPosition(height);

		if ((x + width) >= mapBoundaries.width)
			x = mapBoundaries.width - width;

		if (x <= mapBoundaries.left)
			x = mapBoundaries.left;

		if ((y + height) >= mapBoundaries.height)
			y = mapBoundaries.height - height;

		if (y <= mapBoundaries.top)
			y = mapBoundaries.top;

		gameObject.setPosition(x, y);
	}

}
