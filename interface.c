#include "header.h"

void afficherInterface(BITMAP* page,int map[35][45], time_t tempsdepart, int argent,time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono, int mode)
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
    BITMAP* communiste = load_bitmap("Interface/communiste.bmp", NULL);
    BITMAP* capitaliste = load_bitmap("Interface/capitaliste.bmp", NULL);

    //Déclaration des BITMAP pour les boutons
    BITMAP* boutonQuitter = load_bitmap("Interface/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Interface/boutonQuitterInv.bmp", NULL);
    BITMAP* boutonSauvegarder = load_bitmap("Interface/boutonSauvegarder.bmp", NULL);
    BITMAP* boutonSauvegarderInv = load_bitmap("Interface/boutonSauvegarderInv.bmp", NULL);
    BITMAP* boutonPause = load_bitmap("Interface/boutonPause.bmp", NULL);
    BITMAP* boutonPauseInv = load_bitmap("Interface/boutonPauseInv.bmp", NULL);
    BITMAP* boutonPlay = load_bitmap("Interface/boutonPlay.bmp", NULL);
    BITMAP* boutonPlayInv = load_bitmap("Interface/boutonPlayInv.bmp", NULL);

    BITMAP* boutonElec = load_bitmap("Interface/boutonElec.bmp", NULL);
    BITMAP* boutonElecInv = load_bitmap("Interface/boutonElecInv.bmp", NULL);
    BITMAP* boutonEau = load_bitmap("Interface/boutonEau.bmp", NULL);
    BITMAP* boutonEauInv = load_bitmap("Interface/boutonEauInv.bmp", NULL);

    BITMAP* nbEau = load_bitmap("Interface/nbEau.bmp", NULL);
    BITMAP* nbEauInfos = load_bitmap("Interface/nbEauInfos.bmp", NULL);
    BITMAP* nbElec = load_bitmap("Interface/nbElec.bmp", NULL);
    BITMAP* nbElecInfos = load_bitmap("Interface/nbElecInfos.bmp", NULL);
    BITMAP* nbHab = load_bitmap("Interface/nbHab.bmp", NULL);
    BITMAP* nbHabInfos = load_bitmap("Interface/nbHabInfos.bmp", NULL);
    BITMAP* nbArgent = load_bitmap("Interface/nbArgent.bmp", NULL);
    BITMAP* nbArgentInfos = load_bitmap("Interface/nbArgentInfos.bmp", NULL);
    FONT * maPolice = load_font("submariner.pcx",NULL,NULL);
    //Affichage du fond
    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    //Affichage des boutons pour les concentrations
    AffichageBouton(iconeRoute, iconeRouteInv, page, 0, 0, 920, 130, iconeRoute->w, iconeRoute->h);
    AffichageBouton(iconeMaison, iconeMaisonInv, page, 0,0, 920, 200, iconeMaison->w, iconeMaison->h);
    AffichageBouton(iconeChateauEau, iconeChateauEauInv,page,0,0,930,280,iconeChateauEau->w,iconeChateauEau->h);
    AffichageBouton(iconeCentrale, iconeCentraleInv, page, 0, 0, 920, 380,iconeCentrale->w,iconeCentrale->h);

    //Affichage des boutons
    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);
    if(pause==0)
        AffichageBouton(boutonSauvegarder,boutonSauvegarderInv,page,0,0,920,25,boutonSauvegarder->w,boutonSauvegarder->h);

    if(pause==0)
        AffichageBouton(boutonPause,boutonPauseInv,page,0,0,945,70,boutonPause->w,boutonPause->h);
    if(pause==1)
        AffichageBouton(boutonPlay,boutonPlayInv,page,0,0,945,70,boutonPlay->w,boutonPlay->h);

    if(mode==1)
    {
        masked_blit(communiste,page,0,0,920,710,communiste->w,communiste->h);
    }
    if(mode==2)
    {
        masked_blit(capitaliste,page,0,0,920,710,capitaliste->w,capitaliste->h);
    }

    //Affichage des boutons de niveaux
    AffichageBouton(boutonEau,boutonEauInv,page,0,0, 920, 550, boutonEau->w, boutonEau->h);
    AffichageBouton(boutonElec, boutonElecInv, page, 0,0,920, 620, boutonElec->w,boutonElec->h);


    time_t tempsact = time(NULL);
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);
    unsigned long diff=difftime(tempsact,tempsdepart);
    unsigned long diffP=difftime(tempsDepartPause,tempsdepart);

    if(pause==0)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diff);
    if(pause==1)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diffP);

    textprintf_ex(page,maPolice,80,720,makecol(255,255,255),-1,"%d",argent);
    compteurHab = compterHab(map);
    compteurEau = compterEau(map);
    compteurElec = compterElec(map);

    AffichageIcone(nbEau,nbEau,nbEauInfos,page,0,0,250,715,0,10,nbEau->w,nbEau->h,nbEauInfos->w,nbEauInfos->h);
    AffichageIcone(nbElec,nbElec,nbElecInfos,page,0,0,350,715,0,10,nbElec->w,nbElec->h,nbElecInfos->w,nbElecInfos->h);
    AffichageIcone(nbHab,nbHab,nbHabInfos,page,0,0,150,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);
    AffichageIcone(nbArgent,nbArgent,nbArgentInfos,page,0,0,50,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);

    textprintf_ex(page,maPolice,180,720,makecol(255,255,255),-1,"%d",compteurHab);
    textprintf_ex(page,maPolice,280,720,makecol(255,255,255),-1,"%d",compteurEau);
    textprintf_ex(page,maPolice,380,720,makecol(255,255,255),-1,"%d",compteurElec);

    show_mouse(page);
    blit(page, screen, 0, 0, 0, 0, 1024, 768);

}

