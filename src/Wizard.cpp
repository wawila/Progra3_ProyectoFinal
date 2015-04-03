#include "Wizard.h"

Wizard::Wizard()
{
    lvl = 1;
    xp = 0;
    vida = 5750;
    att = 1000;
    ene = 1000;
    armor = 100;
    elemastery = false;
    frame = 0;
}

/**
    Inferno Blast:

*/

bool Wizard::mov1(Personajes* per)
{
}

/**
    Thunder Strike:

*/
bool Wizard::mov2(Personajes* per)
{
}

/**
    Blizzard:

*/
bool Wizard::mov3(Personajes* per)
{
}

/**
    Wind Shear:
        O
    Blizzard

    Hacen que no ataque a nadie por ese turno!

*/
bool Wizard::mov4(Personajes* per)
{
}

/**
    Elemental Mastery:
        Hace que el siguente ataque sea mas fuerte

*/
bool Wizard::mov5(Personajes* per)
{
    elemastery = true;
}

bool Wizard::mov6(Personajes* per){}
bool Wizard::mov7(Personajes* per){}

Wizard::~Wizard()
{
    //dtor
}
