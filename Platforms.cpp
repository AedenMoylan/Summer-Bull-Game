#include "Platforms.h"

void Platforms::init()
{
	for (int i = 0; i < MAX_PLATFORMS; i++)
	{
		platformShapes[i].setSize(sf::Vector2f(200.0f, 5.0f));
		
		platformShapes[i].setFillColor(sf::Color::Green);
	}

	platformShapes[0].setPosition(500, 670);
	platformShapes[1].setPosition(200, 530);
		
}

void Platforms::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_PLATFORMS; i++)
	{
		window.draw(platformShapes[i]);
	}
}

void Platforms::update(sf::RenderWindow& window)
{
	movePlatforms();
	respawnPlatforms(window);
}

void Platforms::movePlatforms()
{
	for (int i = 0; i < MAX_PLATFORMS; i++)
	{
		platformShapes[1].move(-2, 0);
	}
}

void Platforms::respawnPlatforms(sf::RenderWindow& window)
{
	if (platformShapes[1].getPosition().x < 0)
	{
		platformShapes[1].setPosition(window.getSize().x, platformShapes[1].getPosition().y);
	}
}

sf::RectangleShape Platforms::getPlatformSprite(int platformNumber)
{
	return platformShapes[platformNumber];
}

int Platforms::getMaxPlatforms()
{
	return MAX_PLATFORMS;
}