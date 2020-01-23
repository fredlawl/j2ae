#include <Game/Map/Map.h>
#include <iostream>

namespace J2AE
{
	void Map::init()
	{
		activate();
	}

	void Map::destroy()
	{
		delete texture;
		texture = nullptr;
		deactivate();
	}

	void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		size_t i = 0;
		states.transform *= getTransform();
		states.texture = texture;

		for (; i < layers.size(); ++i) {
			target.draw(layers[i], states);
		}
	}

	bool Map::addLayer(const std::vector<int>& layer)
	{
		if (!isValid()) {
			return false;
		}

		if (layer.size() != getTotalBlocksInMap()) {
			return false;
		}

		sf::VertexArray verticies(sf::Quads, getTotalBlocksInMap() * 4);

		for (unsigned int i = 0; i < mapSizeInBlocks.x; ++i) {
			for (unsigned int j = 0; j < mapSizeInBlocks.y; ++j) {
				// get the current tile number
				int tileNumber = layer[i + j * mapSizeInBlocks.x];

				// find its position in the tileset texture
				int tu = (tileNumber - 1) % (texture->getSize().x / tileSize.x);
				int tv = (tileNumber - 1) / (texture->getSize().x / tileSize.x);


				// get a pointer to the current tile's quad
				sf::Vertex* quad = &verticies[(i + j * mapSizeInBlocks.x) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(
					i * tileSize.x,
					j * tileSize.y
				);

				quad[1].position = sf::Vector2f(
					(i + 1) * tileSize.x,
					j * tileSize.y
				);

				quad[2].position = sf::Vector2f(
					(i + 1) * tileSize.x,
					(j + 1) * tileSize.y
				);

				quad[3].position = sf::Vector2f(
					i * tileSize.x,
					(j + 1) * tileSize.y
				);

				if (tileNumber == 0) {
					quad[0].color = sf::Color::Transparent;
					quad[1].color = sf::Color::Transparent;
					quad[2].color = sf::Color::Transparent;
					quad[3].color = sf::Color::Transparent;
				} else {
					// define its 4 texture coordinates
					quad[0].texCoords = sf::Vector2f(
						((tu * tileSize.x) + tileMargin) + (tu * tileSpacing),
						((tv * tileSize.y) + tileMargin) + (tv * tileSpacing)
					);

					quad[1].texCoords = sf::Vector2f(
						((tu * tileSize.x) + tileMargin) + (tu * tileSpacing) + tileSize.x,
						((tv * tileSize.y) + tileMargin) + (tv * tileSpacing)
					);

					quad[2].texCoords = sf::Vector2f(
						((tu * tileSize.x) + tileMargin) + (tu * tileSpacing) + tileSize.x,
						((tv * tileSize.y) + tileMargin) + (tv * tileSpacing) + tileSize.y
					);

					quad[3].texCoords = sf::Vector2f(
						((tu * tileSize.x) + tileMargin) + (tu * tileSpacing),
						((tv * tileSize.y) + tileMargin) + (tv * tileSpacing) + tileSize.y
					);
				}
			}
		}

		layers.push_back(verticies);

		return true;
	}

	bool Map::isValid() const
	{
		return (mapSizeInBlocks.x > 0 &&
				mapSizeInBlocks.y > 0 &&
				tileSize.x > 0 &&
				tileSize.y > 0 &&
				texture != nullptr);
	}

	void Map::activate()
	{
		active = true;
	}

	void Map::deactivate()
	{
		active = false;
	}


}
