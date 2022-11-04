#include "header.h"


void route (BITMAP* page, int map[35][45], int banque)
{

    BITMAP* route = load_bitmap("Constructions/route.bmp", NULL);
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);

    int x,y;
    int clic=0;
    int testclic=0;

    while(clic!=1)
    {
        if(((mouse_x>=(0)&& mouse_x<=(900))&& ((mouse_y)>=(0)&& mouse_y<=(700)))&&(mouse_b &1))
        {
            x=mouse_x/20;
            y=mouse_y/20;
            testclic=1;
        }
        if(testclic==1 && banque>10) {
            map[y][x] = 1;
            banque-=10;
        }
        if(mouse_b&2)
            clic=1;
        afficher_map(page,map);
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