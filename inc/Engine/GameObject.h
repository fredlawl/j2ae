#ifndef J2AE_GAMEOBJECT_H
#define J2AE_GAMEOBJECT_H

#include <vector>
#include <Engine/Utility/Activatable>
#include <SFML/System.hpp>
#include <Engine/Components/Component.h>
#include <Engine/Utility/Handle.h>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace J2AE
{
	class Component;

	class GameObject final : public Activatable, public sf::Transformable
	{
	public:
		GameObject() = default;
		~GameObject() override;

		void init();
		void destroy();

		void activate() override;
		void deactivate() override;

		bool hasComponent(Component::Type componentType) const;
		bool addComponent(Component::Type componentType, Component* component);

		/**
		 * Please! DO NOT DELETE RETURNED MEMORY ZOMG!! Let GameObject perform cleanup
		 * @param componentType
		 * @return
		 */
		Component* getComponent(Component::Type componentType) const;

		template<typename T, typename = std::enable_if<std::is_base_of<Component, T>::value>>
		T* getComponent(Component::Type componentType) const
		{
			if (!hasComponent(componentType))
				return nullptr;

			return (T*) (components[(size_t) componentType]);
		}

		/**
		 * Removing a component from game object will DEALLOCATE it
		 * @param componentType
		 */
		bool removeComponent(Component::Type componentType);

		inline
		bool isActive() const override
		{
			return active;
		}

		inline
		void setHandle(const Handle& handle)
		{
			this->handle = handle;
		}

		inline
		Handle getHandle() const
		{
			return handle;
		}

		inline
		size_t getComponentKey() const
		{
			return componentKey;
		}

	protected:
		static uint32_t instantiations;

		Handle handle;
		bool active {false};
		std::vector<Component*> components {(size_t) Component::Type::NumberOfComponents};

		size_t componentKey = 0;


	};
}

#endif
