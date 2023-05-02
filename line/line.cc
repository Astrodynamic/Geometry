#include "line.h"

Line::Line(float x1, float y1, float x2, float y2)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void Line::draw(sf::RenderWindow& window) {
  sf::Vertex line[] = {sf::Vertex(sf::Vector2f(m_x1, m_y1)),
                       sf::Vertex(sf::Vector2f(m_x2, m_y2))};
  window.draw(line, 2, sf::Lines);
}

void Line::move(float dx, float dy) {
  m_x1 += dx;
  m_y1 += dy;
  m_x2 += dx;
  m_y2 += dy;
}

void Line::scale(float factor) {
  m_x1 *= factor;
  m_y1 *= factor;
  m_x2 *= factor;
  m_y2 *= factor;
}

void Line::rotate(float angle) {
  // Находим координаты середины отрезка
  float cx = (m_x1 + m_x2) / 2;
  float cy = (m_y1 + m_y2) / 2;

  // Переносим систему координат в середину отрезка
  m_x1 -= cx;
  m_y1 -= cy;
  m_x2 -= cx;
  m_y2 -= cy;

  // Поворачиваем линию относительно точки (0, 0)
  float s = std::sin(angle), c = std::cos(angle);
  float x1 = m_x1 * c - m_y1 * s;
  float y1 = m_x1 * s + m_y1 * c;
  float x2 = m_x2 * c - m_y2 * s;
  float y2 = m_x2 * s + m_y2 * c;

  // Возвращаем систему координат на место
  m_x1 = x1 + cx;
  m_y1 = y1 + cy;
  m_x2 = x2 + cx;
  m_y2 = y2 + cy;
}

void Line::print() {
  std::cout << "Line from (" << m_x1 << ", " << m_y1 << ") to (" << m_x2 << ", " << m_y2 << ")\n";
}
