#include <SFML/Graphics.hpp>

int main() {
  // Создание окна размером 800x600
  sf::RenderWindow window(sf::VideoMode(800, 600), "Geometric shapes");

  // Создание круга
  sf::CircleShape circle(50.f);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(100.f, 100.f);

  // Создание квадрата
  sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
  square.setFillColor(sf::Color::Green);
  square.setPosition(250.f, 100.f);

  // Создание треугольника
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, sf::Vector2f(0.f, 0.f));
  triangle.setPoint(1, sf::Vector2f(50.f, 100.f));
  triangle.setPoint(2, sf::Vector2f(100.f, 0.f));
  triangle.setFillColor(sf::Color::Blue);
  triangle.setPosition(450.f, 100.f);

  // Создание прямоугольника
  sf::RectangleShape rectangle(sf::Vector2f(150.f, 100.f));
  rectangle.setFillColor(sf::Color::Yellow);
  rectangle.setPosition(100.f, 250.f);

  // Главный цикл приложения
  while (window.isOpen()) {
    // Обработка событий
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    // Отрисовка фигур на экране
    window.clear();
    window.draw(circle);
    window.draw(square);
    window.draw(triangle);
    window.draw(rectangle);
    window.display();
  }

  return 0;
}
