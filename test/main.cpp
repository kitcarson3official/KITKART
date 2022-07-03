#include "lin_alg.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <track.h>

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode((unsigned)800, (unsigned)600, 32),
                          "Test window", sf::Style::Titlebar);

  KK::Track track;
  track.load_track("test/test.track");
  std::vector<KK::Point> points = track.track_vertices(5);
  std::ofstream of("data.py");
  if (of.is_open()) {
    of << "import matplotlib.pyplot as plt" << std::endl;
    of << "x = [";
    for (KK::Point &p : points) {
      of << p.x << ", ";
    }
    of << "]\n";
    of << "y = [";
    for (KK::Point &p : points) {
      of << p.y << ", ";
    }
    of << "]\n";
    of << "plt.plot(x, y)" << std::endl << "plt.show()";
    of.close();
  }

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
