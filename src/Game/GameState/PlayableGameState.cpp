#include <Game/GameState/PlayableGameState.h>
#include <Engine/Game.h>
#include <Engine/World/Scene.h>

namespace J2AE
{

	void PlayableGameState::init()
	{
		sf::IntRect textureBoundaries = {0, 0, 800, 600};

		// test stuff
		if (!testTexture.loadFromFile("./../assets/sample-texture.png", sf::IntRect(0, 0, 256, 256))) {
			std::cerr << "Image did not load!" << std::endl;
		}

		testTexture.setSmooth(true);
		testTexture.setRepeated(true);
		testSprite.setTexture(testTexture);
		testSprite.setTextureRect(textureBoundaries);

		//world->load("", game.getRenderTarget());
		//world->init();
		//
		//graphicsSystem->init();
		//cameraSystem->init();
		scene->init();
	}

	void PlayableGameState::destroy()
	{
		scene->destroy();
	}

	void PlayableGameState::update(Game& game)
	{
		scene->sendMessages();
		scene->update();
	}

	void PlayableGameState::draw(double interpolation)
	{
		// todo: This should be handled by the "world"; as in, the world gives back a collection of things to draw?
		//renderTarget.draw(testSprite);

		//std::vector<std::vector<MapSystem::LayerObject*>*>* layers = world->getObjectsInView(renderTarget.getView());
		//std::vector<MapSystem::LayerObject*>* backgroundTiles = layers->at((int) MapSystem::Layer::Background);

		//for (auto it = backgroundTiles->cbegin(); it != backgroundTiles->cend(); ++it) {
		//	MapSystem::LayerObject* layerObject = (*it);
		//	if (layerObject == nullptr)
		//		continue;
		//
		//	renderTarget.draw(*(sf::Drawable*) layerObject->tile);
		//}

		scene->render();
	}

	void PlayableGameState::onEnter(Game& game)
	{
		sf::FloatRect viewDimensions = {0, 0, 1920, 1080};
		sf::View v(viewDimensions);
		v.setViewport(sf::FloatRect(0, 0, 1, 1));
		v.zoom(.2);
		//v.setCenter(400, 300);
		v.setCenter(0, 0);
		game.getRenderTarget().setView(v);

		// todo: This should be handled by the "world"; as in, the world gives back a collection of things to update?
		//for (auto it = objects.begin(); it != objects.end(); ++it) {
		//	(*it)->update(*world);
		//}
	}
}
