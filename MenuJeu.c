#include "header.h"
void affichageregles(BITMAP* bmpAffichage)
{
    int sortie=0;
    int clic=0;
    BITMAP* fondMenu = load_bitmap("menuDepart/fond1.bmp",NULL);
    BITMAP* regle = load_bitmap("menuDepart/regle.bmp",NULL);
    BITMAP* logoEceCitySansFond2 = load_bitmap("menuDepart/logo3.bmp",NULL);
    while(clic!=1)
    {
        clear_bitmap(bmpAffichage);
        blit(fondMenu,bmpAffichage,0,0,0,0,bmpAffichage->w,bmpAffichage->h);
        masked_blit(logoEceCitySansFond2,bmpAffichage,0,0,230,0,logoEceCitySansFond2->w,logoEceCitySansFond2->h);
        masked_stretch_blit(regle,bmpAffichage,0,0,regle->w,regle->h,150,190,regle->w /1.4 ,regle->h/1.4);
        blit(bmpAffichage,screen,0,0,0,0,1024,768);
        if(mouse_b & 2)
        {
            clic=1;
        }

    }

}
int menuJeu(BITMAP* bmpAffichage)
{
    //déclaration des variables
    int sortie = 0;

    //Déclaration des bitmaps
    BITMAP* fondMenu = load_bitmap("menuDepart/fond1.bmp",NULL);
    BITMAP* boutonNouvellePartie = load_bitmap("menuDepart/boutonNouvellePartie.bmp",NULL);
    BITMAP* logoEceCityAvecFond = load_bitmap("menuDepart/logo1.bmp",NULL);
    BITMAP* logoEceCitySansFond = load_bitmap("menuDepart/logo2.bmp",NULL);
    BITMAP* logoEceCitySansFond2 = load_bitmap("menuDepart/logo3.bmp",NULL);
    BITMAP* boutonNouvellePartieInv = load_bitmap("menuDepart/boutonNouvellePartieInv.bmp",NULL);
    BITMAP* boutonChargerPartie = load_bitmap("menuDepart/boutonChargerPartie.bmp",NULL);
    BITMAP* boutonChargerPartieInv = load_bitmap("menuDepart/boutonChargerPartieInv.bmp",NULL);
    BITMAP* boutonQuitterPartie = load_bitmap("menuDepart/boutonQuitterPartie.bmp",NULL);
    BITMAP* boutonQuitterPartieInv = load_bitmap("menuDepart/boutonQuitterPartieInv.bmp",NULL);
    BITMAP* boutonRegle = load_bitmap("menuDepart/boutonRegles.bmp",NULL);
    BITMAP* boutonRegleInv = load_bitmap("menuDepart/boutonReglesInv.bmp",NULL);


    //Affichage des bitmap
    while(sortie == 0)
    {
        clear_bitmap(bmpAffichage);
        blit(fondMenu,bmpAffichage,0,0,0,0,bmpAffichage->w,bmpAffichage->h);
        masked_blit(logoEceCitySansFond2,bmpAffichage,0,0,230,0,logoEceCitySansFond2->w,logoEceCitySansFond2->h);
        AffichageBouton(boutonNouvellePartie,boutonNouvellePartieInv,bmpAffichage,0,0,340,250,boutonNouvellePartie->w ,boutonNouvellePartie->h);
        AffichageBouton(boutonChargerPartie,boutonChargerPartieInv,bmpAffichage,0,0,340,370,boutonChargerPartie->w,boutonChargerPartie->h);
        AffichageBouton(boutonQuitterPartie,boutonQuitterPartieInv,bmpAffichage,0,0,340,490,boutonQuitterPartie->w,boutonQuitterPartie->h);
        AffichageBouton(boutonRegle,boutonRegleInv,bmpAffichage,0,0,340,610,boutonRegle->w,boutonRegle->h);
        show_mouse(bmpAffichage);
        blit(bmpAffichage,screen,0,0,0,0,1024,768);

        if(((mouse_x>=(340)&& mouse_x<=(340+330))&& (mouse_y)>=(250)&& mouse_y<=(250 + 95))&&(mouse_b & 1))
        {
            return 1;
        }
        if(((mouse_x>=(340)&& mouse_x<=(340+330))&& (mouse_y)>=(370)&& mouse_y<=(370 + 95))&&(mouse_b & 1))
        {
            return 2;
        }
        if(((mouse_x>=(340)&& mouse_x<=(340+330))&& (mouse_y)>=(490)&& mouse_y<=(490 + 95))&&(mouse_b & 1))
        {
            return 3;
        }
        if(((mouse_x>=(340)&& mouse_x<=(340+330))&& (mouse_y)>=(610)&& mouse_y<=(610 + 95))&&(mouse_b & 1))
        {
            return 4;
        }
    }

}

//Action en cas de choix
int actionChoixMenu(int choixDuMenu,BITMAP* bmpAffichage)
{
    //Déclaration des variables
    int modeDeJeu = 0;
    if(choixDuMenu == 1)
    {
        rest(200);
        modeDeJeu =  choixModeJeu(bmpAffichage);
    }
    else if(choixDuMenu == 2 && testSauvegarde())
    {

    }
    else if(choixDuMenu == 3)
    {
        exit(0);
    }
    else if(choixDuMenu == 4)
    {
        affichageregles(bmpAffichage);
    }
    return modeDeJeu;
}

//Choix du mode de jeu
int choixModeJeu(BITMAP* bmpAffichage)
{
    //Déclaration des variables
    int sortie = 0;

    //Déclaration des bitmaps
    BITMAP* fondMenu = load_bitmap("menuDepart/fond1.bmp",NULL);
    BITMAP* boutonModeCapitaliste = load_bitmap("menuDepart/boutonCapitaliste.bmp",NULL);
    BITMAP* boutonModeCapitalisteInv = load_bitmap("menuDepart/boutonCapitalisteInv.bmp",NULL);
    BITMAP* boutonModeCommuniste = load_bitmap("menuDepart/boutonCommuniste.bmp",NULL);
    BITMAP* boutonModeCommunisteInv = load_bitmap("menuDepart/boutonCommunisteInv.bmp",NULL);
    BITMAP* phraseChoixMode = load_bitmap("menuDepart/phraseChoixMode.bmp",NULL);

    while(sortie == 0)
    {
        //Affichage des bitmaps
        clear_bitmap(bmpAffichage);
        blit(fondMenu,bmpAffichage,0,0,0,0,bmpAffichage->w,bmpAffichage->h);
        masked_blit(phraseChoixMode,bmpAffichage,0,0,130,100,phraseChoixMode->w,phraseChoixMode->h);
        AffichageBouton(boutonModeCapitaliste,boutonModeCapitalisteInv,bmpAffichage,0,0,340,250,boutonModeCapitaliste->w,boutonModeCapitaliste->h);
        AffichageBouton(boutonModeCommuniste,boutonModeCommunisteInv,bmpAffichage,0,0,340,370,boutonModeCommuniste->w,boutonModeCommuniste->h);
        show_mouse(bmpAffichage);
        blit(bmpAffichage,screen,0,0,0,0,1024,768);

        if(((mouse_x>=(340)&& mouse_x<=(340+330))&& (mouse_y)>=(250)&& mouse_y<=(250 + 95))&&(mouse_b & 1))
        {
            rest(100);
            return 2;
        }
        if(((mouse_x>=(340)&& mouse_x<=(340+330))&& (mouse_y)>=(370)&& mouse_y<=(370 + 95))&&(mouse_b & 1))
        {
            rest(100);
            return 1;
        }
    }
}