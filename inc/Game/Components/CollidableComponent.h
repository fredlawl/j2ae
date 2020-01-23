
#ifndef J2AE_COLLIDABLECOMPONENT_H
#define J2AE_COLLIDABLECOMPONENT_H

#include <SFML/System.hpp>
#include "Engine/Components/Component.h"

namespace J2AE
{
	class CollidableComponent : public Component
	{
	public:
		CollidableComponent() = default;
		~CollidableComponent() override = default;

		void init() override {};
		void destroy() override {};

		inline
		void setSize(const sf::Vector2f& size)
		{
			this->size = size;
			this->boundaries = sf::FloatRect(0, 0, size.x, size.y);
		}

		inline
		const sf::Vector2f& getSize() const
		{
			return size;
		}

		inline
		const sf::FloatRect& getBoundaries() const
		{
			return boundaries;
		}

		inline
		void setRadius(float radius)
		{
			this->radius = radius;
		}

		inline
		float getRadius() const
		{
			return radius;
		}

		inline
		sf::Vector2f getCenter() const
		{
			return {size.x / 2, size.y / 2};
		}

	protected:
		sf::Vector2f size {0, 0};
		sf::FloatRect boundaries {0, 0, 0, 0};
		float radius = 0;
	};

}

#endif
