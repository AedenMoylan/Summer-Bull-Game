#include "Player.h"
#include <iostream>

void Player::init()
{
	if (!m_playerTexture.loadFromFile("ASSETS/IMAGES/Bull.png"));
	{
	//	std::cout << "error with fileeee";
	}

	m_playerSprite.setTexture(m_playerTexture);

	m_playerSprite.setScale(0.15, 0.15);
	m_playerPosition = sf::Vector2f(500, 450);

	m_playerSprite.setPosition(m_playerPosition);
	

}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_playerSprite);
}

void Player::jump()
{
	verticalSpeed = -20;

	isPlayerJumping = true;
}

void Player::detectInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		isPlayerGrounded = false;
		if (isPlayerJumping == false)
		{
			m_playerPosition.y = m_playerPosition.y - 10;
			jump();
			
		}
	}
}

void Player::update()
{
	detectInput();
	detectGround();
	if (isPlayerGrounded == false)
	{
	    applyGravity();
	}

	m_playerSprite.setPosition(m_playerPosition);
}

void Player::applyGravity()
{

	m_playerPosition.y += verticalSpeed;
	verticalSpeed += 1.0;
}

void Player::detectGround()
{
	if (m_playerPosition.y >= 460)
	{
		isPlayerGrounded = true;
		isPlayerJumping = false;
	}
}