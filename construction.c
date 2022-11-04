#include "header.h"


void route (BITMAP* page, int map[35][45])
{
    //Creation Diff batiments
    t_batiment terrain_vague, cabane, maison, immeuble, gratte_ciel, routes, chateau_eau, centrale;

    //Definition prix differents batiments
    terrain_vague.prix = 1000;
    routes.prix = 10;
    centrale.prix = 100000;
    chateau_eau.prix=100000;

    //Definition capacite habitation
    cabane.nb_hab=10;
    maison.nb_hab=50;
    immeuble.nb_hab=100;
    gratte_ciel.nb_hab=1000;

    //Definition capacite de distribution
    centrale.capacite_elec=5000;
    chateau_eau.capacite_eau=5000;

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