#pragma once
#include <vector>
#include "Projectile.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"

class Cannon : public GameObject{
public:
	Cannon();
	~Cannon();
	void update(float dt, float playerX);
	void render(sf::RenderWindow* window);
	
	//Projectile cannonBall;
	sf::Texture cballTexture;
	sf::Clock time;
	std::vector<Projectile> cannonProjectiles;
private:
	bool collision = false;
	float lastTime = 0.f; //check to keep the fire rate constant
	float fireRate = 1.4f; //how fast the cannon shoots
	float timePassed = 0.f;
	bool drawCannonBall = false;
	Animation fire;
};

