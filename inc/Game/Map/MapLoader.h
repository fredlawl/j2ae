
#ifndef J2AE_MAPLOADER_H
#define J2AE_MAPLOADER_H

#include <string>
#include <Engine/ObjectFactory.h>
#include <Game/Map/Map.h>
#include <pugixml.hpp>
#include <fstream>
#include <string>

namespace J2AE
{
	class MapLoader
	{
	public:
		explicit MapLoader(ObjectFactory& objectFactory) :
			objectFactory(objectFactory)
		{

		}

		~MapLoader() = default;

		Map* loadMap(const std::string& filePath);

	private:
		ObjectFactory& objectFactory;
		Map* map = nullptr;

		bool loadMapProperties(const pugi::xml_node& root);
		bool loadTexture(const pugi::xml_node& root);
		bool loadLayers(const pugi::xml_node& root);
		bool loadObjects(const pugi::xml_node& root);
	};
}

#endif
