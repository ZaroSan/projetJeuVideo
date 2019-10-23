#include <iostream>
#include "FactoryCharacter.h"
using namespace std;

int main()
{

    Wizard *w=FactoryCharacter::Get()->createWizard();
    w=new Wizard();
    cout <<w->str();
    return 0;
}
