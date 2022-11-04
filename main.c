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
    SAMPLE* ambiance = load_sample("musique/ambiance_fond.wav");

    //Déclaration des variables
    int choixMenu;
    int map[35][45];
    int sortie=0;


    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        choixMenu = menuJeu(page);
        actionChoixMenu(choixMenu,page);
        if(choixMenu == 1)
        {
            clear_bitmap(page);
            time_t tempsdep = time(NULL);
            play_sample(ambiance,15,0,1000,1);
            lireFichierMap(map,"map/mapBase.txt");
            while(sortie==0)
            {
                creer_map(page,map);
                afficherInterface(page,map);
                time_t temps2 = time(NULL);
                unsigned long diff=difftime(temps2,tempsdep);

                textprintf_ex(page,font,980,700,makecol(255,255,255),-1,"%d",diff);
                show_mouse(page);
                blit(page,screen,0,0,0,0,1024,768);
            }

        }

    }
    return 0;
}
END_OF_MAIN();