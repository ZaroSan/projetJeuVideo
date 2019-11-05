#ifndef MOB_H
#define MOB_H

#include "string"
#include "sstream"
using std::string;
using std::stringstream;

class Mob
{
    private:
        int lifePoint;
        int lifePointFix;
        int power;
        int strength;
        int magicalArmor;
        int physicalArmor;
        int speed;

    public:
        Mob();
        virtual ~Mob();
        Mob(const Mob& other);
        //Mob& operator=(const Mob& other);
        int getStrength() const;
        int getPower() const;
        int getMagicalArmor() const;
        int getPhysicalArmor() const;
        int getLifePoint() const;
        int getLifePointMax() const;
        int getSpeed() const;
        void setStrength(int);
        void setPower(int);
        void setMagicalArmor(int);
        void setPhysicalArmor(int);
        void setLifePoint(int);
        void setSpeed(int);

        void takeDamage(int damage);
        void getStats();
};

#endif // MOB_H
