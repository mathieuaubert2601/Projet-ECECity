#include "header.h"

///Programme pour construire des routes///
void route (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab, int nb_elec, t_centrales tab_elec[20],int nbChateau,t_chateauEau*  tabEau,time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono,int mode)
{
    //Déclaration de differentes BITMAP
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);
    BITMAP* route = load_bitmap("Constructions/route.bmp",NULL);
    BITMAP* routeVerti = load_bitmap("Constructions/routeVerti.bmp", NULL);

    //Initialisation de variables
    int x,y;
    int clic=0;
    int clic2=0;
    int clic3=0;
    int type;


    while(clic!=1)
    {

        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);
        //afficherInterface(page,map,tempsdepart,*banque);
        test_temps(map,tab_hab,banque,nb_hab,nb_elec,tab_elec,nbChateau,tabEau,pause, tempsPause,tempsChrono,mode); //On actualise le niveau et le cycle des maisons
        type=0;
        clic2=0;
        clic3=0;
        interfaceRoute(page, type, tempsdepart, *banque, map,tempsDepartPause,pause, tempsPause,tempsChrono,mode); //Affichage de l'interface/barre a outil
        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2, map);
        blit(buffer2,page,0,0,0,0,900,700);
        if(((mouse_x>=(930)&& mouse_x<=(930+40))&& ((mouse_y)>=(220)&& mouse_y<=(220+40)))&&(mouse_b &1)) { //Si on choisi de construire une route horizontale
            while (clic2 != 1) {
                type = 1;
                interfaceRoute(page, type, tempsdepart, *banque, map,tempsDepartPause,pause, tempsPause,tempsChrono,mode); //On réaffiche l'interface
                afficher_matrice_cases_vertes(buffer2);
                afficher_map(buffer2, map);
                affichagecasefree(buffer2, map, 1);  //Affichage des cases construisibles

                ///Quand la souris passe sur la map on affiche la route en dessous de la souris pour voir ou elle se posera///
                if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {
                    interfaceRoute(page, type, tempsdepart, *banque, map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);

                    show_mouse(buffer2);

                    blit(buffer2,page,0,0,0,0,900,700);
                    blit(route,page,0,0,mouse_x,mouse_y-20,route->w,route->h);
                    blit(page, screen, 0, 0, 0, 0, 1024, 768);
                }

                ///Si on clique sur la map///
                if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700))) && (mouse_b & 1)) {
                    x = mouse_x / 20;
                    y = mouse_y / 20;

                    //On blinde les bords de map
                    if(x > 44)
                    {
                        x =44;
                    }
                    if(x<0)
                    {
                        x =0;
                    }
                    if(y > 34)
                    {
                        y=34;
                    }
                    if(y<0)
                    {
                        y = 0;
                    }

                    ///Si on a assez d'argent et que la case est libre///
                    if(*banque > 10 && map[y][x] == 0)
                    {
                        //On verifie ensuite que la case est collée à une route
                        if((y + 1) <35)
                        {
                            //Si oui, on retire l'argent et on actualise la map
                            if(map[y + 1][x] == 1 || map[y + 1][x] == 2)
                            {
                                map[y][x] = 1;
                                *banque -= 10;
                                afficher_matrice_cases_vertes(buffer2);
                                afficher_map(buffer2, map);

                            }
                        }
                        if((y - 1 )>= 0)
                        {
                            if(map[y - 1][x] == 1 || map[y - 1][x] == 2)
                            {
                                map[y][x] = 1;
                                *banque -= 10;
                                afficher_matrice_cases_vertes(buffer2);
                                afficher_map(buffer2, map);

                            }
                        }
                        if((x + 1) < 45)
                        {
                            if(map[y][x+1] == 1 || map[y][x+1] == 2)
                            {
                                map[y][x] = 1;
                                *banque -= 10;
                                afficher_matrice_cases_vertes(buffer2);
                                afficher_map(buffer2, map);

                            }
                        }
                        if((x - 1 )>= 0)
                        {
                            if(map[y][x-1] == 1 || map[y][x-1] == 2)
                            {
                                map[y][x] = 1;
                                *banque -= 10;
                                afficher_matrice_cases_vertes(buffer2);
                                afficher_map(buffer2, map);

                            }
                        }

                    }
                }
                ///Si clic droit, echap, ou appui sur croix en haut a droite on quitte le programme///
                if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2) ||(key[KEY_ESC]))
                {
                    clic2 = 1;
                    rest(300);
                }
                show_mouse(page);
                blit(page, screen, 0, 0, 0, 0, 1024, 768);
            }

        }
        ///construction de routes verticales (meme fonctionnement que routes horizontales///
        if(((mouse_x>=(930)&& mouse_x<=(930+40))&& ((mouse_y)>=(280)&& mouse_y<=(280+40)))&&(mouse_b &1)) {
            while (clic3 != 1) {
                type = 2;
                interfaceRoute(page, type, tempsdepart, *banque, map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
                afficher_matrice_cases_vertes(buffer2);
                afficher_map(buffer2, map);
                affichagecasefree(buffer2, map, 1);
                if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {
                    interfaceRoute(page, type, tempsdepart, *banque, map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);

                    show_mouse(buffer2);

                    blit(buffer2,page,0,0,0,0,900,700);
                    blit(routeVerti,page,0,0,mouse_x,mouse_y-20,route->w,route->h);
                    blit(page, screen, 0, 0, 0, 0, 1024, 768);
                }
                if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700))) && (mouse_b & 1)) {
                    x = mouse_x / 20;
                    y = mouse_y / 20;

                    //On blinde les bords de map
                    if(x > 44)
                    {
                        x =44;
                    }
                    if(x<0)
                    {
                        x =0;
                    }
                    if(y > 34)
                    {
                        y=34;
                    }
                    if(y<0)
                    {
                        y = 0;
                    }
                    affichagecasefree(page, map, 2);
                    if ((map[y + 1][x] == 1 || map[y - 1][x] == 1 || map[y][x + 1] == 1 || map[y][x - 1] == 1)|| (map[y + 1][x] == 2 || map[y - 1][x] == 2 || map[y][x + 1] == 2 || map[y][x - 1] == 2)){
                        if (*banque > 10 && map[y][x] == 0) {
                            map[y][x] = 2;
                            *banque -= 10;
                            afficher_matrice_cases_vertes(buffer2);
                            afficher_map(page, map);
                        }
                    }
                }
                if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2) || (key[KEY_ESC])){
                    clic3 = 1;
                    rest(300);
                }
                show_mouse(page);
                blit(page, screen, 0, 0, 0, 0, 1024, 768);
            }

        }
        if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2) || (key[KEY_ESC])) {
            clic = 1;
            rest(300);
        }
    }
    show_mouse(page);
    blit(page,screen,0,0,0,0,1024,768);
}

