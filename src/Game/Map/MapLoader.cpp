#include <Game/Map/MapLoader.h>
#include <iostream>
#include <Engine/GameObject.h>

namespace J2AE
{
	Map* MapLoader::loadMap(const std::string& filePath)
	{
		bool mapFailedToLoad = false;
		map = new Map();

		pugi::xml_document mapDocument;
		std::ifstream stream(filePath);
		pugi::xml_parse_result result = mapDocument.load(stream);

		if (result.status != pugi::xml_parse_status::status_ok) {
			std::cerr << "Loading of map filed." << std::endl;
			mapFailedToLoad = true;
		}

		const pugi::xml_node& mapNode = mapDocument.first_child();
		mapFailedToLoad = !mapFailedToLoad && !loadMapProperties(mapNode);
		mapFailedToLoad = !mapFailedToLoad && !loadTexture(mapNode);
		mapFailedToLoad = !mapFailedToLoad && !loadLayers(mapNode);
		mapFailedToLoad = !mapFailedToLoad && !loadObjects(mapNode);

		stream.close();

		if (mapFailedToLoad) {
			std::cerr << "The map \"" << filePath << "\" did not load." << std::endl;
			delete map;
			map = nullptr;
			return nullptr;
		}

		objectFactory.createGameObject("Player");

		map->init();

		return map;
	}

	bool MapLoader::loadTexture(const pugi::xml_node& root)
	{
		unsigned tileWidth, tileHeight;
		int spacing, margin;
		std::string textureFilePath;

		auto* texture = new sf::Texture();
		const auto& tileset = root.first_element_by_path("tileset");
		const auto& image = tileset.first_child();

		tileWidth = static_cast<unsigned int>(std::stoul(tileset.attribute("tilewidth").value()));
		tileHeight = static_cast<unsigned int>(std::stoul(tileset.attribute("tileheight").value()));
		spacing = std::stoi(tileset.attribute("spacing").value());
		margin = std::stoi(tileset.attribute("margin").value());
		textureFilePath = image.attribute("source").value();

		if (!texture->loadFromFile(textureFilePath)) {
			delete texture;
			return false;
		}

		map->setTexture(texture);
		map->setTileSize({tileWidth, tileHeight});
		map->setTileSpacing(spacing);
		map->setTileMargin(margin);

		 return true;
	}

	bool MapLoader::loadMapProperties(const pugi::xml_node& root)
	{
		unsigned width, height;

		width = static_cast<unsigned int>(std::stoul(root.attribute("width").value()));
		height = static_cast<unsigned int>(std::stoul(root.attribute("height").value()));

		map->setMapSizeInBlocks({width, height});

		return true;
	}

	bool MapLoader::loadLayers(const pugi::xml_node& root)
	{
		int tileNumber;
		std::vector<int> layerData;
		auto layers = root.children("layer");

		for (auto& layer : layers) {
			const auto& tiles = layer.first_child().children();

			for (auto& tile : tiles) {
				tileNumber = std::stoi(tile.attribute("gid").value());
				layerData.push_back(tileNumber);
			}

			map->addLayer(layerData);
			layerData.clear();
		}

		return true;
	}

	bool MapLoader::loadObjects(const pugi::xml_node& root)
	{
		const auto& objectGroups = root.children("objectgroup");
		std::string objectName;
		std::string objectType;
		GameObject* entity = nullptr;

		for (auto& group : objectGroups) {
			const auto& objects = group.children();
			for (auto& object : objects) {
				objectName = object.attribute("name").value();
				objectType = object.attribute("type").value();
				entity = objectFactory.createGameObject(objectType);
				entity->setPosition(
					std::stof(object.attribute("x").value()),
					std::stof(object.attribute("y").value())
				);
			}
		}


		return true;
	}
}
