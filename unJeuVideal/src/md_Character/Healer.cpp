#include "Healer.h"

#include<iostream>
#include<string>

Healer::Healer():Personnage()
{
    //ctor
    this->lifePoint=200;
    this->strength=0;
    this->power=30;
    this->magicalArmor=70;
    this->physicalArmor=0;
}

Healer::~Healer()
{
    //dtor

}
Healer::Healer(const Healer& other)
{
    //copy ctor
    this->lifePoint=other.lifePoint;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
    this->power=other.power;
}

void Healer::affiche()
{
    cout<< "---------------------------------------"<<endl;
    cout<< "Nom: "<<this->name<<endl;
    cout<< "PV: "<<this->getLifePoint()<<"/"<<this->getLifePointMax()<<endl;
    cout<< "Attaque: "<<this->getStrength()<<endl;
    cout<< "Defense: "<<this->getPhysicalArmor()<<endl;
    cout<< "Vitesse: "<<this->getSpeed()<<endl;
    cout<< "Attaque 1: "<<endl;
}
