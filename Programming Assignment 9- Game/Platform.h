#pragma once
#include "Resources.h"
#include "Animation.h"
#include "Collision.h"

class Platform {

public:
	Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position) {
		body.setSize(size);
		body.setTexture(texture);
		body.setPosition(position);
		body.setOrigin(size / 2.0f);
	}
	Collision getCollision() { return Collision(body); }
	void Draw(sf::RenderWindow &window) { window.draw(body); }


private:
	sf::RectangleShape body;


};

class Goal : public sf::CircleShape {

public:
	Goal(float radius, const sf::Color &color, sf::Vector2f &pos) : sf::CircleShape(radius) {
		this->setFillColor(color);
		this->setPosition(pos);

	}

};

class Player {
public:
	Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	void Update(float dTime);
	void draw(sf::RenderWindow &window);
	sf::Vector2f getPosition() { return body.getPosition(); }
	Collision getColission() { return Collision(body); }
	void canJumpAgain(sf::Vector2f direction);


private:
	//animation
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool right;

	//jumping;
	sf::Vector2f velocity;
	bool tfJump; //can the player perform a jump
	float jumpHeight;
	
};