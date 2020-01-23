#include <Game/Map/Systems/MapBoundaryCollisionSystem.h>
#include <Game/Map/Map.h>
#include <Engine/World/Scene.h>
#include <Engine/GameObject.h>
#include <Game/Components/CollidableComponent.h>
#include <iostream>
#include <Game/Components/SpriteComponent.h>

namespace J2AE
{
	void MapBoundaryCollisionSystem::init()
	{

	}

	void MapBoundaryCollisionSystem::destroy()
	{
		map = nullptr;
	}

	void MapBoundaryCollisionSystem::update()
	{
		if (map == nullptr)
			return;

		auto gameObjects = scene->getObjectsForSystem(getComponentLock());
		CollidableComponent* collidable = nullptr;
		SpriteComponent* sprite = nullptr;
		for (auto* object : gameObjects) {
			collidable = object->getComponent<CollidableComponent>(Component::Type::Collidable);
			sprite = object->getComponent<SpriteComponent>(Component::Type::Sprite);
			const auto& position = object->getPosition();
			const auto& mapBoundaries = map->getBoundaries();
			const auto& collidableBoundaries = collidable->getBoundaries();

			if (position.x <= mapBoundaries.left) {
				object->setPosition(mapBoundaries.left, position.y);
			}

			if ((position.x + collidableBoundaries.width) >= mapBoundaries.width) {
				object->setPosition(mapBoundaries.width - collidableBoundaries.width, position.y);
			}

			if (position.y <= mapBoundaries.top) {
				object->setPosition(position.x, mapBoundaries.top);
			}

			if ((position.y + collidableBoundaries.height) >= mapBoundaries.height) {
				object->setPosition(position.x, mapBoundaries.height - collidableBoundaries.height);
			}

			sprite->setSpritePosition(object->getPosition());
		}
	}

	void MapBoundaryCollisionSystem::receiveMessage(const Message& message)
	{
		if (message.message == "MAPLOADED") {
			map = (Map*) message.payload;
		}
	}
}
