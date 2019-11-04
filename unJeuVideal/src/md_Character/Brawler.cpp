#include "Brawler.h"

#include<iostream>
#include<string>

Brawler::Brawler():Personnage()
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




void Brawler::affiche()
{
    cout << "---------------------------------------"<<endl;
    cout << "nom: "<<this->name<<endl;
    cout<< "PV: "<<this->getLifePoint()<<"/"<<this->getLifePointMax()<<endl;
    cout<< "Attaque: "<<this->getStrength()<<endl;
    cout<< "Defense: "<<this->getPhysicalArmor()<<endl;
    cout<< "Vitesse: "<<this->getSpeed()<<endl;
    cout<< "Attaque 1: "<<endl;
    /*this->attaque[0].toString();
    cout<< "Attaque 2: "<<endl;
    this->attaque[1].toString();
    cout<< "Attaque 3: "<<endl;
    this->attaque[2].toString();
    cout<< "Attaque 4: "<<endl;
    this->attaque[3].toString();*/

}


