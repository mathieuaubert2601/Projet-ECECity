#include "header.h"

void affichagecasefree(BITMAP* page,int map[35][45],int type) // sspg analysant les espaces libres et la connexité au routes
{
    BITMAP* tuile_surbrillance = load_bitmap("map/tuile_surbrillance.bmp",NULL);
    show_mouse(page);
    int value;
    int matricelibre[35][45];

    for (int i=0 ; i<35; i++)// ici on créé un double de la matice et on lit la map pour mieux travailler cette derniere
    {
        for(int j=0;j<45; j++)
        {
            matricelibre[i][j]=1;// on initialise tout a 1, comme ci les cases etait occupé
            if(map[i][j]==0)// si la case est libre
            {
                matricelibre[i][j]=0;// le doublon est difini comme libre
            }
        }
    }

    if(type==1)// si le type de batiment saisi est une route
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<45; j++)
            {
                if(matricelibre[i][j] == 0)// si la case est libre
                {
                    if((i + 1) <35)
                    {
                        if(map[i + 1][j] == 1 || map[i + 1][j] == 2)// on verifie si il ya une route en dessous
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);//on affiche la tuile libre en surbrillance
                        }
                    }
                    if(i - 1 >= 0)
                    {
                        if(map[i - 1][j] == 1 || map[i - 1][j] == 2)// on verifie si il ya une route au dessus
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);//on affiche la tuile libre en surbrillance
                        }
                    }
                    if((j + 1) < 45)
                    {
                        if(map[i][j+1] == 1 || map[i][j+1] == 2)// on verifie si il ya une route a droite
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);//on affiche la tuile libre en surbrillance
                        }
                    }
                    if(j - 1 >= 0)
                    {
                        if(map[i][j-1] == 1 || map[i][j-1] == 2) // on verifie si il ya une route a gauche
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);//on affiche la tuile libre en surbrillance
                        }
                    }

                }
            }
        }
    }
    if(type==3)// si le batiment est une maison
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<43; j++)
            {
                if((matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 &&
                    matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 &&
                    matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0))// on verifie que l'espace/ l'aire nécessaire au batiment est libre
                {
                    // ensuite on verie qu'une case du perimetre or les angles pour pas de connexité en diagonale soit une route
                    if((i + 1) <35)
                    {
                        if(map[i + 1][j] == 1 || map[i + 1][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i + 1) <35 && (j+1)<45)
                    {
                        if(map[i + 1][j+1] == 1 || map[i + 1][j+1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i + 1) <35 && (j+2)<45)
                    {
                        if(map[i + 1][j+2] == 1 || map[i + 1][j+2] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if( (j+3)<45)
                    {
                        if(map[i ][j+3] == 1 || map[i][j+3] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i - 1) >=0 && (j+3)<45)
                    {
                        if(map[i - 1][j+3] == 1 || map[i -1][j+3] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i - 2) >=0 && (j+3)<45)
                    {
                        if(map[i - 2][j+3] == 1 || map[i -2][j+3] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i - 3) >=0 && (j+2)<45)
                    {
                        if(map[i - 3][j+2] == 1 || map[i -3][j+2] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i - 3) >=0 && (j+1)<45)
                    {
                        if(map[i - 3][j+1] == 1 || map[i -3][j+1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i - 3) >=0)
                    {
                        if(map[i - 3][j] == 1 || map[i -3][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i - 2) >=0 && (j-1)>=0)
                    {
                        if(map[i - 2][j-1] == 1 || map[i -2][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i - 1) >=0 && (j-1)>=0)
                    {
                        if(map[i - 1][j-1] == 1 || map[i -1][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((j-1)>=0)
                    {
                        if(map[i][j-1] == 1 || map[i][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }

                }
            }
        }
    }
    if(type==14)// si le batiment est un chateau d'eau
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<42; j++)
            {
                if(matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 && matricelibre[i][j+3]==0 &&
                   matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 && matricelibre[i-1][j+3]==0 &&
                   matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0 && matricelibre[i-2][j+3]==0 &&
                   matricelibre[i-3][j]==0 && matricelibre[i-3][j+1]==0 && matricelibre[i-3][j+2]==0 && matricelibre[i-3][j+3]==0 &&
                   matricelibre[i-4][j]==0 && matricelibre[i-4][j+1]==0 && matricelibre[i-4][j+2]==0 && matricelibre[i-4][j+3]==0 &&
                   matricelibre[i-5][j]==0 && matricelibre[i-5][j+1]==0 && matricelibre[i-5][j+2]==0 && matricelibre[i-5][j+3]==0)// on verifie que l'espace/ l'aire nécessaire au batiment est libre
                {// ensuite on verie qu'une case du perimetre or les angles pour pas de connexité en diagonale soit une route
                    if((i+1) <35 && (j)>=0)
                    {
                        if(map[i+1][j] == 1 || map[i+1][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i+1) <35 && (j+1)<45)
                    {
                        if(map[i+1][j+1] == 1 || map[i+1][j+1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i+1) <35 && (j+2)<45)
                    {
                        if(map[i+1][j+2] == 1 || map[i+1][j+2] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i+1) <35 && (j+3)<45)
                    {
                        if(map[i+1][j+3] == 1 || map[i+1][j+3] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i) <35 && (j+4)<45)
                    {
                        if(map[i][j+4] == 1 || map[i][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-1) >=0 && (j+4)<45)
                    {
                        if(map[i-1][j+4] == 1 || map[i-1][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-2) >=0 && (j+4)<45)
                    {
                        if(map[i-2][j+4] == 1 || map[i-2][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-3) >=0 && (j+4)<45)
                    {
                        if(map[i-3][j+4] == 1 || map[i-3][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j+4)<45)
                    {
                        if(map[i-4][j+4] == 1 || map[i-4][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-5) >=0 && (j+4)<45)
                    {
                        if(map[i-5][j+4] == 1 || map[i-5][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-6) >=0 && (j+3)<45)
                    {
                        if(map[i-6][j+3] == 1 || map[i-6][j+3] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-6) >=0 && (j+2)<45)
                    {
                        if(map[i-6][j+2] == 1 || map[i-6][j+2] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-6) >=0 && (j+1)<45)
                    {
                        if(map[i-6][j+1] == 1 || map[i-6][j+1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-6) >=0 )
                    {
                        if(map[i-6][j] == 1 || map[i-6][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-5) >=0 && (j-1)>=0)
                    {
                        if(map[i-5][j-1] == 1 || map[i-5][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j-1)>=0)
                    {
                        if(map[i-4][j-1] == 1 || map[i-4][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-3) >=0 && (j-1)>=0)
                    {
                        if(map[i-3][j-1] == 1 || map[i-3][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-2) >=0 && (j-1)>=0)
                    {
                        if(map[i-2][j-1] == 1 || map[i-2][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-1) >=0 && (j-1)>=0)
                    {
                        if(map[i-1][j-1] == 1 || map[i-1][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((j-1)>=0)
                    {
                        if(map[i][j-1] == 1 || map[i][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }

                }
            }
        }
    }
    if(type==15) // si le batiment est une centrale electrique
    {
        for (int i=4 ; i<34; i++)
        {
            for(int j=0;j<40; j++)
            {// on verifie que l'espace/ l'aire nécessaire au batiment est libre
                if(matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 && matricelibre[i][j+3]==0 && matricelibre[i][j+4]==0 && matricelibre[i][j+5]==0 &&
                   matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 && matricelibre[i-1][j+3]==0 && matricelibre[i-1][j+4]==0 && matricelibre[i-1][j+5]==0 &&
                   matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0 && matricelibre[i-2][j+3]==0 && matricelibre[i-2][j+4]==0 && matricelibre[i-2][j+5]==0 &&
                   matricelibre[i-3][j]==0 && matricelibre[i-3][j+1]==0 && matricelibre[i-3][j+2]==0 && matricelibre[i-3][j+3]==0 && matricelibre[i-3][j+4]==0 && matricelibre[i-3][j+5]==0 )

                {// ensuite on verie qu'une case du perimetre or les angles pour pas de connexité en diagonale soit une route
                    if((i+1) <35 && (j)>=0)
                    {
                        if(map[i+1][j] == 1 || map[i+1][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i+1) <35 && (j+1)<45)
                    {
                        if(map[i+1][j+1] == 1 || map[i+1][j+1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }if((i+1) <35 && (j+2)<45)
                    {
                        if(map[i+1][j+2] == 1 || map[i+1][j+2] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }if((i+1) <35 && (j+3)<45)
                    {
                        if(map[i+1][j+3] == 1 || map[i+1][j+3] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }if((i+1)<35 && (j+4)>=0)
                    {
                        if(map[i+1][j+4] == 1 || map[i+1][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }if((i+1) <35 && (j+5)<45)
                    {
                        if(map[i+1][j+5] == 1 || map[i+1][j+5] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i) >=0 && (j+6)<45)
                    {
                        if(map[i][j+6] == 1 || map[i][j+6] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-1) >=0 && (j+6)<45)
                    {
                        if(map[i-1][j+6] == 1 || map[i-1][j+6] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-2) >=0 && (j+6)<45)
                    {
                        if(map[i-2][j+6] == 1 || map[i-2][j+6] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-3) >=0 && (j+6)<45)
                    {
                        if(map[i-3][j+6] == 1 || map[i-3][j+6] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j+5)<45)
                    {
                        if(map[i-4][j+5] == 1 || map[i-4][j+5] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j+4)<45)
                    {
                        if(map[i-4][j+4] == 1 || map[i-4][j+4] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j+3)<45)
                    {
                        if(map[i-4][j+3] == 1 || map[i-4][j+3] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j+2)<45)
                    {
                        if(map[i-4][j+2] == 1 || map[i-4][j+2] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j+1)<45)
                    {
                        if(map[i-4][j+1] == 1 || map[i-4][j+1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-4) >=0 && (j)<45)
                    {
                        if(map[i-4][j] == 1 || map[i-4][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-3) >=0 && (j-1)>=0)
                    {
                        if(map[i-3][j-1] == 1 || map[i-3][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-2) >=0 && (j-1)>=0)
                    {
                        if(map[i-2][j-1] == 1 || map[i-2][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i-1) >=0 && (j-1)>=0)
                    {
                        if(map[i-1][j-1] == 1 || map[i-1][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((i) >=0 && (j-1)>=0)
                    {
                        if(map[i][j-1] == 1 || map[i][j-1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                }
            }
        }
    }
    show_mouse(page);
    //blit(page,screen,0,0,0,0,900,700);
}