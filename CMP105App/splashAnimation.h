#pragma once
#include <vector>

#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"

class splashAnimation : public GameObject {
public:
	
	splashAnimation();
	~splashAnimation();
	void update(float dt) override;
private:
	//// animation for my logo
	Animation moveAnim;
};
