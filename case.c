#include "header.h"

void affichagecasefree(BITMAP* page,int map[35][45],int type,int rotation)
{
    BITMAP* tuilelibre = load_bitmap("map/tuile_test.bmp",NULL);
    int value;
    int matricelibre[35][45];
    for (int i=0 ; i<=35; i++)
    {
        for(int j=0;j<=45; j++)
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
        for (int i=0 ; i<=35; i++)
        {
            for(int j=0;j<=45; j++)
            {
                if(matricelibre[i][j]==0)
                {
                    masked_stretch_blit(tuilelibre, page, 0, 0, 77, 77, j * 20, i * 20, 20, 20);
                }
            }
        }
    }
    if(type==3)
    {
        for (int i=0 ; i<=35; i++)
        {
            for(int j=0;j<=45; j++)
            {
                if(matricelibre[i][j]==0 && matricelibre[i+1][j] && matricelibre[i+1][j+1] && matricelibre[i+1][j-1] && matricelibre[i][j+1] && matricelibre[i][j-1] && matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j-1]==0)
                {
                    masked_stretch_blit(tuilelibre, page, 0, 0, 77, 77, j * 20, i * 20, 20, 20);
                }
            }
        }
    }
    if((type==4 || type==5)&& rotation==0)
    {
        for (int i=0 ; i<=35; i++)
        {
            for(int j=0;j<=45; j++)
            {
                if(matricelibre[i][j]==0 && matricelibre[i+1][j]==0 && matricelibre[i+2][j]==0 && matricelibre[i+3][j]==0 && matricelibre[i][j-1]==0 && matricelibre[i+1][j-1]==0 && matricelibre[i+1][j-1]==0 && matricelibre[i+3][j-1]==0 && matricelibre[i][j-2]==0 && matricelibre[i+1][j-2]==0 && matricelibre[i+2][j-2]==0 && matricelibre[i+3][j-2]==0 && matricelibre[i][j-3]==0 &&  matricelibre[i+1][j-3]==0 && matricelibre[i+2][j-3]==0 && matricelibre[i+3][j-3]==0 && matricelibre[i][j-4]==0 && matricelibre[i+1][j-4]==0 && matricelibre[i+2][j-4]==0 && matricelibre[i+3][j-4]==0 && matricelibre[i][j-5]==0 &&matricelibre[i+1][j-5]==0 && matricelibre[i+2][j-5]==0 && matricelibre[i+3][j-5]==0)
                {
                    masked_stretch_blit(tuilelibre, page, 0, 0, 77, 77, j * 20, i * 20, 20, 20);
                }
            }
        }
    }
    if((type==4 || type==5)&& rotation==1)
    {
        for (int i=0 ; i<=35; i++)
        {
            for(int j=0;j<=45; j++)
            {
                if(matricelibre[i][j]==0 && matricelibre[i+1][j]==0 && matricelibre[i+2][j]==0 && matricelibre[i+3][j]==0 && matricelibre[i+4][j]==0 && matricelibre[i+5][j]==0 && matricelibre[i][j-1]==0 && matricelibre[i+1][j-1]==0 && matricelibre[i+2][j-1]==0 && matricelibre[i+3][j-1]==0 && matricelibre[i+4][j-1]==0 && matricelibre[i+5][j-1]==0 && matricelibre[i][j-2]==0 && matricelibre[i+1][j-2]==0 && matricelibre[i+2][j-2]==0 && matricelibre[i+3][j-2]==0 && matricelibre[i+4][j-2]==0 && matricelibre[i+5][j-2]==0 && matricelibre[i][j-3]==0 && matricelibre[i+1][j-3]==0 && matricelibre[i+2][j-3]==0 && matricelibre[i+3][j-3]==0 && matricelibre[i+4][j-3]==0 && matricelibre[i+5][j-3]==0)
                {
                    masked_stretch_blit(tuilelibre, page, 0, 0, 77, 77, j * 20, i * 20, 20, 20);
                }
            }
        }
    }


}