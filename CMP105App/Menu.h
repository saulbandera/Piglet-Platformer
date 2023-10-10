#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/TileMap.h"
#include "Framework/AudioManager.h"
#include <string>
#include <iostream>
#include "Level.h"

class Menu{
public:
	  Menu(sf::RenderWindow* hwnd, Input* in);
 	  ~Menu();
	  AudioManager menuAudio;


	  bool getPlayClicked();
	  void setPlayClicked(bool clicked);

	  bool getInstructionsClicked();
	  void setInstructionsClicked(bool clicked);

	  bool getSettingsClicked();
	  void setSettingsClicked(bool clicked);
	  void handleInput(float dt, sf::RenderWindow& win, bool soundOn);
 	  void update(float dt, bool soundOn);
  	  void render();
	

private:

	bool playClicked = false;
	bool instructionsClicked = false;
	bool settingsClicked = false;
	
	  ////BACKGROUND
	  sf::RectangleShape background;
	  sf::Texture back;
	  sf::Mouse mouse;

	  ////BUTTONS
	  sf::RectangleShape playButton;
	  sf::Texture pButton;
	  sf::Texture pButtonPressed;

	  sf::RectangleShape instructionsButton;
	  sf::Texture iButton;
	  sf::Texture iButtonPressed;
	  
	  sf::RectangleShape settingsButton;
	  sf::Texture sButton;
	  sf::Texture sButtonPressed;

      void beginDraw();
	  void endDraw();
	  sf::RenderWindow* window;
	  Input* input;
};


