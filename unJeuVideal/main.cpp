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


/*
    Menu menu;
    menu.choix();
*/




    return 0;
}
