#ifndef MOB_H
#define MOB_H


class Mob
{
    public:
        Mob();
        virtual ~Mob();
        Mob(const Mob& other);
        //Mob& operator=(const Mob& other);

        void takeDamage(int damage);

   //     std::string getStats()const;

    protected:

    private:
        int lifePoint;
        int power;
        int strength;
        int magicalArmor;
        int physicalArmor;
};

#endif // MOB_H
