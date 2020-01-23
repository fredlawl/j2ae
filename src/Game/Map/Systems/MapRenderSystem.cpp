#include <Game/Map/Systems/MapRenderSystem.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Engine/World/Scene.h>
#include <Game/Map/Map.h>

namespace J2AE
{
	void J2AE::MapRenderSystem::init()
	{

	}

	void MapRenderSystem::destroy()
	{
		map = nullptr;
	}

	void MapRenderSystem::update()
	{
		sf::RenderTarget* target = scene->getRenderTarget();
		if (map != nullptr) {
			target->draw(*map);
		}
	}

	void MapRenderSystem::receiveMessage(const Message& message)
	{
		if (message.message == "MAPLOADED") {
			map = (Map*) message.payload;
		}
	}
}
