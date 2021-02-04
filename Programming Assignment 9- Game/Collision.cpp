#include "Collision.h"

Collision::Collision(sf::RectangleShape &bound) : 
	bound(bound) 
{

}


bool Collision::checkCollision(Collision &other, sf::Vector2f &direction, float pushWeight) {
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();

	float dx = otherPosition.x - thisPosition.x;
	float dy = otherPosition.y - thisPosition.y;
	float intersectX = abs(dx) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(dy) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) 
	{
		pushWeight = min(max(pushWeight, 0.0f), 1.0f);
		
		if (intersectX > intersectY) 
		{
			if (dx > 0.0f) 
			{
				Move(intersectX * (1.0 - pushWeight), 0.0f);
				other.Move(-intersectX * pushWeight, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{
				Move(-intersectX * (1.0 - pushWeight), 0.0f);
				other.Move(intersectX * pushWeight, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else 
		{
			if (dy > 0.0f) 
			{
				Move(0.0f, intersectY * (1.0 - pushWeight));
				other.Move(0.0f, -intersectY * pushWeight);
				direction.x = 0.0f;
				direction.y = 1.0f; // if y value is positive, it means there is something underneath you
			}
			else 
			{
				Move(0.0f, -intersectY * (1.0 - pushWeight));
				other.Move(0.0f, intersectY * pushWeight);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}


	return false;
}
