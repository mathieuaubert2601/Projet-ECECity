#include "header.h"


void route (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab)
{
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);
    BITMAP* route = load_bitmap("Constructions/route.bmp",NULL);
    BITMAP* routeVerti = load_bitmap("Constructions/routeVerti.bmp", NULL);

    int x,y;
    int clic=0;
    int clic2=0;
    int clic3=0;
    int testclic=0;
    int testclic1=0;
    int type;


    while(clic!=1)
    {

        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);
        //afficherInterface(page,map,tempsdepart,*banque);
        test_temps(map,tab_hab,banque,nb_hab);
        type=0;
        clic2=0;
        clic3=0;
        interfaceRoute(page, type, tempsdepart, *banque, map);
        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2, map);
        blit(buffer2,page,0,0,0,0,900,700);
        if(((mouse_x>=(930)&& mouse_x<=(930+40))&& ((mouse_y)>=(220)&& mouse_y<=(220+40)))&&(mouse_b &1)) {
            while (clic2 != 1) {
                type = 1;
                interfaceRoute(page, type, tempsdepart, *banque, map);
                afficher_matrice_cases_vertes(buffer2);
                afficher_map(buffer2, map);
                affichagecasefree(buffer2, map, 1);
                if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {
                    interfaceRoute(page, type, tempsdepart, *banque, map);

                    show_mouse(buffer2);

                    blit(buffer2,page,0,0,0,0,900,700);
                    blit(route,page,0,0,mouse_x,mouse_y-20,route->w,route->h);
                    blit(page, screen, 0, 0, 0, 0, 1024, 768);
                }

                if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700))) && (mouse_b & 1)) {
                    x = mouse_x / 20;
                    y = mouse_y / 20;
                    if ((map[y + 1][x] == 1 || map[y - 1][x] == 1 || map[y][x + 1] == 1 || map[y][x - 1] == 1) || (map[y + 1][x] == 2 || map[y - 1][x] == 2 || map[y][x + 1] == 2 || map[y][x - 1] == 2)){
                        if (*banque > 10 && map[y][x] == 0) {
                            map[y][x] = 1;
                            *banque -= 10;
                            afficher_matrice_cases_vertes(buffer2);
                            afficher_map(buffer2, map);
                        }
                    }
                }
                if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2))
                {
                    clic2 = 1;
                    rest(300);
                }
                show_mouse(page);
                blit(page, screen, 0, 0, 0, 0, 1024, 768);
            }

        }
        if(((mouse_x>=(930)&& mouse_x<=(930+40))&& ((mouse_y)>=(280)&& mouse_y<=(280+40)))&&(mouse_b &1)) {
            while (clic3 != 1) {
                type = 2;
                interfaceRoute(page, type, tempsdepart, *banque, map);
                afficher_matrice_cases_vertes(buffer2);
                afficher_map(buffer2, map);
                affichagecasefree(buffer2, map, 1);
                if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {
                    interfaceRoute(page, type, tempsdepart, *banque, map);

                    show_mouse(buffer2);

                    blit(buffer2,page,0,0,0,0,900,700);
                    blit(routeVerti,page,0,0,mouse_x,mouse_y-20,route->w,route->h);
                    blit(page, screen, 0, 0, 0, 0, 1024, 768);
                }
                if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700))) && (mouse_b & 1)) {
                    x = mouse_x / 20;
                    y = mouse_y / 20;
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
                if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2)){
                    clic3 = 1;
                    rest(300);
                }
                show_mouse(page);
                blit(page, screen, 0, 0, 0, 0, 1024, 768);
            }

        }
        if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2)) {
            clic = 1;
            rest(300);
        }
    }
    show_mouse(page);
    blit(page,screen,0,0,0,0,1024,768);
}

