#include "Platforms.h"

void Platforms::init()
{
	for (int i = 0; i < MAX_PLATFORMS; i++)
	{
		if (i < MAX_PLATFORMS / 2)
		{
			platformShapes[i].setSize(sf::Vector2f(100.0f, 5.0f));

			platformShapes[i].setFillColor(sf::Color::Green);

        	platformShapes[i].setPosition(500, 200);

		
		}
		else if (i > MAX_PLATFORMS / 2)
		{
			platformShapes[i].setSize(sf::Vector2f(100.0f, 5.0f));

			platformShapes[i].setFillColor(sf::Color::Red);

			platformShapes[i].setPosition( 28 * i, 530);
		}
	}

	platformShapes[0].setSize(sf::Vector2f(1280.0f, 5.0f));

	platformShapes[0].setFillColor(sf::Color::Magenta);

	platformShapes[0].setPosition(0, 650);
		
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
	for (int i = 1; i < MAX_PLATFORMS; i++)
	{
		platformShapes[i].move(-2, 0);
	}
}

void Platforms::respawnPlatforms(sf::RenderWindow& window)
{
	for (int i = 1; i < MAX_PLATFORMS ; i++)
	{
	int randNum = (rand() % randomPlatformSpawn) + 1;
		if (randNum == randomPlatformSpawn)
		{
			if (platformShapes[i].getPosition().x < 0)
			{
				platformShapes[i].setPosition(window.getSize().x, platformShapes[i].getPosition().y);
			}
		}
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

sf::Vector2f Platforms::getPlatformPosition(int platformNumber)
{
	sf::Vector2f platformPos = platformShapes[platformNumber].getPosition();
	return platformPos;
}