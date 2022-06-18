#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#define RECT_SIZE 50.f


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Game", sf::Style::Titlebar && sf::Style::Close);
    sf::Vector2f rectSize(RECT_SIZE, RECT_SIZE);
    sf::RectangleShape rectangle(rectSize);

    rectangle.setFillColor(sf::Color::Green);
    sf::Vector2f mousePosition;


    while (window.isOpen()) 
    {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        mousePosition.x = sf::Mouse::getPosition(window).x;
        mousePosition.y = sf::Mouse::getPosition(window).y;
        rectangle.setPosition(mousePosition);
        sf::Vector2f rectOrigin(RECT_SIZE / 2, RECT_SIZE / 2);
        rectangle.setOrigin(rectOrigin);

        window.clear();
        window.draw(rectangle);
        window.display();
    }
}