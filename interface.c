#include "header.h"

void afficherInterface(BITMAP* page,int map[35][45])
{
    //Déclaration des BITMAP pour l'interface
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);
    BITMAP* iconeRoute = load_bitmap("Interface/iconeRoute.bmp", NULL);
    BITMAP* iconeRouteInv = load_bitmap("Interface/iconeRouteInv.bmp", NULL);
    BITMAP* iconeChateau = load_bitmap("Interface/iconeChateau.bmp", NULL);
    BITMAP* iconeChateauInv = load_bitmap("Interface/iconeChateauInv.bmp",NULL);
    BITMAP* iconeCentrale = load_bitmap("Interface/iconeCentrale.bmp", NULL);
    BITMAP* iconeCentraleInv = load_bitmap("Interface/iconeCentraleInv.bmp", NULL);
    BITMAP* iconeMaison = load_bitmap("Interface/iconeMaison.bmp", NULL);
    BITMAP* iconeMaisonInv = load_bitmap("Interface/iconeMaisonInv.bmp", NULL);

    //Déclaration des BITMAP pour les boutons
    BITMAP* boutonQuitter = load_bitmap("Interface/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Interface/boutonQuitterInv.bmp", NULL);
    BITMAP* boutonSauvegarder = load_bitmap("Interface/boutonSauvegarder.bmp", NULL);
    BITMAP* boutonSauvegarderInv = load_bitmap("Interface/boutonSauvegarderInv.bmp", NULL);
    BITMAP* boutonPause = load_bitmap("Interface/boutonPause.bmp", NULL);
    BITMAP* boutonPauseInv = load_bitmap("Interface/boutonPauseInv.bmp", NULL);

    BITMAP* boutonElec = load_bitmap("Interface/boutonElec.bmp", NULL);
    BITMAP* boutonElecInv = load_bitmap("Interface/boutonElecInv.bmp", NULL);
    BITMAP* boutonEau = load_bitmap("Interface/boutonEau.bmp", NULL);
    BITMAP* boutonEauInv = load_bitmap("Interface/boutonEauInv.bmp", NULL);

    //Affichage du fond
    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    //Affichage des boutons pour les concentrations
    AffichageBouton(iconeRoute, iconeRouteInv, page, 0, 0, 920, 130, iconeRoute->w, iconeRoute->h);
    AffichageBouton(iconeMaison, iconeMaisonInv, page, 0,0, 920, 200, iconeMaison->w, iconeMaison->h);
    AffichageBouton(iconeChateau, iconeChateauInv, page, 0, 0, 920, 260,iconeChateau->w,iconeChateau->h);
    AffichageBouton(iconeCentrale, iconeCentraleInv, page, 0, 0, 920, 340,iconeCentrale->w,iconeCentrale->h);

    //Affichage des boutons
    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);
    AffichageBouton(boutonSauvegarder,boutonSauvegarderInv,page,0,0,920,25,boutonSauvegarder->w,boutonSauvegarder->h);
    AffichageBouton(boutonPause,boutonPauseInv,page,0,0,945,70,boutonPause->w,boutonPause->h);

    //Affichage des boutons de niveaux
    AffichageBouton(boutonElec, boutonElecInv, page, 0,0,920, 550, boutonElec->w,boutonElec->h);
    AffichageBouton(boutonEau,boutonEauInv,page,0,0, 920, 620, boutonEau->w, boutonEau->h);

    //Test pour la construction des routes
    if (((mouse_x >= (920) && mouse_x <= (920 + 90)) && (mouse_y) >= (150) && mouse_y <= (150 + 65)) && (mouse_b & 1))
    {
        route(page,map);
    }

    //Test pour la construction
    if (((mouse_x >= (920) && mouse_x <= (920 + 100)) && (mouse_y) >= (180) && mouse_y <= (180 + 100)) && (mouse_b & 1))
    {
        //sous programme maison
    }

    show_mouse(page);
    blit(page, screen, 0, 0, 0, 0, 1024, 768);

}

/*
void routeInterface (BITMAP* page, int retourInterface)
{
    BITMAP* iconeRouteTran = load_bitmap("Interface/iconeRouteTran.bmp", NULL);

    //affichage route
    if (retourInterface == 1)
    {
        masked_blit(iconeRouteTran, page,0,0,mouse_x,mouse_y,page->w, page->h);
    }
}
*/
