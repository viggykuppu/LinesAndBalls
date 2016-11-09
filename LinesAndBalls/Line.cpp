#include "Line.h"

sf::VertexArray line;

Line::Line(sf::Vector2f a, sf::Vector2f b) {
	line.append(sf::Vertex(a, sf::Color::Black));
	line.append(sf::Vertex(b, sf::Color::Black));
	line.setPrimitiveType(sf::PrimitiveType::LineStrip);
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(line, states);
}