#include "Menu.h"



Menu::Menu(sf::RenderWindow* hwnd, Input* in)
{ 

	
	window = hwnd;
	input = in;

	

	////   BACKGROUND
	back.loadFromFile("gfx/menuBackground.png");
	background.setTexture(&back);
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

	////   BUTTONS
	pButton.loadFromFile("gfx/play.png");
	playButton.setTexture(&pButton);
	playButton.setPosition((window->getSize().x / 2)- 375, 150);
	playButton.setSize(sf::Vector2f(202.5, 37.5));
	pButtonPressed.loadFromFile("gfx/playHighlighted.png");

	iButton.loadFromFile("gfx/instructions.png");
	instructionsButton.setTexture(&iButton);
	instructionsButton.setPosition((window->getSize().x / 2) - 375, 350);
	instructionsButton.setSize(sf::Vector2f(615, 37.5));
	iButtonPressed.loadFromFile("gfx/instructionsHighlighted.png");

	sButton.loadFromFile("gfx/settings.png");
	settingsButton.setTexture(&sButton);
	settingsButton.setPosition((window->getSize().x / 2) - 375, 550);
	settingsButton.setSize(sf::Vector2f(412.5, 37.5));
	sButtonPressed.loadFromFile("gfx/settingsHighlighted.png");
	
    ////   AUDIO
	menuAudio.addMusic("sfx/menuSong.wav", "menuSong");
	menuAudio.addSound("sfx/overButton.wav", "hoverButton");
}

Menu::~Menu(){}


bool Menu::getPlayClicked() {
	return playClicked;
}
void Menu::setPlayClicked(bool clicked) {
	playClicked = clicked;
}


bool Menu::getInstructionsClicked() {
	return instructionsClicked;
}
void Menu::setInstructionsClicked(bool clicked) {
	instructionsClicked = clicked;
}

bool Menu::getSettingsClicked() {
	return settingsClicked;
}

void Menu::setSettingsClicked(bool clicked) {
	settingsClicked = clicked;
}
//#######################  HANDLE INPUT  #######################
void Menu::handleInput(float dt, sf::RenderWindow &win, bool soundOn){
	if (sf::Event::MouseMoved) {
		////######  CHECK FOR MOUSE INPUT  ######
		if (sf::Mouse::getPosition(win).x >= playButton.getPosition().x-150 && sf::Mouse::getPosition(win).x <= playButton.getPosition().x+ 450) {

			if (sf::Mouse::getPosition(win).y >= playButton.getPosition().y && sf::Mouse::getPosition(win).y <= playButton.getPosition().y+ 37.5) {
				// over play button
	
	
				playButton.setTexture(&pButtonPressed);
				instructionsButton.setTexture(&iButton);
				settingsButton.setTexture(&sButton);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					Menu::playClicked = true;
					if (soundOn) {
						menuAudio.playSoundbyName("hoverButton");
					}
				}
			}

			else if (sf::Mouse::getPosition(win).y >= instructionsButton.getPosition().y && sf::Mouse::getPosition(win).y <= instructionsButton.getPosition().y + 37.5) {
				// over instruction button
				
				instructionsButton.setTexture(&iButtonPressed);
				playButton.setTexture(&pButton);
				settingsButton.setTexture(&sButton);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Menu::instructionsClicked = true;
					if (soundOn) {
						menuAudio.playSoundbyName("hoverButton");
					}
				}
			}

			else if (sf::Mouse::getPosition(win).y >= settingsButton.getPosition().y && sf::Mouse::getPosition(win).y <= settingsButton.getPosition().y + 37.5) {
				// over settings button
		
			
				settingsButton.setTexture(&sButtonPressed);
				playButton.setTexture(&pButton);
				instructionsButton.setTexture(&iButton);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					Menu::settingsClicked = true;
					if (soundOn) {
						menuAudio.playSoundbyName("hoverButton");
					}
				}
			}

			else {
				//// no buttons highlighted
				settingsButton.setTexture(&sButton);
				playButton.setTexture(&pButton);
				instructionsButton.setTexture(&iButton);
			}
		}
		else {
			//// no buttons highlighted
			settingsButton.setTexture(&sButton);
			playButton.setTexture(&pButton);
			instructionsButton.setTexture(&iButton);
		}

		
	}



}
//#######################  UPDATE  #######################
void Menu::update(float dt, bool soundOn)
{

	if (menuAudio.getMusic()->getStatus() == sf::SoundSource::Stopped && soundOn) {
		menuAudio.playMusicbyName("menuSong");
	}

	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	playButton.setPosition((window->getSize().x / 2) - 101, 100);
	instructionsButton.setPosition((window->getSize().x / 2) - 307.5, 300);
	settingsButton.setPosition((window->getSize().x / 2) - 206, 500);
}




//#######################  RENDER  #######################
void Menu::render() {
	beginDraw();
	window->draw(background);
	window->draw(playButton);
	window->draw(instructionsButton);
	window->draw(settingsButton);
	endDraw();
}



void Menu::beginDraw() {
	window->clear(sf::Color(33, 33, 33));
}
void Menu::endDraw() {
	window->display();
}