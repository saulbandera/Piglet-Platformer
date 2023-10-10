#include "LevelComplete.h"





LevelComplete::LevelComplete(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	//// BACKGROUND
	back.loadFromFile("gfx/levelCompleted.png");
	background.setTexture(&back);
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));


	//// BUTTON
	rButton.loadFromFile("gfx/return.png");
	returnButton.setTexture(&rButton);
	returnButton.setPosition(900, 300);
	returnButton.setSize(sf::Vector2f(307.5, 37.5));
	rButtonPressed.loadFromFile("gfx/returnHighlighted.png");

	//// AUDIO
	completedAudio.addMusic("sfx/completedSong.wav", "completedSong");
	completedAudio.addSound("sfx/overButton.wav", "clickedButton");
}



LevelComplete::~LevelComplete(){}

bool LevelComplete::getReturnClicked() {
	return returnClicked;
}
void LevelComplete::setReturnClicked(bool clicked) {
	returnClicked = clicked;
}



//#######################  HANDLE INPUT  #######################
void LevelComplete::handleInput(float dt, sf::RenderWindow& win, bool soundOn){
	if (sf::Event::MouseMoved) {
		if (sf::Mouse::getPosition(win).x >= returnButton.getPosition().x && sf::Mouse::getPosition(win).x <= returnButton.getPosition().x + 307.5) {
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
		}
		else {
			returnButton.setTexture(&rButton);
		}
	}
}






//#######################  UPDATE  #######################
void LevelComplete::update(float dt, bool soundOn){
	if (completedAudio.getMusic()->getStatus() == sf::SoundSource::Stopped && soundOn) {
		completedAudio.playMusicbyName("completedSong");
	}
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	returnButton.setPosition(571, 500);
}






//#######################  RENDER  #######################
void LevelComplete::render() {
	beginDraw();
	window->draw(background);
	window->draw(returnButton);
	endDraw();
}


void LevelComplete::beginDraw() {
	window->clear(sf::Color(33, 33, 33));
}
void LevelComplete::endDraw() {
	window->display();
}
