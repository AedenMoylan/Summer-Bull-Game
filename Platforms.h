#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

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
/// <summary>
/// returns the positions of the appropriate platforms
/// </summary>
	sf::Vector2f getPlatformPosition(int platformNumber);
/// <summary>
/// increases randomPlatformSpawn. used to make the platform respawn more random
/// </summary>
	void increasePlatformRespawnRandomizer();
	/// <summary>
	/// sets the platform respawn number back to it's original value
	/// </summary>
	void resetPlatformRespawnNumber();


	/// <summary>
	/// returns randomPlatformSpawn
	/// </summary>
	/// <returns></returns>
	int getRandomPlatformSpawn();

private:
	// max number of platforms
	const static int MAX_PLATFORMS = 50;
	// rectangle shapes for the platforms
	sf::RectangleShape platformShapes[MAX_PLATFORMS];
	// base value for the platform respawn number
	const int basePlatformSpawnNumber = 400;
	// used to determine when to respawn the platforms. value changes based on how long the player leaves the ground
	int randomPlatformSpawn = basePlatformSpawnNumber;
	
};

