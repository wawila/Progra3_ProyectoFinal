#include <Incluir.h>

using namespace std;

void init()
{
    al_init();

    ALLEGRO_DISPLAY *display = NULL;

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(60,60);
    al_set_window_title(display, "DvCHM");

    al_install_keyboard();
    al_install_mouse();
    al_install_joystick();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    //ALLEGRO_EVENT_TIMER *timer = al_create_timer(1.0/FPS);

};

void prueba3()
{
    bool d  = true;
    int x = 0;
    int y = 0;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *fondo = NULL;
    ALLEGRO_BITMAP *personaje = NULL;
    ALLEGRO_KEYBOARD_STATE keyState;

    display = al_create_display(580, 444);
    al_flip_display();
    fondo = al_load_bitmap("assets/image/Translucent.png");
    personaje = al_load_bitmap("assets/image/Actor1.png");

    int frame = 0;

    while(d)
    {
        //ALLEGRO_EVENT events;
        //al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keyState);

        if(al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
        {
            cout<<"ESC"<<endl;
            d = false;
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_DOWN))
        {
            cout<<"DOWN -"<<"Y: "<<y<<endl;
            y += 4;
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_UP))
        {
            cout<<"UP -"<<"Y: "<<y<<endl;
            y -= 4;
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_LEFT))
        {
            cout<<"LEFT -"<<"X: "<<x<<endl;
            x -= 4;
        }
        if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
        {
            cout<<"RIGHT -"<<"X: "<<x<<endl;
            x += 4;
        }

//        else if(al_key_down(&keyState, ALLEGRO_KEY_SPACE))
//        {
//            attanim(att, minion1, 5, 304, 156);
//            cout<<"X "<<x<<" Y "<<y<<endl;
//        }


        frame++;

        al_draw_bitmap(fondo, 0 ,0, 0);

        for (int h = 0; h <= 96; h += 32)
        {
            for(int w = 0; w <= 64; w += 32)
            {
                al_draw_bitmap(fondo, 0 ,0, 0);
                al_draw_bitmap_region(personaje, w, h, 32, 32, x, y, 0 );
                al_flip_display();
                al_rest(0.1);
            }
        }
        al_flip_display();
        al_rest(0.025);

    }



}

/**
Solo funciona con el Joystick conectado
*/
void prueba6()
{
    ALLEGRO_DISPLAY *display = al_create_display(640,480);
    ALLEGRO_BITMAP *fondo = NULL;
    fondo = al_load_bitmap("assets/image/Translucent.png");

    ALLEGRO_EVENT events;
    ALLEGRO_JOYSTICK *js = al_get_joystick(0);
    ALLEGRO_JOYSTICK_STATE jss;

    al_get_joystick_state(js, &jss);
    cout<<al_get_num_joysticks()<<endl;
    cout<<al_get_joystick_name(js)<<endl;
    cout<<al_get_joystick_num_sticks(js)<<endl;
    cout<<al_get_joystick_num_buttons(js)<<endl;
    cout<<al_get_joystick_axis_name(js,2, 0)<<endl;
    cout<<al_get_joystick_event_source()<<endl;

    ALLEGRO_EVENT_QUEUE *aeq = al_create_event_queue();
    al_register_event_source(aeq, al_get_joystick_event_source());


    al_draw_bitmap(fondo, 0, 0, 0);
    al_flip_display();
    // al_rest(1);
    while (true)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(aeq, &events);

        if(jss.button[0])
        {
            cout<<"----------"<<endl;
        }

        else if(events.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN)
        {
            cout<<"Button: "<<events.joystick.button<<endl;


        }
        else if(events.type == ALLEGRO_EVENT_JOYSTICK_AXIS)
        {
            cout<<"Axis: "<<events.joystick.pos<<endl;
        }

    }
    al_draw_bitmap(fondo, 0, 0, 0);
    al_flip_display();
    al_rest(2.0);
}

void start()
{
    bool i = false;
    ALLEGRO_KEYBOARD_STATE keyState;
    cout<<"Se Abrio el Programa"<<endl;
    Core* core = new Core();
    core->menuPrincipal("MenuPrincipal");

    while (!i)
    {
        al_get_keyboard_state(&keyState);

        if(al_key_down(&keyState, ALLEGRO_KEY_ENTER)){
            cout<<"Esta Corriendo el Juego"<<endl;
            core->d=true;
            core->mainLoop();
        }else
        if(al_key_down(&keyState, ALLEGRO_KEY_I)){
            cout<<"Viendo Instrucciones"<<endl;
            core->menuPrincipal("Instrucciones");
            al_rest(0.1);
        }else
         if(al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)){
            i = true;
        }else
        core->menuPrincipal("MenuPrincipal");

        al_rest(0.01);
    }

}

int main()
{
    init();
    start();
    return 0;
}
