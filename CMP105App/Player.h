#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();

	bool getBlocked();
	void setBlocked(bool block);

	bool getRunningLeft();
	void setRunningLeft( bool runleft);

	bool getRunningRight();
	void setRunningRight(bool runright);

	bool getJumping();
	void setJumping(bool jumping);

	bool getCollisionOver();
	void setCollisionOver( bool setcollover);

	bool getCollisionUnder();
	void setCollisionUnder( bool setcollunder);

	bool getOnGround();
	void setOnGround(bool onground);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f vel);

	void update(float dt);
	void handleInput(float dt, float cameraBeggining, float PortalPos);
	void collisionResponse(GameObject*);
	
	
private:
	Animation walk;
	sf::Vector2f direction = sf::Vector2f(1.f, 0);
	sf::Vector2f gravity = sf::Vector2f(0, 20);
	sf::Vector2f jumpVel;
	float position;
	float maxVelocity = 1.f; //the limit of players velocity
	float acceleration = 70.f;
	
	// different situations the player can be in
	bool blocked = false;
	bool runningLeft = false;
	bool runningRight = false;
	bool jumping = false;
	bool collisionOver = false;
	bool collisionUnder = false;
	bool onGround = false;
	//player's velocity
	sf::Vector2f velocity = sf::Vector2f(0, 0);




};
