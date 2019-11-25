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

void Team::affiche()
{
    unsigned int i;

    for(i=0;i<this->getListPersonnage().size();i++)
    {
        cout<<"Personnages "<<i+1<<" : "<<this->getListPersonnage()[i].getName()<<endl;
    }
}

bool Team::isEmpty()
{
    bool vide=false;

    if(this->getListPersonnage().empty())
    {
        vide=true;
    }
    return vide;
}



vector<Character> Team::getListPersonnage()
{
    return this->team;
}



void Team::removePersonnage(int n)
{
    this->team.erase(this->team.begin()+n);
}



void Team::AddPersonnage(Character p)
{
    this->team.push_back(p);
}



void Team::insertPersonnage(Character p, int n)
{
    this->team.insert(this->team.begin()+n,p);
}