void interfaceRoute(BITMAP* page, int type, time_t tempsdepart, int argent, int map[35][45],time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono, int mode)
{
    int compteurEau=0;
    int compteurElec=0;
    int compteurHab=0;
    FONT * maPolice = load_font("submariner.pcx",NULL,NULL);

    //Declaration des BITMAP
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);

    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);

    BITMAP* communiste = load_bitmap("Interface/communiste.bmp", NULL);
    BITMAP* capitaliste = load_bitmap("Interface/capitaliste.bmp", NULL);
    BITMAP* infosRoute = load_bitmap("Constructions/infosRoute.bmp", NULL);
    BITMAP* routeIcone = load_bitmap("Constructions/routeIcone.bmp", NULL);
    BITMAP* routeVertiIcone = load_bitmap("Constructions/routeVertiIcone.bmp", NULL);
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* routeVertiTran = load_bitmap("Constructions/routeVertiTran.bmp", NULL);

    BITMAP* nbEau = load_bitmap("Interface/nbEau.bmp", NULL);
    BITMAP* nbEauInfos = load_bitmap("Interface/nbEauInfos.bmp", NULL);
    BITMAP* nbElec = load_bitmap("Interface/nbElec.bmp", NULL);
    BITMAP* nbElecInfos = load_bitmap("Interface/nbElecInfos.bmp", NULL);
    BITMAP* nbHab = load_bitmap("Interface/nbHab.bmp", NULL);
    BITMAP* nbHabInfos = load_bitmap("Interface/nbHabInfos.bmp", NULL);
    BITMAP* nbArgent = load_bitmap("Interface/nbArgent.bmp", NULL);
    BITMAP* nbArgentInfos = load_bitmap("Interface/nbArgentInfos.bmp", NULL);

    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);

    blit(infosRoute, page, 0,0,910,120,infosRoute->w,infosRoute->h);

    if(type==0)
    {
        blit(routeIcone,page,0,0,930,220,routeIcone->w,routeIcone->h);
        blit(routeVertiIcone,page,0,0,930,280,routeVertiIcone->w,routeVertiIcone->h);
    }

    if(mode==1)
    {
        masked_blit(communiste,page,0,0,920,710,communiste->w,communiste->h);
    }
    if(mode==2)
    {
        masked_blit(capitaliste,page,0,0,920,710,capitaliste->w,capitaliste->h);
    }

    if(type==1)
        blit(routeTran,page,0,0,930,220,routeTran->w,routeTran->h);
        blit(routeVertiIcone,page,0,0,930,280,routeVertiIcone->w,routeVertiIcone->h);
    if(type==2)
    {
        blit(routeIcone,page,0,0,930,220,routeIcone->w,routeIcone->h);
        blit(routeVertiTran,page,0,0,930,280,routeVertiTran->w,routeVertiTran->h);
    }


    time_t tempsact = time(NULL);
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);
    unsigned long diff=difftime(tempsact,tempsdepart);
    unsigned long diffP=difftime(tempsDepartPause,tempsdepart);

    if(pause==0)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diff);
    if(pause==1)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diffP);

    textprintf_ex(page,maPolice,80,720,makecol(255,255,255),-1,"%d",argent);

    compteurHab = compterHab(map);
    compteurEau = compterEau(map);
    compteurElec = compterElec(map);

    AffichageIcone(nbEau,nbEau,nbEauInfos,page,0,0,250,715,0,10,nbEau->w,nbEau->h,nbEauInfos->w,nbEauInfos->h);
    AffichageIcone(nbElec,nbElec,nbElecInfos,page,0,0,350,715,0,10,nbElec->w,nbElec->h,nbElecInfos->w,nbElecInfos->h);
    AffichageIcone(nbHab,nbHab,nbHabInfos,page,0,0,150,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);
    AffichageIcone(nbArgent,nbArgent,nbArgentInfos,page,0,0,50,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);


    textprintf_ex(page,maPolice,180,720,makecol(255,255,255),-1,"%d",compteurHab);
    textprintf_ex(page,maPolice,280,720,makecol(255,255,255),-1,"%d",compteurEau);
    textprintf_ex(page,maPolice,380,720,makecol(255,255,255),-1,"%d",compteurElec);
}


