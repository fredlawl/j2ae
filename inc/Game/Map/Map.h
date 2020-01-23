
#ifndef J2AE_MAP_H
#define J2AE_MAP_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace J2AE
{
	class Map : public sf::Drawable, public sf::Transformable
	{
	public:
		Map() = default;
		~Map() override = default;

		void init();
		void destroy();

		void activate();
		void deactivate();

		bool isValid() const;

		inline
		bool isActive() const
		{
			return active;
		}

		inline
		unsigned getIndexForBlockAt(unsigned x, unsigned y) const
		{
			return (mapSizeInBlocks.x * y) + x;
		}

		inline
		unsigned getIndexForBlockAt(const sf::Vector2u position) const
		{
			return getIndexForBlockAt(position.x, position.y);
		}

		inline
		void setName(const std::string& name)
		{
			this->name = name;
		}

		inline
		const std::string& getName() const
		{
			return name;
		}

		inline
		void setTileMargin(int margin)
		{
			tileMargin = margin;
		}

		inline
		int getTileMargin() const
		{
			return tileMargin;
		}

		inline
		void setTileSpacing(int spacing)
		{
			tileSpacing = spacing;
		}

		inline
		int getTileSpacing() const
		{
			return tileSpacing;
		}

		inline
		void setMapSizeInBlocks(const sf::Vector2u& size)
		{
			mapSizeInBlocks = size;
		}

		inline
		const sf::Vector2u& getMapSizeInBlocks() const
		{
			return mapSizeInBlocks;
		}

		inline
		void setTileSize(const sf::Vector2u& size)
		{
			tileSize = size;
		}

		inline
		const sf::Vector2u& getTileSize() const
		{
			return tileSize;
		}

		inline
		void setTexture(sf::Texture* texture)
		{
			this->texture = texture;
		}

		inline
		unsigned getTotalBlocksInMap() const
		{
			return mapSizeInBlocks.x * mapSizeInBlocks.y;
		}

		inline
		sf::Vector2u getMapSizeInPixels() const
		{
			return {mapSizeInBlocks.x * tileSize.x, mapSizeInBlocks.y * tileSize.y};
		}

		inline
		sf::Rect<unsigned> getBoundaries() const
		{
			const auto& size = getMapSizeInPixels();
			return {0, 0, size.x, size.y};
		}

		bool addLayer(const std::vector<int>& layer);


	private:
		bool active = false;
		std::string name;
		int tileMargin = 0;
		int tileSpacing = 0;
		sf::Vector2u mapSizeInBlocks {0, 0};
		sf::Vector2u tileSize {0, 0};
		sf::Texture* texture = nullptr;
		std::vector<sf::VertexArray> layers;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

#endif
