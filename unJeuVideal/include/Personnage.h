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
        /**
        Now for simplicity’s sake, I used a typedef to define a type for the function
         that is used by the implementation classes to create instances of Personnage.
         This typedef is also used in declaring the map that maps the personnage name
         to the function that creates that particular classe of personnage.
         You can use whatever calling convention you like, but for this example, I chose __stdcall.
        */
       typedef Personnage* (__stdcall *CreatePersonnage)(void);
};

#endif // PERSONNAGE_H
