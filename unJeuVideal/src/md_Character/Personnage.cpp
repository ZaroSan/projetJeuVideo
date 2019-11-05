#include "Personnage.h"

#include<iostream>
#include<string>

Personnage::Personnage()
{
    //ctor
}

Personnage::~Personnage()
{
    //dtor
}

Personnage::Personnage(const Personnage& other)
{
    //copy ctor

}

int Personnage::getStrength()const
{
    return strength;
}

int Personnage::getPower()const
{
    return power;
}

int Personnage::getMagicalArmor()const
{
    return magicalArmor;
}

int Personnage::getPhysicalArmor()const
{
    return physicalArmor;
}

int Personnage::getLifePoint()const
{
    return lifePoint;
}

string Personnage::getName()const
{
    return name;
}

void Personnage::setStrength(int strength)
{
    this->strength = strength;
}

void Personnage::setPower(int power)
{
    this->power = power;
}

void Personnage::setMagicalArmor(int magicalArmor)
{
    this->magicalArmor = magicalArmor;
}

void Personnage::setPhysicalArmor(int physicalArmor)
{
    this->physicalArmor = physicalArmor;
}

void Personnage::setLifePoint(int lifePoint)
{
    this->lifePoint = lifePoint;
}


