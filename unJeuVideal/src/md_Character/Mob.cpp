#include "Mob.h"

using namespace std;;

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
/*
std::string Mob::getStats()const
{
	return
		"Hp: " + std::to_string(this->lifePoint) + "\n" +
		"Strength: " + std::to_string(this->strength) + "\n" +
		"Power: " + std::to_string(this->power) + "\n" +
		"Magical Armor: " + std::to_string(this->magicalArmor) + "\n" +
		"Physical Armor: " + std::to_string(this->physicalArmor) + "\n";
}*/

void Mob::takeDamage(int damage)
{
	this->lifePoint -= damage;

	if (this->lifePoint <= 0)
	{
		this->lifePoint = 0;
	}
}

