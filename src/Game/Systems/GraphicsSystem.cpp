#include <Game/Systems/GraphicsSystem.h>
#include <Engine/GameObject.h>
#include <Game/Components/SpriteComponent.h>
#include <Engine/World/Scene.h>
#include <Engine/ObjectFactory.h>
#include <iostream>


namespace J2AE
{
	void GraphicsSystem::init()
	{

	}

	void GraphicsSystem::destroy()
	{

	}

	void GraphicsSystem::update()
	{
		sf::RenderTarget* target = scene->getRenderTarget();
		const std::vector<GameObject*>& gameObjects = scene->getObjectsForSystem(getComponentLock());

		if (gameObjects.empty())
			return;

		SpriteComponent* component = nullptr;
		for (const auto* object : gameObjects) {
			component = object->getComponent<SpriteComponent>(Component::Type::Sprite);
			target->draw(*component->getSprite());
		}
	}
}