#include <Game/PlayerBall/PlayerBallGraphics.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Engine/GameObject.h>

namespace J2AE
{
	PlayerBallGraphics::PlayerBallGraphics()
	{

	}

	void PlayerBallGraphics::update(GameObject& gameObject)
	{
		ball.setPosition(gameObject.getPosition());
	}

	const sf::Drawable* PlayerBallGraphics::getDrawable() const
	{
		return &ball;
	}

	void PlayerBallGraphics::init()
	{
		ball.setFillColor(sf::Color::Green);
//		ball.setRadius(16);
		ball.setSize(sf::Vector2f(16, 16));
		ball.setPosition(0, 0);
	}
}