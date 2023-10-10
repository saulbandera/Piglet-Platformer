#include "SplashScreen.h"


SplashScreen::SplashScreen(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	////  LOGO
	sf::Image mask; 
	mask.loadFromFile("gfx/Brotheridge logo.png");
	mask.createMaskFromColor(sf::Color::White);

	////  ANIMATION
	animTexture.loadFromImage(mask);
	anim.setPosition(0, 0);
	anim.setSize(sf::Vector2f(300, 300));
	anim.setTexture(&animTexture);
}

SplashScreen::~SplashScreen(){}

void SplashScreen::update(float dt){
	anim.update(dt); // animate logo
}


void SplashScreen::render() {
	beginDraw();
	window->draw(anim);
	endDraw();
}
void SplashScreen::beginDraw() {
	window->clear(sf::Color(33, 33, 33));
}
void SplashScreen::endDraw() {
	window->display();
}