void habitation (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, int* nb_hab, t_habitation tab_hab[50])
{
    BITMAP* maison = load_bitmap("Constructions/maison.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);

    int test_ref = 0;
    int x,y;
    int clic=0;
    int testclic=0;

    interfaceMaisons(page,tempsdepart,*banque,map);
    blit(page,screen,0,0,0,0,1024,768);


    afficher_matrice_cases_vertes(buffer2);
    afficher_map(buffer2,map);
    blit(buffer2,page,0,0,0,0,900,700);
    while(clic!=1)
    {
        interfaceMaisons(page,tempsdepart,*banque,map);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);

        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2,map);
        affichagecasefree(buffer2,map,3);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

            interfaceMaisons(buffer2,tempsdepart,*banque,map);


            show_mouse(buffer2);
            blit(buffer2,page,0,0,0,0,900,700);
            masked_blit(maison, page, 0, 0, mouse_x, mouse_y-60, maison->w, maison->h);
            blit(page,screen,0,0,0,0,900,700);
        }


        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
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
            /* *nb_hab++;
            tab_hab=(t_habitation*)realloc(tab_hab, *nb_hab * sizeof(t_habitation));

            tab_hab[0].nb_hab=0;
            tab_hab[0].niveau=0;
            tab_hab[0].tempsCrea=time(NULL);*/

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


            tab_hab[*nb_hab].nb_habitants=0;
            tab_hab[*nb_hab].niveau=0;
            tab_hab[*nb_hab].tempsCrea=time(NULL);
            tab_hab[*nb_hab].x=x;
            tab_hab[*nb_hab].y=y-2;
            *nb_hab+=1;


            blit(buffer2,page,0,0,0,0,900,700);
        }


        if(mouse_b&2)
            clic=1;

        test_temps(map,tab_hab,banque,*nb_hab);
        interfaceMaisons(page,tempsdepart,*banque,map);
        blit(page,screen,0,0,0,0,900,700);
    }
}

void chateau_eau(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab, t_chateauEau tab_eau[20], int* nb_chateau)
{
    BITMAP* chateauEauTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);
    BITMAP* chateauEau = load_bitmap("Constructions/ChateauEau.bmp", NULL);



    int x,y;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        interfaceChateaux(page,tempsdepart,*banque,map);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);
        affichagecasefree(buffer2,map,14);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        test_temps(map,tab_hab,banque,nb_hab);
        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2,map);
        affichagecasefree(buffer2,map,14);
        interfaceChateaux(page,tempsdepart,*banque,map);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

            interfaceChateaux(page,tempsdepart,*banque,map);


            show_mouse(buffer2);
            blit(buffer2,page,0,0,0,0,900,700);
            masked_blit(chateauEau, page, 0, 0, mouse_x, mouse_y-120, chateauEau->w, chateauEau->h);
            blit(page,screen,0,0,0,0,900,700);
        }
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

            tab_eau[*nb_chateau].x=x;
            tab_eau[*nb_chateau].y=y-6;
            *nb_chateau+=1;



            afficher_matrice_cases_vertes(buffer2);
            afficher_map(buffer2,map);
        }
        if(mouse_b&2)
            clic=1;

        show_mouse(page);
        blit(page,screen,0,0,0,0,900,700);
    }
}


void centrale(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab)
{
    BITMAP* chateauEauTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* buffer2 =create_bitmap(1024,768);
    BITMAP* centrale = load_bitmap("Constructions/centrale.bmp", NULL);


    int x,y;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        affichagecasefree(buffer2,map,15);
        interfaceCentrales(page,tempsdepart,*banque,map);
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        test_temps(map,tab_hab,banque,nb_hab);
        afficher_matrice_cases_vertes(buffer2);
        afficher_map(buffer2,map);
        affichagecasefree(buffer2,map,15);
        interfaceCentrales(page,tempsdepart,*banque,map);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

            interfaceCentrales(page,tempsdepart,*banque,map);


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
            *banque-=100000;
            afficher_matrice_cases_vertes(buffer2);
            afficher_map(buffer2,map);
        }
        if(mouse_b&2)
            clic=1;

        show_mouse(buffer2);
        blit(page,screen,0,0,0,0,900,700);
    }
}