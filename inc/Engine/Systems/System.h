
#ifndef J2AE_SYSTEM_H
#define J2AE_SYSTEM_H


#include <vector>
#include <Engine/Message.h>

namespace J2AE
{
	class Scene;

	class System
	{
	public:
		System() = default;
		virtual ~System() = default;

		virtual void init() = 0;
		virtual void destroy() = 0;
		virtual void update() = 0;

		virtual void receiveMessage(const Message& message)
		{

		}

		virtual size_t getComponentLock() = 0;

		inline
		void setScene(Scene* scene)
		{
			this->scene = scene;
		}

	protected:
		Scene* scene = nullptr;
	};
}

#endif
