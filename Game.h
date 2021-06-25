#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platforms.h"
#include <iostream>


class Game
{
public:


	void run();
	/// <summary>
	/// calls the draw function of each appropriate class
	/// </summary>
	void draw();
	/// <summary>
	/// calls the init function of each appropriate class
	/// </summary>
	void init();
	/// <summary>
	/// detects collisions between objects
	/// </summary>
	void detectCollisions();
	/// <summary>
	/// calls the update function of each appropriate class and some other functions in the game class
	/// </summary>
	void update();
private:

	Player myPlayer;
	Platforms myPlatforms;
};

