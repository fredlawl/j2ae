#include <Engine/Game.h>
#include <unistd.h>
#include <Game/GameState/PausedGameState.h>

namespace J2AE
{
	void PausedGameState::init()
	{

	}

	void PausedGameState::destroy()
	{

	}

	void PausedGameState::update(J2AE::Game& game)
	{
		usleep(200 * 1000);
	}

	void PausedGameState::draw(double interpolation)
	{

	}
}
