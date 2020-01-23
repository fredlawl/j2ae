
#ifndef J2AE_USERMOVEMENTINPUTSYSTEM_H
#define J2AE_USERMOVEMENTINPUTSYSTEM_H

#include <Engine/Systems/System.h>
#include <Engine/Components/Component.h>

namespace J2AE
{
	class GameObject;

	class UserMovementInputSystem : public System
	{
	public:
		UserMovementInputSystem() = default;
		~UserMovementInputSystem() override = default;

		void init() override;
		void destroy() override;
		void update() override;

		size_t getComponentLock() override
		{
			return (1 << (size_t) Component::Type::PlayerControl) |
				(1 << (size_t) Component::Type::Physics) |
				(1 << (size_t) Component::Type::Collidable) |
				(1 << (size_t) Component::Type::Sprite);
		}

	private:
		// todo: this is a cheat, maybe multiple objects could be controlled by a player at the same time
		// but that would be shitty anyways... something to think about.
		GameObject* player = nullptr;
	};
}

#endif
