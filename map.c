//
// Created by thiba on 01/11/2022.
//
#include "header.h"


void creer_map(BITMAP* page)
{
    BITMAP* tuile = load_bitmap("map/test_tuile.bmp",NULL);
    for (int i = 0; i<35; i++)
        for(int j = 0; j<45; j++)
        {
            masked_stretch_blit(tuile,page,0,0,77,77,j*20,i*20,20,20);
            blit(page,screen,0,0,0,0,1024,768);
        }

}