#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Line.h"
#include <vector>
#include <iostream>


Ball addBall();
void update(sf::RenderWindow &window);
void draw(sf::RenderWindow &window);
void run();
void updateColors();

int x = 1000;
int y = 1000;
int barrier = 50;
sf::Uint8 c[3];
sf::Uint8 target[3];
std::vector<Ball> balls;
std::vector<Line> lines;

int main()
{
	sf::Thread thread(&run);
	thread.launch();
	thread.wait();
	return 0;
}

void run() {
	srand(time(NULL));
	c[0] = rand() % 255;
	c[1] = rand() % 255;
	c[2] = rand() % 255;
	target[0] = rand() % 255;
	target[1] = rand() % 255;
	target[2] = rand() % 255;
	sf::RenderWindow window(sf::VideoMode(x, y), "SFML works!");
	sf::CircleShape shape(100.f);
	for (int i = 0; i < 30; i++) {
		balls.push_back(addBall());
	}
	
	while (window.isOpen())
	{
		sf::Clock clock;
		
		update(window);

		draw(window);

		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asMicroseconds() < 1000000.0 / 60.0) {
			sf::sleep(sf::microseconds(1000000 / 60 - elapsed.asMicroseconds()));
		}
	}
	return;
}

Ball addBall() {	
	float radius = rand() % 7 + 3;
	float vx = rand() % 15 - 7;
	float vy = rand() % 15 - 7;
	Ball ball(radius,vx,vy);
	ball.getBall()->setFillColor(sf::Color::Black);
	ball.getBall()->setPosition(rand()%(x- 2*barrier)+ barrier,rand()%(y- 2*barrier)+ barrier);
	return ball;
}

void update(sf::RenderWindow &window) {
	sf::Event event;
	updateColors();
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	for (int i = 0; i < balls.size(); i++) {
		balls[i].update(window);
	}
	lines.clear();
	for (int i = 0; i < balls.size(); i++) {
		for (int j = i + 1; j < balls.size(); j++) {
			Line l(balls[i].getPosition(), balls[j].getPosition());
			lines.push_back(l);
		}
	}
}

void draw(sf::RenderWindow &window) {
	window.clear(sf::Color(c[0],c[1],c[2]));
	for (int i = 0; i < balls.size(); i++) {
		window.draw(balls[i]);
	}
	for (int i = 0; i < lines.size(); i++) {
		window.draw(lines[i]);
	}
	window.display();
}

void updateColors() {
	bool done[3];
	for (int i = 0; i < 3; i++) {
		if (c[i] < target[i]) {
			c[i]++;
		}
		else if (c[i] > target[i]) {
			c[i]--;
		}
	}
	if (c[0] == target[0] && c[1] == target[1] && c[2] == target[2]) {
		target[0] = rand() % 255;
		target[1] = rand() % 255;
		target[2] = rand() % 255;
	}
}