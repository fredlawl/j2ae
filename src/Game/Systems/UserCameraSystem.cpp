#include <Game/Systems/UserCameraSystem.h>
#include <Engine/GameObject.h>
#include <Engine/World/Scene.h>
#include <Engine/ObjectFactory.h>

namespace J2AE
{

	void UserCameraSystem::init()
	{
		view = new sf::View;
		view->setSize(scene->getRenderTarget()->getSize().x, scene->getRenderTarget()->getSize().y);
		view->setViewport(sf::FloatRect(0, 0, 1, 1));
		view->zoom(.2);
		scene->getRenderTarget()->setView(*view);
	}

	void UserCameraSystem::destroy()
	{
		delete view;
	}

	void UserCameraSystem::update()
	{
		sf::RenderTarget* target = scene->getRenderTarget();
		if (player == nullptr) {
			auto gameObjects = scene->getObjectsForSystem(getComponentLock());
			for (auto* object : gameObjects) {
				if (object->hasComponent(Component::Type::PlayerControl)) {
					player = object;
					break;
				}
			}
		}

		if (player == nullptr)
			return;

		// Assume this is player for now...
		float x = player->getPosition().x;
		float y = player->getPosition().y;
		sf::Vector2f viewCenter {x, y};

		view->setCenter(viewCenter);
		target->setView(*view);
	}

}
