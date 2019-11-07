/*
#ifndef HEARLER_H
#define HEARLER_H

#include <Personnage.h>
#include <Attack.h>
#include "string"
#include "sstream"
using std::string;
using std::stringstream;

class Healer : public Personnage
{
    public:
        Healer();
        virtual ~Healer();
        Healer (const Healer& other);
        int getStrength() const{return this->strength;}
        int getPower() const{return this->power;}
        int getMagicalArmor() const{return this->magicalArmor;}
        int getPhysicalArmor() const{return this->physicalArmor;}
        int getLifePoint() const{return this->lifePoint;}
        int getLifePointMax() const{return this->lifePointFix;}
        int getSpeed()const{return speed;}
        void setStrength(int){this->strength=0;}
        void setPower(int i){this->power=i;}
        void setMagicalArmor(int i){this->magicalArmor=i;}
        void setPhysicalArmor(int){this->physicalArmor=0;}
        void setLifePoint(int i){this->lifePoint=i;}
        void setSpeed(int i){this->speed=i;}

        string str(){
            stringstream stri;
            stri <<"Life Points :"<<this->lifePoint<<"\nStrength :"<<this->strength<<"\nPower :"<<this->power<<"\nMagical Armor :"<<this->magicalArmor<<"\nPhysical Armor :"<<this->physicalArmor;
            return stri.str();
        };

        //string sendAttack(Attack,Mob*);
        string boostMagicalArmor(Personnage*);

        void affiche();

    protected:

    private:
        int lifePoint;
        int lifePointFix;
        int power;
        int strength;
        int magicalArmor;
        int physicalArmor;
        int speed;

        string name;


};

#endif // HEARLER_H
*/
