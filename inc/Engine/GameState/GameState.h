
#ifndef J2AE_GAMESTATE_H
#define J2AE_GAMESTATE_H

#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>

namespace J2AE
{
	class Game;

	class GameState
	{
	public:
		enum class Type : uint8_t {
			TitleSequence,
			Playable,
			Battle,
			Paused
		};

		virtual ~GameState() = default;

		virtual void init() = 0;
		virtual void destroy() = 0;
		virtual void onEnter(Game& game) = 0;
		virtual void onLeave(Game& game) = 0;
		virtual void update(Game& game) = 0;
		virtual void draw(double interpolation) = 0;

	protected:
		GameState() = default;
	};
}

#endif
