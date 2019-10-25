#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "FactoryCharacter.h"
#include <vector>

using namespace std;

class Team
{
    private:
        vector<FactoryCharacter> team;
        //liste de personnages


    public:
        Team();
        Team(FactoryCharacter, FactoryCharacter);

        vector<FactoryCharacter> getListCharacter();
        void affiche();
        void removeCharachter(int);
        void AddCharachter(FactoryCharacter);
        void insertCharacter(FactoryCharacter, int);
        bool isEmpty();


};

#endif // TEAM_H
