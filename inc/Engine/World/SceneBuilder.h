
#ifndef J2AE_SCENEBUILDER_H
#define J2AE_SCENEBUILDER_H

#include <SFML/Graphics/RenderTarget.hpp>

namespace J2AE
{
	class System;
	class Scene;
	class ObjectFactory;

	class SceneBuilder
	{
	public:
		explicit SceneBuilder(sf::RenderTarget* renderTarget);
		SceneBuilder(sf::RenderTarget* renderTarget, ObjectFactory* objectFactory);
		~SceneBuilder() = default;

		SceneBuilder* addRenderableSystem(System* system);
		SceneBuilder* addLogicSystem(System* system);
		Scene* build();

	private:
		Scene* scene = nullptr;

	};
}

#endif
