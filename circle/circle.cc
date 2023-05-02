#include "circle.h"

Circle::Circle(float x, float y, float radius) : m_x(x), m_y(y), m_radius(radius) {}

void Circle::draw(sf::RenderWindow& window) {
  sf::CircleShape circle(m_radius);
  circle.setPosition(m_x - m_radius, m_y - m_radius);
  window.draw(circle);
}

void Circle::move(float dx, float dy) {
  m_x += dx;
  m_y += dy;
}

void Circle::scale(float factor) { m_radius *= factor; }

void Circle::rotate(float angle) {
  // Так выглядит бесконечность
}

void Circle::print() {
  std::cout << "x: " << m_x << ", y: " << m_y << ", radius: " << m_radius << std::endl;
}