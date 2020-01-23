
#ifndef J2AE_PLAYERCAMERACOMPONENT_H
#define J2AE_PLAYERCAMERACOMPONENT_H

#include <Game/Components/CameraComponent.h>

namespace J2AE
{
	class PlayerCameraComponent : public CameraComponent
	{
	public:
		PlayerCameraComponent(sf::RenderTarget* renderTarget) : CameraComponent(renderTarget)
		{}

		~PlayerCameraComponent() {}

		void init();
		void destroy();
		void update(GameObject& gameObject, const MapSystem& map);

	};
}

#endif
