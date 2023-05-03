#include "rectangle.h"
Rectangle::Rectangle(float x, float y, float width, float height) : m_x(x), m_y(y), m_width(width), m_height(height) {}

void Rectangle::draw(sf::RenderWindow& window) {
  float cx = m_x + m_width / 2;
  float cy = m_y + m_height / 2;

  sf::Vertex vertices[] = {
      sf::Vertex(sf::Vector2f(m_x, m_y)),
      sf::Vertex(sf::Vector2f(m_x + m_width, m_y)),
      sf::Vertex(sf::Vector2f(m_x + m_width, m_y + m_height)),
      sf::Vertex(sf::Vector2f(m_x, m_y + m_height))
  };

  for (int i = 0; i < 4; i++) {
    vertices[i].position -= sf::Vector2f(cx, cy);
  }

  for (int i = 0; i < 4; i++) {
    vertices[i].position = m_transform.transformPoint(vertices[i].position);
  }

  for (int i = 0; i < 4; i++) {
    vertices[i].position += sf::Vector2f(cx, cy);
  }

  window.draw(vertices, 4, sf::Quads);
}

void Rectangle::move(float dx, float dy) {
  m_transform.translate(dx, dy);
}

void Rectangle::scale(float factor) {
  m_transform.scale(factor, factor);
}

void Rectangle::rotate(float angle) {
  m_transform.rotate(angle);
}

void Rectangle::print() {
  std::cout << "x: " << m_x << ", y: " << m_y << ", width: " << m_width << ", height: " << m_height << std::endl;
}
