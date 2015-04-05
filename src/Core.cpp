#include "Core.h"

Core::Core()
{
    display = al_create_display(800, 600);
}

void Core::initVariables()
{
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    fondo = al_load_bitmap("assets/image/Lava1.png");
    bg = al_load_bitmap("assets/image/RockCave.png");

    boss = al_load_bitmap("assets/image/Dragon.png");
    // minion1 = al_load_bitmap("assets/image/General.png");
    // minion2 = al_load_bitmap("assets/image/Mage.png");


    pl1 = al_load_bitmap("assets/image/Swordman.png");
    pl2 = al_load_bitmap("assets/image/Cleric_f.png");
    pl3 = al_load_bitmap("assets/image/Wizard_m.png");
    pl4 = al_load_bitmap("assets/image/Paladin_f.png");

    barra = al_load_bitmap("assets/image/PruebaVida.png");
    indpl = al_load_bitmap("assets/image/IndicadorPlayer.png");
    menu = al_load_bitmap("assets/image/Background.png");
    menupl = al_load_bitmap("assets/image/Swordman1.png");

    x = 100;
    y = 100;
    w = 180;
    h = 250;
    k = 100;
    contBoss = 1;
    frame = 0;
    d = true;
    bossvidamod = 137.5;
}

void Core::menuPrincipal(string b)
{
    stringstream tipo;
    tipo<<"assets/image/"<<b<<".png";
    fondo = al_load_bitmap(tipo.str().c_str());

    if(b == "YouWin" || b == "GameOver")
        al_draw_scaled_bitmap(fondo, 0, 0, 640, 480, 0, 0, 800, 600, 0);
    else

        al_draw_bitmap(fondo, 0, 0, 0);
    al_flip_display();
    al_rest(0.1);
}

