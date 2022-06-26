
#include "kart.h"

Kart::Kart(Point pos, Point dir, float size, sf::Color color)
    : Car(pos,dir), shape(size) {
  shape.setPosition(pos.x, pos.y);
  shape.setFillColor(color);
  up = false;
  down = false;
  left = false;
  right = false;
}

Kart::~Kart(){

}

void Kart::input(sf::Event event) {
  if(event.type==sf::Event::KeyPressed)
  {
	switch(event.key.code)
	{
		case sf::Keyboard::Left:
			left = true;
			turn_left();
			break;

		case sf::Keyboard::Right:
			right = true;
			turn_right();
			break;

		case sf::Keyboard::Up:
			up = true;
			accelerate();
			break;

		case sf::Keyboard::Down:
			down = true;
			//todo
			break;

		default:break;
	}
  }

  if(event.type==sf::Event::KeyReleased)
  {
	switch(event.key.code)
	{
		case sf::Keyboard::Left:
			left = false;
			go_straight();
			break;

		case sf::Keyboard::Right:
			right = false;
			go_straight();
			break;

		case sf::Keyboard::Up:
			up = false;
			rest();
			break;

		case sf::Keyboard::Down:
			down = false;
			//todo
			break;

		default:break;
	}
  }
}

void Kart::update(float dt, float k) {
  move(dt, k); 
  shape.setPosition(get_pos().x, get_pos().y);
}

void Kart::draw(sf::RenderWindow &window) { window.draw(shape); }

std::string Kart::control_to_string()
{
	return "up:" + std::to_string(up) +
			"\ndown:" + std::to_string(down) + 
			"\nleft:" + std::to_string(left) + 
			"\nright:" + std::to_string(right);
}
