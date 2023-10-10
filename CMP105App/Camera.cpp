#include "Camera.h"

Camera::Camera() {
	
}
Camera::~Camera() {}

void Camera::handleInput(float dt, float speedX, float speedY) {
	Camera::move(-speedX, -speedY); // moves the background according to player movement
}

void Camera::setWindow(sf::RenderWindow* win) {
	window = win;
}

void Camera::render(sf::RenderWindow* window)
{
	window->draw(*this);
}
