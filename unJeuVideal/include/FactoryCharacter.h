#ifndef FACTORYCHARACTER_H
#define FACTORYCHARACTER_H
#include "Personnage.h"


class FactoryCharacter
{
    public:
        FactoryCharacter();
        virtual ~FactoryCharacter();
        FactoryCharacter(const FactoryCharacter& other);
        /*Personnage createWizard();
        Personnage createBrawler();
        Personnage createRanger();
        Personnage createHealer();*/

    protected:

    private:
};

#endif // FACTORYCHARACTER_H
