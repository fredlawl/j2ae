
#ifndef J2AE_PAUSEDGAMESTATE_H
#define J2AE_PAUSEDGAMESTATE_H

#include <Engine/GameState/GameState.h>

namespace J2AE
{
	class PausedGameState : public GameState
	{
	public:
		PausedGameState() = default;
		~PausedGameState() override = default;

		void init() override;
		void destroy() override ;
		void onEnter(Game& game) override {}
		void onLeave(Game& game) override {}
		void update(Game& game) override;
		void draw(double interpolation) override;
	};
}

#endif
