#include "rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height) : m_x(x), m_y(y), m_width(width), m_height(height) {}

void Rectangle::draw(sf::RenderWindow& window) {
  sf::RectangleShape rectangle(sf::Vector2f(m_width, m_height));
  rectangle.setPosition(m_x, m_y);
  window.draw(rectangle);
}

void Rectangle::move(float dx, float dy) {
  m_x += dx;
  m_y += dy;
}

void Rectangle::scale(float factor) {
  m_width *= factor;
  m_height *= factor;
}

void Rectangle::rotate(float angle) {
  float s = std::sin(angle), c = std::cos(angle);
  float x1 = m_x * c - m_y * s;
  float y1 = m_x * s + m_y * c;
  float x2 = (m_x + m_width) * c - (m_y + m_height) * s;
  float y2 = (m_x + m_width) * s + (m_y + m_height) * c;
  m_x = x1;
  m_y = y1;
  m_width = std::abs(x2 - x1);
  m_height = std::abs(y2 - y1);
}