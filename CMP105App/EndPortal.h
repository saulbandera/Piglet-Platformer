#pragma once
#include <vector>
#include "Projectile.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"

class EndPortal : public GameObject {
public:
	EndPortal();
	~EndPortal();
	void update(float dt) override;
	bool collision = false;
	sf::Texture portalTexture;

private:
	Animation animationPortal;
};

