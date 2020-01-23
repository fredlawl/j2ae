
#ifndef J2AE_SIGNOBJECTCREATOR_H
#define J2AE_SIGNOBJECTCREATOR_H

#include <Engine/ObjectCreator.h>

namespace J2AE
{
	class GameObject;

	class SignObjectCreator : public ObjectCreator
	{
	public:
		SignObjectCreator() = default;
		~SignObjectCreator() override = default;
		GameObject* create() const override;
	};
}

#endif
