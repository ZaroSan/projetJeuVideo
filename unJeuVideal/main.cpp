#include <iostream>
#include "FactoryCharacter.h"

#include "Menu.h"
#include "Attack.h"
#include "Game.h"


#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
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

    Healer *h=FactoryCharacter::Get()->createHealer();
    h=new Healer();
    cout<<"Healer \n"<<h->str();


    Game ultimate_fantasy;
    Menu menu;
    menu.choix();





    return 0;
}
