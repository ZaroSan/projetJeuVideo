#include "Team.h"
#include "Character.h"


#include <iostream>
#include <string>
#include <vector>

Team::Team()
{
    //ctor
}

Team::Team(Character perso1,Character perso2)
{
    team.push_back(perso1);
    team.push_back(perso2);
}

void Team::show()
{
    unsigned int i;

    for(i=0;i<this->getListCharacter().size();i++)
    {
        cout<<"Personnages "<<i+1<<" : "<<this->getListCharacter()[i].getName()<<endl;
    }
}

bool Team::isEmpty()
{
    bool isEmpty=false;

    if(this->getListCharacter().empty())
    {
        isEmpty=true;
    }
    return isEmpty;
}



vector<Character> Team::getListCharacter()
{
    return this->team;
}



void Team::removeCharacter(int n)
{
    this->team.erase(this->team.begin()+n);
}



void Team::AddCharacter(Character p)
{
    this->team.push_back(p);
}



void Team::insertCharacter(Character p, int n)
{
    this->team.insert(this->team.begin()+n,p);
}

