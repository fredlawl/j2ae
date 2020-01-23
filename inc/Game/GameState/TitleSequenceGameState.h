
#ifndef J2AE_TITLESEQUENCEGAMESTATE_H
#define J2AE_TITLESEQUENCEGAMESTATE_H

#include <Engine/GameState/GameState.h>
#include <SFML/Graphics/Text.hpp>

namespace J2AE
{
	class Scene;

	class TitleSequenceGameState : public GameState
	{
	public:
		explicit TitleSequenceGameState(Scene* scene) :
			scene(scene)
		{

		}

		~TitleSequenceGameState() override = default;

		void init() override;
		void destroy() override;
		void onEnter(Game& game) override;
		void onLeave(Game& game) override;
		void update(Game& game) override;
		void draw(double interpolation) override;

	private:
		Scene* scene = nullptr;

	};
}

#endif
