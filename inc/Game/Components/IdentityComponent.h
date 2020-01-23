
#ifndef J2AE_IDENTITYCOMPONENT_H
#define J2AE_IDENTITYCOMPONENT_H

#include <string>
#include "Engine/Components/Component.h"

namespace J2AE
{
	class IdentityComponent : public Component
	{
	public:
		IdentityComponent() = default;
		~IdentityComponent() = default;

		void init() {}
		void destroy() {}

		inline
		const std::string& getName() const
		{
			return name;
		}

		inline
		void setName(const std::string& name)
		{
			this->name = name;
		}

	private:
		std::string name {"N/A"};

	};
}

#endif
