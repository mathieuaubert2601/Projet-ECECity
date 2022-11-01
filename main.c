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


    BITMAP* cases;
    cases = load_bitmap("map/test_tuile.bmp", NULL);

    //Déclaration des variables
    int choixMenu;



    while(!key[KEY_ESC])
    {
        //choixMenu = menuJeu(page);
        //actionChoixMenu(choixMenu,page);
       // creer_map(page);

        //masked_blit(cases,page,0,0,0,0,77,77);
        //blit(page,screen,0,0,0,0,1024,768);

    }
    return 0;
}
END_OF_MAIN();
