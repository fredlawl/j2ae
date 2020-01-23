
#ifndef J2AE_PLAYEROBJECTCREATOR_H
#define J2AE_PLAYEROBJECTCREATOR_H

#include <Engine/ObjectCreator.h>

namespace J2AE
{
	class GameObject;

	class PlayerObjectCreator : public ObjectCreator
	{
	public:
		PlayerObjectCreator() = default;
		~PlayerObjectCreator() override = default;
		GameObject* create() const override;
	};
}

#endif
