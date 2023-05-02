#include "rhombus.h"

Rhombus::Rhombus(float x, float y, float width, float height)
    : m_x(x), m_y(y), m_width(width), m_height(height) {}

void Rhombus::draw(sf::RenderWindow& window) {
  sf::ConvexShape rhombus(4);
  rhombus.setPoint(0, sf::Vector2f(m_x, m_y + m_height / 2));
  rhombus.setPoint(1, sf::Vector2f(m_x + m_width / 2, m_y));
  rhombus.setPoint(2, sf::Vector2f(m_x + m_width, m_y + m_height / 2));
  rhombus.setPoint(3, sf::Vector2f(m_x + m_width / 2, m_y + m_height));
  window.draw(rhombus);
}

void Rhombus::move(float dx, float dy) {
  m_x += dx;
  m_y += dy;
}

void Rhombus::scale(float factor) {
  m_width *= factor;
  m_height *= factor;
}

void Rhombus::rotate(float angle) {
  float s = sin(angle), c = cos(angle);
  float x1 = m_x * c - m_y * s;
  float y1 = m_x * s + m_y * c;
  float x2 = (m_x + m_width / 2) * c - (m_y + m_height / 2) * s;
  float y2 = (m_x + m_width / 2) * s + (m_y + m_height / 2) * c;
  m_x = x2 - m_width / 2;
  m_y = y2 - m_height / 2;
  m_width = abs(x2 - x1) * 2;
  m_height = abs(y2 - y1) * 2;
}
