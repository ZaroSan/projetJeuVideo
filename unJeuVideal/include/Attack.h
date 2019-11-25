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
        //formes canoniques
        Attack();
        Attack(string, int, int, int);
        Attack(string);
        ~Attack();

        //getters
        string getName();
        int getPower();
        int getMana();
        int getManaFix();
        int getPrecision();

        //setters
        void setMana(int);
        void setPrecision(int);
        //autres
        void toString();





};

#endif // ATTAK_H
