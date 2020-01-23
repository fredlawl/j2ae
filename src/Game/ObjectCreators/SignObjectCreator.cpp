#include <Game/ObjectCreators/SignObjectCreator.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <Game/Components/SpriteComponent.h>
#include <Game/Components/CollidableComponent.h>
#include <Engine/GameObject.h>
#include <iostream>

namespace J2AE
{

	GameObject* SignObjectCreator::create() const
	{
		auto* sign = new GameObject;
		auto* sprite = new sf::Sprite;
		auto* texture = new sf::Texture;

		if (!texture->loadFromFile("../assets/objects/sign.jpeg"))
		{
			// error...
		}
		texture->setRepeated(false);

		sprite->setTexture(*texture);
		sprite->setTextureRect({0, 0, 32, 32});
		sprite->setPosition(0, 0);
		//sprite->setColor(sf::Color::Black);

		auto* signSpriteComponent = new J2AE::SpriteComponent();
		auto* signCollidable = new J2AE::CollidableComponent();

		signSpriteComponent->setSprite(sprite);
		signCollidable->setRadius(32);
		signCollidable->setSize({32, 32});

		// todo: have some sort of component factory to keep track of those too?
		sign->addComponent(J2AE::Component::Type::Sprite, signSpriteComponent);
		sign->addComponent(J2AE::Component::Type::Collidable, signCollidable);

		sign->setPosition(0, 0);

		return sign;
	}
}