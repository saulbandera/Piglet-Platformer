#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in){
	window = hwnd;
	input = in;

	////  PLAYER
	player.setInput(input);
	playerTexture.loadFromFile("gfx/Run (34x28).png");
	player.setCollisionBox(sf::FloatRect(35, 50, 27.5f, 47.5f));
	player.setPosition(50, 50);
	player.setSize(sf::Vector2f(100, 100));
	player.setTexture(&playerTexture);

	////  TILEMAP
	tileMap.tileMap.setPosition(sf::Vector2f(0, 0));
	
	////  CAMERA
	camera.setInput(input);
	camera1.loadFromFile("gfx/back.png");
	camera.setTexture(&camera1);
	camera.setPosition(0, 0);
	camera.setSize(sf::Vector2f(6617, 681));

	////  LAYER
	sf::Image layerImg;
	layerImg.loadFromFile("gfx/layer.png");
	layerImg.createMaskFromColor(sf::Color::White);
	layer1.setInput(input);
	layer.loadFromImage(layerImg);
	layer1.setTexture(&layer);
	layer1.setPosition(0, -40);
	layer1.setSize(sf::Vector2f(6617, 681));

	////  PORTAL
	pTexture.loadFromFile("gfx/Small_Iceball_9x24.png");
	portal.setCollisionBox(sf::FloatRect(25, 190, 50, 80));
	portal.setPosition(6800, 320);
	portal.setSize(sf::Vector2f(112.5f, 300));
	portal.setTexture(&pTexture);

	////  AUDIO
	audio.addMusic("sfx/gameSong.wav", "song"); 
	audio.addSound("sfx/buttonNote.wav", "death");
	audio.addSound("sfx/mud02.ogg", "run");

	////  ENEMIES
	allCannons.spawn();
	allMoving.spawn();


}

Level::~Level()
{
}



bool Level::getReturnClicked() {
	return returnClicked;
}
void Level::setReturnClicked(bool clicked) {
	returnClicked = clicked;
}


bool Level::getReturnToMenu() {
	return returnToMenu;
}
void Level::setReturnToMenu(bool ret) {
	returnToMenu = ret;
}



void Level::eventCheck(sf::RenderWindow& window, Input& input) {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized:
			window.setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
			break;
		case sf::Event::KeyPressed:
			// update input class
			input.setKeyDown(event.key.code);
			break;
		case sf::Event::KeyReleased:
			//update input class
			input.setKeyUp(event.key.code);
			break;
		case sf::Event::MouseMoved:
			//update input class
			input.setMousePosition(event.mouseMove.x, event.mouseMove.y);
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				//update input class
				input.setMouseLDown(true);
			}
			else if (event.mouseButton.button == sf::Mouse::Right) {
				input.setMouseRDown(true);
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left) {
				//update input class
				input.setMouseLDown(false);
			}
			else if (event.mouseButton.button == sf::Mouse::Right) {
				input.setMouseRDown(false);
			}
			break;
		default:
			// don't handle other events
			break;
		}
	}
}



//#######################  HANDLE INPUT  #######################
void Level::handleInput(float dt){
	////######  SCROLL LEVEL  ######
	player.handleInput(dt, camera.getPosition().x, portal.getPosition().x+100);
	//move according to player movement
	if (player.getRunningLeft() && player.getBlocked() == false) {
		camera.move(player.getVelocity().x/3, 0);
		layer1.move(player.getVelocity().x / 2, 0);
		portal.move(player.getVelocity().x, 0);
		
	}
	else if (player.getRunningRight() && player.getBlocked() == false ) {
		camera.move(-player.getVelocity().x/3, 0);
		layer1.move(-player.getVelocity().x /2 , 0);
		portal.move(-player.getVelocity().x, 0);
	
	}
	allCannons.update(dt, player.getPosition().x, player.getVelocity().x, player.getRunningLeft(), player.getRunningRight(), player.getBlocked(), window);
	allMoving.update(dt, player.getPosition().x, player.getVelocity().x, player.getRunningLeft(), player.getRunningRight(), player.getBlocked(), window);
	std::vector<GameObject>* world = tileMap.tileMap.getLevel();
	for (int i = 0; i < (int)world->size(); i++) { 
		if (player.getRunningLeft() && player.getBlocked() == false) {
			(*world)[i].move(player.getVelocity().x, 0);
		}
		else if (player.getRunningRight() && player.getBlocked() == false ) {
			(*world)[i].move(-player.getVelocity().x, 0);
		}
	}
}






