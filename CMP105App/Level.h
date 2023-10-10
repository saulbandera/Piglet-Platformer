#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/TileMap.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "TileMap1.h"
#include "Projectile.h"
#include "Camera.h"
#include "Cannon.h"
#include "MovingEnemy.h"
#include "EndPortal.h"
#include "LevelComplete.h"
#include "CannonSpawner.h"
#include "DeathScreen.h"
#include "MovingSpawner.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();
	bool getReturnClicked();
	void setReturnClicked(bool clicked);

	bool getReturnToMenu();
	void setReturnToMenu(bool returnM);
	void eventCheck(sf::RenderWindow& window, Input& input);
	void handleInput(float dt);
	void update(float dt, bool godMode, bool soundOn);
	void render();


	


private:
	bool returnToMenu = false;
	bool returnClicked = false;
	// player
	Player player;
	sf::Texture playerTexture;
	sf::RectangleShape cBox;
	sf::RectangleShape line;

	// camera
	sf::Texture camera1;
	sf::Texture layer;
	sf::Texture layer2text;

	// tilemap
	TileMap1 tileMap;

	// cannonball
	Projectile cannonBall;
	sf::Texture cballTexture;

	// cannons
	CannonSpawner allCannons;

	// moving enemy
	MovingSpawner allMoving;

	//portal at end of level
	EndPortal portal;
	sf::Texture pTexture;

	std::vector<GameObject>gameObjects;
	AudioManager audio;

	sf::RectangleShape cbox;


	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;
	Input* input;
	/*GameState* gameState;
	AudioManager* audio;*/
	Camera camera;
	Camera layer1;
	Camera layer2;
};