#include "Settings.h"

Settings::Settings(sf::RenderWindow* hwnd, Input* in)
{

	window = hwnd;
	input = in;

	////  BACKGROUND
	back.loadFromFile("gfx/menuBackGround.png");
	background.setTexture(&back);
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));


	////  BUTTON







	rButton.loadFromFile("gfx/return.png");
	returnButton.setTexture(&rButton);
	returnButton.setPosition(900, 500);
	returnButton.setSize(sf::Vector2f(307.5, 37.5));
	rButtonPressed.loadFromFile("gfx/returnHighlighted.png");


	gButton.loadFromFile("gfx/godMode.png");
	godModeButton.setTexture(&gButton);
	godModeButton.setPosition(900, 100);
	godModeButton.setSize(sf::Vector2f(648, 112.5));
	gButtonH.loadFromFile("gfx/godModeH.png");
	gButtonPressedH.loadFromFile("gfx/godModeSelH.png");
	gButtonPressed.loadFromFile("gfx/godModeSel.png");

	aButton.loadFromFile("gfx/audioOff.png");
	audioOffButton.setTexture(&aButton);
	audioOffButton.setPosition(900, 300);
	audioOffButton.setSize(sf::Vector2f(648, 112.5));
	aButtonH.loadFromFile("gfx/audioOffH.png");
	aButtonPressedH.loadFromFile("gfx/audioOffSelH.png");
	aButtonPressed.loadFromFile("gfx/audioOffSel.png");

	
	settingsAudio.addSound("sfx/overButton.wav", "clickButton");
}



Settings::~Settings()
{}

bool Settings::getReturnClicked() {
	return returnClicked;
}
void Settings::setReturnClicked(bool clicked) {
	returnClicked = clicked;
}


bool Settings::getGodMode() {
	return godMode;
}

void Settings::setGodMode(bool godmode) {
	godMode = godmode;
}

bool Settings::getAudioOn() {
	return audioOn;
}

void Settings::setAudioOn(bool on) {
	audioOn = on;
}
//#######################  HANDLE INPUT  #######################
void Settings::handleInput(float dt, sf::RenderWindow& win, bool menuSound, bool godmode)
{
	//std::cout << "menu sound is: " << menuSound << " \n";
	
	audioOn = menuSound;

	godMode = godmode;

	if (sf::Event::MouseMoved) {
		////######  CHECK FOR MOUSE INPUT  ######
		if (sf::Mouse::getPosition(win).x >= returnButton.getPosition().x && sf::Mouse::getPosition(win).x <= returnButton.getPosition().x + 500) {


			if (sf::Mouse::getPosition(win).y >= returnButton.getPosition().y && sf::Mouse::getPosition(win).y <= returnButton.getPosition().y + 37.5) {
				// over return button
				returnButton.setTexture(&rButtonPressed);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						returnClicked = true;
					
					
				
				}
			}
			else {
				returnButton.setTexture(&rButton);
			}




			if (sf::Mouse::getPosition(win).y >= godModeButton.getPosition().y && sf::Mouse::getPosition(win).y <= godModeButton.getPosition().y + 112.5) {
				// over return button
				if (godMode) {
					godModeButton.setTexture(&gButtonPressedH);
					
				}
				else {
					godModeButton.setTexture(&gButtonH);
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && godMode == true && toggle == false) {
					if (menuSound) {
						settingsAudio.playSoundbyName("clickButton");
					}
					godMode = false;
					toggle = true;
					godModeButton.setTexture(&gButton);
				

				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && godMode == false && toggle == false) {
					if (menuSound) {
						settingsAudio.playSoundbyName("clickButton");
					}
					godMode = true;
					toggle = true;
					godModeButton.setTexture(&gButtonPressed);
				
				}
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					toggle = false;
				}
			}

			else {
				if (godMode) {
					godModeButton.setTexture(&gButtonPressed);
					
				}
				else {
					godModeButton.setTexture(&gButton);
				}
			}





		if (sf::Mouse::getPosition(win).y >= audioOffButton.getPosition().y && sf::Mouse::getPosition(win).y <= audioOffButton.getPosition().y + 112.5) {
				if (audioOn) {
					//std::cout << "button highlighted pressed\n";
					audioOffButton.setTexture(&aButtonH);
				}
				else {
					audioOffButton.setTexture(&aButtonPressedH);
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && audioOn == true && toggleA == false) {
					if (menuSound) {
						settingsAudio.playSoundbyName("clickButton");
					}
					audioOn = false;
					toggleA = true;
					audioOffButton.setTexture(&aButtonPressed);
				}
				 if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && audioOn == false && toggleA == false) {
					 if (menuSound) {
						 settingsAudio.playSoundbyName("clickButton");
					 }
					audioOn = true;
					toggleA = true;
					audioOffButton.setTexture(&aButton);
				}
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					toggleA = false;
				}
		}
		else {
			if (audioOn) {
				audioOffButton.setTexture(&aButton);
			}
			else {
				audioOffButton.setTexture(&aButtonPressed);					
				}
			}
		}











		}
		else {
			if (!godMode) {
				godModeButton.setTexture(&gButtonPressed);
			}
			else {
				godModeButton.setTexture(&gButton);
			}
			if (!audioOn) {
				audioOffButton.setTexture(&aButtonPressed);
			}
			else {
				audioOffButton.setTexture(&aButton);
			}
			// no button highlighted
			returnButton.setTexture(&rButton);
		}


	}




//#######################  UPDATE  #######################
void Settings::update(float dt) {
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	returnButton.setPosition(575, 500);
	godModeButton.setPosition(475, 100);
	audioOffButton.setPosition(475, 300);
}




//#######################  RENDER  #######################
void Settings::render() {
	beginDraw();
	window->draw(background);
	window->draw(returnButton);
	window->draw(godModeButton);
	window->draw(audioOffButton);
	endDraw();
}

void Settings::beginDraw() {
	window->clear(sf::Color(33, 33, 33));
}
void Settings::endDraw() {
	window->display();
}

