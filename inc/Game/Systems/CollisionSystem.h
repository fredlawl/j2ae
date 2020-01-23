
#ifndef J2AE_COLLISIONSYSTEM_H
#define J2AE_COLLISIONSYSTEM_H

#include <Engine/Systems/System.h>

namespace J2AE
{
	class CollisionSystem : public System
	{
	public:
		CollisionSystem() = default;
		~CollisionSystem() override = default;

		void init() override;
		void destroy() override;
		void update() override;
		size_t getComponentLock() override;
	};
}

#endif