void Core::mainLoop()
{
    swordman = new Swordman();
    paladin = new Paladin();
    wizard = new Wizard();
    cleric = new Cleric();
    boss1  = new Boss();

    initVariables();
    frame = 0;
    while(d)
    {
        //ALLEGRO_EVENT events;
        //al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keyState);

        if(al_key_down(&keyState, ALLEGRO_KEY_Q))
        {
            cout<<"ESC"<<endl;
            d = false;
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_DOWN))
        {
            cout<<"DOWN -"<<"Y: "<<y<<endl;
            y += 2;
            al_rest(0.1);
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_UP))
        {
            cout<<"UP -"<<"Y: "<<y<<endl;
            y -= 2;
            al_rest(0.1);
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_LEFT))
        {
            cout<<"LEFT -"<<"X: "<<x<<endl;
            x -= 2;
            al_rest(0.1);
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
        {
            cout<<"RIGHT -"<<"X: "<<x<<endl;
            x += 2;
            al_rest(0.1);
        }

        else if(al_key_down(&keyState, ALLEGRO_KEY_SPACE))
        {
            cout<<"X "<<x<<" Y "<<y<<endl;
        }



//        if(x <= 100)
//        {
//            rgba = al_map_rgba(255, 0, 0, 255);
//        }
//        else
//        {
//            rgba = al_map_rgba(0, 255, 0, 255);
//        }
//
        if(x>=107)
            x = 100;
        if(x<=99)
            x = 106;
        if(y>=107)
            y = 100;
        if(y<=99)
            y = 106;

        if(frame > 13)
            switch(x)
            {
            case 100:
                w = 180;
                h = 250;
                menupl = al_load_bitmap("assets/image/Swordman1.png");
                switch(y)
                {
                case 100:
                    k = 28;
                    rgba = al_map_rgba(255, 0, 0, 255);
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Sword2", 384);
                        swordman->mov1(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    break;
                case 102:
                    k = 56;
                    rgba = al_map_rgba(130, 0, 0, 255);
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Sword10", 576);
                        swordman->mov2(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    break;
                case 104:
                    k = 84;
                    rgba = al_map_rgba(65, 0, 0, 255);
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Sword4", 384);
                        swordman->mov3(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    break;
                case 106:
                    k = 112;
                    rgba = al_map_rgba(30, 0, 0, 255);
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Sword5", 768);
                        swordman->mov4(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    break;
                }
                break;
            case 102:
                w = 296;
                h = 288;
                menupl = al_load_bitmap("assets/image/Paladin1.png");
                switch(y)
                {
                case 100:
                    k = 28;
                    rgba = al_map_rgba(0, 0, 255, 255);
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Special6", 192);
                        paladin->mov1(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    break;
                case 102:
                    k = 56;
                    rgba = al_map_rgba(0, 0, 130, 255);
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Spear2", 384);
                        paladin->mov2(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    break;
                case 104:
                    k = 84;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Paladin "<<paladin->vida<<endl<<" Armadura Paladin "<<paladin->armor<<endl;
                        animacion("Special11", 768);
                        paladin->mov3(paladin);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida P "<<paladin->vida<<endl<<" Armadura Paladin "<<paladin->armor<<endl;
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(0, 0, 65, 255);
                    break;
                case 106:
                    k = 112;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Paladin "<<paladin->vida<<endl<<" Armadura Paladin "<<paladin->armor<<endl;
                        animacion("State6", 768);
                        paladin->mov3(paladin);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida P "<<paladin->vida<<endl<<" Armadura Paladin "<<paladin->armor<<endl;
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(0, 0, 30, 255);
                    break;
                }
                break;
            case 104:
                w = 170;
                h = 366;
                menupl = al_load_bitmap("assets/image/Wizard1.png");
                switch(y)
                {
                case 100:
                    k = 28;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Fire3", 960);
                        wizard->mov1(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(255, 255, 255, 255);
                    break;
                case 102:
                    k = 56;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Thunder1", 384);
                        wizard->mov2(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(130, 130, 130, 255);
                    break;
                case 104:
                    k = 84;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Ice4", 384);
                        wizard->mov3(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(65, 65, 65, 255);
                    break;
                case 106:
                    k = 112;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Wind1", 384);
                        wizard->mov4(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(0, 0, 0, 255);
                    break;
                }
                break;

            case 106:
                w = 78;
                h = 294;
                menupl = al_load_bitmap("assets/image/Cleric1.png");
                switch(y)
                {
                case 100:
                    k = 28;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        animacion("Heal4", 768);
                        cleric->mov1(paladin);
                        cleric->mov1(swordman);
                        cleric->mov1(wizard);
                        cleric->mov1(cleric);
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(0, 255, 0, 255);
                    break;
                case 102:
                    k = 56;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cleric->mov2(paladin);
                        cleric->mov2(swordman);
                        cleric->mov2(wizard);
                        cleric->mov2(cleric);
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(0, 130, 0, 255);
                    break;
                case 104:
                    k = 84;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        animacion("Light2", 768);
                        cleric->mov3(paladin);
                        cleric->mov3(swordman);
                        cleric->mov3(wizard);
                        cleric->mov3(cleric);
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(0, 65, 0, 255);
                    break;
                case 106:
                    k = 112;
                    if(al_key_down(&keyState, ALLEGRO_KEY_ENTER))
                    {
                        cout<<"Antes:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        animacion("Darkness1", 192);
                        cleric->mov4(boss1);
                        cout<<"Despues:"<<endl;
                        cout<<" Vida Boss "<<boss1->vida<<endl<<" Armadura Boss "<<boss1->armor<<endl;
                        al_rest(0.05);
                    }
                    rgba = al_map_rgba(0, 30, 0, 255);
                    break;
                }
                break;
            }
        bossLevel();
        bossAtacar();
        limitStats(paladin);
        limitStats(swordman);
        limitStats(wizard);
        limitStats(cleric);
        limitStats(boss1);

        frame++;
        // cout<<frame<<endl;

        imprimirFinJuego();
        al_rest(0.025);
    }
    /*
        al_destroy_display(display);
        al_destroy_bitmap(boss);
        al_destroy_bitmap(fondo);
        */
};

void Core::imprimirPantalla()
{
    al_draw_scaled_bitmap(fondo, 0, 0, 580, 444, 0, 0, 800 ,444 ,0);
    al_draw_scaled_bitmap(bg, 0, 0, 580, 444, 0, 0, 800, 444, 0);
    al_draw_scaled_bitmap(menu, 0, 0, 800, 200, 0, 445, 800, 155, 0);
    al_draw_bitmap(menupl, 300, 450, 0);
    al_draw_tinted_scaled_bitmap(barra, rgba, 0, 0, 10, 50, 1, 550, 35, 35, 0);

    // Vida Boss1
    al_draw_tinted_scaled_bitmap(barra, al_map_rgba(255, 255, 0, 255)   , 0, 0, 10, 50, 1, 589, boss1->vida/bossvidamod, 10, 0);
    al_draw_tinted_scaled_bitmap(barra, al_map_rgba(255, 0, 0, 255)     , 0, 0, 10, 50, 1, 579, swordman->vida/7.5, 10, 0);
    al_draw_tinted_scaled_bitmap(barra, al_map_rgba(0, 255, 0, 255)     , 0, 0, 10, 50, 1, 569, paladin->vida/13.75, 10, 0);
    al_draw_tinted_scaled_bitmap(barra, al_map_rgba(0, 0, 255, 255)     , 0, 0, 10, 50, 1, 559, cleric->vida/7.25, 10, 0);
    al_draw_tinted_scaled_bitmap(barra, al_map_rgba(255, 0, 255, 255)   , 0, 0, 10, 50, 1, 549, wizard->vida/7.25, 10, 0);

    al_draw_scaled_bitmap(pl1, 0, 0, 197, 195, 86, 164, 167, 165, 0);
    al_draw_bitmap(pl2, 12, 332-140, ALLEGRO_FLIP_HORIZONTAL);
    al_draw_scaled_bitmap(pl4, 0, 0, 194, 210, 208, 196, 185, 170, ALLEGRO_FLIP_HORIZONTAL);
    al_draw_scaled_bitmap(pl3, 0, 0, 216, 235, 108, 242, 180, 195, ALLEGRO_FLIP_HORIZONTAL);
//       al_draw_bitmap(minion2, 50, 300, 0);
    al_draw_bitmap(boss, 430, 120, 0);
    al_draw_bitmap(indpl, w+3, h-140, 0);
    al_draw_scaled_rotated_bitmap(indpl, 22, 25, 275, k+430, 0.8, 0.8, -ALLEGRO_PI/2, 0);

    //     al_draw_bitmap(minion1, 550, 300, 0);
    al_flip_display();
}


/**
    -1 - Nada
     0 - Perdio
     1 - Gano

     Auxiliar de imprimirFinJuego()
*/
int Core::perderGanar()
{
    if(paladin->vida    <= 0 &&
            swordman->vida   <= 0 &&
            wizard->vida     <= 0 &&
            cleric->vida     <= 0)
    {
        cout<<"Has Perdido!"<<endl;
        return 1;
    }

    if(boss1->vida <=0 && contBoss == 3)
    {
        score();
        cout<<"Has Ganado!"<<endl;
        return 0;
    }

    return -1;

}

void Core::imprimirFinJuego()
{
    if(perderGanar() == -1)
        imprimirPantalla();

    if(perderGanar() == 0)
    {
        d = false;
        menuPrincipal("YouWin");
        al_rest(3);
    }

    if(perderGanar() == 1)
    {
        d = false;
        menuPrincipal("GameOver");
        al_rest(3);
    }

}

void Core::bossLevel()
{
    if(boss1->vida <= 0 && contBoss == 1)
    {
        contBoss = 2;
        boss1->levelBoss(contBoss);
        fondo = al_load_bitmap("assets/image/Lava2.png");
        boss = al_load_bitmap("assets/image/Demon.png");
        bossvidamod = 143.75;
    }

    if(boss1->vida <= 0 && contBoss == 2)
    {
        contBoss = 3;
        boss1->levelBoss(contBoss);
        fondo = al_load_bitmap("assets/image/LavaCave1.png");
        bg = al_load_bitmap("assets/image/LavaCave2.png");
        boss = al_load_bitmap("assets/image/Evilgod.png");
        bossvidamod = 156.25;
    }
}

void Core::bossAtacar()
{
    if(frame % 30 == 0 && boss1->vida > 0)
    {
        int rnd = rand() %100 +1;

        if(rnd >= 1 && rnd < 45 && paladin->vida > 0)
            boss1->mov6(paladin);

        if(rnd >= 45 && rnd < 60 && swordman->vida > 0)
            boss1->mov6(swordman);

        if(rnd >= 60 && rnd < 75 && wizard->vida > 0)
            boss1->mov6(wizard);

        if(rnd >= 75 && rnd <= 90 && cleric->vida > 0)
            boss1->mov6(cleric);

        if(rnd >= 90 && rnd <= 100
                && paladin->vida > 0
                || paladin->vida > 0
                || paladin->vida > 0
                || paladin->vida > 0)
        {
            boss1->mov6(paladin);
            boss1->mov6(swordman);
            boss1->mov6(wizard);
            boss1->mov6(cleric);
        }

    }
}

void Core::limitStats(Personajes* per)
{
    if(per->vida < 0)
        per->vida = 0;

    if(per->armor < 0)
        per->armor = 0;

    if(per->ene < 0)
        per->ene = 0;

    if(per->nombre == "Paladin")
    {
        if(per->vida > 11000)
            per->vida = 11000;
    }

    if(per->nombre == "Swordman")
    {
        if(per->vida > 6000)
            per->vida = 6000;
    }

    if(per->nombre == "Wizard")
    {
        if(per->vida > 5800)
            per->vida = 5800;
    }

    if(per->nombre == "Cleric")
    {
        if(per->vida > 5800)
            per->vida = 5800;
    }

    if(per->nombre == "Boss1")
    {
        if(per->vida > 110000)
            per->vida = 110000;
    }

    if(per->nombre == "Boss2")
    {
        if(per->vida > 115000)
            per->vida = 115000;
    }

    if(per->nombre == "Boss3")
    {
        if(per->vida > 125000)
            per->vida = 125000;
    }
}

/**
    Hacer parametros para decir donde se va a imprimir
    para los ataques que son para uno mismo

    @param i = Cantidad de filas - 1 * 192
*/

void Core::animacion(string t, int i)
{

    if(al_key_down(&keyState, ALLEGRO_KEY_LSHIFT))
    {
        cout<<"Animacion Cancelada"<<endl;
        return;
    }

    stringstream anim;
    anim<<"assets/anim/"<<t<<".png";

    ALLEGRO_BITMAP* animacion = al_load_bitmap(anim.str().c_str());

    for(int h = 0; h <= i; h += 192)
    {
        for(int w = 0; w <= 768; w += 192)
        {
            imprimirFinJuego();
            al_draw_bitmap_region(animacion, w, h, 192, 192, 533, 165, 0 );
            al_flip_display();
            al_rest(0.08);
        }
    }

}


int Primero = 99999, Segundo = 99999, Tercero = 99999;
void Core::score()
{
    ifstream in("HighScore.txt");
    in>>Primero;
    in>>Segundo;
    in>>Tercero;

    in.close();

    ofstream out("HighScore.txt", ios::in);

    if(frame<Primero){
        out<<frame<<endl;
        out<<Primero<<endl;
        out<<Segundo<<endl;
    }else if(frame<Segundo && frame>Primero){
        out<<Primero<<endl;
        out<<frame<<endl;
        out<<Segundo<<endl;
    }else if(frame<Tercero && frame>Tercero){
        out<<Primero<<endl;
        out<<Segundo<<endl;
        out<<frame<<endl;
    }else
        out<<Primero<<endl;
        out<<Segundo<<endl;
        out<<Tercero<<endl;
    out.close();

    cout<<"Tu Score: "<<frame;

}

Core::~Core()
{
    //dtor
}
