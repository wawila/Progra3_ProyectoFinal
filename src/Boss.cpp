#include "Boss.h"

Boss::Boss()
{
        vida = 110000;
        att = 250;
        armor = 5000;
        target = 1;
}

Boss::Boss(bool d)
{
        vida = 1000;
        att = 250;
        armor = 500;
        target = 1;

}

void Boss::levelBoss(int x)
{
    switch(x)
    {
    case 1:
        vida = 110000;
        att = 250;
        armor = 5000;
        frame = 0;
        target = 1;
        break;
    case 2:
        vida = 115000;
        att = 750;
        armor = 10000;
        frame = 0;
        target = 1;
        break;
    case 3:
        vida = 125000;
        att = 1500;
        armor = 15000;
        frame = 0;
        target = 1;
        break;
    }
}

/**
    Escoge un Nuevo Target:
     1-45  - Paladin
    45-60  - Sword Man
    60-75  - Wizard
    75-90  - Cleric
    90-100 - Todos

    @param x =  0 - No ataca a nadie
                1 - Paladin
                2 - Hacer random

*/
int Boss::newTarget(int x)
{
    switch(x)
    {
    case 0:
        return 0;

    case 1:
        return 1;

    case 2:
        int rnd = rand() %100 +1;

        if(rnd >= 1 && rnd < 45)
            return 1;

        if(rnd >= 45 && rnd < 60)
            return 2;

        if(rnd >= 60 && rnd < 75)
            return 3;

        if(rnd >= 75 && rnd <= 90)
            return 4;

        if(rnd >= 90 && rnd <= 100)
            return 5;
    }
}

bool Boss::atacar()
{
   x = newTarget(2);

}


/**
    Ataque para Paladin:
        Quita 200% del Ataque al Escudo
        Quita 150% del Ataque a la Vida

*/

bool Boss::mov1(Personajes* per)
{
    per->vida -= att*1.5;
    per->armor -= att*2;

}

/**
    Ataque para Cleric:

*/
bool Boss::mov2(Personajes* per)
{
}

/**
    Ataque para Cualquiera

*/
bool Boss::mov3(Personajes* per)
{
}

/**
    Ataque para Todos:
*/
bool Boss::mov4(Personajes* per)
{
}

bool Boss::mov5(Personajes* per){}
bool Boss::mov6(Personajes* per){}
bool Boss::mov7(Personajes* per){}

Boss::~Boss()
{
    //dtor
}