//#######################  UPDATE GAME OBJECTS  #######################
void Level::update(float dt, bool godMode, bool soundOn){
	////AUDIO CONTROL
	if (audio.getSound("run")->getStatus() == sf::SoundSource::Stopped && soundOn &&player.getRunningRight()||audio.getSound("run")->getStatus() == sf::SoundSource::Stopped && soundOn && player.getRunningLeft() ) {
		if (player.getJumping()) {
			audio.getSound("run")->setVolume(0);

		}
		else {
			audio.getSound("run")->setVolume(100);
			audio.playSoundbyName("run");
		}
	}
	else if (player.getJumping()) {
		audio.getSound("run")->setVolume(0);
	
	}
	



	if (audio.getMusic()->getStatus() == sf::SoundSource::Stopped && soundOn) {
		audio.playMusicbyName("song"); }
    
	portal.update(dt);
	
	player.update(dt);
    //######  COLLISION CHECKING ######
	std::vector<GameObject>* world = tileMap.tileMap.getLevel();
	for (int i = 0; i < (int)world->size(); i++) { //// loop through each object in the tilemap


		//// PLAYER AND TILES
		if ((*world)[i].isCollider()) {
			if (Collision::checkBoundingBox(&player, &(*world)[i])) {
				

			
							if (player.getVelocity().y < 0) { //// collision with ceiling
								player.setPosition(player.getPosition().x, (*world)[i].getCollisionBox().top + 12.5f);
								player.setCollisionUnder(true);
								player.collisionResponse(&(*world)[i]);
							}
							if (player.getVelocity().y > 0) { //// collision with ground
								player.setPosition(player.getPosition().x, (*world)[i].getCollisionBox().top - player.getCollisionBox().height - 50);
								player.setCollisionOver(true);
								player.collisionResponse(&(*world)[i]);
							}
						
			
			}
			else {
					player.setOnGround(false);
			}



			

			////  MOVING ENEMY AND WALL
			for (int x = 0; x < allMoving.movingEnemies.size(); x++) {
				if (Collision::checkBoundingBox(&allMoving.movingEnemies[x], &(*world)[i])) {
					if (allMoving.movingEnemies[x].getMovingLeft() == true) {
						allMoving.movingEnemies[x].setPosition(((*world)[i].getCollisionBox().left + 50.f), (allMoving.movingEnemies[x].getPosition().y));
					}
					else {
						allMoving.movingEnemies[x].setPosition(((*world)[i].getCollisionBox().left - 180.f), (allMoving.movingEnemies[x].getPosition().y));
					}
					allMoving.movingEnemies[x].collisionResponse();
				}
			
			
			}

		}

	}
	//// PLAYER AND PORTAL
	if (Collision::checkBoundingBox(&player, &portal)){  
		Input completeInput;
		LevelComplete levelCompleted(window, &completeInput);
		audio.stopAllMusic();
		//// open and manage level complete window
		while (levelCompleted.getReturnClicked() == false && window->isOpen()) {
			
			eventCheck(*window, *input);
			levelCompleted.handleInput(dt, *window, soundOn);
			levelCompleted.update(dt, soundOn);
			levelCompleted.render();
		}
		returnClicked = true;
	}
	

	if (godMode == false) {
		// PLAYER AND CANNONS/MOVING ENEMIES
		for (int i = 0; i < allCannons.cannons.size(); i++) {
			for (int prj = 0; prj < allCannons.cannons[i].cannonProjectiles.size(); prj++) {
				if (Collision::checkBoundingBox(&player, &allCannons.cannons[i].cannonProjectiles[prj]) || Collision::checkBoundingBox(&player, &allCannons.cannons[i])) {
					if ( soundOn) {
						audio.playSoundbyName("death");
					}
					Input deathInput;
						DeathScreen deathScreen(window, &deathInput);
						//// open and manage death window
						audio.stopAllMusic();
						while (deathScreen.getReturnClicked() == false && window->isOpen()) {
							eventCheck(*window,*input);
							deathScreen.handleInput(dt, *window, soundOn);
							deathScreen.update(dt, soundOn);
							deathScreen.render();
						}
					returnClicked = true;
				
					break;
				}

				if (Collision::checkBoundingBox(&player, &allMoving.movingEnemies[i])) {
					if (allMoving.movingEnemies[i].isAlive()) {
						if (player.getJumping()) {
							player.setPosition(player.getPosition().x, allMoving.movingEnemies[i].getCollisionBox().top - player.getCollisionBox().height - 50);
							player.setVelocity(sf::Vector2f(player.getVelocity().x, -500));
							allMoving.movingEnemies[i].setAlive(false);
						
						}
						else {
							if (soundOn) {
								audio.playSoundbyName("death");
							}
							Input deathInput;
							DeathScreen deathScreen(window, &deathInput);
							audio.stopAllMusic();
							//// open and manage death window
							while (deathScreen.getReturnClicked() == false && window->isOpen()) {
								eventCheck(*window, *input);
								deathScreen.handleInput(dt, *window, soundOn);
								deathScreen.update(dt, soundOn);
								deathScreen.render();
							}
							returnClicked = true;

							break;

						}
					}
				}
			}

		}
	}
}






//#######################  RENDER  #######################
void Level::render(){
	beginDraw();
	window->draw(camera);
	window->draw(layer1);
	window->draw(player);
	allCannons.render(window);
	allMoving.render(window);
	tileMap.render(window);
	
	window->draw(portal);
	endDraw();
}
void Level::beginDraw(){
	window->clear(sf::Color(240, 0, 240));
}
void Level::endDraw(){
	window->display();
}