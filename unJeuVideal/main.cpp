#include <iostream>
#include "FactoryCharacter.h"



#include <SFML/Graphics.hpp>
using namespace std;

int main()
{

    Wizard *w=FactoryCharacter::Get()->createWizard();
    w=new Wizard();
    cout <<"Wizard \n"<<w->str();


    //TEST SFML
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }




    return 0;
}
