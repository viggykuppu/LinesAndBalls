#include "Ball.h"
#include <iostream>

sf::CircleShape circle;
float vx, vy;

Ball::Ball(float radius, float vx, float vy) {
	circle.setRadius(radius);
	this->vx = vx;
	this->vy = vy;
}

void Ball::setRadius(float radius) {
	this->circle.setRadius(radius);
}

float Ball::getRadius() {
	return this->circle.getRadius();
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(circle, states);
}

sf::CircleShape* Ball::getBall() {
	return &circle;
}

void Ball::update(sf::RenderWindow &window) {
	unsigned int gx = window.getSize().x;
	unsigned int gy = window.getSize().y;
	float ix = this->getPosition().x;
	float iy = this->getPosition().y;
	float x = ix + vx;
	float y = iy + vy;
	bool flipX = false;
	bool flipY = false;
	if (x - circle.getRadius() < 0) {
		x = -1 * (x - circle.getRadius()) + circle.getRadius();
		flipX = true;
	}
	if (y - circle.getRadius() < 0) {
		y = -1 * (y - circle.getRadius()) + circle.getRadius();
		flipY = true;
	}
	if (x + circle.getRadius() > gx) {
		x = gx - ((x + circle.getRadius())-gx)- circle.getRadius();
		flipX = true;
	}
	if (y + circle.getRadius() > gy) {
		y = gy - ((y + circle.getRadius()-gy))-circle.getRadius();
		flipY = true;
	}
	if (flipX) {
		this->flipX();
	}
	if (flipY) {
		this->flipY();
	}
	this->setPosition(x,y);
}

void Ball::flipX() {
	this->vx = -vx;
}

void Ball::flipY() {
	this->vy = -vy;
}

void Ball::setPosition(float x, float y) {
	circle.setPosition(sf::Vector2f(x - circle.getRadius(), y - circle.getRadius()));
}

sf::Vector2f Ball::getPosition() {
	return sf::Vector2f(circle.getPosition().x + circle.getRadius(),circle.getPosition().y + circle.getRadius());
}