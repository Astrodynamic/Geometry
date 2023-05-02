#pragma once

#include "primitive.h"

// Класс окружности
class Circle : public Primitive {
 public:
  Circle(float x, float y, float radius);

  virtual void draw(sf::RenderWindow& window) override;
  virtual void move(float dx, float dy) override;
  virtual void scale(float factor) override;
  virtual void rotate(float angle) override;
  virtual void print() override;

 private:
  float m_x, m_y, m_radius;
};