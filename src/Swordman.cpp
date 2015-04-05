#include "Swordman.h"

Swordman::Swordman()
{
    nombre = "Swordman";
    lvl = 1;
    xp = 0;
    vida = 6000;
    att = 1200;
    ene = 500;
    armor = 100;
    frame = 0;
}

Swordman::Swordman(bool d)
{
    lvl = 1;
    xp = 0;
    vida = 6000;
    att = 100;
    ene = 500;
    armor = 100;
    frame = 0;
}

/**
    Flaming Fury:
        Ataca por el 85% del ataque si tiene
        escudo sino  por 115% del ataque a vida
*/

bool Swordman::mov1(Personajes* per)
{
    if(vida > 0)
    {
        if(per->armor >= att*0.85)
        {
            per->armor -= att*0.85;
        }
        else if (per->armor < att*0.85)
        {
            per->vida -= (att*0.85)-per->armor;
            per->armor = 0;
        }
        else if (per->armor <= 0)
        {
            per->vida -= att*1.15;
        }

        return true;
    }else
        return false;
}

/**
    Sunder Armor:
        Ataca por el 300% del ataca a escudos
        No hace daño a vida
*/
bool Swordman::mov2(Personajes* per)
{
    if(vida > 0 && per->armor > 0)
    {
        if(per->armor > att*3)
            per->armor -= att*3;
        else
            per->armor = 0;

            return true;
    }else
        return false;
}

/**
    Quick Attack:
        Ataca por 85% ignorando escudo
        (ataca tan rapido que no puede defenderse)
*/
bool Swordman::mov3(Personajes* per)
{
    if(vida > 0){
        per->vida -= (att*0.85);
        return true;
    }else
        return false;
}

/**
    Multi Strike:
        Ataca 4 veces por el 30% del ataque
*/
bool Swordman::mov4(Personajes* per)
{
    if(vida > 0){
        for(int i = 0; i <= 4; i++)
        {
            if(per->armor >= att*0.3)
            {
                per->armor -= att*0.3;
            }
            else if (per->armor < att*0.3)
            {
                per->vida -= (att*0.3)-per->armor;
                per->armor = 0;
            }
        }
        return true;
    }
        return false;
}
bool Swordman::mov5(Personajes* per){}
bool Swordman::mov6(Personajes* per){}
bool Swordman::mov7(Personajes* per){}
void Swordman::levelBoss(int x){}

Swordman::~Swordman()
{
    //dtor
}
