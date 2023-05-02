#include "triangle.h"

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3) {}

void Triangle::draw(sf::RenderWindow& window) {
  sf::ConvexShape triangle(3);
  triangle.setPoint(0, sf::Vector2f(m_x1, m_y1));
  triangle.setPoint(1, sf::Vector2f(m_x2, m_y2));
  triangle.setPoint(2, sf::Vector2f(m_x3, m_y3));
  window.draw(triangle);
}

void Triangle::move(float dx, float dy) {
  m_x1 += dx;
  m_y1 += dy;
  m_x2 += dx;
  m_y2 += dy;
  m_x3 += dx;
  m_y3 += dy;
}

void Triangle::scale(float factor) {
  m_x1 *= factor;
  m_y1 *= factor;
  m_x2 *= factor;
  m_y2 *= factor;
  m_x3 *= factor;
  m_y3 *= factor;
}

void Triangle::rotate(float angle) {
  // Находим координаты центра масс треугольника
  float cx = (m_x1 + m_x2 + m_x3) / 3;
  float cy = (m_y1 + m_y2 + m_y3) / 3;

  // Переносим систему координат в центр масс
  m_x1 -= cx;
  m_y1 -= cy;
  m_x2 -= cx;
  m_y2 -= cy;
  m_x3 -= cx;
  m_y3 -= cy;

  // Поворачиваем треугольник относительно точки (0, 0)
  float s = std::sin(angle), c = std::cos(angle);
  float x1 = m_x1 * c - m_y1 * s;
  float y1 = m_x1 * s + m_y1 * c;
  float x2 = m_x2 * c - m_y2 * s;
  float y2 = m_x2 * s + m_y2 * c;
  float x3 = m_x3 * c - m_y3 * s;
  float y3 = m_x3 * s + m_y3 * c;

  // Возвращаем систему координат на место
  m_x1 = x1 + cx;
  m_y1 = y1 + cy;
  m_x2 = x2 + cx;
  m_y2 = y2 + cy;
  m_x3 = x3 + cx;
  m_y3 = y3 + cy;
}

void Triangle::print() {
  std::cout << "Triangle with vertices (" << m_x1 << ", " << m_y1 << "), (" << m_x2 << ", " << m_y2 << "), (" << m_x3 << ", " << m_y3 << ")\n";
}