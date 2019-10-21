#ifndef RANGER_H
#define RANGER_H

#include <Personnage.h>


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

        static Personnage* __stdcall Create() {return new Ranger();}

    protected:

    private:
};

#endif // RANGER_H
