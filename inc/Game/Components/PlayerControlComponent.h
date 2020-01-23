
#ifndef J2AE_PLAYERCONTROLCOMPONENT_H
#define J2AE_PLAYERCONTROLCOMPONENT_H

#include "Engine/Components/Component.h"

namespace J2AE
{
	class PlayerControlComponent : public Component
	{
	public:
		PlayerControlComponent() = default;
		~PlayerControlComponent() override = default;

		void init() override {};
		void destroy() override {};
	};
}

#endif
