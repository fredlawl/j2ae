#include <Game/Systems/UserMovementInputSystem.h>
#include <Engine/Utility/Direction.h>
#include <SFML/Window/Keyboard.hpp>
#include <Engine/GameObject.h>
#include <Game/Components/PhysicsComponent.h>
#include <Engine/ObjectFactory.h>
#include <Engine/World/Scene.h>
#include <Game/Components/CollidableComponent.h>
#include <Game/Components/SpriteComponent.h>

namespace J2AE
{

	void UserMovementInputSystem::init()
	{

	}

	void UserMovementInputSystem::destroy()
	{

	}

	void UserMovementInputSystem::update()
	{
		sf::Vector2f nextPosition;
		float acceleration = 0;
		PhysicsComponent* physicsComponent = nullptr;
		CollidableComponent* collidableComponent = nullptr;
		SpriteComponent* spriteComponent = nullptr;
		const std::vector<GameObject*>& gameObjects = scene->getObjectsForSystem(getComponentLock());

		if (gameObjects.empty())
			return;

		Direction directionX = Direction::NONE;
		Direction directionY = Direction::NONE;

		if (
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			) {
			acceleration = 1;
		} else {
			return;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			directionX = Direction::RIGHT;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			directionX = Direction::LEFT;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			directionY = Direction::UP;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			directionY = Direction::DOWN;


		for (auto* object : gameObjects) {
			physicsComponent = object->getComponent<PhysicsComponent>(Component::Type::Physics);
			collidableComponent = object->getComponent<CollidableComponent>(Component::Type::Collidable);
			spriteComponent = object->getComponent<SpriteComponent>(Component::Type::Sprite);

			physicsComponent->setAcceleration(acceleration);
			physicsComponent->setDirection(directionX, directionY);

			nextPosition = physicsComponent->calculateNextPosition(object->getPosition(), collidableComponent->getBoundaries());

			spriteComponent->setSpritePosition(nextPosition);
			object->setPosition(nextPosition);
		}

	}
}
