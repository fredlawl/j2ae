#include <Game/PlayerBall/PlayerCameraComponent.h>

namespace J2AE
{
	void PlayerCameraComponent::update(GameObject& gameObject, const MapSystem& map)
	{
		float x = gameObject.getPosition().x;
		float y = gameObject.getPosition().y;
		const sf::Rect<unsigned> mapBoundaries = map.getBoundaries();

		sf::Vector2f viewCenter;
		sf::FloatRect viewBounds;
		viewBounds.left = (getSize().x / 2);
		viewBounds.width = mapBoundaries.width - viewBounds.left;

		viewBounds.top = (getSize().y / 2);
		viewBounds.height = mapBoundaries.height - viewBounds.top;

		if (x >= viewBounds.left && x <= viewBounds.width) {
			viewCenter.x = x;
		} else if (x <= viewBounds.left) {
			viewCenter.x = viewBounds.left;
		} else if (x >= viewBounds.width) {
			viewCenter.x = viewBounds.width;
		}

		if (y >= viewBounds.top && y <= viewBounds.height) {
			viewCenter.y = y;
		} else if (y <= viewBounds.top) {
			viewCenter.y = viewBounds.top;
		} else if (y >= viewBounds.height) {
			viewCenter.y = viewBounds.height;
		}

		setCenter(viewCenter);
		renderTarget->setView(*this);
	}

	void PlayerCameraComponent::init()
	{
		setSize(renderTarget->getSize().x, renderTarget->getSize().y);
		setViewport(sf::FloatRect(0, 0, 1, 1));
		zoom(.2);
		renderTarget->setView(*this);
	}

	void PlayerCameraComponent::destroy()
	{

	}
}
