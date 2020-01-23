#include <Engine/GameObject.h>
#include <Game/ObjectCreators/PlayerObjectCreator.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <Game/Components/SpriteComponent.h>
#include <Game/Components/PhysicsComponent.h>
#include <Game/Components/IdentityComponent.h>
#include <Game/Components/CollidableComponent.h>
#include <Game/Components/PlayerControlComponent.h>

namespace J2AE
{

	GameObject* J2AE::PlayerObjectCreator::create() const
	{
		auto* player = new GameObject;
		auto* sprite = new sf::Sprite;
		auto* texture = new sf::Texture;

		if (!texture->loadFromFile("../assets/objects/player.jpeg"))
		{
			// error...
		}
		texture->setRepeated(false);

		sprite->setTexture(*texture);
		sprite->setTextureRect({0, 0, 17, 25});
		sprite->setPosition(0, 0);
		//sprite.setColor(sf::Color::Black);

		auto* playerSpriteComponent = new J2AE::SpriteComponent();
		auto* playerPhysicsComponent = new J2AE::PhysicsComponent();
		auto* playerIdentity = new J2AE::IdentityComponent();
		auto* playerCollidable = new J2AE::CollidableComponent();
		auto* playerControl = new J2AE::PlayerControlComponent();

		playerSpriteComponent->setSprite(sprite);
		playerIdentity->setName("Player 1");
		playerCollidable->setRadius(20);
		playerCollidable->setSize({17, 25});

		// todo: have some sort of component factory to keep track of those too?
		player->addComponent(J2AE::Component::Type::Sprite, playerSpriteComponent);
		player->addComponent(J2AE::Component::Type::Physics, playerPhysicsComponent);
		player->addComponent(J2AE::Component::Type::Identity, playerIdentity);
		player->addComponent(J2AE::Component::Type::Collidable, playerCollidable);
		player->addComponent(J2AE::Component::Type::PlayerControl, playerControl);
		player->setPosition(0, 0);

		return player;
	}

}
