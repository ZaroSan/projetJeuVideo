#include "Wizard.h"


Wizard::Wizard()
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

