#include "Boss.h"

Boss::Boss()
{
    nombre = "Boss";
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
        att = 500;
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

/**
        Quita 200% del Ataque al Escudo
        Quita 150% del Ataque a la Vida
*/

bool Boss::mov1(Personajes* per)
{
    if(vida > 0)
    {
        per->vida -= att*1.5;
        per->armor -= att*2;
        cout<<nombre<<" le quito vida y escudo a "
            <<per->nombre<<endl<<" Vida: "<<per->vida<<endl
            <<" Escudo: "<<per->armor<<endl;
    }
}

/**
        Quita el 25% del escudo a alguien
        si no tiene escudo le quita att a la vida
*/
bool Boss::mov2(Personajes* per)
{
    if(vida > 0)
    {
        if(per->armor > 0)
            {
            per->armor *= 0.75;
        cout<<nombre<<" le quito escudo a "
            <<per->nombre<<endl<<" Escudo: "<<per->armor<<endl;
            }
        else
        {
            per->vida -= att;
            cout<<nombre<<" le quito vida a "
                <<per->nombre<<endl<<" Vida: "<<per->vida<<endl;
        }
    }
}

/**
        Le quita el 10% de la vida
        + el att
*/
bool Boss::mov3(Personajes* per)
{
    if(vida > 0)
    {
        per->vida -= (per->vida*0.1 + att);
        cout<<nombre<<" le quito vida a "
            <<per->nombre<<endl<<" Vida: "<<per->vida<<endl;
    }
}

/**
        Le quita todo el escudo
*/
bool Boss::mov4(Personajes* per)
{
    if(vida > 0)
    {
        per->armor = 0;
        cout<<nombre<<" le quito todo el escudo a "<<per->nombre<<endl;
    }
}

/**
        Le quita el 75% de la energia
*/
bool Boss::mov5(Personajes* per)
{
    if(vida > 0)
    {
        per->ene *= 0.25;
        cout<<nombre<<" le quito el 75% de la energia a "
            <<per->nombre<<endl<<"Energia Restanate: "<<per->ene<<endl;;
    }
}

/**
    no es un movimiento si no donde se escoge cual se va a usar
*/
bool Boss::mov6(Personajes* per)
{
    if(vida > 0)
        {
        int rnd = rand() %100 +1;

        if(rnd >= 1 && rnd < 45)
            mov1(per);

        if(rnd >= 45 && rnd < 60)
            mov2(per);

        if(rnd >= 60 && rnd < 75)
            mov3(per);

        if(rnd >= 75 && rnd <= 90)
            mov4(per);

        if(rnd >= 90 && rnd <= 100)
            mov5(per);


     if(per->vida < 0)
            per->vida = 0;

        if(per->armor < 0)
            per->armor = 0;

            return true;
            }
            return false;

}
bool Boss::mov7(Personajes* per) {}

Boss::~Boss()
{
    //dtor
}
