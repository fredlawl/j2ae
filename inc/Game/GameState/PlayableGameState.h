
#ifndef J2AE_PLAYABLEGAMESTATE_H
#define J2AE_PLAYABLEGAMESTATE_H

#include <Engine/GameState/GameState.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <Game/Systems/GraphicsSystem.h>
#include <Game/Systems/UserCameraSystem.h>

namespace J2AE
{
	class GameObject;
	class Tile;
	class Scene;

	class PlayableGameState : public GameState
	{
	public:
		explicit PlayableGameState(Scene* world) :
			scene(world)
		{

		}

		~PlayableGameState() override = default;

		void init() override;
		void destroy() override;
		void onEnter(Game& game) override;
		void onLeave(Game& game) override {}
		void update(Game& game) override;
		void draw(double interpolation) override;

	private:
		sf::Texture testTexture;
		sf::Sprite testSprite;
		Scene* scene = nullptr;

	};
}

#endif
