#include "header.h"

void afficherInterface(BITMAP* page)
{
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas", NULL);
    BITMAP* iconeRoute = load_bitmap("Interface/iconeRoute.bmp", NULL);
    BITMAP* iconeRouteInv = load_bitmap("Interface/iconeRouteInv.bmp", NULL);
    BITMAP* iconeRouteTran = load_bitmap("Interface/iconeRouteTran.bmp", NULL);
    BITMAP* iconeBatiment = load_bitmap("Interface/iconeBatiment.bmp", NULL);
    BITMAP* iconeBatimentInv = load_bitmap("Interface/iconeBatimentInv.bmp",NULL);
    BITMAP* iconeMaison = load_bitmap("Interface/iconeMaison.bmp", NULL);
    BITMAP* iconeMaisonInv = load_bitmap("Interface/iconeMaisonInv.bmp", NULL);

    BITMAP* boutonQuitter = load_bitmap("Interface/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Interface/boutonQuitterInv.bmp", NULL);
    BITMAP* boutonSauvegarder = load_bitmap("Interface/boutonSauvegarder.bmp", NULL);
    BITMAP* boutonSauvegarderInv = load_bitmap("Interface/boutonSauvegarderInv.bmp", NULL);
    BITMAP* boutonPause = load_bitmap("Interface/boutonPause.bmp", NULL);
    BITMAP* boutonPauseInv = load_bitmap("Interface/boutonPauseInv.bmp", NULL);

    int sortie =0;
    int route;

    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);

    AffichageBouton(iconeRoute, iconeRouteInv, page, 0, 0, 920, 130, iconeRoute->w, iconeRoute->h);
    AffichageBouton(iconeMaison, iconeMaisonInv, page, 0,0, 920, 200, iconeMaison->w, iconeMaison->h);
    AffichageBouton(iconeBatiment, iconeBatimentInv, page, 0, 0, 920, 250,iconeBatiment->w,iconeBatiment->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);
    AffichageBouton(boutonSauvegarder,boutonSauvegarderInv,page,0,0,920,25,boutonSauvegarder->w,boutonSauvegarder->h);
    AffichageBouton(boutonPause,boutonPauseInv,page,0,0,945,70,boutonPause->w,boutonPause->h);

    if (((mouse_x >= (920) && mouse_x <= (920 + 90)) && (mouse_y) >= (150) && mouse_y <= (150 + 65)) && (mouse_b & 1))
    {
        masked_blit(iconeRouteTran, page,0,0,mouse_x,mouse_y,page->w, page->h);
    }
    if (((mouse_x >= (920) && mouse_x <= (920 + 100)) && (mouse_y) >= (180) && mouse_y <= (180 + 100)) && (mouse_b & 1)) {
        masked_blit(iconeRouteTran, page,0,0,mouse_x,mouse_y,page->w, page->h);
    }
    show_mouse(page);
    blit(page, screen, 0, 0, 0, 0, 1024, 768);

}

/*
void route (BITMAP* page, int retourInterface)
{
    BITMAP* iconeRouteTran = load_bitmap("Interface/iconeRouteTran.bmp", NULL);

    //affichage route
    if (retourInterface == 1)
    {
        masked_blit(iconeRouteTran, page,0,0,mouse_x,mouse_y,page->w, page->h);
    }
}
*/
