
#ifndef J2AE_COMPONENT_H
#define J2AE_COMPONENT_H

#include <Engine/Utility/Activatable>
#include <cstddef>
#include <cstdint>

namespace J2AE
{
	class Component : public Activatable
	{
	public:
		enum class Type : size_t
		{
			Physics = 0,
			Sprite,
			Identity,
			Collidable,
			PlayerControl,
			NumberOfComponents
		};

		~Component() override = default;

		virtual void init() = 0;
		virtual void destroy() = 0;

		void activate() override;
		void deactivate() override;

		inline
		bool isActive() const override
		{
			return active;
		}

	protected:
		Component() = default;
		bool active{true};

	};
}

#endif
