#ifndef CORE_H
#define CORE_H

#include <Incluir.h>

class Core
{
    public:

    int x;
    int y;
    int w;
    int h;
    int k;
    int contBoss;
    int frame;
    bool d;
    int bossvidamod;

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();


    ALLEGRO_KEYBOARD_STATE keyState;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *fondo = NULL;
    ALLEGRO_BITMAP *bg = NULL;
    ALLEGRO_BITMAP *boss = NULL;
    ALLEGRO_BITMAP *pl1 = NULL;
    ALLEGRO_BITMAP *pl2 = NULL;
    ALLEGRO_BITMAP *pl3 = NULL;
    ALLEGRO_BITMAP *pl4 = NULL;
//   ALLEGRO_BITMAP *minion1 = NULL;
//   ALLEGRO_BITMAP *minion2 = NULL;
    // ALLEGRO_BITMAP *att = al_load_bitmap("assets/anim/Fire3.png");

    ALLEGRO_BITMAP *barra = NULL;
    ALLEGRO_BITMAP *indpl = NULL;
    ALLEGRO_BITMAP *menu = NULL;
    ALLEGRO_BITMAP *menupl = NULL;

    ALLEGRO_COLOR rgba;

    Personajes* swordman;
    Personajes* paladin;
    Personajes* wizard;
    Personajes* cleric;
    Personajes* boss1;

        Core();
        void score();
        void limitStats(Personajes* per);
        void bossAtacar();
        int perderGanar();
        void bossLevel();
        void imprimirFinJuego();
        void initVariables();
        void menuPrincipal(string t);
        void mainLoop();
        void imprimirPantalla();
        void animacion(string t, int i);
        virtual ~Core();
    protected:
    private:
};

#endif // CORE_H
