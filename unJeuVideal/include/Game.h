#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>


#include "Team.h"

using namespace sf;
using namespace std;

class Game:RenderWindow
{
    public:
        Game();
        int play(Team*, Team*);




};
//constantes pour faciliter les chemins d'accées
const string PATH_IMAGE="Images/";
const string BACK="_back";
const string ICON="icon_";
const string EXTENSION_IMAGE=".png";





#endif // GAME_H

