#ifndef FACTORYCHARACTER_H
#define FACTORYCHARACTER_H
#include "vector"
#include "Personnage.h"
#include "Wizard.h"
#include "Brawler.h"
#include "Ranger.h"
#include "Healer.h"

using std::vector;

class FactoryCharacter
{
    public:

        static FactoryCharacter *Get(){
            static FactoryCharacter instance;
            return &instance;
        }
        Healer *createHealer(){
            Healer h;
            m_FactoryHistory.push_back(&h);
            return &h;
        }
        Ranger *createRanger(){
            Ranger r;
            m_FactoryHistory.push_back(&r);
            return &r;
        }
        Wizard *createWizard(){
            Wizard w;
            m_FactoryHistory.push_back(&w);
            return &w;
        }
        Brawler *createBrawler(){
            Brawler b;
            m_FactoryHistory.push_back(&b);
            return &b;
        }

        virtual ~FactoryCharacter();
        FactoryCharacter(const FactoryCharacter& other);
        FactoryCharacter& operator=(const FactoryCharacter& other);
    protected:

    private:
        vector<Personnage*> m_FactoryHistory;
        FactoryCharacter();




};

#endif // FACTORYCHARACTER_H
