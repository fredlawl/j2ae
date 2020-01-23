#include <Engine/Components/Component.h>

namespace J2AE
{

	void Component::activate()
	{
		active = true;
	}

	void Component::deactivate()
	{
		active = false;
	}
}
