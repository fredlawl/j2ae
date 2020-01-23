
#include <Game/PlayerBall/PlayerBall.h>

namespace J2AE
{

	void PlayerBall::init()
	{
		input->init();
		physics->init();
		camera->init();
		graphics->init();
		setOrigin(8, 8);
	}

	void PlayerBall::destroy()
	{

	}

	void PlayerBall::update(const Map& map)
	{
		input->update(*this, *physics);
		physics->update(*this, map);
		camera->update(*this, map);
		graphics->update(*this);
	}

	void PlayerBall::draw(sf::RenderTarget& renderTarget)
	{
		renderTarget.draw(*graphics->getDrawable());
	}
}