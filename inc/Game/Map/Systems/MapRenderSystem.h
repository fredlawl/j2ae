
#ifndef J2AE_MAPRENDERER_H
#define J2AE_MAPRENDERER_H

#include <Engine/Systems/System.h>
#include <Engine/Components/Component.h>

namespace J2AE
{
	class Map;

	class MapRenderSystem : public System
	{
	public:
		MapRenderSystem() = default;
		~MapRenderSystem() override = default;

		void init() override;
		void destroy() override;
		void update() override;
		void receiveMessage(const Message& message) override;

		size_t getComponentLock() override
		{
			return 0;
		};

	private:
		Map* map = nullptr;

	};
}

#endif
