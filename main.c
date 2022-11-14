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
    int banque=banqueDep;
    int nb_hab=0;

    //t_habitation* tab_hab = NULL;
    //tab_hab=(t_habitation*)malloc(nb_hab*sizeof (t_habitation));
    t_habitation tab_hab[50];


    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        play_sample(musiqueFond,15,0,1000,1);
        choixMenu = menuJeu(page);
        actionChoixMenu(choixMenu,page);
        if(choixMenu == 1 || choixMenu==2)
        {
            clear_bitmap(page);
            time_t tempsdep = time(NULL);
            play_sample(ambiance,15,0,1000,1);
            if(choixMenu==2)
            {
                lireFichierMap(map,"Sauvegarde/fichierCarte.txt");
                nb_hab = chargerTableauHabitation(tab_hab,"Sauvegarde/tableauBatiment.bin");
                sortie = 0;
            }
            if(choixMenu==1)
            {
                sortie = 0;
                creer_map(page,map);
                map[20][1]=1;
            }
            while(sortie==0)
            {
                afficher_map(page,map);
                afficherInterface(page,map,tempsdep, banque);
                test_temps(map,tab_hab,&banque,nb_hab);
                if (((mouse_x >= (920) && mouse_x <= (920 + 90)) && (mouse_y) >= (130) && mouse_y <= (130 + 65)) &&
                    (mouse_b & 1)) {
                    route(page, map, tempsdep,&banque,tab_hab,nb_hab);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 100)) && (mouse_y) >= (200) && mouse_y <= (200 + 100)) && (mouse_b & 1))
                {
                    habitation(page,map,tempsdep,&banque,&nb_hab, tab_hab);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (270) && mouse_y <= (270 + 100)) &&
                    (mouse_b & 1)) {
                    chateau_eau(page, map,tempsdep,&banque, tab_hab, nb_hab);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (380) && mouse_y <= (380 + 100)) &&
                    (mouse_b & 1)) {
                    centrale(page, map,tempsdep,&banque, tab_hab, nb_hab);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1)) {
                    sauvegarderTableauBatiment("Sauvegarde/tableauBatiment.bin",tab_hab,nb_hab);
                    sauvegarderMatriceFichier(map,"Sauvegarde/fichierCarte.txt");
                }
                if (((mouse_x >= (970) && mouse_x <= (970 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1)) {
                    sortie = 1;
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1024,768);
            }
        }
    }
    //free(tab_hab);
    //tab_hab=NULL;
    return 0;
}
END_OF_MAIN();