#include "splashAnimation.h"
#include "MovingEnemy.h"

#include <iostream>
using namespace std;
splashAnimation::splashAnimation() {


	//// ANIMATION
	moveAnim.addFrame(sf::IntRect(1,  0, 626, 626));
	moveAnim.addFrame(sf::IntRect(626,  0, 626, 626));
	moveAnim.addFrame(sf::IntRect(1251, 0, 626, 626));
	moveAnim.addFrame(sf::IntRect(1,  790, 626, 626));
	moveAnim.addFrame(sf::IntRect(626, 790, 626, 626));
	moveAnim.addFrame(sf::IntRect(1251, 790, 626, 626));
	moveAnim.setFrameSpeed(0.1f);



}
splashAnimation::~splashAnimation() {}




void splashAnimation::update(float dt) {
			moveAnim.animate(dt);
			setTextureRect(moveAnim.getCurrentFrame());
}
