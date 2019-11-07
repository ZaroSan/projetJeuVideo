#include "Personnage.h"

#include"Game.h"

#include<iostream>
#include<string>

Personnage::Personnage()
{
    //ctor
    this->strength=10;
    this->power=10;
    this->lifePoint=100;
    this->magicalArmor=10;
    this->physicalArmor=10;

    this->name="Brawler";

    this->attack[0] = Attack("attaque1");
    this->attack[1] = Attack("attaque2");
    this->attack[2] = Attack("attaque3");
    this->attack[3] = Attack("attaque4");
}

Personnage::Personnage(string name, int lifePoint, int strength, int power, int physicalArmor, int magicalArmor, Attack* attack)
{
    this->strength=strength;
    this->power=power;
    this->lifePoint=lifePoint;
    this->magicalArmor=magicalArmor;
    this->physicalArmor=physicalArmor;

    this->name=name;

    this->attack[0] = attack[0];
    this->attack[1] = attack[1];
    this->attack[2] = attack[2];
    this->attack[3] = attack[3];


    setPath();

    cout<<"Construction personnage "<<this->getName()<<endl;
}

Personnage::Personnage(string name)
{
    this->strength=10;
    this->power=10;
    this->lifePoint=100;
    this->magicalArmor=10;
    this->physicalArmor=10;

    this->name=name;

    this->attack[0] = Attack("attaque1");
    this->attack[1] = Attack("attaque2");
    this->attack[2] = Attack("attaque3");
    this->attack[3] = Attack("attaque4");

     setPath();
}
Personnage::Personnage (const Personnage& other){
    this->name=other.name;
    this->lifePoint=other.lifePoint;
    this->strength=other.strength;
    this->magicalArmor=other.magicalArmor;
    this->physicalArmor=other.physicalArmor;
    this->power=other.power;
}

Personnage::~Personnage()
{
    //dtor
    static int i=0;
    if(i<5000)
    {
        i++;
    }else{
    i=0;
    }
}


/*
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
*/
/*void Personnage::setName(string Name)
{
    this->name=name;
}
*/
string Personnage::getPath(bool front){

	if(front)
	{
	return pathFront;
	}
	else
	{
	return pathBack;
	}
}

void Personnage::setPath(){

    pathBack=PATH_IMAGE+this->getName()+BACK+EXTENSION_IMAGE;
    pathFront=PATH_IMAGE+this->getName()+EXTENSION_IMAGE;


}


