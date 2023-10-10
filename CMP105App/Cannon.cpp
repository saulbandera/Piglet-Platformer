#include "Cannon.h"
#include <iostream>
using namespace std;
Cannon::Cannon() {
	////    FIRE ANIMATION
	fire.addFrame(sf::IntRect(0, 0, 44, 28));
	fire.addFrame(sf::IntRect(44, 0, 44, 28));
	fire.addFrame(sf::IntRect(88, 0, 44, 28));
	fire.addFrame(sf::IntRect(132, 0, 44, 28));
	fire.addFrame(sf::IntRect(0, 0, 44, 28));
	fire.setFrameSpeed(0.07f);
	fire.setLooping(false);


}
Cannon::~Cannon(){}






//#######################  UPDATE  #######################
void Cannon::update(float dt, float playerX){
	setTextureRect(fire.getCurrentFrame());
	if (playerX > Cannon::getPosition().x - 700) { ////if player in range, shoot
		if (drawCannonBall) {
			Projectile cannonBall;
			cannonBall.setCollisionBox(sf::FloatRect(50, 35, 25, 25));
			cannonBall.setPosition(getPosition().x, getPosition().y - 35);
			cannonBall.setSize(sf::Vector2f(110, 70));
			cannonBall.setPosition(getPosition().x, getPosition().y - 20);
			cannonProjectiles.push_back(cannonBall);
			drawCannonBall = false;
			
		}
		if (time.getElapsedTime().asSeconds() > fireRate) {
			//// shoot cannonball
		
			drawCannonBall = true;
			time.restart();
			fire.stop();
			fire.play(true);
		}
		fire.animate(dt);
		setTextureRect(fire.getCurrentFrame());
	}
	else {
		//// move cannonball
		fire.currentFrame = 0;
	
	}


	for (int i = 0; i < cannonProjectiles.size(); i++) {
		
		if (cannonProjectiles[i].getPosition().x > -100) {
			cannonProjectiles[i].setAlive(true);
		}
		else {
			cannonProjectiles[i].setAlive(false);
		}

		if (cannonProjectiles[i].isAlive()) {
			cannonProjectiles[i].update(dt);
		}
	}
}




//#######################  RENDER  #######################
void Cannon::render(sf::RenderWindow* window) {
	cballTexture.loadFromFile("gfx/Cannon Ball.png");
	for (int i = 0; i < cannonProjectiles.size(); i++) {
		if (cannonProjectiles[i].isAlive()) {
			cannonProjectiles[i].setTexture(&cballTexture);
			window->draw(cannonProjectiles[i]);
		}
		else {

		}
		
	}


	window->draw(*this);
	
}
