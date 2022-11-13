#include "header.h"


void route (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab)
{
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);

    int x,y;
    int clic=0;
    int clic2=0;
    int clic3=0;
    int testclic=0;
    int testclic1=0;

    interfaceRoute(page);
    show_mouse(page);
    blit(page,screen,0,0,0,0,1024,768);
    while(clic!=1)
    {
        show_mouse(page);
        blit(page,screen,0,0,0,0,1024,768);
        //afficherInterface(page,map,tempsdepart,*banque);
        test_temps(map,tab_hab,banque,nb_hab);
        if(((mouse_x>=(930)&& mouse_x<=(930+40))&& ((mouse_y)>=(220)&& mouse_y<=(220+40)))&&(mouse_b &1)) {
            while(clic2!=1) {

                if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700))) && (mouse_b & 1)) {
                    x = mouse_x / 20;
                    y = mouse_y / 20;
                    affichagecasefree(page,map,1);
                    testclic = 1;
                }
                if (testclic == 1 && *banque > 10 && map[y][x] == 0) {
                    map[y][x] = 1;
                    *banque -= 10;
                    afficher_map(page, map);
                    show_mouse(page);
                    blit(page,screen,0,0,0,0,1024,768);
                }
                if (mouse_b & 2) {
                    clic2 = 1;
                    rest(500);
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1024,768);
            }
        }
        if(((mouse_x>=(930)&& mouse_x<=(930+40))&& ((mouse_y)>=(280)&& mouse_y<=(280+40)))&&(mouse_b &1)) {
            while(clic3!=1) {
                show_mouse(page);
                blit(page,screen,0,0,0,0,1024,768);
                if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700))) && (mouse_b & 1)) {
                    x = mouse_x / 20;
                    y = mouse_y / 20;
                    affichagecasefree(page,map,2);
                    testclic1 = 1;
                }
                if (testclic1 == 1 && *banque > 10 && map[y][x] == 0) {
                    map[y][x] = 2;
                    *banque -= 10;
                    afficher_map(page, map);
                    show_mouse(page);
                    blit(page,screen,0,0,0,0,1024,768);
                }
                if (mouse_b & 2) {
                    clic3 = 1;
                    rest(500);
                }
                show_mouse(page);
                blit(page,screen,0,0,0,0,1024,768);
            }
        }
        if (mouse_b & 2) {
            clic = 1;
        }
    }
    show_mouse(page);
    blit(page,screen,0,0,0,0,1024,768);
}

void interfaceRoute(BITMAP* page)
{
    printf("hey");
    //Declaration des BITMAP
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);

    BITMAP* boutonQuitter = load_bitmap("Interface/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Interface/boutonQuitterInv.bmp", NULL);
    BITMAP* boutonPause = load_bitmap("Interface/boutonPause.bmp", NULL);
    BITMAP* boutonPauseInv = load_bitmap("Interface/boutonPauseInv.bmp", NULL);

    BITMAP* infosRoute = load_bitmap("Constructions/infosRoute.bmp", NULL);
    BITMAP* route = load_bitmap("Constructions/route.bmp", NULL);
    BITMAP* routeVerti = load_bitmap("Constructions/routeVerti.bmp", NULL);

    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);
    AffichageBouton(boutonPause,boutonPauseInv,page,0,0,945,70,boutonPause->w,boutonPause->h);

    blit(infosRoute, page, 0,0,910,120,infosRoute->w,infosRoute->h);
    masked_stretch_blit(route,page,0,0, 20,20, 930,220,40,40);
    masked_stretch_blit(routeVerti,page,0,0, 20,20, 930,280,40,40);

}

