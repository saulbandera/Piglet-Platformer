#include "MovingSpawner.h"

MovingSpawner::MovingSpawner() {
	texture.loadFromFile("gfx/KingRun.png");
	//initialize 6 moving enemies
	for (int i = 0; i < 4; i++) {
		movingEnemies.push_back(MovingEnemy());
		movingEnemies[i].setAlive(false);
		movingEnemies[i].setTexture(&texture);
		movingEnemies[i].setCollisionBox(sf::FloatRect(100, 50, 39, 55));
		movingEnemies[i].setSize(sf::Vector2f(195, 145));
	}
}
MovingSpawner::~MovingSpawner() {}






//#######################  UPDATE MOVING ENEMIES  #######################
void MovingSpawner::update(float dt, float playerX, float pVelX, bool left, bool right,bool blocked, sf::RenderWindow* hwnd) {
	window = hwnd;
	for (int i = 0; i < movingEnemies.size(); i++) {
		if (movingEnemies[i].isAlive()) {
			//move according to player velocity
			movingEnemies[i].update(dt, playerX);
			if (right && !blocked) {
				movingEnemies[i].move(-pVelX, 0);
			}
			if (left && !blocked) {
				movingEnemies[i].move(pVelX, 0);
			}
		}
	}
}






//#######################  SPAWN  #######################
void MovingSpawner::spawn(){
	for (int i = 0; i < movingEnemies.size(); i++) {
		if (!movingEnemies[i].isAlive()) {
			movingEnemies[i].setAlive(true);
			movingEnemies[i].setPosition(sf::Vector2f(spawnPositions[0][i], spawnPositions[1][i]));
		}
	}
}






//#######################  RENDER  #######################
void MovingSpawner::render(sf::RenderWindow* window){
	for (int i = 0; i < movingEnemies.size(); i++) {
		////draw enemies
		if (movingEnemies[i].isAlive()) {
			window->draw(movingEnemies[i]);
			movingEnemies[i].render(window);
		}
	}
}