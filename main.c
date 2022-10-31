#include "header.h"


int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    srand(time(NULL));


    BITMAP* page=create_bitmap(1024,768);


    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        menuJeu(page);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);

    }
    return 0;
}
END_OF_MAIN();
