#include "EndPortal.h"
#include "Cannon.h"
#include <iostream>
using namespace std;
EndPortal::EndPortal() {
	//// ANIMATION
	animationPortal.addFrame(sf::IntRect(0, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(9, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(18, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(27, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(36, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(45, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(54, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(63, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(72, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(81, 0, 9, 24));
	animationPortal.addFrame(sf::IntRect(0, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(9, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(18, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(27, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(36, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(45, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(54, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(63, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(72, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(81, 24, 9, 24));
	animationPortal.addFrame(sf::IntRect(0, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(9, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(18, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(27, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(36, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(45, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(54, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(63, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(72, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(81, 48, 9, 24));
	animationPortal.addFrame(sf::IntRect(0, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(9, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(18, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(27, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(36, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(45, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(54, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(63, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(72, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(81, 72, 9, 24));
	animationPortal.addFrame(sf::IntRect(0, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(9, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(18, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(27, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(36, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(45, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(54, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(63, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(72, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(81, 96, 9, 24));
	animationPortal.addFrame(sf::IntRect(0, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(9, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(18, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(27, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(36, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(45, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(54, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(63, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(72, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(81, 120, 9, 24));
	animationPortal.addFrame(sf::IntRect(0, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(9, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(18, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(27, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(36, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(45, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(54, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(63, 140, 9, 24));
	animationPortal.addFrame(sf::IntRect(72, 144, 9, 24));
	animationPortal.addFrame(sf::IntRect(81, 144, 9, 24));
	animationPortal.setFrameSpeed(0.01f);
	animationPortal.setLooping(false);
}
EndPortal::~EndPortal() {}

void EndPortal::update(float dt){
	//// loop animation
	animationPortal.animate(dt);
	if (animationPortal.currentFrame >= 60) {
		animationPortal.currentFrame = 0;
	}
	setTextureRect(animationPortal.getCurrentFrame());
}


