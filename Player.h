#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:

	/// <summary>
	/// starting info for the player
	/// </summary>
	void init();
	/// <summary>
	/// draws the player
	/// </summary>
	/// <param name="window"></param>
	void draw(sf::RenderWindow& window);
	/// <summary>
	/// sets verticalSpeed to -20 , sets isPlayerJumping to true, moves player sprite upwards by 10 pixels to stop it touching the ground,
	/// and sets isPlayerGrounded to false
	/// </summary>
	void jump();
	/// <summary>
	/// calls appropriate constantly updated functions
	/// </summary>
	void update();
	/// <summary>
	/// 
	/// </summary>
	void detectInput();
	/// <summary>
	/// adds a constant downward force on the player and also sets the new player position
	/// </summary>
	void applyGravity();
	/// <summary>
	/// sets verticalSpeed to 0 and changes appropriate bools to make the player detect touching the ground
	/// </summary>
	void detectGround();
	/// <summary>
	/// returns playerSprite
	/// </summary>
	/// <returns></returns>
	sf::Sprite getPlayerSprite();
	/// <summary>
	/// sets isPlayerGrounded to false
	/// </summary>
	void playerIsNotTouchingPlatform();
	/// <summary>
	/// detects is player is rising by seeing if the value of verticalSpeed is plus or minus. returns isPlayerRising
	/// </summary>
	/// <returns></returns>
	bool detectIfPlayerIsRising();

	/// <summary>
	/// returns platformCollisionRectangle
	/// </summary>
	/// <returns></returns>
	sf::RectangleShape getPlatformCollisionRectangle();

	void movePlatformCollisionRectangle();

private:
	// true if player is standing on ground or platform
	bool isPlayerGrounded = true;
	// stores player position
	sf::Vector2f m_playerPosition;
	// this value is added to the player's y value to make him rise or fall
	float verticalSpeed = 0;
	
	// player texture
	sf::Texture m_playerTexture;
	// player sprite
	sf::Sprite m_playerSprite;

	// false when player isn't jumping
	bool isPlayerJumping = false;
	// true is player is ascending
	bool isPlayerRising = false;
	// this rectangle follows the bottom of the player and it is used to detect collisions between the platforms and this rectangle
	sf::RectangleShape platformCollisionRectangle;
};

