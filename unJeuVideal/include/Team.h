#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "Personnage.h"
#include "Mob.h"
#include <vector>

using namespace std;

class Team
{
    private:
        vector<Personnage> team;
        vector<Mob> teamEnnemy;
        //liste de personnages


    public:
        Team();
        Team(Personnage, Mob);

        vector<Personnage> getListPersonnage();
        vector<Mob> getListMob();
        void affiche();
        void removePersonnage(int);
        void removeMob(int);
        void AddPersonnage(Personnage);
        void AddMob(Mob);
        bool isEmpty();
        bool isEmptyEnnemy();
        void insertPersonnage(Personnage, int);


};

#endif // TEAM_H
