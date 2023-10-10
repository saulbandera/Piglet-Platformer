#pragma once
#include "MovingEnemy.h"
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"
#include<math.h>
#include<vector>

class MovingSpawner {

public:
	MovingSpawner();
	~MovingSpawner();
	void spawn();
	void update(float dt, float playerX, float pVelX, bool left, bool right, bool blocked, sf::RenderWindow* hwnd);
	void render(sf::RenderWindow* window);
	std::vector<MovingEnemy> movingEnemies; //vector of moving enemies

private:
	int spawnPositions[2][4] = { {2551,3880,5080,6080},{520,520,520,520} }; //positions where they spawn
	sf::RenderWindow* window;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
};