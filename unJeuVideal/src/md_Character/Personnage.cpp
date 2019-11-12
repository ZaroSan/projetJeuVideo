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

void Personnage::affiche()
{
    cout << "---------------------------------------"<<endl;
    cout <<"Nom: "<<this->name<<endl;
    cout <<"PV: "<<this->getLifePoint()<<"/"<<this->getLifePointMax()<<endl;
    cout <<"Force: "<<this->getStrength()<<endl;
    cout <<"Puissance: "<<this->getPower()<<endl;
    cout <<"Reistance physique: "<<this->getPhysicalArmor()<<endl;
    cout <<"Reistance Magique: "<<this->getMagicalArmor()<<endl;
    cout << "Attaque 1: "<<endl;
	this->attack[0].toString();
	cout << "Attaque 2: "<<endl;
	this->attack[1].toString();
	cout << "Attaque 3: "<<endl;
	this->attack[2].toString();
	cout << "Attaque 4: "<<endl;
	this->attack[3].toString();
}

bool Personnage::estKO(){
    if(this->lifePoint<=0)
        return true;
    else
        return false;
}

Attack* Personnage::getAttack(){
    return this->attack;

}

int Personnage::getSpeed()const
{
    return speed;
}
/*
int Personnage::getDegat(Attack a, Personnage *p)
{
    double degat;
    if(a.getStrength()==true)
    {
        degat=this->attack*a.getPower()/(p/)
    }
}
*/

