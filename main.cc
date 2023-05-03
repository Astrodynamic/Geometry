#include <SFML/Graphics.hpp>
#include <memory>

#include "line.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "square.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Geometry");
  std::vector<std::unique_ptr<Primitive>> primitives;
  primitives.emplace_back(std::make_unique<Line>(100, 100, 200, 200));
  primitives.emplace_back(std::make_unique<Circle>(400, 300, 50));
  primitives.emplace_back(std::make_unique<Triangle>(300, 100, 400, 200, 200, 200));
  primitives.emplace_back(std::make_unique<Rectangle>(500, 400, 100, 50));
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    window.clear();
    for (auto& primitive : primitives) {
      // primitive->print();
      primitive->draw(window);
      primitive->rotate(0.1f);
    }
    window.display();
    sf::sleep(sf::milliseconds(50));
  }
  return 0;
}
