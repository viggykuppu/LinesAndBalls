#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable{
	public:
		Ball(float radius, float x, float y);
		void setRadius(float radius);
		float getRadius();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		sf::CircleShape* getBall();
		void update(sf::RenderWindow &window);
		void setPosition(float x, float y);
		sf::Vector2f getPosition();
	
	private:
		sf::CircleShape circle;
		float vx, vy;
		void flipX();
		void flipY();
		float x, y;
		
		
};
