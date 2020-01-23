#include <Game/Components/SpriteComponent.h>

namespace J2AE
{

	void J2AE::SpriteComponent::init()
	{

	}

	void J2AE::SpriteComponent::destroy()
	{
		delete sprite->getTexture();
		delete sprite;
	}

	void J2AE::SpriteComponent::setSprite(sf::Sprite* sprite)
	{
		this->sprite = sprite;
	}

	const sf::Sprite* J2AE::SpriteComponent::getSprite() const
	{
		return sprite;
	}

	const sf::Drawable& J2AE::SpriteComponent::getDrawable() const
	{
		return *(sf::Drawable*) sprite;
	}

	void SpriteComponent::setSpritePosition(const sf::Vector2f& position)
	{
		sprite->setPosition(position);
	}
}