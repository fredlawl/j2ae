#ifndef J2AE_PLAYERBALL_H
#define J2AE_PLAYERBALL_H

#include <Engine/GameObject.h>
#include <Game/Components/SpriteComponent.h>
#include <Game/Components/PhysicsComponent.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <Game/Components/CameraComponent.h>
#include "PlayerBallKeyboardComponent.h"

namespace J2AE
{
	//class PlayerBall : public GameObject
	//{
	//public:
	//	PlayerBall(
	//			SpriteComponent* graphics,
	//			PhysicsComponent* physics,
	//			PlayerBallKeyboardComponent* input,
	//			CameraComponent* camera
	//	) :
	//			graphics(graphics),
	//			physics(physics),
	//			input(input),
	//			camera(camera)
	//	{ }
	//
	//	~PlayerBall() {}
	//
	//	void init();
	//	void destroy();
	//
	//	void update(const MapSystem& map);
	//
	//	void draw(sf::RenderTarget& renderTarget);
	//
	//protected:
	//	SpriteComponent* graphics = nullptr;
	//	PhysicsComponent* physics = nullptr;
	//	PlayerBallKeyboardComponent* input = nullptr;
	//	CameraComponent* camera = nullptr;
	//
	//};
}

#endif
