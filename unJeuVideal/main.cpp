#include <iostream>
#include "Character.h"


#include "Menu.h"
#include "Game.h"


#include <string>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;

int main()
{

    srand(time(0));
    Game ultimate_fantasy;
    Menu menu;
    menu.choice();


    return 0;
}
