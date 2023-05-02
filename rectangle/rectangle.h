#pragma once

#include "primitive.h"

class Rectangle : public Primitive {
 public:
  Rectangle(float x, float y, float width, float height);

  void draw(sf::RenderWindow& window) override;
  void move(float dx, float dy) override;
  void scale(float factor) override;
  void rotate(float angle) override;

 protected:
  float m_x, m_y, m_width, m_height;
};
