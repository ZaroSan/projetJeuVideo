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
    this->lifePointMax=lifePoint;
    this->speed=speed;

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
    this->lifePointMax=lifePoint;
    this->speed=speed;

    this->name=name;

    this->attack[0] = attack[0];
    this->attack[1] = attack[1];
    this->attack[2] = attack[2];
    this->attack[3] = attack[3];


    setPath();

   // cout<<"Construction personnage "<<this->getName()<<endl;
}

Personnage::Personnage(string name)
{
    this->strength=10;
    this->power=10;
    this->lifePoint=100;
    this->magicalArmor=10;
    this->physicalArmor=10;
    this->speed=10;

    this->name=name;

    this->attack[0] = Attack("attaque1");
    this->attack[1] = Attack("attaque2");
    this->attack[2] = Attack("attaque3");
    this->attack[3] = Attack("attaque4");

     setPath();
}
Personnage::Personnage (const Personnage& other){
        this->lifePoint=other.lifePoint;
        this->strength=other.strength;
        this->power=other.power;
        this->magicalArmor=other.magicalArmor;
        this->physicalArmor=other.physicalArmor;
        this->speed=other.speed;
        this->lifePointMax=other.lifePointMax;


        this->name=other.name;

        this->attack[0]=other.attack[0];
        this->attack[1]=other.attack[1];
        this->attack[2]=other.attack[2];
        this->attack[3]=other.attack[3];

        this->pathFront=other.pathFront;
        this->pathBack=other.pathBack;


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
    cout<<pathBack<<endl;

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

int Personnage::getDegat(Attack a, Personnage *p, Mob m)
{
    double degatAD; //degat physique
    double degatAP; //degat magique
    double degat;

    if(p->strength > m.getPhysicalArmor())
    {
        degatAD=a.getPower()/(p->strength - m.getPhysicalArmor());
    }else{
        degatAD =0;
    }

    if(p->power > m.getMagicalArmor())
    {
        degatAP=a.getPower()/(p->power - m.getMagicalArmor());
    }else{
        degatAP = 0;
    }

    degat = (degatAD+degatAP);
    return (double) degat;


}

string Personnage::lancerAttaque(Attack a, Personnage *p, Mob m)
{
    double degat=0;
    string s;
    int pourcent;
    int proba;


    srand(time(0));
    proba=rand()%100+1;

    s=this->getName()+" lance "+a.getName()+" !\n";

    if(a.getPrecision() <= proba){

        s+=this->getName()+" rate son attaque !\n";
    }else{

        if(a.getPower()!=0)
        {
            degat=getDegat(a, p, m);
            m.setLifePoint(m.getLifePoint()-degat);


            pourcent=(int)(100*degat/m.getLifePointMax());

            if (pourcent>=100)
               pourcent=100;

            s+=m.getName()+" perd "+Personnage::toString(pourcent)+"% de ses PV !\n"; //peut etre rajouter un algo itoa pour le calculer si necessaire

            if (m.estKO()){
              m.setLifePoint(0);
              s+=m.getName()+" est KO!\n ";
             }




        }

    }

    return s;



}

string Personnage::toString(int n)
{
    return itoa(n, 10);
}

string Personnage::toString(double n)
{
    return itoa(n, 10);
}

string Personnage::itoa(int value, int base)
{
    string buf;

        // check that the base if valid
        if (base < 2 || base > 16) return buf;

        enum { kMaxDigits = 35 };
        buf.reserve( kMaxDigits ); // Pre-allocate enough space.


        int quotient = value;

        // Translating number to string with base:
        do {
            buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
            quotient /= base;
        } while ( quotient );

        // Append the negative sign
        if ( value < 0) buf += '-';

        std::reverse( buf.begin(), buf.end() );
    return buf;
}

string Personnage::itoa(double value, int base) {

        string buf;

        // check that the base if valid
        if (base < 2 || base > 16) return buf;

        enum { kMaxDigits = 35 };
        buf.reserve( kMaxDigits ); // Pre-allocate enough space.


        int quotient = value;

        // Translating number to string with base:
        do {
            buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
            quotient /= base;
        } while ( quotient );

        // Append the negative sign
        if ( value < 0) buf += '-';

        std::reverse( buf.begin(), buf.end() );
        return buf;
}



