#include "MovingEnemy.h"

#include <iostream>
using namespace std;
MovingEnemy::MovingEnemy() 
{
	////  ANIMATION
	moveAnim.addFrame(sf::IntRect(0, 0, 78, 58));
	moveAnim.addFrame(sf::IntRect(78, 0, 78, 58));
	moveAnim.addFrame(sf::IntRect(156, 0, 78, 58));
	moveAnim.addFrame(sf::IntRect(234, 0, 78, 58));
	moveAnim.addFrame(sf::IntRect(312, 0, 78, 58));
	moveAnim.addFrame(sf::IntRect(390, 0, 78, 58));
	moveAnim.addFrame(sf::IntRect(468, 0, 78, 58));
	moveAnim.addFrame(sf::IntRect(546, 0, 78, 58));
	moveAnim.setFrameSpeed(0.1f);
}
MovingEnemy::~MovingEnemy() {}


bool MovingEnemy::getMovingLeft() {
	return movingLeft;
}
void MovingEnemy::setMovingLeft(bool left) {
	movingLeft = left;
}


//#######################  UPDATE  #######################
void MovingEnemy::update(float dt, float playerX)
{
	setTextureRect(moveAnim.getCurrentFrame());
	if (playerX >= MovingEnemy::getPosition().x - 800 ) { // is in range 
		if (movingLeft == false) {
			moveAnim.setFlipped(false);
			move(100 * dt, 0);
		}
		if (movingLeft == true) {
			moveAnim.setFlipped(true);
			move(-100 * dt, 0);
		}


		moveAnim.animate(dt);
		setTextureRect(moveAnim.getCurrentFrame());
	}

	else {
		moveAnim.currentFrame = 0;
		setTextureRect(moveAnim.getCurrentFrame());
	}
}






//#######################  COLLISION  #######################
void MovingEnemy::collisionResponse() {
	if (movingLeft == false) {
		movingLeft = true;
	}
	else {
		movingLeft = false;
	}
	
};






//#######################  RENDER  #######################
void MovingEnemy::render(sf::RenderWindow* window) {
	window->draw(*this);
}
