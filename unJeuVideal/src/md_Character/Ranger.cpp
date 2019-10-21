#include "Ranger.h"

Ranger::Ranger()
{
    //ctor
    this->lifePoint=100;
    this->strength=60;
    this->power=0;
    this->magicalArmor=0;
    this->physicalArmor=40;
}

Ranger::~Ranger()
{
    //dtor
}

Ranger::Ranger(const Ranger& other)
{
    //copy ctor
    this->lifePoint=other.lifePoint;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
    this->power=other.power;
}
