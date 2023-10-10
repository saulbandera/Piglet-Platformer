#pragma once
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"
#include "Cannon.h"
#include<math.h>
#include<vector>

class CannonSpawner {

public:
	CannonSpawner();
   ~CannonSpawner();
void spawn();
void update(float dt, float playerX, float pVelX, bool left, bool right,bool blocked, sf::RenderWindow* hwnd);
void render(sf::RenderWindow* window);
std::vector<Cannon> cannons;
private:
	int spawnPositions[2][4] = { {2200,3990,4820,5260},{370,570,115,570} }; //positions for spawning
	sf::RenderWindow* window;
	sf::Vector2f spawnPoint;
	sf::Texture texture; };