void interfaceMaisons(BITMAP* page,time_t tempsdepart, int argent, int map[35][45],time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono, int mode)
{
    int compteurEau=0;
    int compteurElec=0;
    int compteurHab=0;
    FONT * maPolice = load_font("submariner.pcx",NULL,NULL);

    //Declaration des BITMAP
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);

    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);


    BITMAP* iconeMaison = load_bitmap("Interface/iconeMaison.bmp", NULL);
    BITMAP* iconeMaisonInv = load_bitmap("Interface/iconeMaisonInv.bmp", NULL);

    BITMAP* communiste = load_bitmap("Interface/communiste.bmp", NULL);
    BITMAP* capitaliste = load_bitmap("Interface/capitaliste.bmp", NULL);
    BITMAP* nbEau = load_bitmap("Interface/nbEau.bmp", NULL);
    BITMAP* nbEauInfos = load_bitmap("Interface/nbEauInfos.bmp", NULL);
    BITMAP* nbElec = load_bitmap("Interface/nbElec.bmp", NULL);
    BITMAP* nbElecInfos = load_bitmap("Interface/nbElecInfos.bmp", NULL);
    BITMAP* nbHab = load_bitmap("Interface/nbHab.bmp", NULL);
    BITMAP* nbHabInfos = load_bitmap("Interface/nbHabInfos.bmp", NULL);
    BITMAP* nbArgent = load_bitmap("Interface/nbArgent.bmp", NULL);
    BITMAP* nbArgentInfos = load_bitmap("Interface/nbArgentInfos.bmp", NULL);


    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);

    AffichageBouton(iconeMaison, iconeMaisonInv, page, 0,0, 920, 200, iconeMaison->w, iconeMaison->h);

    time_t tempsact = time(NULL);
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);
    unsigned long diff=difftime(tempsact,tempsdepart);
    unsigned long diffP=difftime(tempsDepartPause,tempsdepart);

    if(pause==0)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diff);
    if(pause==1)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diffP);

    if(mode==1)
    {
        masked_blit(communiste,page,0,0,920,710,communiste->w,communiste->h);
    }
    if(mode==2)
    {
        masked_blit(capitaliste,page,0,0,920,710,capitaliste->w,capitaliste->h);
    }

    textprintf_ex(page,maPolice,80,720,makecol(255,255,255),-1,"%d",argent);

    compteurHab = compterHab(map);
    compteurEau = compterEau(map);
    compteurElec = compterElec(map);

    AffichageIcone(nbEau,nbEau,nbEauInfos,page,0,0,250,715,0,10,nbEau->w,nbEau->h,nbEauInfos->w,nbEauInfos->h);
    AffichageIcone(nbElec,nbElec,nbElecInfos,page,0,0,350,715,0,10,nbElec->w,nbElec->h,nbElecInfos->w,nbElecInfos->h);
    AffichageIcone(nbHab,nbHab,nbHabInfos,page,0,0,150,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);
    AffichageIcone(nbArgent,nbArgent,nbArgentInfos,page,0,0,50,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);


    textprintf_ex(page,maPolice,180,720,makecol(255,255,255),-1,"%d",compteurHab);
    textprintf_ex(page,maPolice,280,720,makecol(255,255,255),-1,"%d",compteurEau);
    textprintf_ex(page,maPolice,380,720,makecol(255,255,255),-1,"%d",compteurElec);


}


