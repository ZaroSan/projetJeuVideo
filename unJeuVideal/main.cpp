#include <iostream>
#include "FactoryCharacter.h"

#include "Menu.h"
#include "Attack.h"



#include <SFML/Graphics.hpp>
using namespace std;

int main()
{

    Wizard *w=FactoryCharacter::Get()->createWizard();
    w=new Wizard();
    cout <<"Wizard \n"<<w->str();
    cout <<"\n";
    Attack a("coucou",150,20,30);
    a.toString();


    Brawler *b=FactoryCharacter::Get()->createBrawler();
    b=new Brawler();
    b->affiche();



    Menu menu;
    menu.choix();



/*
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


*/

    return 0;
}
