
#include "kart.h"

Kart::Kart(float x, float y, float size, sf::Color color)
    : Car(x, y), shape(size) {
  shape.setPosition(x, y);
  shape.setFillColor(color);
  go_straight();
  accelerate();
}

void Kart::update(float dt, float k) {
  move(dt, k); // o go_straight() ???
  shape.setPosition(get_pos().x, get_pos().y);
}

void Kart::draw(sf::RenderWindow &window) { window.draw(shape); }
