#include "Projectiles.h"

#include <iostream>
using namespace std;
Projectiles::Projectiles() {
	// Setup walk animation.
	explode.addFrame(sf::IntRect(0, 0, 44, 28));
	explode.setFrameSpeed(0.07f);
	
}
Projectiles::~Projectiles()
{

}


void Projectiles::update(float dt)
{
	Projectiles::move(-10 * dt, 0);
}

void Projectiles::collisionResponse(GameObject* collider, float dt)
{
	//splode

	explode.animate(dt);
	setTextureRect(explode.getCurrentFrame());

	//kill sprite and player
};