#include "Paladin.h"

Paladin::Paladin()
{
    nombre = "Paladin";
    lvl = 1;
    xp = 0;
    vida = 11000;
    att = 800;
    ene = 800;
    armor = 1000;
    vindspiritusado = false;
    frame = 0;
}


/**
    Taunt:
        Hace que el boss ataque a este personaje
*/

bool Paladin::mov1(Personajes* per)
{
    if(vida > 0){
        per->target = 1;
        return true;
    }else
        return false;

}

/**
    Colossus Smash:
        Ataca por el 100% del ataque, si
        tiene escudo ataca por el 250%
*/
bool Paladin::mov2(Personajes* per)
{
    if(vida > 0)
    {
        if(per->armor >= att*2.5)
        {
            per->armor -= att*2.5;
        }
        else if (per->armor < att*2.5)
        {
            per->vida -= (att*2.5)-per->armor;
            per->armor = 0;
        }
        else if (per->armor <= 0)
        {
            per->vida -= att;
        }

        return true;
    }else
        return false;
}

/**
    Righteous Shield:
        Le agrega el doble de ataque como escudo
*/
bool Paladin::mov3(Personajes* per)
{
    if(vida > 0){
        armor += att*2;
        return true;
    }else
        return false;

}

/**
    Vindicator Spirit:
        Cuando muere el personaje regresa con:
        100% energia (800)
        25% Vida total (2750)
        1000 de armadura
        1000 de ataque
        Solo funciona 1 ves
*/
bool Paladin::mov4(Personajes* per)
{
    if(vida <= 0 && !vindspiritusado)
    {
        vida = 2750;
        ene = 800;
        armor = 1000;
        att = 1000;
        vindspiritusado = true;
        return true;
    }
    else
        return false;

}

bool Paladin::mov5(Personajes* per){}
bool Paladin::mov6(Personajes* per){}
bool Paladin::mov7(Personajes* per){}
void Paladin::levelBoss(int x){}

Paladin::~Paladin()
{
    //dtor
}
