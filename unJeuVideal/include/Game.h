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
        round();
        void getCharacter();
        int play(Team*, Team*);


};

const string PATH_IMAGE="Images/";
const string BACK="_back";
const string ICON="icon_";
const string EXTENSION_IMAGE=".png";





#endif // GAME_H

