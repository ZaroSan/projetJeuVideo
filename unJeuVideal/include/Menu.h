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
        int choix();
        /*
        bool findCharacter(Team, FactoryCharacter);
        vector<FactoryCharacter> initialisation();
 */
    protected:

    private:

};

#endif // MENU_H

