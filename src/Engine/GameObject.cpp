#include <Engine/GameObject.h>
#include <cassert>

namespace J2AE
{
	void GameObject::activate()
	{
		active = true;
	}

	void GameObject::deactivate()
	{
		active = false;
	}

	void GameObject::init()
	{
		setPosition(0, 0);
	}

	void GameObject::destroy()
	{
		for (auto& component : components) {
			if (component == nullptr)
				continue;

			component->destroy();
			delete component;
		}
	}

	bool GameObject::hasComponent(Component::Type componentType) const
	{
		assert((size_t) componentType < (size_t) Component::Type::NumberOfComponents);
		return components[(size_t) componentType] != nullptr;
	}

	bool GameObject::addComponent(Component::Type componentType, Component* component)
	{
		if (component == nullptr)
			return false;

		if (hasComponent(componentType))
			return false;

		component->init();
		components[(size_t) componentType] = component;
		componentKey |= (1 << ((size_t) componentType));
		return true;
	}

	bool GameObject::removeComponent(Component::Type componentType)
	{
		if (!hasComponent(componentType))
			return false;

		components[(size_t) componentType]->destroy();
		delete components[(size_t) componentType];
		components[(size_t) componentType] = nullptr;
		componentKey ^= (1 << ((size_t) componentType));
		return true;
	}

	GameObject::~GameObject()
	{
		destroy();
	}

	Component* GameObject::getComponent(Component::Type componentType) const
	{
		if (!hasComponent(componentType))
			return nullptr;

		return components[(size_t) componentType];
	}
}
