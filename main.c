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
    int nb_chateau=0;
    int nb_centrales=0;
    int play_musique=0;
    //t_habitation* tab_hab = NULL;
    //tab_hab=(t_habitation*)malloc(nb_hab*sizeof (t_habitation));
    t_habitation tab_hab[50];
    t_chateauEau tab_eau[20];
    t_centrales tab_elec[20];


    while(!key[KEY_ESC])
    {
        clear_bitmap(page);
        if (play_musique==0)
        {
            play_sample(musiqueFond,15,0,1000,1);
            play_musique++;
        }

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
                //map[20][1]=1;
            }
            while(sortie==0)
            {
                afficher_matrice_cases_vertes(page);
                afficher_map(page,map);
                afficherInterface(page,map,tempsdep, banque);
                test_temps(map,tab_hab,&banque,nb_hab,nb_centrales,tab_elec);
                if (((mouse_x >= (920) && mouse_x <= (920 + 90)) && (mouse_y) >= (130) && mouse_y <= (130 + 65)) &&
                    (mouse_b & 1)) {
                    route(page, map, tempsdep,&banque,tab_hab,nb_hab,nb_centrales,tab_elec);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 100)) && (mouse_y) >= (200) && mouse_y <= (200 + 100)) && (mouse_b & 1))
                {

                    habitation(page,map,tempsdep,&banque,&nb_hab, tab_hab,tab_elec,nb_centrales);

                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (270) && mouse_y <= (270 + 100)) &&
                    (mouse_b & 1)) {
                    chateau_eau(page, map,tempsdep,&banque, tab_hab, nb_hab,  tab_eau, &nb_chateau,nb_centrales,tab_elec);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (380) && mouse_y <= (380 + 100)) &&
                    (mouse_b & 1)) {
                    centrale(page, map,tempsdep,&banque, tab_hab, nb_hab,&nb_centrales,tab_elec);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1)) {
                    sauvegarderTableauBatiment("Sauvegarde/tableauBatiment.bin",tab_hab,nb_hab);
                    sauvegarderMatriceFichier(map,"Sauvegarde/fichierCarte.txt");
                }
                if (((mouse_x >= (970) && mouse_x <= (970 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1)) {
                    stop_sample(ambiance);
                    sortie = 1;
                }
                if(((mouse_x>=(920)&& mouse_x<=(920+50))&& ((mouse_y)>=(550)&& mouse_y<=(550+50)))&&(mouse_b &1))
                {
                    canalisations(page,map);
                }
                if(((mouse_x>=(920)&& mouse_x<=(920+50))&& ((mouse_y)>=(620)&& mouse_y<=(620+50)))&&(mouse_b &1))
                {
                    lignes(page,map);
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
