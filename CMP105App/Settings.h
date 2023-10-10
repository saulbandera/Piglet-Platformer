#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/TileMap.h"
#include <string>
#include <iostream>
#include "Level.h"

class Settings
{
public:
	Settings(sf::RenderWindow* hwnd, Input* in);
	~Settings();
	bool getReturnClicked();
	void setReturnClicked(bool clicked);
	bool getGodMode();
	void setGodMode(bool godmode);
	bool getAudioOn();
	void setAudioOn(bool audioon);
	void handleInput(float dt, sf::RenderWindow& win, bool menuSound, bool godmode);
	void update(float dt);
	void render();
	AudioManager settingsAudio;
private:

	bool returnClicked = false;
	bool godMode = false;
	bool audioOn = true;

	sf::RectangleShape background;
	sf::Texture back;
	sf::Mouse mouse;

	bool toggle = false;
	bool toggleA = false;
	////BUTTON
	sf::RectangleShape returnButton;
	sf::Texture rButton;
	sf::Texture rButtonPressed;


	sf::RectangleShape godModeButton;
	sf::Texture gButton;
	sf::Texture gButtonH;
	sf::Texture gButtonPressed;
	sf::Texture gButtonPressedH;

	sf::RectangleShape audioOffButton;
	sf::Texture aButton;
	sf::Texture aButtonH;
	sf::Texture aButtonPressed;
	sf::Texture aButtonPressedH;

	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;
	Input* input;

};
