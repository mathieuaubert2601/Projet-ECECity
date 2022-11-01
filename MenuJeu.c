#include "header.h"

void menuJeu(BITMAP* bmpAffichage)
{
    //Déclaration des bitmaps
    BITMAP* fondMenu = load_bitmap("menuDepart/fond1.bmp",NULL);
    BITMAP* boutonNouvellePartie = load_bitmap("menuDepart/boutonNouvellePartie.bmp",NULL);
    BITMAP* boutonNouvellePartieInv = load_bitmap("menuDepart/boutonNouvellePartieInv.bmp",NULL);

    blit(fondMenu,bmpAffichage,0,0,0,0,bmpAffichage->w,bmpAffichage->h);
    AffichageBouton(boutonNouvellePartie,boutonNouvellePartieInv,bmpAffichage,0,0,340,200,boutonNouvellePartie->w ,boutonNouvellePartie->h);
}