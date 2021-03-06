#include "Cleric.h"

Cleric::Cleric()
{
    nombre = "Cleric";
    lvl = 1;
    xp = 0;
    vida = 5800;
    att = 500;
    ene = 1000;
    armor = 100;
    frame = 0;
    shadowstance = false;

}
/**
    Mover los ataques de shadow form a
    mov1 mov2 mov3 y mov4
*/

bool Cleric::getShadowstance()
{
    return shadowstance;
}

/**
    Barrier:
        Le da a todos el 10% del producto de su
        escudo por su ataque y hace el ataque 0;
        Si no tiene escudo le da a el un escudo de 100;
        Si no tiene ataque no hace nada

*/
int escudo = 0;
bool Cleric::mov1(Personajes* per)
{
    mov5(per);

    if(!shadowstance && vida > 0 && att > 0)
    {
        if(armor > 0)
        {
            per->armor += (att*armor)/10;
        }
        else
            armor = 100;


        escudo++;

        if(escudo == 4)
        {
            att = 0;
            escudo = 0;

        }

        cout<<per->nombre<<" Barrier  "<<escudo<<endl;
        return true;
    }
    else
        return false;

}

/**
    Holy Light:
        Le suma 125 al ataque, maximo 500, y
        Cura un personaje por el doble de su ataque
*/
bool Cleric::mov2(Personajes* per)
{
    mov6(per);

    if(!shadowstance && vida > 0)
    {
        if(att < 500)
            att += 125;

        if(att > 500)
            att = 500;
        if(att < 0)
            att = 0;

        per->vida += (att*2);

        return true;
    }
    else
        return false;

}

/**
    Avenging Wrath:
        Le suma su ataque a los demas personajes
        por el siguiente, haciendo su ataque 0
*/
int arma = 0;
bool Cleric::mov3(Personajes* per)
{
    // Crear instancias de todos los otros persones
    // Talves recursivo con los diferentes tipos
    if(!shadowstance && vida > 0)
    {
        if(att > 0)
        {
            per->att += att;
        }

        arma++;

        if(arma == 4)
        {
            att = 0;
            arma = 0;

        }

    }else
        mov7(per);

        return false;

}

/**
    Shadow Stance:
        Iguala su ataque a vida*0.25 y
        le da ataques nuevos
*/
bool Cleric::mov4(Personajes* per)
{


    if(!shadowstance && vida > 0)
    {
        att = vida*0.25;
        shadowstance = true;
        return true;
    }else
        return false;
}

/**
    Shadow Bolt:
        Ataque y le resta 10% a la vida;
        Ataque se vuelve a igualar a la vida
        Si se puede matar solo
*/
bool Cleric::mov5(Personajes* per)
{
    if(shadowstance && vida > 0)
    {
        att = vida*0.25;
        if(per->armor >= att)
        {
            per->armor -= att;
            vida -= (vida*0.1);
        }
        else if (per->armor < att)
        {
            per->vida -= (att-per->armor);
            per->armor = 0;
            vida -= (vida*0.1);
        }

        if(vida < 0)
            vida = 0;

        return true;
    }
    else
        return false;
}

/**
    Soul Burn:
        Ataque por el valor de su energia, ignora escudos;
        le resta 15% a la vida y divide el energia en 2
*/
bool Cleric::mov6(Personajes* per)
{
    if(shadowstance && vida > 0)
    {
        per->vida -= ene;
        vida -= (vida*0.15);
        ene = ene/2;

        return true;
    }
    else
        return false;
}

/**
    Holy Stance:
        Regresa el ataque a 0 y el escudo a 100
*/
bool Cleric::mov7(Personajes* per)
{
    if(shadowstance && vida > 0)
    {
        att = 0;
        armor = 100;
        shadowstance = false;
        return true;
    }
    else
        return false;
}

void Cleric::levelBoss(int x){}

Cleric::~Cleric()
{
    //dtor
}
