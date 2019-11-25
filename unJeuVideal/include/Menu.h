#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Team.h"

using namespace sf;
using namespace std;

class Menu:RenderWindow
{
    public:
        Menu();
        int choice();

        vector<Character> initialisation();
        bool findPersonnage(Team, Character);




};

const string _BACK="_back";
const string _ICON="icon_";


#endif // MENU_H

