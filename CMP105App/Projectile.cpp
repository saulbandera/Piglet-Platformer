#include "Projectile.h"
Projectile::Projectile() {
}
Projectile::~Projectile(){}


void Projectile::update(float dt){
	//move cannonball
	Projectile::move(-1600 * dt, 0);
}




