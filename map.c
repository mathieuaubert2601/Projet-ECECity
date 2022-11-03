#include "header.h"

void creer_map(BITMAP* page, int map[35][45])
{
    BITMAP* tuile = load_bitmap("map/tuile_test.bmp",NULL);
    BITMAP* maison = load_bitmap("map/maison.bmp",NULL);
    BITMAP* route = load_bitmap("map/route.bmp",NULL);

    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            if (map[i][j] == 0) {
                masked_stretch_blit(tuile, page, 0, 0, 77, 77, j * 20, i * 20, 20, 20);
            }
            else if(map[i][j] == 1)
            {
                blit(route,page,0,0,j*20,i*20,maison->w,maison->h);
            }
            else if(map[i][j] == 3)
            {
                blit(maison,page,0,0,j*20,i*20,maison->w,maison->h);
            }
            else if(map[i][j] == 9)
            {

            }
            else if(map[i][j] == 5)
            {

            }
            else
            {
                masked_stretch_blit(tuile, page, 0, 0, 77, 77, j * 20, i * 20, 20, 20);
            }
        }
    }

    show_mouse(page);
    blit(page,screen,0,0,0,0,1024,768);
}

void lireFichierMap(int matrice_a_remplir[35][45],char* nomFichier)
{
    //déclaration des variables
    FILE* fichier_a_lire = fopen(nomFichier,"r");
    int caractere_du_fichier;
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
                matrice_a_remplir[i][j] = 0;
                j++;

            }
            else if (caractere_du_fichier == '1')
            {
                matrice_a_remplir[i][j] = 1;
                j++;
            }
            else if (caractere_du_fichier == '3')
            {
                matrice_a_remplir[i][j] = 3;
                j++;
            }
            else if (caractere_du_fichier == '4')
            {
                matrice_a_remplir[i][j] = 4;
                j++;
            }
            else if (caractere_du_fichier == '5')
            {
                matrice_a_remplir[i][j] = 5;
                j++;
            }
            else if (caractere_du_fichier == '6')
            {
                matrice_a_remplir[i][j] = 6;
                j++;
            }
            else if (caractere_du_fichier == '7')
            {
                matrice_a_remplir[i][j] = 7;
                j++;
            }
            else if (caractere_du_fichier == '8')
            {
                matrice_a_remplir[i][j] = 8;
                j++;
            }
            else if (caractere_du_fichier == '9')
            {
                matrice_a_remplir[i][j] = 9;
                j++;
            }
            if(j == 45)
            {
                j=0;
                i++;
            }
        }
    }
    while(caractere_du_fichier != EOF);

    //On ferme le fichier
    fclose(fichier_a_lire);
    fichier_a_lire = NULL;
}
