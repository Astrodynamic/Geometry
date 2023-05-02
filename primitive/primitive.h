#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// Абстрактный базовый класс для всех примитивов
class Primitive {
 public:
  virtual void draw(sf::RenderWindow& window) = 0;
  virtual void move(float dx, float dy) = 0;
  virtual void scale(float factor) = 0;
  virtual void rotate(float angle) = 0;
  virtual void print();
  virtual ~Primitive() = default;
};
