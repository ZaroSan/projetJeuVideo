#include "Mob.h"

#include"Game.h"


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
    this->speed=40;

    this->name="Mob";

    this->attack[0] = Attack("attaque1");
    this->attack[1] = Attack("attaque2");
    this->attack[2] = Attack("attaque3");
    this->attack[3] = Attack("attaque4");
}

Mob::~Mob()
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

Mob::Mob(string name, int lifePoint, int strength, int power, int physicalArmor, int magicalArmor, Attack* attack)
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

  //  cout<<"Construction Mob "<<this->getName()<<endl;
}

Mob::Mob(string name)
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

Mob::Mob(const Mob& other)
{
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

void Mob::affiche()
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

bool Mob::estKO(){
    if(this->lifePoint<=0)
        return true;
    else
        return false;
}

Attack* Mob::getAttack(){
    return this->attack;

}

int Mob::getSpeed()const
{
    return speed;
}

void Mob::setPath(){

    pathBack=PATH_IMAGE+this->getName()+BACK+EXTENSION_IMAGE;
    pathFront=PATH_IMAGE+this->getName()+EXTENSION_IMAGE;


}

string Mob::getPath(bool front){

	if(front)
	{
	return pathFront;
	}
	else
	{
	return pathBack;
	}
}

int Mob::getDegat(Attack a, Personnage p, Mob *m)
{
    double degatAD; //degat physique
    double degatAP; //degat magique
    double degat;

    if(m->strength > p.getPhysicalArmor())
    {
        degatAD=a.getPower()/(m->strength - p.getPhysicalArmor());
    }else{
        degatAD =0;
    }

    if(m->power > p.getMagicalArmor())
    {
        degatAP=a.getPower()/(m->power - p.getMagicalArmor());
    }else{
        degatAP = 0;
    }

    degat = (degatAD+degatAP);
     return (double) degat;


}

string Mob::lancerAttaque(Attack a, Personnage p, Mob *m)
{
    double degat=0;
    string s;
    int pourcent;
    int proba;


    srand(time(0));
    proba=(rand()%99+1);

    s=this->getName()+" lance "+a.getName()+" !\n";

    if(proba >a.getPrecision()){

        s+=this->getName()+" rate son attaque !\n";
    }else{

        if(a.getPower()!=0)
        {
            degat=getDegat(a, p, m);
            p.setLifePoint(p.getLifePoint()-degat);


            pourcent=(int)(100*degat/p.getLifePointMax());

            if (pourcent>=100)
               pourcent=100;

            s+=p.getName()+" perd "+Mob::toString(pourcent)+"% de ses PV !\n"; //peut etre rajouter un algo itoa pour le calculer si necessaire

            if (p.estKO()){
              p.setLifePoint(0);
              s+=p.getName()+" est KO!\n ";
             }




        }

    }

    return s;



}

string Mob::toString(int n)
{
    return itoa(n, 10);
}

string Mob::toString(double n)
{
    return itoa(n, 10);
}

string Mob::itoa(int value, int base)
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

string Mob::itoa(double value, int base) {

        std::string buf;

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




















