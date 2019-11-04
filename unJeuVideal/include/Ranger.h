#ifndef RANGER_H
#define RANGER_H

#include <Personnage.h>
#include "string"
#include "sstream"
using std::string;
using std::stringstream;

class Ranger : public Personnage
{
    public:
        Ranger();
        virtual ~Ranger();
        Ranger(const Ranger& other);
        int getStrength() const{return this->strength;}
        int getPower() const{return this->power;}
        int getMagicalArmor() const{return this->magicalArmor;}
        int getPhysicalArmor() const{return this->physicalArmor;}
        int getLifePoint() const{return this->lifePoint;}
        void setStrength(int i){this->strength=i;}
        void setPower(int i){this->power=0;}
        void setMagicalArmor(int i){this->magicalArmor=0;}
        void setPhysicalArmor(int i){this->physicalArmor=i;}
        void setLifePoint(int i){this->lifePoint=i;}
        string str(){
            stringstream stri;
            stri <<"Life Points :"<<this->lifePoint<<"\nStrength :"<<this->strength<<"\nPower :"<<this->power<<"\nMagical Armor :"<<this->magicalArmor<<"\nPhysical Armor :"<<this->physicalArmor;
            return stri.str();
        };
        string sendAttack(Attack,Mob*);

    protected:

    private:
        int lifePoint;
        int power;
        int strength;
        int magicalArmor;
        int physicalArmor;
};

#endif // RANGER_H
