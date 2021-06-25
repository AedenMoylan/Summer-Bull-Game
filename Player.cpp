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
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 2, m_playerSprite.getGlobalBounds().height / 2);
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

	isPlayerGrounded = false;

	m_playerPosition.y = m_playerPosition.y - 10;

	isPlayerJumping = true;
}

void Player::detectInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (isPlayerJumping == false)
		{		
			jump();		
		}
	}
}

void Player::update()
{
	detectInput();
	if (isPlayerGrounded == false)
	{
	    applyGravity();
    	m_playerSprite.setPosition(m_playerPosition);
	}
}

void Player::applyGravity()
{
	verticalSpeed += 1;
	m_playerPosition.y += verticalSpeed;
}

void Player::detectGround()
{
		isPlayerGrounded = true;
		isPlayerJumping = false;
		verticalSpeed = 0;
}

void Player::playerIsNotTouchingPlatform()
{
	isPlayerGrounded = false;
}

sf::Sprite Player::getPlayerSprite()
{
	return m_playerSprite;
}

bool Player::detectIfPlayerIsRising()
{
	if (verticalSpeed < 0)
	{
		isPlayerRising = true;
	}
	else
	{
		isPlayerRising = false;
	}
	return isPlayerRising;
}