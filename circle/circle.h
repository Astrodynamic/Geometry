#pragma once

#include "primitive.h"

// Класс окружности
class Circle : public Primitive {
 public:
  Circle(float x, float y, float radius);

  void draw(sf::RenderWindow& window) override;
  void move(float dx, float dy) override;
  void scale(float factor) override;
  void rotate(float angle) override;

 private:
  float m_x, m_y, m_radius;
};