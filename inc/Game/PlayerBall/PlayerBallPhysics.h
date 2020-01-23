
#ifndef J2AE_PLAYERBALLPHYSICS_H
#define J2AE_PLAYERBALLPHYSICS_H

#include <Game/Components/PhysicsComponent.h>
#include <SFML/Graphics/RenderWindow.hpp>

namespace J2AE
{
	class PlayerBallPhysics : public PhysicsComponent
	{
	public:
		PlayerBallPhysics();
		~PlayerBallPhysics() {}

		void init();

		void update(GameObject& gameObject, const MapSystem& map);

	};
}

#endif
