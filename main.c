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
    int map[35][45];
    int** matriceEauPasChateau = malloc(35 * sizeof(int*));
    int sortie=0;
    int banque=banqueDep;
    int nb_hab=0;
    int nb_chateau=0;
    int nb_centrales=0;
    int play_musique=0;
    int pause=0;
    int mode=0;
    int** matriceEau;
    t_habitation tab_hab[50];
    t_chateauEau tab_eau[20];
    t_centrales tab_elec[20];
    time_t tempsDebutPause;
    time_t tempsFinPause;
    unsigned long tempsPause=0;
    unsigned long tempsChrono=0;

    while(!key[KEY_ESC])
    {
        tempsPause=0;
        tempsChrono=0;
        clear_bitmap(page);
        if (play_musique==0)
        {
            play_sample(musiqueFond,15,0,1000,1);
            play_musique++;
        }
        choixMenu = menuJeu(page);
        mode = actionChoixMenu(choixMenu,page);
        if(choixMenu == 1 || choixMenu==2)
        {
            clear_bitmap(page);
            //On initialise le temps de depart
            time_t tempsdep = time(NULL);
            tempsdep= modificationTemps(tempsdep,1,tempsChrono);
            //Si on charge une partie sauvegardée
            if(choixMenu==2)
            {
                if(testSauvegarde())
                {
                    //On charge les informations sauvegardées
                    chargementTempsChrono(&tempsChrono,&tempsPause);
                    tempsPause=0;
                    banque = chargementArgent();
                    mode = chargementModeJeu();
                    lireFichierMap(map,"Sauvegarde/fichierCarte.txt");
                    nb_hab = chargerTableauHabitation(tab_hab,"Sauvegarde/tableauHabitation.bin");
                    nb_centrales = chargerTableauCentrale(tab_elec,"Sauvegarde/tableauCentrale.bin");
                    nb_chateau = chargerTableauChateauEau(tab_eau,"Sauvegarde/tableauChateauEau.bin");
                    chargementTempsCycle(nb_hab,tab_hab,tempsPause,tempsChrono);
                    distribution(nb_centrales,nb_hab,tab_elec,tab_hab);
                    if(nb_chateau > 0 && nb_hab >0)
                        chercherCheminPlusCourtEau(map,nb_hab,tab_hab,tab_eau,nb_chateau);
                    time_t tempsdep = time(NULL);
                    tempsdep= modificationTemps(tempsdep,0,tempsPause);
                    tempsdep= modificationTemps(tempsdep,1,tempsChrono);
                    sortie = 0;
                }
                else
                {
                    sortie = 1;
                }
            }
            //Si on démarre une nouvelle partie, on réinitialise le variables à 0
            if(choixMenu==1)
            {
                sortie = 0;
                creer_map(page,map);
                banque = banqueDep;
                nb_hab=0;
                nb_chateau=0;
                nb_centrales=0;
                pause=0;
            }
            while(sortie==0)
            {
                //Affichage de la map, de la barre d'outil et des informations
                afficher_matrice_cases_vertes(page);
                afficher_map(page,map);
                afficherInterface(page,map,tempsdep, banque,tempsDebutPause,pause, tempsPause,tempsChrono,mode);
                //On actualise les cycles des habitations
                test_temps(map,tab_hab,&banque,nb_hab,nb_centrales,tab_elec,nb_chateau,tab_eau,pause, tempsPause,tempsChrono,mode);
                //Si on clique sur l'icone de construction de routes, on rentre dans le sous programme pour construire des routes
                if (((mouse_x >= (920) && mouse_x <= (920 + 90)) && (mouse_y) >= (130) && mouse_y <= (130 + 65)) &&
                    (mouse_b & 1)) {
                    route(page, map, tempsdep,&banque,tab_hab,nb_hab,nb_centrales,tab_elec,nb_chateau,tab_eau,tempsDebutPause,pause, tempsPause,tempsChrono,mode);
                }
                //Si on clique sur l'icone de construction d'habitations, on rentre dans le sous programme pour construire des habitations
                if (((mouse_x >= (920) && mouse_x <= (920 + 100)) && (mouse_y) >= (200) && mouse_y <= (200 + 100)) && (mouse_b & 1))
                {
                    habitation(page,map,tempsdep,&banque,&nb_hab, tab_hab,tab_elec,nb_centrales,nb_chateau,tab_eau,tempsDebutPause,pause, tempsPause,tempsChrono,mode);
                }
                //Si on clique sur l'icone de construction de chateaux d'eau, on rentre dans le sous programme pour construire des chateaux d'eau
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (270) && mouse_y <= (270 + 100)) &&
                    (mouse_b & 1)) {
                    chateau_eau(page, map,tempsdep,&banque, tab_hab, nb_hab,  tab_eau, &nb_chateau,nb_centrales,tab_elec,tempsDebutPause,pause, tempsPause,tempsChrono,mode);
                }
                //Si on clique sur l'icone de construction de centrales, on rentre dans le sous programme pour construire des centrales
                if (((mouse_x >= (920) && mouse_x <= (920 + 75)) && (mouse_y) >= (380) && mouse_y <= (380 + 100)) &&
                    (mouse_b & 1)) {
                    centrale(page, map,tempsdep,&banque, tab_hab, nb_hab,&nb_centrales,tab_elec,nb_chateau,tab_eau,tempsDebutPause,pause, tempsPause,tempsChrono,mode);
                }
                //Si on appuie sur lebouton sauvegarder, on procède a la sauvegarde des informations nécessaires
                if (((mouse_x >= (920) && mouse_x <= (920 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1) && pause == 0) {
                    indiquerSauvegarde(1);
                    sauvegarderTableauHabitation("Sauvegarde/tableauHabitation.bin",tab_hab,nb_hab);
                    sauvegarderTableauCentrale("Sauvegarde/tableauCentrale.bin",tab_elec,nb_centrales);
                    sauvegarderTableauChateauEau("Sauvegarde/tableauChateauEau.bin",tab_eau,nb_chateau);
                    sauvegarderMatriceFichier(map,"Sauvegarde/fichierCarte.txt");
                    sauvegardeTempsCycle(nb_hab,tab_hab,tempsPause,tempsChrono);
                    sauvegardeChrono(tempsdep,tempsPause,tempsChrono);
                    sauvegardeArgent(banque);
                    sauvegardeModeJeu(mode);
                }
                //Si on appuie sur le bouton pause lorsqu'il n'ya pas de pause, on met le jeu en pause
                if(((mouse_x>=(945)&& mouse_x<=(945+40))&& ((mouse_y)>=(70)&& mouse_y<=(70+40)))&&(mouse_b &1)&&(pause==0)) //bouton pause
                {
                    //On sauvegarde le temps de début de la pause afin de l'afficher sur l'interface
                    tempsDebutPause = time(NULL);
                    tempsDebutPause= modificationTemps(tempsDebutPause,0,tempsPause);
                    tempsDebutPause= modificationTemps(tempsDebutPause,1,tempsChrono);
                    pause=1;
                    rest(300);
                }
                //Si on appui sur le bouton pause alors que le jeu est déja en pause alors le chrono reprend
                if(((mouse_x>=(945)&& mouse_x<=(945+40))&& ((mouse_y)>=(70)&& mouse_y<=(70+40)))&&(mouse_b &1)&&(pause==1)) //bouton pause
                {
                    tempsFinPause = time(NULL);
                    tempsFinPause= modificationTemps(tempsFinPause,1,tempsChrono);
                    pause=0;
                    tempsPause= difftime(tempsFinPause,tempsDebutPause);//On enregistre le temps de pause total
                    rest(300);
                }
                //Si on clique sur la croix rouge on quitte le jeu
                if (((mouse_x >= (970) && mouse_x <= (970 + 40)) && (mouse_y) >= (25) && mouse_y <= (25 + 40)) &&
                    (mouse_b & 1)) {
                    sortie = 1;
                }
                if(((mouse_x>=(920)&& mouse_x<=(920+50))&& ((mouse_y)>=(550)&& mouse_y<=(550+50)))&&(mouse_b &1))
                {
                    //Si le nombre de chateau d'eau est supérieur à 0
                    if(nb_chateau > 0)
                    {
                        //On cherche le plus court chemin pour l'eau et on l'affiche dans le bon niveau
                        matriceEau = chercherCheminPlusCourtEau(map,nb_hab,tab_hab,tab_eau,nb_chateau);
                        canalisations(page,map,tab_hab,nb_hab,matriceEau,nb_chateau,tab_eau,tab_elec,nb_centrales);
                    }
                    else //Dans le cas où le nombre de chateau d'eau est 0
                    {
                        //On remplit une matrice de 0 car il n'y a pas d'eau
                        for(int i = 0 ; i<35 ; i++)
                        {
                            matriceEauPasChateau[i] = malloc(45 * sizeof(int));
                            for(int j = 0 ; j<45 ; j++)
                            {
                                matriceEauPasChateau[i][j] = 0;
                            }
                        }
                        //On initialise les informations des maisons à -1 pour le tableau de chateau d'eau car elles ne sont pas alimentées
                        for(int i = 0 ; i<nb_hab ; i++)
                        {
                            for(int j = 0 ; j<15 ; j++)
                            {
                                tab_hab[i].chateauEauNCR[j][0] = -1;
                                tab_hab[i].chateauEauNCR[j][1] = -1;
                                tab_hab[i].quantiteeEau = 0;
                            }
                        }
                        //On appelle le sous programme pour afficher le niveau adéquat
                        canalisations(page,map,tab_hab,nb_hab,matriceEauPasChateau,nb_chateau,tab_eau,tab_elec,nb_centrales);
                    }
                }
                if(((mouse_x>=(920)&& mouse_x<=(920+50))&& ((mouse_y)>=(620)&& mouse_y<=(620+50)))&&(mouse_b &1))
                {
                    //On affiche les lignes electrique dans le niveau adéquat
                    lignes(page,map,tab_hab,nb_hab,nb_chateau,tab_eau,tab_elec,nb_centrales);
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1024,768);
            }
        }
    }
    return 0;
}
END_OF_MAIN();
