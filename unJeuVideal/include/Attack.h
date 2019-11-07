#ifndef ATTACK_H
#define ATTACK_H

#include<string>

using namespace std;


class Attack
{
    private:
        string name;
        int power;
        int mana;
        int manaFix;
        int precision;

    public:
        Attack();
        Attack(string, int, int, int);
        Attack(string);
        ~Attack();

        string getName();
        int getPower();
        int getMana();
        int getManaFix();
        int getPrecision();
        void setMana(int);
        void setPrecision(int);
        void toString();





};

#endif // ATTAK_H
