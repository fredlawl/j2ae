#include <Game/Map/Systems/MapSystem.h>
#include <Engine/World/Scene.h>
#include <Engine/ObjectFactory.h>
#include <Game/Map/MapLoader.h>

namespace J2AE
{
	void MapSystem::init()
	{

	}

	void MapSystem::destroy()
	{
		delete map;
		map = nullptr;
	}

	void MapSystem::update()
	{
		if (map == nullptr) {
			Message mapHasLoaded;
			map = mapLoader->loadMap("../assets/maps/betamap.tmx");

			if (map == nullptr)
				return;

			scene->mapGameObjectsToSystems();

			mapHasLoaded.message = "MAPLOADED";
			mapHasLoaded.payload = map;

			scene->receiveMessage(mapHasLoaded);
		}
	}


}