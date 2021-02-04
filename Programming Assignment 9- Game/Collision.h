#pragma once
#include "Resources.h"

class Collision {

public:
	Collision(sf::RectangleShape &bound);
	void Move(float dx, float dy) { bound.move(dx, dy); }
	bool checkCollision(Collision &other,sf::Vector2f &direction, float pushWeight);
	sf::Vector2f getPosition() { return bound.getPosition(); }
	sf::Vector2f getHalfSize() { return bound.getSize() / 2.0f; }

private:
	sf::RectangleShape &bound;
};