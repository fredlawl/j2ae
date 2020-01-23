
#ifndef J2AE_SCENE_H
#define J2AE_SCENE_H

#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <unordered_map>
#include <queue>
#include "Engine/Message.h"

namespace J2AE
{
	class System;
	class ObjectFactory;
	class GameObject;

	class Scene
	{
	public:
		explicit Scene(sf::RenderTarget* renderTarget) : renderTarget(renderTarget) {}
		~Scene() = default;

		void init();
		void destroy();

		void update();
		void render();

		void addLogicSystem(System* system);
		void addRenderableSystem(System* system);
		void mapGameObjectsToSystems();

		void setObjectFactory(ObjectFactory* objectFactory);

		inline
		ObjectFactory* getObjectFactory() const
		{
			return objectFactory;
		}

		inline
		void setRenderTarget(sf::RenderTarget* renderTarget)
		{
			this->renderTarget = renderTarget;
		}

		inline
		sf::RenderTarget* getRenderTarget() const
		{
			return renderTarget;
		}

		const std::vector<GameObject*>& getSceneObjects() const;

		bool hasObjectsForScene(size_t systemLock) const;
		std::vector<GameObject*> getObjectsForSystem(size_t systemLock) const;

		void sendMessages();
		void receiveMessage(Message message);

	private:
		static std::vector<GameObject*> defaultEmptyObjects;

		ObjectFactory* objectFactory = nullptr;
		sf::RenderTarget* renderTarget = nullptr;
		std::vector<System*> renderableSystems;
		std::vector<System*> logicSystems;
		std::unordered_map<size_t, std::vector<GameObject*>> systemObjectMap;
		std::queue<Message> messageQueue;

		void registerSystem(System* system);
	};
}

#endif
