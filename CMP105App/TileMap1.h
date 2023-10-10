#pragma once
#include "Framework/GameObject.h"
#include "Framework/TileMap.h"
class TileMap1 :
	public GameObject
{
public:
	TileMap1();
	~TileMap1();
	void render(sf::RenderWindow*);
	TileMap tileMap;
private:
	
	GameObject tile;
	std::vector<GameObject> tiles; //vector for all the tiles
};

