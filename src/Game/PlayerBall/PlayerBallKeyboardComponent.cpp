#include <Game/PlayerBall/PlayerBallKeyboardComponent.h>
#include <SFML/Window/Keyboard.hpp>
#include <Engine/GameObject.h>

namespace J2AE
{
	void PlayerBallKeyboardComponent::init()
	{

	}

	void PlayerBallKeyboardComponent::update(GameObject& gameObject, PhysicsComponent& physicsComponent)
	{
		Direction directionX = Direction::NONE;
		Direction directionY = Direction::NONE;

		if (
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		) {
			physicsComponent.setAcceleration(1);
		} else {
			physicsComponent.setAcceleration(0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			directionX = Direction::RIGHT;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			directionX = Direction::LEFT;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			directionY = Direction::UP;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			directionY = Direction::DOWN;

		physicsComponent.setDirection(directionX, directionY);
	}
}
