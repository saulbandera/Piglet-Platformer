#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string.h>
#include <iostream>
class Camera : public GameObject{
public:
	Camera();
	~Camera();

	void setWindow(sf::RenderWindow* win);
	void handleInput(float dt, float speedX, float speedY);
	void render(sf::RenderWindow* window);
	

private:
	sf::RenderWindow* window;
};