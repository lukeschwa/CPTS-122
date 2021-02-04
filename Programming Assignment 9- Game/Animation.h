#pragma once
#include "Resources.h"
class Animation {
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void Update(int row, float dTime, bool right);

	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};