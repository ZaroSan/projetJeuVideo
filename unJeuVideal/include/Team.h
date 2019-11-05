#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "Personnage.h"
#include <vector>

using namespace std;

class Team
{
    private:
        vector<Personnage> team;
        //liste de personnages


    public:
        Team();
        Team(Personnage, Personnage);

        vector<Personnage> getListPersonnage();
        void affiche();
        void removePersonnage(int);
        void AddPersonnage(Personnage);
        bool isEmpty();
        void insertPersonnage(Personnage, int);


};

#endif // TEAM_H
