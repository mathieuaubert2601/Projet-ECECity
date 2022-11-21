#include "header.h"

void creer_map(BITMAP* page, int map[35][45])
{
    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            map[i][j]=0;
        }
    }

    map[0][22]=2;
}

void afficher_matrice_cases_vertes(BITMAP* page)
{
    BITMAP* tuile = load_bitmap("map/tuile_verte.bmp",NULL);
    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            masked_stretch_blit(tuile, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
        }
    }
}


void afficher_map(BITMAP* page, int map[35][45])
{
    BITMAP* tuile = load_bitmap("map/tuile_verte.bmp",NULL);
    //BITMAP* maison = load_bitmap("map/maison.bmp",NULL);
    BITMAP* route = load_bitmap("Constructions/route.bmp",NULL);
    BITMAP* routeVerti = load_bitmap("Constructions/routeVerti.bmp", NULL);
    BITMAP* chateauEau = load_bitmap("Constructions/ChateauEau.bmp", NULL);
    BITMAP* centrale = load_bitmap("Constructions/centrale.bmp", NULL);
    BITMAP* terrain_vague = load_bitmap("Constructions/terrain_vague.bmp", NULL);
    BITMAP* cabane = load_bitmap("Constructions/cabane.bmp", NULL);
    BITMAP* maison = load_bitmap("Constructions/maison.bmp", NULL);
    BITMAP* immeuble = load_bitmap("Constructions/immeuble.bmp", NULL);
    BITMAP* gratte_ciel = load_bitmap("Constructions/gratte_ciel.bmp", NULL);

    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            //Affichage cases vertes
            if (map[i][j] == 0) {
                masked_stretch_blit(tuile, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
            }
                //Affichage routes horizontales
            else if(map[i][j] == 1)
            {
                blit(route,page,0,0,j*20,i*20,route->w,route->h);
            }
            else if(map[i][j] == 2)
            {
                blit(routeVerti,page,0,0,j*20,i*20,routeVerti->w,routeVerti->h);
            }
            else if(map[i][j] == 3)
            {
                blit(terrain_vague,page,0,0,j*20,i*20,terrain_vague->w,terrain_vague->h);
            }
                //Affichage cabane
            else if(map[i][j] == 4)
            {
                masked_blit(cabane,page,0,0,j*20,i*20,cabane->w,cabane->h);

            }
                //Affichage maison
            else if(map[i][j] == 5)
            {
                masked_blit(maison,page,0,0,j*20,i*20,terrain_vague->w,terrain_vague->h);
            }
                //Affichage immeuble
            else if(map[i][j] == 6)
            {
                masked_blit(immeuble,page,0,0,j*20,i*20,terrain_vague->w,terrain_vague->h);
            }
                //Affichage gratte ciel
            else if(map[i][j] == 7)
            {
                masked_blit(gratte_ciel,page,0,0,j*20,i*20,terrain_vague->w,terrain_vague->h);
            }
                //Case libre pour affichage terrain vague
            else if(map[i][j] == 9)
            {

            }
                //Case libre pour affichage cabane
            else if(map[i][j] == 10)
            {

            }
                //Case libre pour affichage maison
            else if(map[i][j] == 11)
            {

            }
                //Case libre pour affichage immeuble
            else if(map[i][j] == 12)
            {

            }
                //Case libre pour affichage gratte ciel
            else if(map[i][j] == 13)
            {

            }
                //Afficher chateau d'eau
            else if(map[i][j] == 14)
            {
                blit(chateauEau,page,0,0,j*20,i*20,chateauEau->w,chateauEau->h);
            }
                //Afficher centrale
            else if(map[i][j] == 15)
            {
                blit(centrale,page,0,0,j*20,i*20,centrale->w,centrale->h);
            }
                //Case libre pour affichage chateau d'eau
            else if(map[i][j] == 16)
            {

            }
                //Case libre pour affichage centrale
            else if(map[i][j] == 17)
            {

            }
            else
            {
                masked_stretch_blit(tuile, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
            }
        }
    }

    show_mouse(page);
    //blit(page,screen,0,0,0,0,1024,768);
}

void lireFichierMap(int matrice_a_remplir[35][45],char* nomFichier)
{
    //déclaration des variables
    FILE* fichier_a_lire = fopen(nomFichier,"r");
    int caractere_du_fichier,caractere_du_fichier_prec = ' ';
    int i = 0, j = 0;

    //test d'ouverture du fichier
    if(fichier_a_lire == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    //lecture dans le fichier
    do
    {
        //On récupère le caractère dans le fichier
        caractere_du_fichier = fgetc(fichier_a_lire);
        if(caractere_du_fichier != EOF) //On met le caractère dans la matrice à remplir
        {
            if(caractere_du_fichier == '0')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 0;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 10;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 20;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 10;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 20;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '1')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 1;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 11;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 21;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 11;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 21;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '2')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 2;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 12;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 22;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 12;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 22;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '3')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 3;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 13;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 23;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 13;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 23;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '4')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 4;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 14;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 24;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 14;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 24;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '5')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 5;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 15;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 25;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 15;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 25;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '6')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 6;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 16;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 26;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 16;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 26;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '7')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 7;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 17;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 27;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 17;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 27;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '8')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 8;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 18;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 28;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 18;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 28;
                        }
                    }

                }
            }
            else if (caractere_du_fichier == '9')
            {
                if(caractere_du_fichier_prec == ' ' ||caractere_du_fichier_prec == '\n' )
                {
                    matrice_a_remplir[i][j] = 9;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        if(matrice_a_remplir[i-1][44] == 1)
                        {
                            matrice_a_remplir[i-1][44] = 19;
                        }
                        else if(matrice_a_remplir[i-1][44] == 2)
                        {
                            matrice_a_remplir[i-1][44] = 29;
                        }

                    }
                    else
                    {
                        if(matrice_a_remplir[i][j-1] == 1)
                        {
                            matrice_a_remplir[i][j-1] = 19;
                        }
                        else if(matrice_a_remplir[i][j-1] == 2)
                        {
                            matrice_a_remplir[i][j-1] = 29;
                        }
                    }

                }
            }
            if(j == 45) {
                j = 0;
                i++;
            }
        }
        caractere_du_fichier_prec = caractere_du_fichier;
    }
    while(caractere_du_fichier != EOF);

    //On ferme le fichier
    fclose(fichier_a_lire);
    fichier_a_lire = NULL;
}