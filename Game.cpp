#include "Game.h"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Bull Run");

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

void Game::init()
{
	myPlayer.init();
}


void Game::run()
{

	srand(time(NULL));
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;


	// the clock object keeps the time.
	sf::Clock clock;
	sf::Int32 lag = 0;
	clock.restart();




	while (window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//write the main code below
		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			window.clear();

			draw();
			update();
			
			window.display();
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}

}

void Game::draw()
{
	myPlayer.draw(window);
}

void Game::update()
{
	myPlayer.update();
}