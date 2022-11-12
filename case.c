#include "header.h"

void affichagecasefree(BITMAP* page,int map[35][45],int type)
{
    BITMAP* tuile_surbrillance = load_bitmap("map/tuile_surbrillance.bmp",NULL);
    show_mouse(page);
    int value;
    int matricelibre[35][45];

    for (int i=0 ; i<35; i++)
    {
        for(int j=0;j<45; j++)
        {
            matricelibre[i][j]=1;
            if(map[i][j]==0)
            {
                matricelibre[i][j]=0;
            }
        }

    }

    if(type==1)
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<45; j++)
            {
                if(matricelibre[i][j]==0 &&
                (map[i+1][j]==1 || map[i+1][j+1]==1 || map[i+1][j-1]==1 ||
                map[i-1][j]==1 || map[i-1][j-1]==1 || map[i-1][j+1]==1 ||
                map[i][j+1]==1 || map[i][j-1]==1) )
                {
                    masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                }
            }
        }
    }
    if(type==3)
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<45; j++)
            {
                if((matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 &&
                matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 &&
                matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0) &&
                ( map[i+1][j-1]==1 || map[i+1][j]==1 || map[i+1][j+1]==1 || map[i+1][j+2]==1 ||
                map[i+1][j+3]==1 || map[i][j+3]==1 || map[i-1][j+3]==1 || map[i-2][j+3]==1 ||
                map[i-3][j+3]==1 || map[i-3][j+2]==1 || map[i-3][j+1]==1 || map[i-3][j]==1 ||
                map[i-3][j-1]==1 || map[i-2][j-1]==1 || map[i-1][j-1]==1 || map[i][j]-1==1) )
                {
                    masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                }
            }
        }
    }
    if(type==14)
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<45; j++)
            {
                if(matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 && matricelibre[i][j+3]==0 &&
                matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 && matricelibre[i-1][j+3]==0 &&
                matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0 && matricelibre[i-2][j+3]==0 &&
                matricelibre[i-3][j]==0 && matricelibre[i-3][j+1]==0 && matricelibre[i-3][j+2]==0 && matricelibre[i-3][j+3]==0 &&
                matricelibre[i-4][j]==0 && matricelibre[i-4][j+1]==0 && matricelibre[i-4][j+2]==0 && matricelibre[i-4][j+3]==0 &&
                matricelibre[i-5][j]==0 && matricelibre[i-5][j+1]==0 && matricelibre[i-5][j+2]==0 && matricelibre[i-5][j+3]==0 &&
                ( map[i+1][j-1]==1 || map[i+1][j]==1 || map[i+1][j+1]==1 || map[i+1][j+2]==1 || map[i+1][j+3]==1 ||
                map[i+1][j+4]==1 || map[i][j+4]==1 || map[i-1][j+4]==1 || map[i-2][j+4]==1 || map[i-3][j+4]==1 || map[i-4][j+4]==1 || map[i-5][j+4]==1 ||
                map[i-6][j+4]==1 || map[i-6][j+3]==1|| map[i-6][j+2]==1 || map[i-6][j+1]==1 || map[i-6][j]==1 ||
                map[i-6][j-1]==1 || map[i-5][j-1]==1 || map[i-4][j-1]==1 || map[i-3][j-1]==1 || map[i-2][j-1]==1 || map[i-1][j-1]==1 || map[i][j-1]==1))
                {
                    masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                }
            }
        }
    }
    if(type==15)
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<45; j++)
            {
                if(matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 && matricelibre[i][j+3]==0 && matricelibre[i][j+4]==0 && matricelibre[i][j+5]==0 &&
                matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 && matricelibre[i-1][j+3]==0 && matricelibre[i-1][j+4]==0 && matricelibre[i-1][j+5]==0 &&
                matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0 && matricelibre[i-2][j+3]==0 && matricelibre[i-2][j+4]==0 && matricelibre[i-2][j+5]==0 &&
                matricelibre[i-3][j]==0 && matricelibre[i-3][j+1]==0 && matricelibre[i-3][j+2]==0 && matricelibre[i-3][j+3]==0 && matricelibre[i-3][j+4]==0 && matricelibre[i-3][j+5]==0 &&
                ( map[i+1][j-1]==1 || map[i+1][j]==1 || map[i+1][j+1]==1 || map[i+1][j+2]==1 || map[i+1][j+3]==1 || map[i+1][j+4]==1 || map[i+1][j+5]==1 ||
                map[i+1][j+6]==1 || map[i][j+6]==1 || map[i-1][j+6]==1 || map[i-2][j+6]==1 || map[i-3][j+6]==1 ||
                map[i-4][j+6]==1 || map[i-4][j+5]==1 || map[i-4][j+4]==1 || map[i-4][j+3]==1 || map[i-4][j+2]==1 || map[i-4][j+1]==1 || map[i-4][j]==1 ||
                map[i-4][j-1]==1 || map[i-3][j-1]==1 || map[i-2][j-1]==1 || map[i-1][j-1]==1 || map[i][j-1]==1))
                {
                    masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                }
            }
        }
    }

    show_mouse(page);
    blit(page,screen,0,0,0,0,900,700);
}