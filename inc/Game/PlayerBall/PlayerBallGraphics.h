
#ifndef J2AE_PLAYERBALLGRAPHICS_H
#define J2AE_PLAYERBALLGRAPHICS_H

#include <Game/Components/SpriteComponent.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace J2AE
{
	class PlayerBallGraphics : public SpriteComponent
	{
	public:
		PlayerBallGraphics();
		~PlayerBallGraphics() {}

		void init();
		void destroy() {}

		//virtual void update(GameObject& gameObject);
		//const sf::Drawable* getDrawable() const;

	private:
		sf::RectangleShape ball;
	};
}

#endif
