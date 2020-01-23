#include <Engine/GameState/GameState.h>
#include <Engine/Game.h>

namespace J2AE
{
	Game::Game(sf::RenderWindow& window)
	{
		this->window = &window;
	}

	void Game::init()
	{
		setState(GameState::Type::TitleSequence);
	}

	void Game::destroy()
	{

	}

	void Game::run()
	{
		sf::Clock gameTime;
		sf::Time curTime;

		uint16_t TICKS_PER_SECOND = 25;
		uint16_t SKIP_TICKS = (uint16_t) (1000 / TICKS_PER_SECOND);
		uint8_t MAX_FRAME_SKIP = 5;

		uint32_t loopCount = 0;
		uint64_t nextTick = (uint64_t) curTime.asMicroseconds();
		double interpolation;

		while (window->isOpen()) {
			curTime = gameTime.getElapsedTime();
			loopCount = 0;

			handleEvents();

			while (curTime.asMilliseconds() > nextTick && loopCount < MAX_FRAME_SKIP) {
				currentGameState->update(*this);
				nextTick += SKIP_TICKS;
				++loopCount;
			}

			interpolation = double(curTime.asMilliseconds() + SKIP_TICKS - nextTick) / double(SKIP_TICKS);

			window->clear(sf::Color::Black);
			currentGameState->draw(interpolation);
			window->display();
		}
	}

	void Game::handleEvents()
	{
		sf::Event event;
		if (window->pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				std::cout << "CLOSED" << std::endl;
				this->window->close();
			}

			if (event.type == sf::Event::LostFocus) {
				std::cout << "PAUSED" << std::endl;
				setState(GameState::Type::Paused);
			}

			if (event.type == sf::Event::GainedFocus) {
				std::cout << "RUNNING" << std::endl;
				setState(getPreviousGameStateType());
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				window->close();
			}

		}
	}

	void Game::insertGameState(GameState::Type type, GameState* state)
	{
		if (state == nullptr) {
			return;
		}

		state->init();
		gameStates.emplace((uint8_t) type, state);
	}

	void Game::setState(GameState::Type state)
	{
		std::unordered_map<uint8_t, GameState*>::const_iterator searchedState = gameStates.find((uint8_t) state);
		if (searchedState == gameStates.cend()) {
			std::cerr << "Unable to switch to game state because it was not found." << std::endl;
			return;
		}

		if (currentGameState != nullptr) {
			currentGameState->onLeave(*this);
			previousGameStateType = currentGameStateType;
		}

		currentGameStateType = state;
		currentGameState = searchedState->second;
		currentGameState->onEnter(*this);
	}

}