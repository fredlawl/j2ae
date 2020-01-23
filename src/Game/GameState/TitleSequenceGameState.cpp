#include <Engine/Game.h>
#include <Game/GameState/TitleSequenceGameState.h>
#include <Engine/World/Scene.h>

namespace J2AE
{
	void TitleSequenceGameState::init()
	{
		scene->init();
	}

	void TitleSequenceGameState::destroy()
	{
		scene->destroy();
	}

	void TitleSequenceGameState::update(Game& game)
	{
		scene->update();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			game.setState(GameState::Type::Playable);
		}
	}

	void TitleSequenceGameState::draw(double interpolation)
	{
//		renderTarget.draw(text);
		scene->render();
	}

	void TitleSequenceGameState::onEnter(Game& game)
	{
		sf::FloatRect viewDimensions = {0, 0, 1920, 1080};
		sf::View v(viewDimensions);
		v.zoom(1);
		game.getRenderTarget().setView(v);
	}

	void TitleSequenceGameState::onLeave(Game& game)
	{
		std::cout << "On leave" << std::endl;
	}

}