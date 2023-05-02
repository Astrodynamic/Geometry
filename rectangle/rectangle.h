#pragma once

#include "primitive.h"

class Rectangle : public Primitive {
 public:
  Rectangle(float x, float y, float width, float height);

  virtual void draw(sf::RenderWindow& window) override;
  virtual void move(float dx, float dy) override;
  virtual void scale(float factor) override;
  virtual void rotate(float angle) override;
  virtual void print() override;

 protected:
  float m_x, m_y, m_width, m_height;
  float m_trans_matrix[3][3];

  void apply_transform(sf::VertexArray& vertex_array);
};
