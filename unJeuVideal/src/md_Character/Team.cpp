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
    //ajout des perso à l'équipe
    team.push_back(perso1);
    team.push_back(perso2);
}

//permet d'afficher les perso présent dans une equipe
void Team::show()
{
    unsigned int i;

    for(i=0;i<this->getListCharacter().size();i++)
    {
        cout<<"Personnages "<<i+1<<" : "<<this->getListCharacter()[i].getName()<<endl;
    }
}

//vérifie si l'équipe est vide
bool Team::isEmpty()
{
    bool isEmpty=false;

    if(this->getListCharacter().empty())
    {
        isEmpty=true;
    }
    return isEmpty;
}


//getters de la liste de personnage
vector<Character> Team::getListCharacter()
{
    return this->team;
}


//suppresion du personnage de l'equipe
void Team::removeCharacter(int n)
{
    this->team.erase(this->team.begin()+n);
}


//ajout du personange dans l'équipe
void Team::AddCharacter(Character p)
{
    this->team.push_back(p);
}


//insere un personnage dans l'equipe +1
void Team::insertCharacter(Character p, int n)
{
    this->team.insert(this->team.begin()+n,p);
}

