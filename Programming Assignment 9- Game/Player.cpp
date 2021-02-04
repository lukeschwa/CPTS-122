#include "Platform.h"

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) : animation(texture,imageCount,switchTime) {
	this->jumpHeight = jumpHeight;
	this->speed = speed;
	row = 0;
	right = true;

	body.setSize(sf::Vector2f(40.0f, 68.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(20.0f, 280.0f);
	body.setTexture(texture);
}

void Player::Update(float dTime) {
	velocity.x *= 0.5f; //makes player slowly lose there speed when falling from a jump
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && tfJump) {
		tfJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);  //This is an equation for determaining if a player can jump, This is a Kinematic equation that i did not come up with
														 //9.81 is a constant of gravity, however it has to modified as it is expressed in meters. SFML's y-axis is also flipped
	}										             //so the equation mus be negative
	
	velocity.y += 981.0f * dTime;
	

	if (velocity.x == 0.0f) {
		row = 0;
	}
	else {
		row = 0;
		if (velocity.x > 0.0f)
			right = true;
		else 
			right = false;
	}

	animation.Update(row, dTime, right);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * dTime);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(body);
}
void Player::canJumpAgain(sf::Vector2f direction) {
	if (direction.x < 0.0f) {
		velocity.x = 0.0f; //colision on the left
	}
	else if (direction.x > 0.0f) {
		velocity.x = 0.0f; // collision on the right
	}
	if (direction.y < 0.0f) {
		velocity.y = 0.0f; //collision on the floor
		tfJump = true;
	}
	else if (direction.y > 0.0f) {
		velocity.y = 0.0f; //colision with ceiling(unessesary as there are no ceilings)
	}
}


