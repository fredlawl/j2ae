
#ifndef J2AE_SPRITECOMPONENT_H
#define J2AE_SPRITECOMPONENT_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Engine/Components/Component.h"

namespace J2AE
{
	class SpriteComponent : public Component
	{
	public:
		SpriteComponent() = default;
		~SpriteComponent() override = default;

		void init() override;
		void destroy() override;

		void setSprite(sf::Sprite* sprite);
		const sf::Sprite* getSprite() const;
		void setSpritePosition(const sf::Vector2f& position);
		const sf::Drawable& getDrawable() const;

	protected:
		sf::Sprite* sprite = nullptr;

	};
}

#endif
