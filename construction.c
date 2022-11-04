#include "header.h"


void route (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque)
{
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);

    int x,y;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        //afficher_map(page,map);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

            blit(routeTran, page, 0, 0, mouse_x-20, mouse_y-20, routeTran->w, routeTran->h);
            afficherInterface(page,map,tempsdepart, banque);

        }

        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        afficher_map(page,map);
        if(testclic==1 && *banque>10 && map[y][x]==0) {
            map[y][x] = 1;
            *banque-=10;
        }
        if(mouse_b&2)
            clic=1;

        show_mouse(page);
        blit(page,screen,0,0,0,0,900,700);
    }
}

void chateau_eau(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque)
{
    BITMAP* chateauEauTran = load_bitmap("Constructions/routeTran.bmp", NULL);

    int x,y;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        //afficher_map(page,map);
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))) {

            blit(chateauEauTran, page, 0, 0, mouse_x-20, mouse_y-20, chateauEauTran->w, chateauEauTran->h);
            afficherInterface(page,map,tempsdepart, banque);
        }

        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        afficher_map(page,map);
        if(testclic==1 && *banque>=100000 && map[y][x]==0 && (map[y][x] == 0)&&(map[y-1][x] == 0)&&(map[y-2][x] == 0)&&(map[y-3][x] == 0)&&(map[y-4][x] == 0)&&(map[y-5][x] == 0)&&(map[y][x+1]==0)
        &&(map[y-1][x+1]==0) && (map[y-2][x+1]==0) &&(map[y-3][x+1]==0)&&(map[y-4][x+1]==0)&&(map[y-5][x+1]==0)&&(map[y][x+2]==0)&&
                (map[y-1][x+2]==0)&&(map[y-2][x+2]==0)&&(map[y-3][x+2]==0)&&(map[y-4][x+2]==0)&&(map[y-5][x+2]==0)&&(map[y][x+3]==0)&&
                (map[y-1][x+3]==0)&&(map[y-2][x+3]==0)&&(map[y-3][x+3]==0)&&(map[y-4][x+3]==0)&&(map[y-5][x+3]==0))
        {
            map[y][x] = 9;
            map[y-1][x] =9;
            map[y-2][x] =9;
            map[y-3][x] =9;
            map[y-4][x] =9;
            map[y-5][x] =5;

            map[y][x+1] =9;
            map[y-1][x+1] =9;
            map[y-2][x+1] =9;
            map[y-3][x+1] =9;
            map[y-4][x+1] =9;
            map[y-5][x+1] =9;

            map[y][x+2] =9;
            map[y-1][x+2] =9;
            map[y-2][x+2] =9;
            map[y-3][x+2] =9;
            map[y-4][x+2] =9;
            map[y-5][x+2] =9;

            map[y][x+3] =9;
            map[y-1][x+3] =9;
            map[y-2][x+3] =9;
            map[y-3][x+3] =9;
            map[y-4][x+3] =9;
            map[y-5][x+3] =9;
            *banque-=100000;
        }
        if(mouse_b&2)
            clic=1;

        show_mouse(page);
        blit(page,screen,0,0,0,0,900,700);
    }
}

/*
void canalisations (BITMAP* page)
{

}

void cables (BITMAP* page)
{

}*/