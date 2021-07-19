#include "Game.h"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Bull Run");

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

void Game::init()
{
	srand(time(nullptr)); // set the seed once
	myPlayer.init();
	myPlatforms.init();

	
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
	myPlatforms.draw(window);
}

void Game::update()
{
	myPlayer.update();
	myPlatforms.update(window);
	detectCollisions();

	//std::cout << "Player :" << myPlayer.getPlayerSprite().getGlobalBounds().height + myPlayer.getPlayerSprite().getPosition().y + 10 << std::endl;
	//std::cout << "Platform :" << myPlatforms.getPlatformSprite(0).getPosition().y << std::endl;
}


void Game::detectCollisions()
{
	for (int i = 0; i < myPlatforms.getMaxPlatforms(); i++)
	{
		sf::Vector2f platformPos = myPlatforms.getPlatformPosition(i);
		sf::Vector2f playerPos = myPlayer.getPlayerSprite().getPosition();

		

		if (playerPos.y + myPlayer.getPlayerSprite().getGlobalBounds().height - 20 <= platformPos.y && playerPos.y + myPlayer.getPlayerSprite().getGlobalBounds().height + 20 >= platformPos.y )
		{
			if (playerPos.x + myPlayer.getPlayerSprite().getGlobalBounds().width >= platformPos.x && playerPos.x + myPlayer.getPlayerSprite().getGlobalBounds().width <= platformPos.x + myPlatforms.getPlatformSprite(i).getGlobalBounds().width
				|| playerPos.x >= platformPos.x && playerPos.x <= platformPos.x + myPlatforms.getPlatformSprite(i).getGlobalBounds().width)

			/*if (myPlayer.getPlatformCollisionRectangle().getGlobalBounds().intersects(myPlatforms.getPlatformSprite(i).getGlobalBounds()))*/
			{

				if (myPlayer.detectIfPlayerIsRising() == false )
				{
					myPlayer.detectGround();

				}

				break;
			}
		}
			else 
			{
 				myPlayer.playerIsNotTouchingPlatform();
			}


	}
}