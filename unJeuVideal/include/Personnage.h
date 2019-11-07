#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Attack.h"

#include <string>
#include "sstream"
using std::string;
using std::stringstream;

using namespace std;
class Personnage
{
public:
    Personnage();
    Personnage(string);
    Personnage(string, int, int, int, int, int, Attack* );


    virtual ~Personnage();
    Personnage (const Personnage& other);
   /* virtual int getStrength() const;
    virtual int getPower() const;
    virtual int getMagicalArmor() const;
    virtual int getPhysicalArmor() const;
    virtual int getLifePoint() const;
    virtual string getName()const;
    virtual void setName(string);
    virtual void setStrength(int);
    virtual void setPower(int);
    virtual void setMagicalArmor(int);
    virtual void setPhysicalArmor(int);
    virtual void se int getStrength() const{return this->strength;}
        int getPower() const{return this->power;}
        int getMagicalArmor() const{return this->magicalArmor;}
        int getPhysicalArmor() const{return this->physicalArmor;}
        int getLifePoint() const{return this->lifePoint;}
        int getLifePointMax() const{return this->lifePointFix;}
        int getSpeed()const{return speed;}
        void setStrength(int i){this->strength=i;}
        void setPower(int i){this->power=0;}
        void setMagicalArmor(int i){this->magicalArmor=0;}
        void setPhysicalArmor(int i){this->physicalArmor=i;}
        void setLifePoint(int i){this->lifePoint=i;}
        void setSpeed(int i){this->speed=i;}
        string getName()const{return this->name;}tLifePoint(int);

    virtual string str(){
            stringstream stri;
            stri <<"Life Points :"<<this->lifePoint<<"\n name: "<<this->name<<"\nStrength :"<<this->strength<<"\nPower :"<<this->power<<"\nMagical Armor :"<<this->magicalArmor<<"\nPhysical Armor :"<<this->physicalArmor;
            return stri.str();
        };

*/
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
        void setName(string str){this->name=str;};
        string getName()const{return this->name;}
        string str(){
            stringstream stri;
            stri <<"Life Points :"<<this->lifePoint<<"\nName :"<<this->name<<"\nStrength :"<<this->strength<<"\nPower :"<<this->power<<"\nMagical Armor :"<<this->magicalArmor<<"\nPhysical Armor :"<<this->physicalArmor;
            return stri.str();
        };
    void setPath();
    string getPath(bool);

    Personnage & operator=(Personnage const & other)
    {
        this->lifePoint=other.lifePoint;
        this->strength=other.strength;
        this->power=other.power;
        this->magicalArmor=other.magicalArmor;
        this->physicalArmor=other.physicalArmor;

        this->name=other.name;

        this->attack[0]=other.attack[0];
        this->attack[1]=other.attack[1];
        this->attack[2]=other.attack[2];
        this->attack[3]=other.attack[3];

        this->pathFront=other.pathFront;
        this->pathBack=other.pathBack;

        return*this;
    }





private:
    int strength;
    int power;
    int magicalArmor;
    int physicalArmor;
    int lifePoint;

    string name;

    string pathFront;
    string pathBack;

    Attack attack[4];



};

#endif // PERSONNAGE_H
