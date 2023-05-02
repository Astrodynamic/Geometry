#pragma once

#include "primitive.h"

class Triangle : public Primitive {
 public:
  Triangle(float x1, float y1, float x2, float y2, float x3, float y3);

  virtual void draw(sf::RenderWindow& window) override;
  virtual void move(float dx, float dy) override;
  virtual void scale(float factor) override;
  virtual void rotate(float angle) override;
  virtual void print() override;

 private:
  float m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;
};