///Sous programme pour créer une maison///
void habitation (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, int* nb_hab, t_habitation tab_hab[50], t_centrales tab_elec[20], int nb_elec,int nbChateau,t_chateauEau*  tabEau,time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono,int mode)
{
    BITMAP* maison = load_bitmap("Constructions/maison.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);
    SAMPLE* sonMaison = load_sample("sons/sonMaison.wav");

    int test_ref = 0;
    int x,y;
    int clic=0;
    int testclic=0;

    //On affiche la barre a outil de la maison
    interfaceMaisons(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
    blit(page,screen,0,0,0,0,1024,768);


    afficher_matrice_cases_vertes(buffer2);
    afficher_map(buffer2,map);
    blit(buffer2,page,0,0,0,0,900,700);
    while(clic!=1)
    {
        interfaceMaisons(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);

        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2,map);
        affichagecasefree(buffer2,map,3);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {  //Si la souris passe sur la map, on affiche une maison en dessous afin de voir ou on la placera

            interfaceMaisons(buffer2,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);


            show_mouse(buffer2);
            blit(buffer2,page,0,0,0,0,900,700);
            masked_blit(maison, page, 0, 0, mouse_x, mouse_y-60, maison->w, maison->h);
            blit(page,screen,0,0,0,0,900,700);
        }

        ///Si clic gauche///
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        ///On test si les cases sont disponibles et si elles sont a coté d'une route///
        if((testclic==1 && *banque>1000 && y>1 && x<43
            && map[y][x]==0 && map[y][x+1]==0 && map[y][x+2]==0
            && map[y-1][x]==0 && map[y-1][x+1]==0 && map[y-1][x+2]==0
            && map[y-2][x]==0 && map[y-2][x+1]==0 && map[y-2][x+2]==0)
           && ((map[y+1][x]==1 || map[y+1][x+1]==1 || map[y+1][x+2]==1 ||
                map[y][x+3]==1 || map[y-1][x+3]==1 || map[y-2][x+3]==1 ||
                map[y-3][x+2]==1 || map[y-3][x+1]==1 || map[y-3][x]==1 ||
                map[y-2][x-1]==1 || map[y-1][x-1]==1 || map[y][x-1]==1)
               ||  ( map[y+1][x]==2 || map[y+1][x+1]==2 || map[y+1][x+2]==2 ||
                     map[y][x+3]==2 || map[y-1][x+3]==2 || map[y-2][x+3]==2 ||
                     map[y-3][x+2]==2 || map[y-3][x+1]==2 || map[y-3][x]==2 ||
                     map[y-2][x-1]==2 || map[y-1][x-1]==2 || map[y][x-1]==2)))
        {
            play_sample(sonMaison,15,0,1000,0); //On joue un son
            //On actualise la map et on enlève l'argent
            map[y][x]=9;
            map[y][x+1]=9;
            map[y][x+2]=9;
            map[y-1][x]=9;
            map[y-1][x+1]=9;
            map[y-1][x+2]=9;
            map[y-2][x]=3;
            map[y-2][x+1]=9;
            map[y-2][x+2]=9;
            afficher_matrice_cases_vertes(buffer2);
            afficher_map(buffer2,map);
            *banque-=1000;
            test_ref=0;

            y = y - 2;
            //On attribue une case de la route liée a la maison
            for (int h=x; h<x+3;h++)
            {
                for(int k=y; k<y+3; k++)
                {
                    if(((map[k+1][h]==1)||(map[k+1][h]==2))&&(test_ref==0))
                    {
                        tab_hab[*nb_hab].XRef=h;
                        tab_hab[*nb_hab].YRef=k+1;
                        test_ref++;
                    }
                    if(((map[k-1][h]==1)||(map[k-1][h]==2))&&(test_ref==0))
                    {
                        tab_hab[*nb_hab].XRef=h;
                        tab_hab[*nb_hab].YRef=k-1;
                        test_ref++;
                    }
                    if(((map[k][h+1]==1)||(map[k][h+1]==2))&&(test_ref==0))
                    {
                        tab_hab[*nb_hab].XRef=h+1;
                        tab_hab[*nb_hab].YRef=k;
                        test_ref++;
                    }
                    if(((map[k][h-1]==1)||(map[k][h-1]==2))&&(test_ref==0))
                    {
                        tab_hab[*nb_hab].XRef=h-1;
                        tab_hab[*nb_hab].YRef=k;
                        test_ref++;
                    }
                }
            }
            y = y + 2;

            //On remplit un tableau d'habitations avec les bonnes informations
            tab_hab[*nb_hab].nb_habitants=0;
            tab_hab[*nb_hab].niveau=0;
            tab_hab[*nb_hab].tempsCrea=time(NULL);//On rentre le temps de création (temps actuel-temps de pause +temps possible ancien chrono
            tab_hab[*nb_hab].tempsCrea= modificationTemps(tab_hab[*nb_hab].tempsCrea,0,tempsPause);
            tab_hab[*nb_hab].tempsCrea= modificationTemps(tab_hab[*nb_hab].tempsCrea,1,tempsChrono);
            tab_hab[*nb_hab].x=x;
            tab_hab[*nb_hab].y=y-2;
            *nb_hab+=1;
            tab_hab[*nb_hab].numero=*nb_hab;
            for(int i = 0 ;i<15 ;i++)
            {
                tab_hab[*nb_hab].chateauEauNCR[i][0]= -1;
                tab_hab[*nb_hab].chateauEauNCR[i][1]= -1;
            }
            //On distribue l'eau et l'elec avec cette nouvelle maison
            distribution(nb_elec,*nb_hab,tab_elec,tab_hab);
            if(nbChateau > 0 && *nb_hab > 0)
                chercherCheminPlusCourtEau(map,*nb_hab,tab_hab,tabEau,nbChateau);
            blit(buffer2,page,0,0,0,0,900,700);
        }

        ///Si clic droit, echap, ou appui sur croix en haut a droite on quitte le programme///
        if((mouse_b&2 || ((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1)) || (key[KEY_ESC])) {
            clic = 1;
            rest(300);
        }
        test_temps(map,tab_hab,banque,*nb_hab,nb_elec,tab_elec,nbChateau,tabEau,pause, tempsPause,tempsChrono,mode);
        interfaceMaisons(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
        blit(page,screen,0,0,0,0,900,700);
    }
}

///Construction de chateau d'eau///
void chateau_eau(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab, t_chateauEau tab_eau[20], int* nb_chateau, int nb_elec, t_centrales tab_elec[20],time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono,int mode)
{
    BITMAP* chateauEauTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);
    BITMAP* chateauEau = load_bitmap("Constructions/ChateauEau.bmp", NULL);
    SAMPLE* sonEau = load_sample("sons/sonEau.wav");



    int x,y,test_ref = 0;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        interfaceChateaux(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);
        affichagecasefree(buffer2,map,14);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))//Si clic gauche sur la map
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        test_temps(map,tab_hab,banque,nb_hab,nb_elec,tab_elec,*nb_chateau,tab_eau,pause, tempsPause,tempsChrono,mode);
        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2,map);
        affichagecasefree(buffer2,map,14);
        interfaceChateaux(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {     //Si la souris passe sur la map, on affiche un chateau d'eau en dessous afin de voir ou on la placera

            interfaceChateaux(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);


            show_mouse(buffer2);
            blit(buffer2,page,0,0,0,0,900,700);
            masked_blit(chateauEau, page, 0, 0, mouse_x, mouse_y-120, chateauEau->w, chateauEau->h);
            blit(page,screen,0,0,0,0,900,700);
        }

        ///On test si les cases sont disponibles et si elles sont a coté d'une route///
        if((testclic==1 && *banque>=100000 && y>4 && x<42 &&
            map[y][x]==0&&(map[y-1][x] == 0)&&(map[y-2][x] == 0)&&(map[y-3][x] == 0)&&(map[y-4][x] == 0)&&(map[y-5][x] == 0)&&
            (map[y][x+1]==0)&&(map[y-1][x+1]==0)&&(map[y-2][x+1]==0)&&(map[y-3][x+1]==0)&&(map[y-4][x+1]==0)&&(map[y-5][x+1]==0)&&
            (map[y][x+2]==0)&&(map[y-1][x+2]==0)&&(map[y-2][x+2]==0)&&(map[y-3][x+2]==0)&&(map[y-4][x+2]==0)&&(map[y-5][x+2]==0)&&
            (map[y][x+3]==0)&&(map[y-1][x+3]==0)&&(map[y-2][x+3]==0)&&(map[y-3][x+3]==0)&&(map[y-4][x+3]==0)&&(map[y-5][x+3]==0))&&
           ((map[y+1][x]==1 || map[y+1][x+1]==1 || map[y+1][x+2]==1 || map[y+1][x+3]==1 ||
             map[y][x+4]==1 || map[y-1][x+4]==1 || map[y-2][x+4]==1 || map[y-3][x+4]==1 || map[y-4][x+4]==1 || map[y-5][x+4]==1 ||
             map[y-6][x+3]==1|| map[y-6][x+2]==1 || map[y-6][x+1]==1 || map[y-6][x]==1 ||
             map[y-5][x-1]==1 || map[y-4][x-1]==1 || map[y-3][x-1]==1 || map[y-2][x-1]==1 || map[y-1][x-1]==1 || map[y][x-1]==1)||
            (map[y+1][x]==2 || map[y+1][x+1]==2 || map[y+1][x+2]==2 || map[y+1][x+3]==2 ||
             map[y][x+4]==2 || map[y-1][x+4]==2 || map[y-2][x+4]==2 || map[y-3][x+4]==2 || map[y-4][x+4]==2 || map[y-5][x+4]==2 ||
             map[y-6][x+3]==2|| map[y-6][x+2]==2 || map[y-6][x+1]==2 || map[y-6][x]==2 ||
             map[y-5][x-1]==2 || map[y-4][x-1]==2 || map[y-3][x-1]==2 || map[y-2][x-1]==2 || map[y-1][x-1]==2 || map[y][x-1]==2)
           ))
        {
            //MAJ argent + map
            map[y][x] = 16;
            map[y-1][x] =16;
            map[y-2][x] =16;
            map[y-3][x] =16;
            map[y-4][x] =16;
            map[y-5][x] =14;

            map[y][x+1] =16;
            map[y-1][x+1] =16;
            map[y-2][x+1] =16;
            map[y-3][x+1] =16;
            map[y-4][x+1] =16;
            map[y-5][x+1] =16;

            map[y][x+2] =16;
            map[y-1][x+2] =16;
            map[y-2][x+2] =16;
            map[y-3][x+2] =16;
            map[y-4][x+2] =16;
            map[y-5][x+2] =16;

            map[y][x+3] =16;
            map[y-1][x+3] =16;
            map[y-2][x+3] =16;
            map[y-3][x+3] =16;
            map[y-4][x+3] =16;
            map[y-5][x+3] =16;
            *banque-=100000;

            test_ref = 0;
            y = y-5;
            play_sample(sonEau,15,0,1000,0);//On joue un son


            //On attribue une case de la route
            for (int h=x; h<x+4;h++)
            {
                for(int k=y; k<y+6; k++)
                {
                    if(((map[k+1][h]==1)||(map[k+1][h]==2))&&(test_ref==0))
                    {
                        tab_eau[*nb_chateau].XRef=h;
                        tab_eau[*nb_chateau].YRef=k+1;
                        test_ref++;
                    }
                    if(((map[k-1][h]==1)||(map[k-1][h]==2))&&(test_ref==0))
                    {
                        tab_eau[*nb_chateau].XRef=h;
                        tab_eau[*nb_chateau].YRef=k-1;
                        test_ref++;
                    }
                    if(((map[k][h+1]==1)||(map[k][h+1]==2))&&(test_ref==0))
                    {
                        tab_eau[*nb_chateau].XRef=h+1;
                        tab_eau[*nb_chateau].YRef=k;
                        test_ref++;
                    }
                    if(((map[k][h-1]==1)||(map[k][h-1]==2))&&(test_ref==0))
                    {
                        tab_eau[*nb_chateau].XRef=h-1;
                        tab_eau[*nb_chateau].YRef=k;
                        test_ref++;
                    }
                }
            }

            y=y+5;

            //On remplit un tableau de chateau d'eau avec les bonnes valeurs

            tab_eau[*nb_chateau].x=x;
            tab_eau[*nb_chateau].y=y-5;
            *nb_chateau+=1;


            //On distribue l'eau
            if(*nb_chateau > 0 && nb_hab >0)
                chercherCheminPlusCourtEau(map,nb_hab,tab_hab,tab_eau,*nb_chateau);

            afficher_matrice_cases_vertes(buffer2);
            afficher_map(buffer2,map);
        }
        if((mouse_b&2 || ((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1)) || (key[KEY_ESC])){
            clic = 1;
            rest(300);
        }

        show_mouse(page);
        blit(page,screen,0,0,0,0,900,700);
    }
}

