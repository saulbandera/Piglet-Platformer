
#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/TileMap.h"
#include <string>
#include <iostream>
#include "Level.h"

class DeathScreen{
public:
	DeathScreen(sf::RenderWindow* hwnd, Input* in);
	~DeathScreen();
	bool getReturnClicked();
	void setReturnClicked(bool clicked);
	void handleInput(float dt, sf::RenderWindow& win, bool soundOn);
	void update(float dt, bool soundOn);
	void render();
	

private:
	bool returnClicked = false;
	sf::RectangleShape background;
	sf::Texture back;
	sf::Mouse mouse;
	////BUTTON
	sf::RectangleShape returnButton;
	sf::Texture rButton;
	sf::Texture rButtonPressed;
	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;
	Input* input;
	AudioManager deathAudio;
};


