#include "Wizard.h"

#include<iostream>
#include<string>


Wizard::Wizard():Personnage()
{
    //ctor
    this->lifePoint=100;
    this->strength=0;
    this->power=60;
    this->magicalArmor=40;
    this->physicalArmor=0;
}

Wizard::~Wizard()
{
    //dtor
}
Wizard::Wizard(const Wizard& other){
    this->lifePoint=other.lifePoint;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
    this->power=other.power;
}

void Wizard::affiche()
{
    cout<< "---------------------------------------"<<endl;
    cout<< "Nom: "<<this->name<<endl;
    cout<< "PV: "<<this->getLifePoint()<<"/"<<this->getLifePointMax()<<endl;
    cout<< "Attaque: "<<this->getStrength()<<endl;
    cout<< "Defense: "<<this->getPhysicalArmor()<<endl;
    cout<< "Vitesse: "<<this->getSpeed()<<endl;
    cout<< "Attaque 1: "<<endl;
}

