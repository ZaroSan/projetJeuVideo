#include "Mob.h"

#include<iostream>
#include<string>

using namespace std;

Mob::Mob()
{
    this->lifePoint=100;
    this->strength=40;
    this->power=40;
    this->magicalArmor=40;
    this->physicalArmor=40;
}

Mob::~Mob()
{
    //dtor
}

Mob::Mob(const Mob& other)
{
    this->lifePoint=other.lifePoint;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
    this->power=other.power;
}

void Mob::getStats()
{
    cout<< "---------------------------------------"<<endl;
    cout<< "PV: "<<this->getLifePoint()<<"/"<<this->getLifePointMax()<<endl;
    cout<< "Attaque: "<<this->getStrength()<<endl;
    cout<< "Defense: "<<this->getPhysicalArmor()<<endl;
    cout<< "Vitesse: "<<this->getSpeed()<<endl;
}

void Mob::takeDamage(int damage)
{
	this->lifePoint -= damage;

	if (this->lifePoint <= 0)
	{
		this->lifePoint = 0;
	}
}

int Mob::getStrength()const
{
    return strength;
}

int Mob::getPower()const
{
    return power;
}

int Mob::getMagicalArmor()const
{
    return magicalArmor;
}

int Mob::getPhysicalArmor()const
{
    return physicalArmor;
}

int Mob::getLifePoint()const
{
    return lifePoint;
}

int Mob::getLifePointMax()const
{
    return lifePointFix;
}

int Mob::getSpeed()const
{
    return speed;
}

void Mob::setStrength(int strength)
{
    this->strength = strength;
}

void Mob::setPower(int power)
{
    this->power = power;
}

void Mob::setMagicalArmor(int magicalArmor)
{
    this->magicalArmor = magicalArmor;
}

void Mob::setPhysicalArmor(int physicalArmor)
{
    this->physicalArmor = physicalArmor;
}

void Mob::setLifePoint(int lifePoint)
{
    this->lifePoint = lifePoint;
}

void Mob::setSpeed(int speed)
{
    this->speed = speed;
}



