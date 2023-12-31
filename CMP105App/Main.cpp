// CODE BY: Saul Bandera Brotheridge, Student Num: 1900264
#include <iostream>
#include "Level.h"
#include "SplashScreen.h"
#include "Menu.h"
#include "Instructions.h"
#include "Settings.h"
bool settings = false;
bool menuOpen = false;
int counter = 0;
bool godMode = false;
bool sound = true;




//#######################  CHECK EVENTS  #######################
void eventCheck(sf::RenderWindow &window, Input &input) { 
	sf::Event event;
	while (window.pollEvent(event)){
		switch (event.type){
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
			if (event.mouseButton.button == sf::Mouse::Left){
				//update input class
				input.setMouseLDown(true);
			}
			else if (event.mouseButton.button == sf::Mouse::Right){
				input.setMouseRDown(true);
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left){
				//update input class
				input.setMouseLDown(false);
			}
			else if (event.mouseButton.button == sf::Mouse::Right){
				input.setMouseRDown(false);
			}
			break;
		default:
			// don't handle other events
			break;
		}
	}
}






//#######################  LOOP MENU  #######################
void menuLoop(sf::RenderWindow& menuWindow, Input& menuIN, Menu& menu, float deltaTime, sf::Clock& clock, bool menuOpen) {
	while (menuOpen == false) {
		// Handle window events.
		eventCheck(menuWindow, menuIN);
		deltaTime = clock.restart().asSeconds();
		menu.handleInput(deltaTime, menuWindow, sound);
		menu.update(deltaTime, sound);
		menu.render();

		////######  PLAY  ######
		if (menu.getPlayClicked() == true) {
			// start game
			menu.menuAudio.stopAllMusic();
			menu.setPlayClicked(false);
			Input input;
			Level level(&menuWindow, &input);
			while (level.getReturnClicked() == false && menuWindow.isOpen()) { //while player hasn't died or completed the level
				eventCheck(menuWindow, input);
				deltaTime = clock.restart().asSeconds();
				level.handleInput(deltaTime);
				level.update(deltaTime, godMode, sound);
				level.render();
			}
			menuOpen = true;
		}

		////######  INSTRUCTIONS  ######
		else if (menu.getInstructionsClicked() == true) {
			// open instructions 
			menu.setInstructionsClicked(false);
			Instructions instructions(&menuWindow, &menuIN);
			while (instructions.getReturnClicked() == false && menuWindow.isOpen()) { 
				eventCheck(menuWindow, menuIN);
				deltaTime = clock.restart().asSeconds();
				instructions.handleInput(deltaTime, menuWindow, sound);
				instructions.update(deltaTime);
				instructions.render();
			}
			menuOpen = true;
		}

		////######  SETTINGS  ######
		else if (menu.getSettingsClicked() == true) {
			menu.setSettingsClicked(false);
			Settings settings(&menuWindow, &menuIN);
			while (settings.getReturnClicked() == false && menuWindow.isOpen()) {
				eventCheck(menuWindow, menuIN);
				deltaTime = clock.restart().asSeconds();
				settings.handleInput(deltaTime, menuWindow, sound, godMode);
				settings.update(deltaTime);
				settings.render();
				if (settings.getGodMode()) {
					godMode = true;
				}
				if (!settings.getGodMode()) {
					godMode = false;
				}

				if (settings.getAudioOn()) {
					sound = true;
				}
				if (!settings.getAudioOn()) {
					sound = false;
				}
			}
			menuOpen = true;
		}
	}
}






//#######################  MAIN  #######################
int main()
{

    ////  SPLASH SCREEN WITH MY LOGO
	sf::RenderWindow splash(sf::VideoMode(300, 300), " ");
	Input splashInput;
	SplashScreen spscreen(&splash, &splashInput);
	sf::Clock clock;
	sf::Clock timerSplash;
	float timer;
	float deltaTime;
	timer = timerSplash.restart().asSeconds();
	while (timer < 1.f) {
		timer = timerSplash.getElapsedTime().asSeconds();
		deltaTime = clock.restart().asSeconds();
		spscreen.update(deltaTime);
		spscreen.render();
	}
	splash.close();


    ////  MENU
	sf::RenderWindow menuWindow(sf::VideoMode(1500, 675), " ");
	Input menuIN;
	while (menuWindow.isOpen()) { //keeps the game running
		Menu menu(&menuWindow, &menuIN);
		deltaTime = clock.restart().asSeconds();
		menuLoop(menuWindow, menuIN, menu, deltaTime, clock, menuOpen);
		std::cout << "The End\n";
	}
}