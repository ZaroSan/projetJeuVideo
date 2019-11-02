#include "Mob.h"

Mob::Mob()
{
    //ctor
}

Mob::~Mob()
{
    //dtor
}

Mob::Mob(const Mob& other)
{
    //copy ctor
}

Mob& Mob::operator=(const Mob& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
