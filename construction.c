#include "header.h"


void route (BITMAP* page, int map[35][45])
{

    BITMAP* route = load_bitmap("Constructions/route.bmp", NULL);
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);

    int x,y;

    if(((mouse_x >= (0) && mouse_x <= (900)) && (mouse_y) >= (0) && mouse_y <= (900)))
    {
        masked_blit(routeTran, page,0,0,mouse_x,mouse_y,page->w, page->h);
        if(((mouse_x >= (0) && mouse_x <= (900)) && (mouse_y) >= (0) && mouse_y <= (700 ))&&(mouse_b==1))
        {
            x=mouse_x;
            y=mouse_y;
            map[x][y]=1;
        }
    }
}

/*
void canalisations (BITMAP* page)
{

}

void cables (BITMAP* page)
{

}*/