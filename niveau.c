#include "header.h"

//Niveau -1 (Eau)
void afficher_niveau(BITMAP* page, int map[35][45],t_habitation habitation[50],int nb_maison,int** matriceEau,int nb_chateauEau,t_chateauEau tab_eau[20],t_centrales tab_elec[20], int nb_centrales)
{
    //Declarations des Bitmaps
    BITMAP* tuile = load_bitmap("Niveau/tuile_blanche.bmp",NULL);
    BITMAP* maisonGrise = load_bitmap("Niveau/maisonGrise.bmp",NULL);
    BITMAP* maisonBleue = load_bitmap("Niveau/maisonBleue.bmp",NULL);
    BITMAP* canalisations = load_bitmap("Niveau/canalisation.bmp",NULL);
    BITMAP* chateauBleu = load_bitmap("Niveau/ChateauBleu.bmp", NULL);
    BITMAP* centraleGrise = load_bitmap("Niveau/CentraleGrise.bmp", NULL);
    BITMAP* infos = load_bitmap("Interface/infos.bmp",NULL);

    int nb_chateau_maison=0;

    //Affichage des bitmaps liés au niveau -1
    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            //tuile grise du fond
            if (matriceEau[i][j] == 0) {
                blit(tuile, page, 0, 0, j*20, i*20, 20, 20);
            }
            //route alimentés => canalisations
            if (matriceEau[i][j]==1) {
                blit(canalisations, page, 0, 0, j*20, i*20, 20, 20);
            }

            //Affichage des maisons
            for (int m=0; m<nb_maison; m++) {
                nb_chateau_maison=0;
                //maison bleue, alimentées
                if (habitation[m].quantiteeEau == habitation[m].nb_habitants && habitation[m].niveau!=0) {
                    blit(maisonBleue, page, 0, 0, habitation[m].x * 20, habitation[m].y * 20, 60, 60);
                    if ((mouse_x >= (habitation[m].x * 20) && mouse_x <= (habitation[m].x * 20 + 60)) && (mouse_y) >= (habitation[m].y*20) && mouse_y <= (habitation[m].y*20 + 60))
                    {
                        stretch_blit(infos,page,0,0,infos->w,infos->h,(habitation[m].x * 20+10),(habitation[m].y * 20+10),infos->w+40,infos->h);
                        textprintf_ex(page,font,habitation[m].x * 20+20,habitation[m].y * 20+20,makecol(0,122,122),-1,"Maison %d:",habitation[m].numero);
                        textprintf_ex(page,font,habitation[m].x * 20+20,habitation[m].y * 20+30,makecol(0,122,122),-1,"%d/%d",habitation[m].quantiteeEau,habitation[m].nb_habitants);
                        for (int o=0; o<15; o++)
                        {
                            if(habitation[m].chateauEauNCR[o][0]!=-1)
                            {
                                nb_chateau_maison+=1;
                                printf("%d",nb_chateau_maison);
                                textprintf_ex(page,font,habitation[m].x * 20+20,habitation[m].y * 20+40+(5*nb_chateau_maison),makecol(0,122,122),-1,"Chateau %d :%d/%d",nb_chateau_maison,habitation[m].chateauEauNCR[o][1],habitation[m].chateauEauNCR[o][1]);
                            }
                        }
                    }
                }
                    //maison grise, pas alimentées
                else if ((habitation[m].quantiteeEau != habitation[m].nb_habitants) || habitation[m].niveau==0)
                {
                    blit(maisonGrise,page,0,0,habitation[m].x*20,habitation[m].y*20,60,60);
                }
            }
            //chateauEau
            for (int k=0; k<nb_chateauEau; k++) {
                blit(chateauBleu, page, 0, 0, tab_eau[k].x * 20, tab_eau[k].y * 20, chateauBleu->w, chateauBleu->h);
                if ((mouse_x >= (tab_eau[k].x * 20) && mouse_x <= (tab_eau[k].x * 20 + 80)) && (mouse_y) >= (tab_eau[k].y*20) && mouse_y <= (tab_eau[k].y*20 + 120))
                {
                    blit(infos,page,0,0,(tab_eau[k].x * 20+10),(tab_eau[k].y * 20+10),infos->w,infos->h);
                    textprintf_ex(page,font,tab_eau[k].x * 20+20,tab_eau[k].y * 20+20,makecol(0,122,122),-1,"Chateau %d :",k+1);
                    textprintf_ex(page,font,tab_eau[k].x * 20+20,tab_eau[k].y * 20+35,makecol(0,122,122),-1,"%d/%d",tab_eau[k].capaciteRestante,5000);
                }
            }
            //centrale grise (pas bon niveau)
            for(int l=0; l<nb_centrales; l++)
            {
                blit(centraleGrise,page,0,0,tab_elec[l].x*20,tab_elec[l].y*20,centraleGrise->w,centraleGrise->h);
            }
        }
    }
    show_mouse(page);
}

