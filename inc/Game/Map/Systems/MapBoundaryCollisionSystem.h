
#ifndef J2AE_MAPBOUNDARYCOLLISIONSYSTEM_H
#define J2AE_MAPBOUNDARYCOLLISIONSYSTEM_H

#include <Engine/Systems/System.h>
#include <Engine/Components/Component.h>

namespace J2AE
{
	class Map;

	class MapBoundaryCollisionSystem : public System
	{
	public:
		MapBoundaryCollisionSystem() = default;
		~MapBoundaryCollisionSystem() override = default;

		void init() override;
		void destroy() override;
		void update() override ;

		void receiveMessage(const Message& message) override;

		size_t getComponentLock() override
		{
			return 	(1 << (size_t) Component::Type::Collidable) |
					(1 << (size_t) Component::Type::Sprite);
		}

	private:
		Map* map = nullptr;
	};
}

#endif
