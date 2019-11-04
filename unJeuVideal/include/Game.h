
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "FactoryCharacter.h"

using namespace sf;
using namespace std;

class Game
{
    public:
        Game();
        round();
        void getCharacter();


};

const string PATH_IMAGE="Images/";
const string BACK="_back";
const string ICON="_icon";
const string EXTENSION_IMAGE=".png";





#endif // GAME_H

