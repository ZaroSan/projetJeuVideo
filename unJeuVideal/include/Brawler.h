#ifndef BRAWLER_H
#define BRAWLER_H

#include <Personnage.h>
#include <Attack.h>

#include "string"
#include "sstream"
using std::string;
using std::stringstream;

class Brawler : public Personnage
{
     private:
        int lifePoint;
        int lifePointFix;
        int power;
        int strength;
        int magicalArmor;
        int physicalArmor;
        int speed;

        string pathFront;
        string pathBack;

        string name;
        Attack attaque[4];

    public:
        Brawler();
        virtual ~Brawler();
        Brawler(const Brawler& other);
        int getStrength() const{return this->strength;}
        int getPower() const{return this->power;}
        int getMagicalArmor() const{return this->magicalArmor;}
        int getPhysicalArmor() const{return this->physicalArmor;}
        int getLifePoint() const{return this->lifePoint;}
        int getLifePointMax() const{return this->lifePointFix;}
        int getSpeed()const{return speed;}
        void setStrength(int i){this->strength=i;}
        void setPower(int i){this->power=0;}
        void setMagicalArmor(int i){this->magicalArmor=0;}
        void setPhysicalArmor(int i){this->physicalArmor=i;}
        void setLifePoint(int i){this->lifePoint=i;}
        void setSpeed(int i){this->speed=i;}

        string str(){
            stringstream stri;
            stri <<"Life Points :"<<this->lifePoint<<"\nStrength :"<<this->strength<<"\nPower :"<<this->power<<"\nMagical Armor :"<<this->magicalArmor<<"\nPhysical Armor :"<<this->physicalArmor;
            return stri.str();
        };

        //string sendAttack(Attack,Mob*);
        string boostPhysicalArmor(Personnage*);

        void affiche();

};

#endif // BRAWLER_H
