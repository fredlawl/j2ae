#ifndef J2AE_GAME_H
#define J2AE_GAME_H

#include <chrono>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <Engine/GameState/GameState.h>

namespace J2AE {

	class Game final
	{

		public:
			explicit Game(sf::RenderWindow& window);
			~Game() = default;

			void init();
			void destroy();
			void run();

			void insertGameState(GameState::Type type, GameState* state);
			void setState(GameState::Type state);

			inline
			GameState* getState(GameState::Type type) const
			{
				return currentGameState;
			}

			inline
			GameState::Type getPreviousGameStateType() const
			{
				return previousGameStateType;
			}

			inline
			sf::RenderTarget& getRenderTarget() const
			{
				return *window;
			}

		private:
			GameState* currentGameState = nullptr;
			GameState::Type currentGameStateType;
			GameState::Type previousGameStateType;

			std::unordered_map<uint8_t, GameState*> gameStates;
			sf::RenderWindow* window = nullptr;

			void handleEvents();
	};

}

#endif
