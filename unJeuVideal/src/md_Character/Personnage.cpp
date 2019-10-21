#include "Personnage.h"

Personnage::Personnage(int power,int strength,int lifePoint,int magicalArmor,int physicalArmor=0){
    //ctor
   this->power=power;
   this->strength=strength;
   this->lifePoint=lifePoint;
   this->magicalArmor=magicalArmor;
   this->physicalArmor=physicalArmor;
}

Personnage::~Personnage()
{
    //dtor
}
Personnage::Personnage(const Personnage& other){
    this->lifePoint=other.lifePoint;
    this->power=other.power;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
}
