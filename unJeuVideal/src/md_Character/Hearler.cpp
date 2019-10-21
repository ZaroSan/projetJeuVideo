#include "Hearler.h"

Hearler::Hearler()
{
    //ctor
    this->lifePoint=200;
    this->strength=0;
    this->power=30;
    this->magicalArmor=70;
    this->physicalArmor=0;
}

Hearler::~Hearler()
{
    //dtor
    this->lifePoint=other.lifePoint;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
    this->power=other.power;
}