void interfaceChateaux(BITMAP* page,time_t tempsdepart, int argent, int map[35][45],time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono, int mode)
{
    int compteurEau=0;
    int compteurElec=0;
    int compteurHab=0;
    FONT * maPolice = load_font("submariner.pcx",NULL,NULL);

    //Declaration des BITMAP
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);

    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);

    BITMAP* iconeChateauEau = load_bitmap("Interface/iconeChateauEau.bmp", NULL);
    BITMAP* iconeChateauEauInv = load_bitmap("Interface/iconeChateauEauInv.bmp",NULL);

    BITMAP* communiste = load_bitmap("Interface/communiste.bmp", NULL);
    BITMAP* capitaliste = load_bitmap("Interface/capitaliste.bmp", NULL);
    BITMAP* nbEau = load_bitmap("Interface/nbEau.bmp", NULL);
    BITMAP* nbEauInfos = load_bitmap("Interface/nbEauInfos.bmp", NULL);
    BITMAP* nbElec = load_bitmap("Interface/nbElec.bmp", NULL);
    BITMAP* nbElecInfos = load_bitmap("Interface/nbElecInfos.bmp", NULL);
    BITMAP* nbHab = load_bitmap("Interface/nbHab.bmp", NULL);
    BITMAP* nbHabInfos = load_bitmap("Interface/nbHabInfos.bmp", NULL);
    BITMAP* nbArgent = load_bitmap("Interface/nbArgent.bmp", NULL);
    BITMAP* nbArgentInfos = load_bitmap("Interface/nbArgentInfos.bmp", NULL);

    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);

    AffichageBouton(iconeChateauEau, iconeChateauEauInv,page,0,0,920,270,iconeChateauEau->w,iconeChateauEau->h);

    time_t tempsact = time(NULL);
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);
    unsigned long diff=difftime(tempsact,tempsdepart);
    unsigned long diffP=difftime(tempsDepartPause,tempsdepart);

    if(pause==0)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diff);
    if(pause==1)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diffP);

    if(mode==1)
    {
        masked_blit(communiste,page,0,0,920,710,communiste->w,communiste->h);
    }
    if(mode==2)
    {
        masked_blit(capitaliste,page,0,0,920,710,capitaliste->w,capitaliste->h);
    }

    textprintf_ex(page,maPolice,80,720,makecol(255,255,255),-1,"%d",argent);

    compteurHab = compterHab(map);
    compteurEau = compterEau(map);
    compteurElec = compterElec(map);

    AffichageIcone(nbEau,nbEau,nbEauInfos,page,0,0,250,715,0,10,nbEau->w,nbEau->h,nbEauInfos->w,nbEauInfos->h);
    AffichageIcone(nbElec,nbElec,nbElecInfos,page,0,0,350,715,0,10,nbElec->w,nbElec->h,nbElecInfos->w,nbElecInfos->h);
    AffichageIcone(nbHab,nbHab,nbHabInfos,page,0,0,150,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);
    AffichageIcone(nbArgent,nbArgent,nbArgentInfos,page,0,0,50,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);


    textprintf_ex(page,maPolice,180,720,makecol(255,255,255),-1,"%d",compteurHab);
    textprintf_ex(page,maPolice,280,720,makecol(255,255,255),-1,"%d",compteurEau);
    textprintf_ex(page,maPolice,380,720,makecol(255,255,255),-1,"%d",compteurElec);


}


