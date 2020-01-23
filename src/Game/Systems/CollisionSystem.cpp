#include <Game/Systems/CollisionSystem.h>
#include <Engine/Components/Component.h>

namespace J2AE
{
	void CollisionSystem::init()
	{

	}

	void CollisionSystem::destroy()
	{

	}

	void CollisionSystem::update()
	{
		// ... perform collion detection
	}

	size_t CollisionSystem::getComponentLock()
	{
		return (1 << (size_t) Component::Type::Collidable);
	}

}
