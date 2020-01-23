
#ifndef J2AE_PHYSICSCOMPONENT_H
#define J2AE_PHYSICSCOMPONENT_H

#include <Engine/Components/Component.h>
#include <SFML/Graphics/View.hpp>
#include <Engine/Utility/Direction.h>
#include <SFML/Graphics/RenderTarget.hpp>

namespace J2AE
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;
		~PhysicsComponent() override = default;

		void init() override {}
		void destroy() override {}

		sf::Vector2f calculateNextPosition(const sf::Vector2f& currentPosition, const sf::FloatRect& objectBounds) const;

		inline
		float getSpeed() const
		{
			return speed;
		}

		inline
		void setSpeed(float speed)
		{
			this->speed = speed;
		}

		inline
		float getAcceleration() const
		{
			return acceleration;
		}

		inline
		void setAcceleration(float acceleration)
		{
			this->acceleration = acceleration;
		}

		void setDirection(Direction x, Direction y);
		void setDirection(const sf::Vector2<Direction>& direction);

		inline
		const sf::Vector2<Direction>& getDirection()
		{
			return direction;
		}

		inline
		float getSpeedAcceleration() const
		{
			return (speed * acceleration);
		}

	protected:
		float speed {1};
		float acceleration {1};
		sf::Vector2<Direction> direction {Direction::RIGHT, Direction::DOWN};

		inline
		short convertDirection(Direction direction) const
		{
			return (short) direction;
		}

	};
}

#endif
