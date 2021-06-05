#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public:


	void run();
	void draw();
	void init();
private:
	Player myPlayer;
	void update();
};

