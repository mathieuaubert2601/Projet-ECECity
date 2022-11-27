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
                if(matricelibre[i][j] == 0)
                {
                    if((i + 1) <35)
                    {
                        if(map[i + 1][j] == 1 || map[i + 1][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if(i - 1 >= 0)
                    {
                        if(map[i - 1][j] == 1 || map[i - 1][j] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if((j + 1) < 45)
                    {
                        if(map[i][j+1] == 1 || map[i][j+1] == 2)
                        {
                            masked_stretch_blit(tuile_surbrillance, page, 0, 0, 20, 20, j * 20, i * 20, 20, 20);
                        }
                    }
                    if(j - 1 >= 0)
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
    if(type==3)
    {
        for (int i=0 ; i<35; i++)
        {
            for(int j=0;j<43; j++)
            {
                if((matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 &&
                    matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 &&
                    matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0))
                {
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
                   matricelibre[i-5][j]==0 && matricelibre[i-5][j+1]==0 && matricelibre[i-5][j+2]==0 && matricelibre[i-5][j+3]==0)
                {
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
    if(type==15)
    {
        for (int i=4 ; i<34; i++)
        {
            for(int j=0;j<40; j++)
            {
                if(matricelibre[i][j]==0 && matricelibre[i][j+1]==0 && matricelibre[i][j+2]==0 && matricelibre[i][j+3]==0 && matricelibre[i][j+4]==0 && matricelibre[i][j+5]==0 &&
                   matricelibre[i-1][j]==0 && matricelibre[i-1][j+1]==0 && matricelibre[i-1][j+2]==0 && matricelibre[i-1][j+3]==0 && matricelibre[i-1][j+4]==0 && matricelibre[i-1][j+5]==0 &&
                   matricelibre[i-2][j]==0 && matricelibre[i-2][j+1]==0 && matricelibre[i-2][j+2]==0 && matricelibre[i-2][j+3]==0 && matricelibre[i-2][j+4]==0 && matricelibre[i-2][j+5]==0 &&
                   matricelibre[i-3][j]==0 && matricelibre[i-3][j+1]==0 && matricelibre[i-3][j+2]==0 && matricelibre[i-3][j+3]==0 && matricelibre[i-3][j+4]==0 && matricelibre[i-3][j+5]==0 )

                {
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