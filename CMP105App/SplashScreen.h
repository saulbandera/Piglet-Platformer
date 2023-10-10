#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/TileMap.h"
#include <string>
#include <iostream>
#include "splashAnimation.h"
class SplashScreen
{
public:
	SplashScreen(sf::RenderWindow* hwnd, Input* in);
	~SplashScreen();
	void update(float dt);
	void render();


private:
	splashAnimation anim;
	sf::Texture animTexture;
	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;
	Input* input;

};

