#include "rectangle.h"
Rectangle::Rectangle(float x, float y, float width, float height)
    : m_x(x), m_y(y), m_width(width), m_height(height) {
  m_trans_matrix[0][0] = 1;
  m_trans_matrix[0][1] = 0;
  m_trans_matrix[0][2] = 0;
  m_trans_matrix[1][0] = 0;
  m_trans_matrix[1][1] = 1;
  m_trans_matrix[1][2] = 0;
  m_trans_matrix[2][0] = 0;
  m_trans_matrix[2][1] = 0;
  m_trans_matrix[2][2] = 1;
}

void Rectangle::draw(sf::RenderWindow& window) {
  sf::RectangleShape rectangle(sf::Vector2f(m_width, m_height));
  rectangle.setPosition(m_x, m_y);
  sf::VertexArray vertex_array(sf::LinesStrip, 5);
  vertex_array[0].position = rectangle.getPosition();
  vertex_array[1].position = rectangle.getPosition() + sf::Vector2f(m_width, 0);
  vertex_array[2].position = rectangle.getPosition() + sf::Vector2f(m_width, m_height);
  vertex_array[3].position = rectangle.getPosition() + sf::Vector2f(0, m_height);
  vertex_array[4].position = rectangle.getPosition();
  apply_transform(vertex_array);
  window.draw(vertex_array);
}

void Rectangle::move(float dx, float dy) {
  m_trans_matrix[0][2] += dx;
  m_trans_matrix[1][2] += dy;
}

void Rectangle::scale(float factor) {
  m_trans_matrix[0][0] *= factor;
  m_trans_matrix[1][1] *= factor;
}

void Rectangle::rotate(float angle) {
  float rad = angle * M_PI / 180.0f;
  float cos_val = cos(rad);
  float sin_val = sin(rad);
  float old_a = m_trans_matrix[0][0];
  float old_b = m_trans_matrix[0][1];
  m_trans_matrix[0][0] = old_a * cos_val + m_trans_matrix[1][0] * sin_val;
  m_trans_matrix[0][1] = old_b * cos_val + m_trans_matrix[1][1] * sin_val;
  m_trans_matrix[1][0] = m_trans_matrix[1][0] * cos_val - old_a * sin_val;
  m_trans_matrix[1][1] = m_trans_matrix[1][1] * cos_val - old_b * sin_val;
}

void Rectangle::apply_transform(sf::VertexArray& vertex_array) {
  sf::Transform transform(
      m_trans_matrix[0][0], m_trans_matrix[0][1], m_trans_matrix[0][2],
      m_trans_matrix[1][0], m_trans_matrix[1][1], m_trans_matrix[1][2],
      m_trans_matrix[2][0], m_trans_matrix[2][1], m_trans_matrix[2][2]);
  for (size_t i = 0; i < vertex_array.getVertexCount(); ++i) {
    vertex_array[i].position =
        transform.transformPoint(vertex_array[i].position);
  }
}

void Rectangle::print() {
  std::cout << "x: " << m_x << ", y: " << m_y << ", width: " << m_width
            << ", height: " << m_height << std::endl;
}