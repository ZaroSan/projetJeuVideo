#include "Team.h"
#include "Personnage.h"
#include "Mob.h"

#include <iostream>
#include <string>
#include <vector>

Team::Team()
{
    //ctor
}

Team::Team(Personnage perso,Mob mob)
{
    team.push_back(perso);
    teamEnnemy.push_back(mob);
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

bool Team::isEmptyEnnemy()
{
    bool vide=false;

    if(this->getListMob().empty())
    {
        vide=true;
    }
    return vide;
}


vector<Personnage> Team::getListPersonnage()
{
    return this->team;
}

vector<Mob> Team::getListMob()
{
    return this->teamEnnemy;
}

void Team::removePersonnage(int n)
{
    this->team.erase(this->team.begin()+n);
}

void Team::removeMob(int n)
{
    this->teamEnnemy.erase(this->teamEnnemy.begin()+n);
}

void Team::AddPersonnage(Personnage p)
{
    this->team.push_back(p);
}

void Team::AddMob(Mob p)
{
    this->teamEnnemy.push_back(p);
}

void Team::insertPersonnage(Personnage p, int n)
{
    this->team.insert(this->team.begin()+n,p);
}

