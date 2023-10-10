#include "CannonSpawner.h"


CannonSpawner::CannonSpawner(){
	texture.loadFromFile("gfx/Shoot (44x28).png");
	//initialize 6 cannon spawn
	for(int i = 0; i < 4; i++){
		cannons.push_back(Cannon());
		cannons[i].setAlive(false);
		cannons[i].setTexture(&texture);
		cannons[i].setCollisionBox(sf::FloatRect(0, 0, 44 / 2, 28 / 2));
		cannons[i].setSize(sf::Vector2f(110, 70));
	}
}
CannonSpawner::~CannonSpawner(){}






//#######################  UPDATE CANNONS  #######################
void CannonSpawner::update(float dt, float playerX, float pVelX, bool left, bool right,bool blocked, sf::RenderWindow* hwnd){
	window = hwnd;
	for(int i = 0; i < cannons.size(); i++){
		if(cannons[i].isAlive()){
			//move according to player velocity
			cannons[i].update(dt, playerX);
			if (right && !blocked) {
				cannons[i].move(-pVelX, 0);
				
			}
			if (left&& !blocked) {
				cannons[i].move(pVelX, 0);
				
			}
		}
	}
}






//#######################  SPAWN  #######################
void CannonSpawner::spawn(){
	for (int i = 0; i < cannons.size(); i++){
		if (!cannons[i].isAlive()){
			cannons[i].setAlive(true);
			cannons[i].setPosition(sf::Vector2f(spawnPositions[0][i], spawnPositions[1][i]));
		}
	}
}






//#######################  RENDER  #######################
void CannonSpawner::render(sf::RenderWindow* window){
	for (int i = 0; i < cannons.size(); i++){
		if (cannons[i].isAlive()){
			window->draw(cannons[i]);
			cannons[i].render(window);
		}
	}
}

































































































