//
// Created by Lea on 20/11/2022.
//
#include "header.h"


void afficher_niveau(BITMAP* page, int map[35][45],int test)
{
    BITMAP* tuile = load_bitmap("Niveau/tuile_blanche.bmp",NULL);
    BITMAP* maisonGrise = load_bitmap("Niveau/maisonGrise.bmp",NULL);
    BITMAP* maisonBleue = load_bitmap("Niveau/maisonBleue.bmp",NULL);
    BITMAP* canalisations = load_bitmap("Niveau/canalisation.bmp",NULL);
    BITMAP* lignes = load_bitmap("Niveau/lignes.bmp",NULL);
    BITMAP* chateauBleu = load_bitmap("Niveau/ChateauBleu.bmp", NULL);
    BITMAP* chateauGris = load_bitmap("Niveau/chateauGris.bmp", NULL);
    BITMAP* centraleJaune = load_bitmap("Niveau/CentraleJaune.bmp", NULL);
    BITMAP* centraleGrise = load_bitmap("Niveau/CentraleGrise.bmp", NULL);

    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            //Affichage cases vertes
            if (map[i][j] == 0) {
                blit(tuile, page, 0, 0, j*20, i*20, 20, 20);
            }
            if ((map[i][j] == 1 || map[i][j] == 2) && test==1) {
                blit(canalisations, page, 0, 0, j*20, i*20, 20, 20);
            }
            if ((map[i][j] == 1 || map[i][j] == 2) && test==2) {
                blit(lignes, page, 0, 0, j*20, i*20, 20, 20);
            }
            if (map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5 || map[i][j] == 6 || map[i][j] == 7)
            {
                blit(maisonBleue,page,0,0,j*20,i*20,60,60);
            }
            if (map[i][j] == 14 && test==1) {
                blit(chateauBleu, page, 0, 0, j*20, i*20, chateauBleu->w, chateauBleu->h);
            }
            if (map[i][j] == 14 && test==2) {
                blit(chateauGris, page, 0, 0, j*20, i*20, chateauGris->w, chateauGris->h);
            }
            if (map[i][j] == 15 && test==2) {
                blit(centraleJaune, page, 0, 0, j*20, i*20, centraleJaune->w, centraleJaune->h);
            }
            if (map[i][j] == 15 && test==1) {
                blit(centraleGrise, page, 0, 0, j*20, i*20, centraleGrise->w, centraleGrise->h);
            }
        }

    }

    show_mouse(page);
}


void canalisations (BITMAP* page, int map[35][45])
{
    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);

    int clic=0;
    int type=0;
    int test=1;

    while(clic!=1)
    {
        clear_bitmap(page);
        interfaceNiveau(page,type);
        afficher_niveau(page,map,test);
        blit(page,screen,0,0,0,0,1024,768);

        if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2)) {
            clic = 1;
            rest(300);
        }
    }

}

void lignes(BITMAP* page, int map[35][45])
{
    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);

    int clic=0;
    int type=0;
    int test=2;

    while(clic!=1)
    {
        clear_bitmap(page);
        interfaceNiveau(page,type);
        afficher_niveau(page,map,test);
        blit(page,screen,0,0,0,0,1024,768);

        if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2)) {
            clic = 1;
            rest(300);
        }
    }

}

void interfaceNiveau(BITMAP* page, int type)
{
    //Initialisation
    int compteurEau=0;

    //Déclaration des BITMAP pour l'interface
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);

    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);

    BITMAP* infosChateau = load_bitmap("Constructions/infosRoute.bmp", NULL);
    BITMAP* routeIcone = load_bitmap("Constructions/routeIcone.bmp", NULL);
    BITMAP* routeVertiIcone = load_bitmap("Constructions/routeVertiIcone.bmp", NULL);
    BITMAP* routeTran = load_bitmap("Constructions/routeTran.bmp", NULL);
    BITMAP* routeVertiTran = load_bitmap("Constructions/routeVertiTran.bmp", NULL);

    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);

    blit(infosChateau, page, 0,0,910,120,infosChateau->w,infosChateau->h);

}
