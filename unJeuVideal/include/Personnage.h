#ifndef PERSONNAGE_H
#define PERSONNAGE_H


class Personnage
{
    public:
       virtual int getStrength() const=0;
       virtual int getPower() const=0;
       virtual int getMagicalArmor() const=0;
       virtual int getPhysicalArmor() const=0;
       virtual int getLifePoint() const=0;
       virtual void setStrength(int)=0;
       virtual void setPower(int)=0;
       virtual void setMagicalArmor(int)=0;
       virtual void setPhysicalArmor(int)=0;
       virtual void setLifePoint(int)=0;

};

#endif // PERSONNAGE_H
