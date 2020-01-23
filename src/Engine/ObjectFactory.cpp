#include <Engine/ObjectFactory.h>
#include <Engine/ObjectCreator.h>
#include <Engine/GameObject.h>
#include <iostream>
#include <cassert>

namespace J2AE
{

	ObjectFactory::~ObjectFactory()
	{
		for (auto creator : objectCreators) {
			delete creator.second;
		}
	}

	GameObject* ObjectFactory::createGameObject(const std::string& objectName)
	{
		GameObject* createdObj = nullptr;
		auto it = objectCreators.find(objectName);
		if (it == objectCreators.cend()) {
			std::cerr << "Unable to find a object creator for the object " << objectName << std::endl;
			return nullptr;
		}

		// handle = index, counter, object type
		auto indexCounter = (uint32_t) gameObjects.size();
		Handle handle(indexCounter, indexCounter + 1, 1);
		createdObj = it->second->create();
		createdObj->init();
		createdObj->activate();
		createdObj->setHandle(handle);

		// TODO: we want this to be an array of COPIED game objects in the future for cache purposes
		gameObjects.push_back(createdObj);

		// delete createdObj; // todo: after copy...

		return createdObj;
	}

	void ObjectFactory::cleanup()
	{
		for (auto gameObject : gameObjects) {
			cleanup(gameObject);
		}

		gameObjects.clear();
	}

	void ObjectFactory::cleanup(GameObject* gameObject) const
	{
		gameObject->deactivate();
		gameObject->destroy();

		// TODO: Remove this delete statement once it's copied data, here'll want to remove from array
		delete gameObject;
	}

	void ObjectFactory::registerObjectCreator(const std::string& objectName, ObjectCreator* creator)
	{
		assert(creator != nullptr);
		objectCreators.emplace(objectName, creator);
	}

}
