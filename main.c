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
    //SAMPLE* ambiance = load_sample("musique/ambiance_fond.wav");

    //Déclaration des variables
    int choixMenu;
    int map[35][45];
    int sortie=0;
    int banque=banqueDep;
    int nb_hab=0;
    int nb_chateau=0;
    int nb_centrales=0;
    int play_musique=0;
    int pause=0;
    //t_habitation* tab_hab = NULL;
    //tab_hab=(t_habitation*)malloc(nb_hab*sizeof (t_habitation));
    t_habitation tab_hab[50];
    t_chateauEau tab_eau[20];
    t_centrales tab_elec[20];
    time_t tempsDebutPause;
    time_t tempsFinPause;
    unsigned long tempsPause=0;
    unsigned long tempsChrono=0;


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
            tempsdep= modificationTemps(tempsdep,0,tempsPause);
            tempsdep= modificationTemps(tempsdep,1,tempsChrono);


            if(choixMenu==2)
            {
                lireFichierMap(map,"Sauvegarde/fichierCarte.txt");
                nb_hab = chargerTableauHabitation(tab_hab,"Sauvegarde/tableauHabitation.bin");
                nb_centrales = chargerTableauCentrale(tab_elec,"Sauvegarde/tableauCentrale.bin");
                nb_chateau = chargerTableauChateauEau(tab_eau,"Sauvegarde/tableauChateauEau.bin");
                for(int i = 0 ; i<nb_hab ;i++)
                {
                    tab_hab[i].tempsCrea = time(NULL);
                }
                distribution(nb_centrales,nb_hab,tab_elec,tab_hab);
                chercherCheminPlusCourtEau(map,nb_hab,tab_hab,tab_eau,nb_chateau);
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
                afficherInterface(page,map,tempsdep, banque,tempsDebutPause,pause, tempsPause,tempsChrono);
                test_temps(map,tab_hab,&banque,nb_hab,nb_centrales,tab_elec,nb_chateau,tab_eau,pause, tempsPause,tempsChrono);
                if (((mouse_x >= (920) && mouse_x <= (920 + 90)) && (mouse_y) >= (130) && mouse_y <= (130 + 65)) &&
                    (mouse_b & 1)) {
                    route(page, map, tempsdep,&banque,tab_hab,nb_hab,nb_centrales,tab_elec,nb_chateau,tab_eau,tempsDebutPause,pause, tempsPause,tempsChrono);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 100)) && (mouse_y) >= (200) && mouse_y <= (200 + 100)) && (mouse_b & 1))
                {
                    habitation(page,map,tempsdep,&banque,&nb_hab, tab_hab,tab_elec,nb_centrales,nb_chateau,tab_eau,tempsDebutPause,pause, tempsPause,tempsChrono);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (270) && mouse_y <= (270 + 100)) &&
                    (mouse_b & 1)) {
                    chateau_eau(page, map,tempsdep,&banque, tab_hab, nb_hab,  tab_eau, &nb_chateau,nb_centrales,tab_elec,tempsDebutPause,pause, tempsPause,tempsChrono);
                    //creerMatriceEau(tab_hab,nb_hab,tab_eau,1,map);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (380) && mouse_y <= (380 + 100)) &&
                    (mouse_b & 1)) {
                    centrale(page, map,tempsdep,&banque, tab_hab, nb_hab,&nb_centrales,tab_elec,nb_chateau,tab_eau,tempsDebutPause,pause, tempsPause,tempsChrono);
                }
                if (((mouse_x >= (920) && mouse_x <= (920 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1)) {
                    sauvegarderTableauHabitation("Sauvegarde/tableauHabitation.bin",tab_hab,nb_hab);
                    sauvegarderTableauCentrale("Sauvegarde/tableauCentrale.bin",tab_elec,nb_centrales);
                    sauvegarderTableauChateauEau("Sauvegarde/tableauChateauEau.bin",tab_eau,nb_chateau);
                    sauvegarderMatriceFichier(map,"Sauvegarde/fichierCarte.txt");
                }
                if(((mouse_x>=(945)&& mouse_x<=(945+40))&& ((mouse_y)>=(70)&& mouse_y<=(70+40)))&&(mouse_b &1)&&(pause==0)) //bouton pause
                {
                    tempsDebutPause = time(NULL);
                    tempsDebutPause= modificationTemps(tempsDebutPause,0,tempsPause);
                    tempsDebutPause= modificationTemps(tempsDebutPause,1,tempsChrono);
                    pause=1;
                    rest(300);
                }
                if(((mouse_x>=(945)&& mouse_x<=(945+40))&& ((mouse_y)>=(70)&& mouse_y<=(70+40)))&&(mouse_b &1)&&(pause==1)) //bouton pause
                {
                    tempsFinPause = time(NULL);
                    pause=0;
                    tempsPause= difftime(tempsFinPause,tempsDebutPause);
                    rest(300);
                }
                if (((mouse_x >= (970) && mouse_x <= (970 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1)) {
                    //stop_sample(ambiance);
                    sortie = 1;
                }
                if(((mouse_x>=(920)&& mouse_x<=(920+50))&& ((mouse_y)>=(550)&& mouse_y<=(550+50)))&&(mouse_b &1))
                {
                    canalisations(page,map,tab_hab);
                }
                if(((mouse_x>=(920)&& mouse_x<=(920+50))&& ((mouse_y)>=(620)&& mouse_y<=(620+50)))&&(mouse_b &1))
                {
                    lignes(page,map,tab_hab,nb_hab,tab_elec,nb_centrales);
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