///Creation centrale///
void centrale(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab, int* nb_elec, t_centrales tab_elec[20],int nbChateau,t_chateauEau*  tabEau,time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono,int mode)
{
    BITMAP* chateauEauTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);
    BITMAP* centrale = load_bitmap("Constructions/centrale.bmp", NULL);
    SAMPLE* sonElec = load_sample("sons/sonElec.wav");


    int x,y;
    int clic=0;
    int testclic=0;
    int num;

    while(clic!=1)
    {
        affichagecasefree(buffer2,map,15);
        interfaceCentrales(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        test_temps(map,tab_hab,banque,nb_hab,*nb_elec,tab_elec,nbChateau,tabEau,pause, tempsPause,tempsChrono,mode);
        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2,map);
        affichagecasefree(buffer2,map,15);
        interfaceCentrales(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

            interfaceCentrales(page,tempsdepart,*banque,map,tempsDepartPause,pause, tempsPause,tempsChrono,mode);


            show_mouse(buffer2);
            blit(buffer2,page,0,0,0,0,900,700);
            masked_blit(centrale, page, 0, 0, mouse_x, mouse_y-80, centrale->w, centrale->h);
            blit(page,screen,0,0,0,0,900,700);
        }

        if(testclic==1 && *banque>=100000 && y>2 && x<40 &&
           map[y][x]==0&&(map[y-1][x] == 0)&&(map[y-2][x] == 0)&&(map[y-3][x] == 0)&&(map[y][x+4] == 0)&&(map[y][x+5] == 0)&&
           (map[y][x+1]==0)&&(map[y-1][x+1]==0)&&(map[y-2][x+1]==0)&&(map[y-3][x+1]==0)&&(map[y-1][x+4]==0)&&(map[y-1][x+5]==0)&&
           (map[y][x+2]==0)&&(map[y-1][x+2]==0)&&(map[y-2][x+2]==0)&&(map[y-3][x+2]==0)&&(map[y-2][x+4]==0)&&(map[y-2][x+5]==0)&&
           (map[y][x+3]==0)&&(map[y-1][x+3]==0)&&(map[y-2][x+3]==0)&&(map[y-3][x+3]==0)&&(map[y-3][x+4]==0)&&(map[y-3][x+5]==0)&&
           ((map[y+1][x]==1 || map[y+1][x+1]==1 || map[y+1][x+2]==1 || map[y+1][x+3]==1 || map[y+1][x+4]==1 || map[y+1][x+5]==1 ||
             map[y][x+6]==1 || map[y-1][x+6]==1 || map[y-2][x+6]==1 || map[y-3][x+6]==1 ||
             map[y-4][x+5]==1 || map[y-4][x+4]==1 || map[y-4][x+3]==1 || map[y-4][x+2]==1 || map[y-4][x+1]==1 || map[y-4][x]==1 ||
             map[y-3][x-1]==1 || map[y-2][x-1]==1 || map[y-1][x-1]==1 || map[y][x-1]==1)||
            (map[y+1][x]==2 || map[y+1][x+1]==2 || map[y+1][x+2]==2 || map[y+1][x+3]==2 || map[y+1][x+4]==2 || map[y+1][x+5]==2 ||
             map[y][x+6]==2 || map[y-1][x+6]==2 || map[y-2][x+6]==2 || map[y-3][x+6]==2 ||
             map[y-4][x+5]==2 || map[y-4][x+4]==2 || map[y-4][x+3]==2 || map[y-4][x+2]==2 || map[y-4][x+1]==2 || map[y-4][x]==2 ||
             map[y-3][x-1]==2 || map[y-2][x-1]==2 || map[y-1][x-1]==2 || map[y][x-1]==2)))
        {
            map[y][x] = 17;
            map[y-1][x] =17;
            map[y-2][x] =17;
            map[y-3][x] =15;

            map[y][x+1] =17;
            map[y-1][x+1] =17;
            map[y-2][x+1] =17;
            map[y-3][x+1] =17;

            map[y][x+2] =17;
            map[y-1][x+2] =17;
            map[y-2][x+2] =17;
            map[y-3][x+2] =17;

            map[y][x+3] =17;
            map[y-1][x+3] =17;
            map[y-2][x+3] =17;
            map[y-3][x+3] =17;

            map[y][x+4] =17;
            map[y-1][x+4] =17;
            map[y-2][x+4] =17;
            map[y-3][x+4] =17;

            map[y][x+5] =17;
            map[y-1][x+5] =17;
            map[y-2][x+5] =17;
            map[y-3][x+5] =17;
            play_sample(sonElec,15,0,1000,0);
            *banque-=100000;

            //On remplit un tableau avec les informatino de la centrale
            tab_elec[*nb_elec].x=x;
            tab_elec[*nb_elec].y=y-3;
            tab_elec[*nb_elec].capaciteRestante=5000;
            tab_elec[*nb_elec].num=*nb_elec+1;
            *nb_elec+=1;

            //On distribue l'electricité
            distribution(*nb_elec,nb_hab,tab_elec,tab_hab);

            afficher_matrice_cases_vertes(buffer2);
            afficher_map(buffer2,map);

        }
        if((mouse_b&2 || ((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1)) || (key[KEY_ESC])){
            clic = 1;
            rest(300);
        }

        show_mouse(buffer2);
        blit(page,screen,0,0,0,0,900,700);
    }
}