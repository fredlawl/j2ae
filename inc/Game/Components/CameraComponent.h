
#ifndef J2AE_CAMERACOMPONENT_H
#define J2AE_CAMERACOMPONENT_H

#include <Game/Map/Systems/MapSystem.h>
#include "Engine/Components/Component.h"

namespace J2AE
{
	class CameraComponent : public Component, public sf::View
	{
	public:
		CameraComponent(sf::RenderTarget* renderTarget) : renderTarget(renderTarget) {}
		virtual ~CameraComponent() {}

		virtual void init() = 0;
		virtual void destroy() = 0;
		virtual void update(GameObject& gameObject, const MapSystem& map) = 0;

	protected:
		sf::RenderTarget* renderTarget = nullptr;

	};
}

#endif
