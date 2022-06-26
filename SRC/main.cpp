#include <string>
#include <SFML/Graphics.hpp>

#include "../libkk/car.h"

#include "kart.h"

#define WINDOW_W 1920
#define WINDOW_H 1080
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
    info.setCharacterSize(20);
    info.setStyle(sf::Text::Regular);

    std::string control_str = ""; 

    sf::Text control_info;
    control_info.setFont(font);
    control_info.setCharacterSize(20);
    control_info.setStyle(sf::Text::Regular);
    control_info.setPosition(500,0);

    Kart *kart = new Kart( {250.f, 1000.f}, {0.f, -1.f}, 50.f, sf::Color(250, 250, 0));

    //main loop
    while (window.isOpen())
    {
        //events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window.close(); }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
            {
                kart = new Kart( {250.f, 1000.f}, {0.f, -1.f}, 50.f, sf::Color(250, 250, 0));
            }

			kart->input(event);
            control_str = kart->control_to_string();
            control_info.setString(control_str);
        }

        //update
        sf::Time time = clock.getElapsedTime();
        clock.restart();
        
        kart->update( time.asSeconds(), 1.f);

        info_str = "pos " + kart->get_pos().to_string() +
                    "\nacc " + kart->get_acc().to_string()+
                    "\nvel " + kart->get_vel().to_string();

        info.setString(info_str);

        control_info.setString(control_str);

        //draw
        window.clear(sf::Color(150, 150, 150));

        window.draw(info);
        window.draw(control_info);

        kart->draw(window);

        window.display();
    }



    return 0;
}
