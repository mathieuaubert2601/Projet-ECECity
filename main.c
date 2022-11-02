#include "header.h"


int main()
{
    //Initialisation
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    time_t tempsdep = time(NULL);


    //Création et déclaration des bitmaps
    BITMAP* page=create_bitmap(1024,768);
    SAMPLE* musiqueFond = load_sample("musique/musique_fond.wav");

    //Déclaration des variables
    int choixMenu;



    while(!key[KEY_ESC])
    {
        //clear_bitmap(page);
        //play_sample(musiqueFond,25,0,1000,1);
        choixMenu = menuJeu(page);
        actionChoixMenu(choixMenu,page);
        /*time_t temps2 = time(NULL);
        unsigned long diff=difftime(temps2,tempsdep);
        creer_map(page);
        textprintf_ex(page,font,980,750,makecol(255,255,255),-1,"%d",diff);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);*/

    }
    return 0;
}
END_OF_MAIN();
