#include <Engine/World/Scene.h>
#include <Game/Map/Systems/MapSystem.h>
#include <Engine/ObjectFactory.h>

namespace J2AE
{
	std::vector<GameObject*> Scene::defaultEmptyObjects {0};

	void Scene::init()
	{
		for (auto* logicSystem : logicSystems) {
			logicSystem->init();
		}

		for (auto* renderSystem : renderableSystems) {
			renderSystem->init();
		}
	}

	void Scene::destroy()
	{
		for (auto* logicSystem : logicSystems) {
			logicSystem->destroy();
			delete logicSystem;
		}

		for (auto* renderSystem : renderableSystems) {
			renderSystem->destroy();
			delete renderSystem;
		}
	}

	void Scene::update()
	{
		for (auto* logicSystem : logicSystems) {
			logicSystem->update();
		}
	}

	void Scene::render()
	{
		for (auto* renderSystem : renderableSystems) {
			renderSystem->update();
		}
	}

	void Scene::addLogicSystem(System* system)
	{
		registerSystem(system);
		logicSystems.push_back(system);
	}

	void Scene::addRenderableSystem(System* system)
	{
		registerSystem(system);
		renderableSystems.push_back(system);
	}

	void Scene::setObjectFactory(ObjectFactory* objectFactory)
	{
		if (objectFactory == nullptr)
			return;

		this->objectFactory = objectFactory;
	}

	void Scene::registerSystem(System* system)
	{
		system->setScene(this);

		std::vector<GameObject*> vec;
		systemObjectMap.emplace(system->getComponentLock(), vec);
	}

	void Scene::mapGameObjectsToSystems()
	{
		auto objects = objectFactory->getObjects();
		for (auto* entity : objects) {
			for (auto& systemLock : systemObjectMap) {
				if ((systemLock.first & entity->getComponentKey()) != 0) {
					(systemLock.second).push_back(entity);
				}
			}
		}
	}

	bool Scene::hasObjectsForScene(size_t systemLock) const
	{
		return !getObjectsForSystem(systemLock).empty();
	}

	std::vector<GameObject*> Scene::getObjectsForSystem(size_t systemLock) const
	{
		std::vector<GameObject*> subsetOfGameObjects;
		const auto foundBucket = systemObjectMap.find(systemLock);
		if (foundBucket == systemObjectMap.cend()) {
			return defaultEmptyObjects;
		}

		const auto& foundObjects = foundBucket->second;
		for (const auto& gameObject : foundObjects) {
			if (gameObject->getComponentKey() >= systemLock) {
				subsetOfGameObjects.push_back(gameObject);
			}
		}

		return subsetOfGameObjects;
	}

	const std::vector<GameObject*>& Scene::getSceneObjects() const
	{
		return objectFactory->getObjects();
	}

	void Scene::sendMessages()
	{
		Message* message;
		std::vector<System*> allSystems;
		allSystems.insert(allSystems.cbegin(), logicSystems.cbegin(), logicSystems.cend());
		allSystems.insert(allSystems.cend(), renderableSystems.cbegin(), renderableSystems.cend());

		while (!messageQueue.empty()) {
			message = &messageQueue.front();
			for (auto* system : allSystems) {
				system->receiveMessage(*message);
			}
			messageQueue.pop();
		}
	}

	void Scene::receiveMessage(Message message)
	{
		messageQueue.emplace(message);
	}

}
