#include <iostream>
#include <SFML/Graphics.hpp>
#include <Engine/Game.h>
#include <Game/Components/IdentityComponent.h>
#include <Engine/ObjectFactory.h>
#include <Game/ObjectCreators/PlayerObjectCreator.h>
#include <Game/Systems/PhysicsSystem.h>
#include <Engine/World/SceneBuilder.h>
#include <Game/Systems/UserMovementInputSystem.h>
#include <Game/Systems/CollisionSystem.h>
#include <Game/Map/Systems/MapRenderSystem.h>
#include <Game/Map/MapLoader.h>
#include <Game/Map/Systems/MapBoundaryCollisionSystem.h>
#include <Game/GameState/TitleSequenceGameState.h>
#include <Game/GameState/PlayableGameState.h>
#include <Game/GameState/PausedGameState.h>
#include <Game/Map/Systems/MapSystem.h>
#include <Game/ObjectCreators/SignObjectCreator.h>

const unsigned int WINDOW_WIDTH = 1920;
const unsigned int WINDOW_HEIGHT = 1080;

int main()
{
	srand (time(NULL));

	// Create window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Just Another 2D Engine", sf::Style::Titlebar | sf::Style::Close);
	sf::View view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

	window.setView(view);
	window.setVerticalSyncEnabled(true);

	J2AE::ObjectFactory objFactory;
	objFactory.registerObjectCreator("Player", new J2AE::PlayerObjectCreator);
	objFactory.registerObjectCreator("Sign", new J2AE::SignObjectCreator);

	auto* mapLoader = new J2AE::MapLoader(objFactory);

	J2AE::SceneBuilder playableSceneBuilder(&window, &objFactory);
	J2AE::SceneBuilder titleSceneBuilder(&window);

	J2AE::Scene* titleScene = titleSceneBuilder
		.addRenderableSystem(new J2AE::GraphicsSystem())
		->build();

	J2AE::Scene* playableScene = playableSceneBuilder
		.addRenderableSystem(new J2AE::MapRenderSystem())
		->addRenderableSystem(new J2AE::GraphicsSystem())
		->addLogicSystem(new J2AE::MapSystem(mapLoader))
		->addLogicSystem(new J2AE::UserMovementInputSystem())
		->addLogicSystem(new J2AE::PhysicsSystem())
		->addLogicSystem(new J2AE::MapBoundaryCollisionSystem())
		->addLogicSystem(new J2AE::CollisionSystem)
		->addLogicSystem(new J2AE::UserCameraSystem())
		->build();


	J2AE::TitleSequenceGameState titleSequenceGameState(titleScene);
	J2AE::PlayableGameState playableGameState(playableScene);
	J2AE::PausedGameState pausedGameState;

	// Setup Game
	J2AE::Game game(window);
	game.insertGameState(J2AE::GameState::Type::TitleSequence, &titleSequenceGameState);
	game.insertGameState(J2AE::GameState::Type::Playable, &playableGameState);
	game.insertGameState(J2AE::GameState::Type::Paused, &pausedGameState);

	game.init();
	game.run();
	game.destroy();

	return 0;
}