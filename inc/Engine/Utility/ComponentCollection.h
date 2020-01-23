
#ifndef J2AE_COMPONENTCOLLECTION_H
#define J2AE_COMPONENTCOLLECTION_H

#include <cstdint>
#include <vector>

namespace J2AE
{
	class Component;

	class ComponentCollection final
	{
	public:
		using handle_t = uint32_t;

		ComponentCollection() {}
		~ComponentCollection() {}

		handle_t insert(Component* component);
		void remove(handle_t handle);
		void activate(handle_t handle);
		void deactivate(handle_t handle);

		inline
		size_t numberOfActiveComponents() const
		{
			return activeComponents;
		}

		inline
		size_t totalComponents() const
		{
			return components.size();
		}

	private:
		std::vector<handle_t> components;
		size_t activeComponents;
	};
}

#endif
