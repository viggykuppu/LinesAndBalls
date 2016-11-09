#pragma once
#include <SFML/Graphics.hpp>

class Line : public sf::Drawable {
	public:
		Line(sf::Vector2f a, sf::Vector2f b);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::VertexArray line;
};