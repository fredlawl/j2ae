
#ifndef J2AE_MAPSYSTEM_H
#define J2AE_MAPSYSTEM_H

#include <vector>
#include <unordered_map>
#include <string>
#include <SFML/Graphics/View.hpp>
#include <Engine/GameObject.h>
#include <Engine/World/Tile.h>
#include <SFML/Graphics/Texture.hpp>
#include <Engine/Systems/System.h>
#include <SFML/Graphics/Sprite.hpp>
#include <Game/Map/Map.h>

namespace J2AE
{
	class MapLoader;

	class MapSystem : public System
	{
	public:

		explicit MapSystem(MapLoader* mapLoader) :
			mapLoader(mapLoader)
		{

		}

		~MapSystem() override = default;

		void init() override;
		void destroy() override;
		void update() override;

		size_t getComponentLock() override
		{
			return (1 << (size_t) Component::Type::NumberOfComponents);
		}

	private:
		Map* map = nullptr;
		MapLoader* mapLoader = nullptr;

	};
}

#endif
