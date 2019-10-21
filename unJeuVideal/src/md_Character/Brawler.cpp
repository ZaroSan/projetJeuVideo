#include "Brawler.h"

Brawler::Brawler()
{
    //ctor
    this->lifePoint=200;
    this->strength=20;
    this->power=0;
    this->magicalArmor=0;
    this->physicalArmor=70;
}

Brawler::~Brawler()
{
    //dtor
}

Brawler::Brawler(const Brawler& other)
{
    //copy ctor
    this->lifePoint=other.lifePoint;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
    this->power=other.power;
}
