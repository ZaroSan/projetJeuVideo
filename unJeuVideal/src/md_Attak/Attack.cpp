#include "Attack.h"

#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

Attack::Attack()
{
    //ctor
}

Attack::Attack(string name, int power, int mana, int precision)
{
    this->name=name;
    this->power=power;
    this->mana=mana;
    this->precision=precision;
}

Attack::Attack(string name)
{
    this->name=name;
    this->power=20;
    this->mana=10;
}

Attack::~Attack()
{

}

void Attack::setMana(int mana)
{
    this->mana=mana;
}

int Attack::getMana()
{
    return this->mana;
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
    cout<<"Nom: "<<this->name<<endl;;
    cout<<" Puissance: "<<this->power<<endl;;
    cout<<" Mana: "<<this->mana<<endl;
    cout<<" Precision: "<<this->precision<<endl;


}

int Attack::getPower()
{
    return this->power;
}