void chateau_eau(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab)
{
    BITMAP* chateauEauTran = load_bitmap("Constructions/routeTran.bmp", NULL);

    int x,y;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        //afficher_map(page,map);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {
            afficherInterface(page,map,tempsdepart,*banque);
            affichagecasefree(page,map,14);
            /*if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

                blit(chateauEauTran, page, 0, 0, mouse_x-20, mouse_y-20, chateauEauTran->w, chateauEauTran->h);
                afficherInterface(page,map,tempsdepart, *banque);
            }*/
        }

        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        test_temps(map,tab_hab,banque,nb_hab);

        afficherInterface(page,map,tempsdepart, *banque);
        if(testclic==1 && *banque>=100000 &&
           map[y][x]==0&&(map[y-1][x] == 0)&&(map[y-2][x] == 0)&&(map[y-3][x] == 0)&&(map[y-4][x] == 0)&&(map[y-5][x] == 0)&&
           (map[y][x+1]==0)&&(map[y-1][x+1]==0)&&(map[y-2][x+1]==0)&&(map[y-3][x+1]==0)&&(map[y-4][x+1]==0)&&(map[y-5][x+1]==0)&&
           (map[y][x+2]==0)&&(map[y-1][x+2]==0)&&(map[y-2][x+2]==0)&&(map[y-3][x+2]==0)&&(map[y-4][x+2]==0)&&(map[y-5][x+2]==0)&&
           (map[y][x+3]==0)&&(map[y-1][x+3]==0)&&(map[y-2][x+3]==0)&&(map[y-3][x+3]==0)&&(map[y-4][x+3]==0)&&(map[y-5][x+3]==0))
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
            afficher_map(page,map);
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

    int x,y;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        //afficher_map(page,map);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {
            afficherInterface(page,map,tempsdepart,*banque);
            affichagecasefree(page,map,14);
            /*if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

                blit(chateauEauTran, page, 0, 0, mouse_x-20, mouse_y-20, chateauEauTran->w, chateauEauTran->h);
                afficherInterface(page,map,tempsdepart, *banque);
            }*/
        }

        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        test_temps(map,tab_hab,banque,nb_hab);
        afficher_map(page,map);
        afficherInterface(page,map,tempsdepart, *banque);
        if(testclic==1 && *banque>=100000 &&
           map[y][x]==0&&(map[y-1][x] == 0)&&(map[y-2][x] == 0)&&(map[y-3][x] == 0)&&(map[y][x+4] == 0)&&(map[y][x+5] == 0)&&
           (map[y][x+1]==0)&&(map[y-1][x+1]==0)&&(map[y-2][x+1]==0)&&(map[y-3][x+1]==0)&&(map[y-1][x+4]==0)&&(map[y-1][x+5]==0)&&
           (map[y][x+2]==0)&&(map[y-1][x+2]==0)&&(map[y-2][x+2]==0)&&(map[y-3][x+2]==0)&&(map[y-2][x+4]==0)&&(map[y-2][x+5]==0)&&
           (map[y][x+3]==0)&&(map[y-1][x+3]==0)&&(map[y-2][x+3]==0)&&(map[y-3][x+3]==0)&&(map[y-3][x+4]==0)&&(map[y-3][x+5]==0))
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
            afficher_map(page,map);
        }
        if(mouse_b&2)
            clic=1;

        show_mouse(page);
        blit(page,screen,0,0,0,0,900,700);
    }
}

void habitation (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, int* nb_hab, t_habitation tab_hab[50]) {
    BITMAP *terrain_vague = load_bitmap("Constructions/terrain_vague.bmp", NULL);

    int x, y;
    int clic = 0;
    int testclic = 0;

    while (clic != 1) {
        if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700)))) {
            afficherInterface(page, map, tempsdepart, *banque);
            affichagecasefree(page, map, 3);
            /*if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

                afficher_map(page,map);
                afficherInterface(page,map,tempsdepart, *banque);
                blit(terrain_vague, page, 0, 0, mouse_x, mouse_y-40, terrain_vague->w, terrain_vague->h);
                blit(page,screen,0,0,0,0,900,700);
            }
            }*/


            if (((mouse_x >= (0) && mouse_x <= (900)) && ((mouse_y) >= (0) && mouse_y <= (700))) && (mouse_b & 1)) {
                x = mouse_x / 20;
                y = mouse_y / 20;
                testclic = 1;

            }
            if (testclic == 1 && *banque > 1000 && map[y][x] == 0 && map[y][x + 1] == 0 && map[y][x + 2] == 0 &&
                map[y - 1][x] == 0 && map[y - 1][x + 1] == 0 && map[y - 1][x + 2] == 0 && map[y - 2][x] == 0 &&
                map[y - 2][x + 1] == 0 && map[y - 2][x + 2] == 0) {
                map[y][x] = 9;
                map[y][x + 1] = 9;
                map[y][x + 2] = 9;
                map[y - 1][x] = 9;
                map[y - 1][x + 1] = 9;
                map[y - 1][x + 2] = 9;
                map[y - 2][x] = 3;
                map[y - 2][x + 1] = 9;
                map[y - 2][x + 2] = 9;

                afficher_map(page, map);
                *banque -= 1000;


                /* *nb_hab++;
                tab_hab=(t_habitation*)realloc(tab_hab, *nb_hab * sizeof(t_habitation));

                tab_hab[0].nb_hab=0;
                tab_hab[0].niveau=0;
                tab_hab[0].tempsCrea=time(NULL);*/

                tab_hab[*nb_hab].nb_habitants = 0;
                tab_hab[*nb_hab].niveau = 0;
                tab_hab[*nb_hab].tempsCrea = time(NULL);
                tab_hab[*nb_hab].x = x;
                tab_hab[*nb_hab].y = y - 2;

                *nb_hab += 1;
            }


            if (mouse_b & 2)
                clic = 1;

            test_temps(map, tab_hab, banque, *nb_hab);
            afficher_map(page, map);
            afficherInterface(page, map, tempsdepart, *banque);
            show_mouse(page);
            blit(page, screen, 0, 0, 0, 0, 900, 700);
        }
    }
}
