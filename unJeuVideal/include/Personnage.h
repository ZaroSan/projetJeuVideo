#ifndef PERSONNAGE_H
#define PERSONNAGE_H


class Personnage
{
    public:
        Personnage(int power,int strength ,int lifePoint,int magicalArmor,int physicalArmor);
        virtual ~Personnage();
        Personnage(const Personnage& other);
        int getStrength()const{return this->strength;};
        int getPower()const{return this->power;};
        int getLifePoint()const {return this->lifePoint;};
        int getMagicalArmor()const {return this->magicalArmor};
        int getPhysicalArmor()const {return this->physicalArmor};
        void setStrength(int i);
        void setPower(int i);
        void setLifePoint(int i);
        void setMagicalArmor(int i);
        void setPhysicalArmor(int i);
    protected:

    private:
        int power;
        int strength;
        int lifePoint;
        int magicalArmor;
        int physicalArmor;
};

#endif // PERSONNAGE_H
