#include "header.h"


int main()
{
    //Initialisation
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    srand(time(NULL));

    //Création et déclaration des bitmaps
    BITMAP* page=create_bitmap(1024,768);


    //Déclaration des variables
    int choixMenu;



    while(!key[KEY_ESC])
    {
        //choixMenu = menuJeu(page);
        //actionChoixMenu(choixMenu);
        creer_map(page);


    }
    return 0;
}
END_OF_MAIN();
