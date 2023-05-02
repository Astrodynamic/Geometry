#pragma once

#include "primitive.h"

class Triangle : public Primitive {
 public:
  Triangle(float x1, float y1, float x2, float y2, float x3, float y3);

  void draw(sf::RenderWindow& window) override;
  void move(float dx, float dy) override;
  void scale(float factor) override;
  void rotate(float angle) override;

 private:
  float m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;
};
