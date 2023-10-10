#include "Instructions.h"




Instructions::Instructions(sf::RenderWindow* hwnd, Input* in)
{

	window = hwnd;
	input = in;

	////  BACKGROUND
	back.loadFromFile("gfx/instructionsBack.png");
	background.setTexture(&back);
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));


	////  BUTTON
	rButton.loadFromFile("gfx/return.png");
	returnButton.setTexture(&rButton);
	returnButton.setPosition(900, 300);
	returnButton.setSize(sf::Vector2f(307.5, 37.5));
	rButtonPressed.loadFromFile("gfx/returnHighlighted.png");

	instructionsAudio.addSound("sfx/overButton.wav", "clickedButton");
}



Instructions::~Instructions()
{
}



bool Instructions::getReturnClicked() {
	return returnClicked;
}
void Instructions::setReturnClicked(bool clicked) {
	returnClicked = clicked;
}
//#######################  HANDLE INPUT  #######################
void Instructions::handleInput(float dt, sf::RenderWindow& win, bool soundOn)
{
	if (sf::Event::MouseMoved) {
		////######  CHECK FOR MOUSE INPUT  ######
		if (sf::Mouse::getPosition(win).x >= returnButton.getPosition().x  && sf::Mouse::getPosition(win).x <= returnButton.getPosition().x + 307.5) {
			if (sf::Mouse::getPosition(win).y >= returnButton.getPosition().y && sf::Mouse::getPosition(win).y <= returnButton.getPosition().y + 37.5) {
				// over return button
				returnButton.setTexture(&rButtonPressed);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					returnClicked = true;
				}
			}
			else {
				// no button highlighted
				returnButton.setTexture(&rButton);
			}
		}
		else {
			// no button highlighted
			returnButton.setTexture(&rButton);
		}


	}



}
//#######################  UPDATE  #######################
void Instructions::update(float dt){
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	returnButton.setPosition(700, 300);
}




//#######################  RENDER  #######################
void Instructions::render() {
	beginDraw();
	window->draw(background);
	window->draw(returnButton);
	endDraw();
}

void Instructions::beginDraw() {
	window->clear(sf::Color(33, 33, 33));
}
void Instructions::endDraw() {
	window->display();
}
