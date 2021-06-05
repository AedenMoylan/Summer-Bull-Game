#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:

	void init();
	void draw(sf::RenderWindow& window);
	void jump();
	void update();
	void detectInput();
	void applyGravity();
	void detectGround();


private:

	sf::Vector2f m_playerPosition;
	float verticalSpeed = 0;
	
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	bool isPlayerJumping = false;
	bool isPlayerGrounded = true;
};

