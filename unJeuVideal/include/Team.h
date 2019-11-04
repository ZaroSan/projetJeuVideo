#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "FactoryCharacter.h"
#include <vector>

using namespace std;

class Team
{
    private:
        vector<Personnage> team;
        //liste de personnages


    public:
        Team();

        vector<Personnage> getListCharacter();
        void affiche();
        void removeCharachter(int);
        void AddCharachter(Personnage);
        bool isEmpty();


};

#endif // TEAM_H
