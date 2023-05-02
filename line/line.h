#pragma once

#include "primitive.h"

// Класс отрезка
class Line : public Primitive {
 public:
  Line(float x1, float y1, float x2, float y2);

  virtual void draw(sf::RenderWindow& window) override;
  virtual void move(float dx, float dy) override;
  virtual void scale(float factor) override;
  virtual void rotate(float angle) override;
  virtual void print() override;

 private:
  float m_x1, m_y1, m_x2, m_y2;
};
