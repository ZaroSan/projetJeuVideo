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

        vector<Character> getListCharacter();

        void show();
        void removeCharacter(int);
        void AddCharacter(Character);
        bool isEmpty();
        void insertCharacter(Character, int);


};

#endif // TEAM_H
