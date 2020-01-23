
#ifndef J2AE_PHYSICSSYSTEM_H
#define J2AE_PHYSICSSYSTEM_H

#include <Engine/Systems/System.h>
#include <Engine/Components/Component.h>

namespace J2AE
{
	class PhysicsSystem : public System
	{
	public:
		PhysicsSystem() = default;
		~PhysicsSystem() override = default;

		void init() override;
		void destroy() override;
		void update() override;

		size_t getComponentLock() override
		{
			return (1 << (size_t) Component::Type::Physics) | (1 << (size_t) Component::Type::Collidable);
		}
	};
}

#endif
