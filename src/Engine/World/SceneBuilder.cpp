#include <Engine/World/SceneBuilder.h>
#include <Engine/World/Scene.h>
#include <Game/Map/Systems/MapSystem.h>
#include <Engine/Systems/System.h>

namespace J2AE
{
	SceneBuilder::SceneBuilder(sf::RenderTarget* renderTarget)
	{
		scene = new Scene(renderTarget);
	}

	SceneBuilder::SceneBuilder(sf::RenderTarget *renderTarget, ObjectFactory *objectFactory)
	{
		scene = new Scene(renderTarget);
		scene->setObjectFactory(objectFactory);
	}

	SceneBuilder* SceneBuilder::addLogicSystem(System* system)
	{
		scene->addLogicSystem(system);
		return this;
	}

	SceneBuilder* SceneBuilder::addRenderableSystem(System* system)
	{
		scene->addRenderableSystem(system);
		return this;
	}

	Scene* SceneBuilder::build()
	{
		return scene;
	}

}
