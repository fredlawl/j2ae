
#ifndef J2AE_TILE_H
#define J2AE_TILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

namespace J2AE
{
	class Tile : public sf::Drawable
	{
	public:

		Tile()
		{
			sf::Vector2f size;
			size.x = size.y = 16;
			shape.setOutlineColor(sf::Color::Red);
			shape.setOutlineThickness(1.0);
			shape.setSize(size);
			shape.setFillColor(sf::Color::Transparent);
		}

		~Tile() {}

		inline
		void setSlot(int x, int y)
		{
			slotX = x;
			slotY = y;
			shape.setPosition(x * 16, y * 16);
		}


		void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const
		{
			target.draw(shape);
		}

	private:
		int slotX = 0;
		int slotY = 0;
		sf::RectangleShape shape;
	};
}

#endif
