#include "header.h"

void afficherInterface(BITMAP* page,int map[35][45], time_t tempsdepart, int argent)
{
    int compteurEau=0;
    int compteurElec=0;
    int compteurHab=0;

    //Déclaration des BITMAP pour l'interface
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);
    BITMAP* iconeRoute = load_bitmap("Interface/iconeRoute.bmp", NULL);
    BITMAP* iconeRouteInv = load_bitmap("Interface/iconeRouteInv.bmp", NULL);
    BITMAP* iconeChateauEau = load_bitmap("Interface/iconeChateauEau.bmp", NULL);
    BITMAP* iconeChateauEauInv = load_bitmap("Interface/iconeChateauEauInv.bmp",NULL);
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
    AffichageBouton(iconeChateauEau, iconeChateauEauInv,page,0,0,920,270,iconeChateauEau->w,iconeChateauEau->h);
    AffichageBouton(iconeCentrale, iconeCentraleInv, page, 0, 0, 920, 380,iconeCentrale->w,iconeCentrale->h);

    //Affichage des boutons
    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);
    AffichageBouton(boutonSauvegarder,boutonSauvegarderInv,page,0,0,920,25,boutonSauvegarder->w,boutonSauvegarder->h);
    AffichageBouton(boutonPause,boutonPauseInv,page,0,0,945,70,boutonPause->w,boutonPause->h);

    //Affichage des boutons de niveaux
    AffichageBouton(boutonElec, boutonElecInv, page, 0,0,920, 550, boutonElec->w,boutonElec->h);
    AffichageBouton(boutonEau,boutonEauInv,page,0,0, 920, 620, boutonEau->w, boutonEau->h);


    time_t tempsact = time(NULL);
    unsigned long diff=difftime(tempsact,tempsdepart);
    textprintf_ex(page,font,980,720,makecol(255,255,255),-1,"%d",diff);

    textprintf_ex(page,font,80,720,makecol(255,255,255),-1,"%d",argent);

    compteurHab = compterHab(map);
    compteurEau = compterEau(map);
    compteurElec = compterElec(map);

    textprintf_ex(page,font,180,720,makecol(255,255,255),-1,"%d",compteurHab);
    textprintf_ex(page,font,280,720,makecol(255,255,255),-1,"%d",compteurEau);
    textprintf_ex(page,font,380,720,makecol(255,255,255),-1,"%d",compteurElec);

    show_mouse(page);
    blit(page, screen, 0, 0, 0, 0, 1024, 768);

}

