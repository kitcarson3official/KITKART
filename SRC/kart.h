#ifndef KART
#define KART

#include <SFML/Graphics.hpp>

#include "../LIB/car.h"

using namespace KK;

class Kart:public Car
{
	sf::CircleShape shape;

    public: 
        Kart(float x, float y, float size, sf::Color color);
        void update(float dt, float k);
		void draw(sf::RenderWindow &window);
};

#endif