//Affichage du niveau -1 (Eau)
void canalisations (BITMAP* page, int map[35][45],t_habitation maison[50],int nb_maison,int** matriceEau,int nb_chateauEau,t_chateauEau tab_eau[20],t_centrales tab_elec[20], int nb_centrales)
{
    //Initialisation
    int clic=0;
    int type=0;

    //boucle tant qu'on reste dans le niveau -1
    while(clic!=1)
    {
        clear_bitmap(page);
        interfaceNiveau(page,type);
        //Affichage de tout ce qui est relatif au niveau eau
        afficher_niveau(page,map,maison,nb_maison,matriceEau,nb_chateauEau,tab_eau,tab_elec,nb_centrales);
        blit(page,screen,0,0,0,0,1024,768);

        //test pour sortir du niveau -1
        if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2)) {
            clic = 1;
            rest(300);
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Niveau -2 (Elec)
void afficher_niveau2(BITMAP* page, int map[35][45],t_habitation maison[50], int nb_maison,int nb_chateauEau,t_chateauEau *tab_eau,t_centrales tab_elec[20], int nb_centrales)
{
    //Declaration des bitmaps
    BITMAP* tuile = load_bitmap("Niveau/tuile_blanche.bmp",NULL);
    BITMAP* maisonGrise = load_bitmap("Niveau/maisonGrise.bmp",NULL);
    BITMAP* maisonJaune = load_bitmap("Niveau/maisonJaune.bmp",NULL);
    BITMAP* lignes = load_bitmap("Niveau/lignes.bmp",NULL);
    BITMAP* chateauGris = load_bitmap("Niveau/chateauGris.bmp", NULL);
    BITMAP* centraleJaune = load_bitmap("Niveau/CentraleJaune.bmp", NULL);
    BITMAP* infos = load_bitmap("Interface/infos.bmp",NULL);

    //boucle pour créer l'affichage du niveau elec
    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            //affichage des tuiles grises (espace pas occupé)
            if (map[i][j] == 0) {
                blit(tuile, page, 0, 0, j*20, i*20, 20, 20);
            }
            //Affichage des lignes électriques en fonction des routes
            if (map[i][j] == 1 || map[i][j] == 2) {
                blit(lignes, page, 0, 0, j*20, i*20, 20, 20);
            }
            //boucle pour afficher les maisons
            for(int k=0; k<nb_maison; k++)
            {
                //Jaune pour les maisons alimentées
                if(maison[k].elec==1 && maison[k].niveau!=0) {
                    blit(maisonJaune, page, 0, 0, maison[k].x * 20, maison[k].y * 20, maisonJaune->w, maisonJaune->h);
                    if ((mouse_x >= (maison[k].x * 20) && mouse_x <= (maison[k].x * 20 + 80)) && (mouse_y) >= (maison[k].y*20) && mouse_y <= (maison[k].y*20 + 120))
                    {
                        blit(infos,page,0,0,(maison[k].x * 20+10),(maison[k].y * 20+10),infos->w,infos->h);
                        textprintf_ex(page,font,maison[k].x * 20+20,maison[k].y * 20+20,makecol(0,122,122),-1,"Maison :");
                        textprintf_ex(page,font,maison[k].x * 20+20,maison[k].y * 20+35,makecol(0,122,122),-1,"%d/%d",maison[k].nb_habitants,maison[k].nb_habitants);
                    }
                }
                //Grise pour les maisons pas alimentées
                if(maison[k].elec==0 || maison[k].niveau==0)
                    blit(maisonGrise,page,0,0,maison[k].x*20,maison[k].y*20,maisonGrise->w,maisonGrise->h);
            }
            //boucle pour afficher les centrales
            for(int l=0; l<nb_centrales; l++)
            {
                blit(centraleJaune,page,0,0,tab_elec[l].x*20,tab_elec[l].y*20,centraleJaune->w,centraleJaune->h);
                if ((mouse_x >= (tab_elec[l].x * 20) && mouse_x <= (tab_elec[l].x * 20 + 80)) && (mouse_y) >= (tab_elec[l].y*20) && mouse_y <= (tab_elec[l].y*20 + 120))
                {
                    blit(infos,page,0,0,(tab_elec[l].x * 20+10),(tab_elec[l].y * 20+10),infos->w,infos->h);
                    textprintf_ex(page,font,tab_elec[l].x * 20+20,tab_elec[l].y * 20+20,makecol(0,122,122),-1,"Centrale %d :",l);
                    textprintf_ex(page,font,tab_elec[l].x * 20+20,tab_elec[l].y * 20+35,makecol(0,122,122),-1,"%d/%d",tab_elec[l].capaciteRestante,5000);
                }
            }

            //affichage des chateau d'eau en gris (non relatif à ce niveau)
            for (int k=0; k<nb_chateauEau; k++)
                blit(chateauGris, page, 0, 0, tab_eau[k].x*20, tab_eau[k].y*20, chateauGris->w, chateauGris->h);
        }
    }
    show_mouse(page);
}

