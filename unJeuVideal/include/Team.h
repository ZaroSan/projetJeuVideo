#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "Character.h"

#include <vector>

using namespace std;

class Team
{
    private:
        vector<Character> team;
        //liste de personnages


    public:
        Team();
        Team(Character, Character);

        vector<Character> getListPersonnage();

        void affiche();
        void removePersonnage(int);
        void AddPersonnage(Character);
        bool isEmpty();
        void insertPersonnage(Character, int);


};

#endif // TEAM_H
