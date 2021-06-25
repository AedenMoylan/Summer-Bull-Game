#pragma once
#include <SFML/Graphics.hpp>

class Platforms
{

public:

	/// <summary>
	/// initialises platform data
	/// </summary>
	void init();
	/// <summary>
	/// calls appropriate constantly updating functions
	/// </summary>
	/// <param name="window"></param>
	void update(sf::RenderWindow& window);
	/// <summary>
	/// draws the platforms
	/// </summary>
	/// <param name="window"></param>
	void draw(sf::RenderWindow& window);
	/// <summary>
	/// moves the platforms to the left
	/// </summary>
	void movePlatforms();
	/// <summary>
	/// respawns platforms if they go off screen
	/// </summary>
	/// <param name="window"></param>
	void respawnPlatforms(sf::RenderWindow& window);
	/// <summary>
	/// returns platfornSprite
	/// </summary>
	/// <param name="platformNumber"></param>
	/// <returns></returns>
	sf::RectangleShape getPlatformSprite(int platformNumber);
	/// <summary>
	/// returns MAX_PLATFORMS
	/// </summary>
	/// <returns></returns>
	int getMaxPlatforms();
private:
	// max number of platforms
	const static int MAX_PLATFORMS = 2;
	// rectangle shapes for the platforms
	sf::RectangleShape platformShapes[MAX_PLATFORMS];
};

