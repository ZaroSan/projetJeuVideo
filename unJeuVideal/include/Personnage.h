#ifndef PERSONNAGE_H
#define PERSONNAGE_H


class Personnage
{
    public:
        Personnage();
        virtual ~Personnage();
        Personnage (const Personnage& other);
        virtual int getStrength() const;
       virtual int getPower() const;
       virtual int getMagicalArmor() const;
       virtual int getPhysicalArmor() const;
       virtual int getLifePoint() const;
       virtual void setStrength(int);
       virtual void setPower(int);
       virtual void setMagicalArmor(int);
       virtual void setPhysicalArmor(int);
       virtual void setLifePoint(int);

};

#endif // PERSONNAGE_H
