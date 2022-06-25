#include <string>
#include <SFML/Graphics.hpp>

#include "../libkk/car.h"

#include "kart.h"

#define WINDOW_W 1280
#define WINDOW_H 720
#define WINDOW_BIT 32
#define WINDOW_TITLE "KITKART"

int main()
{
    sf::RenderWindow window( sf::VideoMode((unsigned)WINDOW_W, (unsigned)WINDOW_H, WINDOW_BIT), WINDOW_TITLE, sf::Style::Titlebar);
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    clock.restart();

    sf::Font font ;
    font.loadFromFile("DATA/RobotoMono-Regular.ttf");

    std::string info_str = ""; 

    sf::Text info;
    info.setFont(font);
    info.setCharacterSize(30);
    info.setStyle(sf::Text::Regular);

    Kart kart(250.f, 250.f, 50.f, sf::Color(250, 250, 0));
    kart.accelerate();//simuliamo uno che pigia la freccia in su e non la rilascia mai

    //main loop
    while (window.isOpen())
    {
        //events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        //update
        sf::Time time = clock.getElapsedTime();
        clock.restart();
        
        kart.update( time.asSeconds(), 0.1f);

        info_str = "x:" + std::to_string( kart.get_pos().x ) + 
                   " y:" + std::to_string( kart.get_pos().y );


        info.setString(info_str);

        //draw
        window.clear(sf::Color(150, 150, 150));

        window.draw(info);

        kart.draw(window);

        window.display();
    }



    return 0;
}
