#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"
class Projectile : public GameObject{
public:
	Projectile();
	~Projectile();
	void update(float dt) override;

};