void interfaceCentrales(BITMAP* page,time_t tempsdepart, int argent, int map[35][45],time_t tempsDepartPause, int pause, unsigned long tempsPause, unsigned long tempsChrono, int mode)
{
    int compteurEau=0;
    int compteurElec=0;
    int compteurHab=0;
    FONT * maPolice = load_font("submariner.pcx",NULL,NULL);
    //Declaration des BITMAP
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);

    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);

    BITMAP* iconeCentrale = load_bitmap("Interface/iconeCentrale.bmp", NULL);
    BITMAP* iconeCentraleInv = load_bitmap("Interface/iconeCentraleInv.bmp", NULL);

    BITMAP* communiste = load_bitmap("Interface/communiste.bmp", NULL);
    BITMAP* capitaliste = load_bitmap("Interface/capitaliste.bmp", NULL);
    BITMAP* nbEau = load_bitmap("Interface/nbEau.bmp", NULL);
    BITMAP* nbEauInfos = load_bitmap("Interface/nbEauInfos.bmp", NULL);
    BITMAP* nbElec = load_bitmap("Interface/nbElec.bmp", NULL);
    BITMAP* nbElecInfos = load_bitmap("Interface/nbElecInfos.bmp", NULL);
    BITMAP* nbHab = load_bitmap("Interface/nbHab.bmp", NULL);
    BITMAP* nbHabInfos = load_bitmap("Interface/nbHabInfos.bmp", NULL);
    BITMAP* nbArgent = load_bitmap("Interface/nbArgent.bmp", NULL);
    BITMAP* nbArgentInfos = load_bitmap("Interface/nbArgentInfos.bmp", NULL);

    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);

    AffichageBouton(iconeCentrale, iconeCentraleInv, page, 0, 0, 920, 380,iconeCentrale->w,iconeCentrale->h);

    time_t tempsact = time(NULL);
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);
    unsigned long diff=difftime(tempsact,tempsdepart);
    unsigned long diffP=difftime(tempsDepartPause,tempsdepart);

    if(pause==0)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diff);
    if(pause==1)
        textprintf_ex(page,maPolice,980,720,makecol(255,255,255),-1,"%d",diffP);

    if(mode==1)
    {
        masked_blit(communiste,page,0,0,920,710,communiste->w,communiste->h);
    }
    if(mode==2)
    {
        masked_blit(capitaliste,page,0,0,920,710,capitaliste->w,capitaliste->h);
    }

    textprintf_ex(page,maPolice,80,720,makecol(255,255,255),-1,"%d",argent);

    compteurHab = compterHab(map);
    compteurEau = compterEau(map);
    compteurElec = compterElec(map);

    AffichageIcone(nbEau,nbEau,nbEauInfos,page,0,0,250,715,0,10,nbEau->w,nbEau->h,nbEauInfos->w,nbEauInfos->h);
    AffichageIcone(nbElec,nbElec,nbElecInfos,page,0,0,350,715,0,10,nbElec->w,nbElec->h,nbElecInfos->w,nbElecInfos->h);
    AffichageIcone(nbHab,nbHab,nbHabInfos,page,0,0,150,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);
    AffichageIcone(nbArgent,nbArgent,nbArgentInfos,page,0,0,50,715,0,10,nbHab->w,nbHab->h,nbHabInfos->w,nbHabInfos->h);


    textprintf_ex(page,maPolice,180,720,makecol(255,255,255),-1,"%d",compteurHab);
    textprintf_ex(page,maPolice,280,720,makecol(255,255,255),-1,"%d",compteurEau);
    textprintf_ex(page,maPolice,380,720,makecol(255,255,255),-1,"%d",compteurElec);


}
