#include "FactoryCharacter.h"

FactoryCharacter::FactoryCharacter()
{
    //ctor
}

FactoryCharacter::~FactoryCharacter()
{
    //dtor
    m_FactoryHistory.clear();
}

FactoryCharacter::FactoryCharacter(const FactoryCharacter& other)
{
    //copy ctor
}

FactoryCharacter& FactoryCharacter::operator=(const FactoryCharacter& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
