
#ifndef J2AE_OBJECTFACTORY_H
#define J2AE_OBJECTFACTORY_H

#include <string>
#include <unordered_map>
#include <vector>

namespace J2AE
{
	class GameObject;
	class ObjectCreator;

	class ObjectFactory
	{
	public:
		ObjectFactory() = default;
		~ObjectFactory();
		GameObject* createGameObject(const std::string& objectName);
		void cleanup(GameObject* gameObject) const;
		void cleanup();
		void registerObjectCreator(const std::string& objectName, ObjectCreator* creator);

		inline
		size_t objectCount() const
		{
			return gameObjects.size();
		}

		inline
		const std::vector<GameObject*>& getObjects() const
		{
			return gameObjects;
		}

	private:
		std::unordered_map<std::string, ObjectCreator*> objectCreators;

		// TODO: Should be list of GameObject not GameObject*
		std::vector<GameObject*> gameObjects;
	};
}

#endif