void lignes(BITMAP* page, int map[35][45],t_habitation maison[50], int nb_maison,int nb_chateauEau,t_chateauEau *tab_eau, t_centrales tab_elec[20], int nb_centrales)
{
    //Initialisation
    int clic=0;
    int type=0;

    //boucle tant qu'on est dans le niveau -2
    while(clic!=1)
    {
        clear_bitmap(page);
        interfaceNiveau(page,type);
        //affichage de tout ce qui est nécessaire pour le niveau elec
        afficher_niveau2(page,map,maison,nb_maison,nb_chateauEau,tab_eau,tab_elec,nb_centrales);
        blit(page,screen,0,0,0,0,1024,768);

        //test pour sortir du niveau -2
        if((((mouse_x>=(970)&& mouse_x<=(970+30))&& ((mouse_y)>=(25)&& mouse_y<=(25+30)))&&(mouse_b&1))||(mouse_b &2)) {
            clic = 1;
            rest(300);
        }
    }

}

//Interface pour l'affichage des differents niveaux
void interfaceNiveau(BITMAP* page, int type)
{
    //Déclaration des BITMAP pour l'interface
    BITMAP* fondCote = load_bitmap("Interface/fondCote.bmp",NULL);
    BITMAP* fondBas = load_bitmap("Interface/fondBas.bmp", NULL);

    BITMAP* boutonQuitter = load_bitmap("Constructions/boutonQuitter.bmp", NULL);
    BITMAP* boutonQuitterInv = load_bitmap("Constructions/boutonQuitterInv.bmp", NULL);

    //Affichage de l'interface
    blit(fondCote, page, 0, 0, 900, 0, page->w, page->h);
    blit(fondBas, page, 0, 0, 0, 700, page->w, page->h);

    AffichageBouton(boutonQuitter,boutonQuitterInv,page,0,0,970,25,boutonQuitter->w,boutonQuitter->h);
}
