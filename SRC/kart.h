#ifndef KART
#define KART

#include <SFML/Graphics.hpp>

#include "../libkk/car.h"

using namespace KK;

class Kart : public Car {
  bool up;
  bool down;
  bool left;
  bool right;
  sf::CircleShape shape;

public:
  Kart(Point pos, Point dir, float size, sf::Color color);
  ~Kart();
  void input(sf::Event event);
  void update(float dt, float k);
  void draw(sf::RenderWindow &window);
  std::string control_to_string();
};

#endif
