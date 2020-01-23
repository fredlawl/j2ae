
#ifndef J2AE_PLAYERKEYBOARDCOMPONENT_H
#define J2AE_PLAYERKEYBOARDCOMPONENT_H

#include <Engine/Components/Component.h>
#include <Game/Components/PhysicsComponent.h>

namespace J2AE
{
	class PlayerBallKeyboardComponent : public Component
	{
	public:
		PlayerBallKeyboardComponent() {}
		~PlayerBallKeyboardComponent() {}

		void init();
		void destroy() {}

		void update(GameObject& gameObject, PhysicsComponent& physicsComponent);
	};
}

#endif
