#include "Attack.h"

#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

Attack::Attack()
{
    //ctor
}

Attack::Attack(string name, int power, int mana, int manaFix)
{
    this->name=name;
    this->power=power;
    this->mana=mana;
    this->manaFix=mana;
}

Attack::~Attack()
{

}

void Attack::setMana(int mana)
{
    this->mana=mana;
}

int Attack::getManaFix()
{
    return this->mana;
}

string Attack::getName()
{
    return this->name;
}

void Attack::setPrecision(int precision)
{
    this->precision=precision;
}

int Attack::getPrecision()
{
    return this->precision;
}

void Attack::toString()
{
    cout<<"Nom: "<<this->name;
    cout<<" Puissance: "<<this->power;
    cout<<" Mana: "<<this->mana<<endl;

}

int Attack::getPower()
{
    return this->power;
}
<<<<<<< HEAD
=======


>>>>>>> cba3473a4b2395af2e79e0dfbc87e9b3918a977f
