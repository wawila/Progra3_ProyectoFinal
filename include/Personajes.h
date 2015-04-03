#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <cmath>

#ifndef PERSONAJES_H
#define PERSONAJES_H

using namespace std;

class Personajes
{
public:
    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *anim1;


    short lvl;
    short xp;
    float vida;
    float att;
    float ene;
    float armor;
    float x;
    float y;
    /**
    0- Nadie
    1- Paladin
    2- Sword man
    3- Wizard
    4- Cleric
    5- Todos
    */
    short target;
    int frame;

    virtual ~Personajes(){};

    /**

        To Do:
        - Validar si tienen suficiente energia
        X Agregar las animaciones
        - Wizard
        - !!!Trunos (parametro de frames para el boss)
        - !!!Enemigos
        - Regen (Energia)
        - !!!Pantalla de Ganar y Perder
            - Hacer una funcion para ver cuales siguen vivos
                si los 4 ya estan muertos pierde
            - Hacer una funcion para ver a quiene ya mato
                si mato a los tres gana
        - !!!Niveles
        - Enemigos Debiles y Bosses
        X Ordenar Codigo
        X !!!Menu
        X Mecanicas del Juego
        - !!!Guardar Mejores Scores (3)
        X Herencia y Polimorfismo
        - Color de Vida
        -----------------Debug------------------
        - Funciones para subir de nivel
        - Funciones para imprimir info
        - Imprimir lo que hace en cada ataque
        -----------------Extra------------------
        - Items
        - Free Roam
        - Musica
        - Arreglar Artes
        - Mas Personajes

        Hacer que apreten 1-2-3-4 para saber a quien van
        a target, para los ataques que son del equipo, Cleric

    */
    virtual bool mov1(Personajes* per) = 0;
    virtual bool mov2(Personajes* per) = 0;
    virtual bool mov3(Personajes* per) = 0;
    virtual bool mov4(Personajes* per) = 0;
    virtual bool mov5(Personajes* per) = 0;
    virtual bool mov6(Personajes* per) = 0;
    virtual bool mov7(Personajes* per) = 0;

    virtual bool sufEne(int x)
    {
        if(x <= ene)
            return true;
        else
            return false;
    }

   // virtual void draw(ALLEGRO_BITMAP *sp) = 0;

    virtual void lvlStats(int xp)
    {
        bool level = lvlUp(xp);
        if(level)
        {
            att += (att*0.1);
            vida += (vida*0.25);
            ene += (ene*0.5);
            lvl += 1;
            cout<<"Level Up!"<<endl;
            level = false;
        }
    }

    int lvlup = 3;
    virtual bool lvlUp(short xp)
    {
        if(xp == lvlup)
        {
            lvlup += 3;
            return true;
        }
        else
            return false;
    }

protected:
private:
};

#endif // PERSONAJES_H
