#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode((unsigned)800, (unsigned)600, 32),
                          "Test window", sf::Style::Titlebar);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color(0, 0, 0));
    window.display();
  }
  return 0;
}
