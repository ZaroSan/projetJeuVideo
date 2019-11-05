#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Attack.h"


class Personnage
{
    private:
        int lifePoint;
        int lifePointFix;
        int power;
        int strength;
        int magicalArmor;
        int physicalArmor;
        int speed;

        string name;

    //  Attack attack[4];

    public:
        Personnage();
        virtual ~Personnage();
        Personnage (const Personnage& other);
        virtual int getStrength() const;
        virtual int getPower() const;
        virtual int getMagicalArmor() const;
        virtual int getPhysicalArmor() const;
        virtual int getLifePoint() const;
        virtual string getName()const;
        virtual void setStrength(int);
        virtual void setPower(int);
        virtual void setMagicalArmor(int);
        virtual void setPhysicalArmor(int);
        virtual void setLifePoint(int);
};

#endif // PERSONNAGE_H
