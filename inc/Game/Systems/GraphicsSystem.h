
#ifndef J2AE_GRAPHICSSYSTEM_H
#define J2AE_GRAPHICSSYSTEM_H

#include <Engine/Systems/System.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Engine/Components/Component.h>

namespace J2AE
{
	class GraphicsSystem : public System
	{
	public:
		GraphicsSystem() = default;
		~GraphicsSystem() override = default;

		void init() override;
		void destroy() override;
		void update() override;

		size_t getComponentLock() override
		{
			return (1 << (size_t) Component::Type::Sprite);
		}

	};
}

#endif
