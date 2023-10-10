#pragma once
#include <vector>
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"

class MovingEnemy : public GameObject {
public:
	MovingEnemy();
	~MovingEnemy();

	bool getMovingLeft();
	void setMovingLeft(bool left);
	void update(float dt, float playerX) ;
	void collisionResponse();
	void render(sf::RenderWindow* window);

	
private:
	bool movingLeft = false; //the direction in which it is moving
	Animation moveAnim;
};
