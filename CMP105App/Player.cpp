#include "Player.h"
#include "Level.h"
#include "windows.h"
#include <iostream>
using namespace std;
Player::Player() 
{

	//// ANIMATION
	walk.addFrame(sf::IntRect(0, 0, 34, 28));
	walk.addFrame(sf::IntRect(34, 0, 34, 28));
	walk.addFrame(sf::IntRect(68, 0, 34, 28));
	walk.addFrame(sf::IntRect(102, 0, 34, 28));
	walk.addFrame(sf::IntRect(136, 0, 34, 28));
	walk.addFrame(sf::IntRect(170, 0, 34, 28));
	walk.setFrameSpeed(0.07f);

	////  JUMP
	jumpVel = sf::Vector2f(velocity.x, -900.f);
	jumping = false;
}
Player::~Player(){}



bool Player::getBlocked() {
	return blocked;
}
void Player::setBlocked(bool block) {
	blocked = block;
}


bool Player::getRunningLeft() {
	return runningLeft;
}
void Player::setRunningLeft(bool runleft) {
	runningLeft = runleft;
}

bool Player::getRunningRight() {
	return runningRight;
}
void Player::setRunningRight( bool runright) {
	runningRight = runright;
}

bool Player::getJumping() {
	return jumping;
}
void Player::setJumping(bool jump) {
	jumping = jump;
}


bool Player::getCollisionOver() {
	return collisionOver;
}
void Player::setCollisionOver(bool collover) {
	collisionOver = collover;
}

bool Player::getCollisionUnder() {
	return collisionUnder;
}
void Player::setCollisionUnder(bool collunder) {
	collisionUnder = collunder;
}

bool Player::getOnGround() {
	return onGround;
}
void Player::setOnGround(bool onground) {
	onGround = onground;
}

sf::Vector2f Player::getVelocity() {
	return velocity;
}
void Player::setVelocity(sf::Vector2f vel) {
	velocity = vel;
}





//#######################  HANDLE INPUT  #######################
void Player::handleInput(float dt, float cameraBeggining, float portalPos) {


	////######  RUN LEFT  ######
	if (input->isKeyDown(sf::Keyboard::A)) { 

		if (Player::getPosition().x <= cameraBeggining + 800) { // stop the player from moving left at the beggining
			Player::setPosition(cameraBeggining + 800, Player::getPosition().y);
			blocked = true;
		}
		else {
			blocked = false;
			runningLeft = true;
			runningRight = false;
			if (jumping) { //if player is mid jump
				walk.currentFrame = 0;
				setTextureRect(walk.getCurrentFrame());
			}
			else {
				//walking animation
				walk.animate(dt);
				setTextureRect(walk.getCurrentFrame());
				if (walk.currentFrame > 6) {
					walk.currentFrame = 0;
				}
			}
			//movement
			if (velocity.x > maxVelocity) {
				velocity.x = maxVelocity;
			}
			velocity.x += 3.f * (direction.x * acceleration) * dt;
			Player::setPosition((getPosition().x - (velocity.x)), getPosition().y);
			walk.setFlipped(false);
		}
	}


	////######  RUN RIGHT  ######
	else if (input->isKeyDown(sf::Keyboard::D)){ 
		if (Player::getPosition().x >= portalPos) {  // stop the player from moving right at the end
			Player::setPosition(portalPos - 100, Player::getPosition().y);
			blocked = true;
		}
		else {
			blocked = false;
			runningRight = true;
			runningLeft = false;
			if (jumping) { //if player is mid jump
				walk.currentFrame = 0;
				setTextureRect(walk.getCurrentFrame());
			}
			else {
				//walking animation
				walk.animate(dt);
				setTextureRect(walk.getCurrentFrame());
				if (walk.currentFrame > 6) {
					walk.currentFrame = 0;
				}
			}
			//movement
			if (velocity.x > maxVelocity) {
				velocity.x = maxVelocity;
			}
			velocity.x += 3.f * (direction.x * acceleration) * dt;
			Player::setPosition((getPosition().x + (velocity.x)), getPosition().y);
			walk.setFlipped(true);
		}
	}


	////######  STOPPED  ######
	else {	
		if (jumping) { //if player is mid jump
			walk.currentFrame = 0;
			setTextureRect(walk.getCurrentFrame());
		}
		else { //idle
			walk.currentFrame = 3;
			setTextureRect(walk.getCurrentFrame());
		}
		
		if (runningLeft == true) { ////slow down while running left
			velocity.x -= 0.08f * (direction.x * acceleration) * dt;
			Player::setPosition((getPosition().x - (velocity.x)), getPosition().y);
		}
		else if (runningRight == true) { ////slow down while running right
			velocity.x -= 0.08f * (direction.x * acceleration) * dt;
			Player::setPosition((getPosition().x + (velocity.x)), getPosition().y);
		}
		
		if (velocity.x < 0 && runningRight == true) { ////stop while right
			velocity.x = 0;
			runningRight = false;
			runningLeft = false;
		}
		else if (velocity.x < 0 && runningLeft == true) { ////stop while left
			velocity.x = 0;
			runningRight = false;
			runningLeft = false;
		}
	}


	////######  JUMP  ######
	if (input->isKeyDown(sf::Keyboard::W)) {
		walk.currentFrame = 0;
		setTextureRect(walk.getCurrentFrame());
		// unblock player, used in collision
		if (!jumping) { //check that player isn't already jumping
				velocity.y += jumpVel.y;
				sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt;
				Player::setPosition(getPosition().x, (getPosition().y + pos.y));
				jumping = true;
				onGround = false;
		}
	}
}











//#######################  UPDATE  #######################
void Player::update(float dt) {

	if (Player::getPosition().y >= 700) { 
			//for testing, incase player falls under map
			Player::setPosition(50, 200);
	}
		
	Player::setPosition(750, getPosition().y); //keep player centered

	if (onGround == false) { //gravity acts on player
			/*cout << " off ground\n";
			std::cout << " \n";*/
			velocity.y += gravity.y;
			sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt;
			Player::setPosition(getPosition().x, (getPosition().y + pos.y));
	}
	else {
		  velocity.y = 0;
	}		
}






	//################################# COLLISION RESPONSE #############################################
	void Player::collisionResponse(GameObject* collider){


		if (collisionUnder == true && onGround == false) { ////hit a ceiling
			velocity = sf::Vector2f(velocity.x, 0);
			onGround = false;
			collisionUnder = false;
		}

		else if(collisionOver == true) { ////hit the ground
			onGround = true;
			jumping = false;
			velocity = sf::Vector2f(velocity.x, 0);
			collisionOver = false;
		}
};
	