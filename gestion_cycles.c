//
// Created by thiba on 05/11/2022.
//


#include "header.h"

void test_temps(int map[35][45], t_habitation tab_hab[50], int* argent, int nb_hab, int nb_elec, t_centrales tab_elec[20])
{
    time_t tempsact = time(NULL);
    unsigned long diff;
    int x;
    int y;
    for (int i=0; i<nb_hab; i++)
    {
        int avant=0,apres=0;
        diff=difftime(tempsact,tab_hab[i].tempsCrea);
        if (diff>=15)
        {
            x=tab_hab[i].x;
            y=tab_hab[i].y;
            tab_hab[i].tempsCrea=time(NULL);
            if(tab_hab[i].elec==1)
            {
                if(tab_hab[i].niveau<4)
                {
                    tab_hab[i].niveau++;
                    map[y][x]++;
                }
                if(tab_hab[i].niveau==1)
                    tab_hab[i].nb_habitants=10;
                if(tab_hab[i].niveau==2)
                    tab_hab[i].nb_habitants=50;
                if(tab_hab[i].niveau==3)
                    tab_hab[i].nb_habitants=100;
                if(tab_hab[i].niveau==4)
                    tab_hab[i].nb_habitants=1000;
                apres=distribution(nb_elec,nb_hab,tab_elec,tab_hab);
                if (tab_hab[i].elec!=1)
                {
                    if(tab_hab[i].niveau>0)
                    {
                        tab_hab[i].niveau--;
                        map[y][x]--;
                    }
                    if(tab_hab[i].niveau==0)
                        tab_hab[i].nb_habitants=0;
                    if(tab_hab[i].niveau==1)
                        tab_hab[i].nb_habitants=10;
                    if(tab_hab[i].niveau==2)
                        tab_hab[i].nb_habitants=50;
                    if(tab_hab[i].niveau==3)
                        tab_hab[i].nb_habitants=100;
                    if(tab_hab[i].niveau==4)
                        tab_hab[i].nb_habitants=1000;
                }
            }
            if (tab_hab[i].elec==0)
            {
                if(tab_hab[i].niveau>0)
                {
                    tab_hab[i].niveau--;
                    map[y][x]--;
                }
                if(tab_hab[i].niveau==0)
                    tab_hab[i].nb_habitants=0;
                if(tab_hab[i].niveau==1)
                    tab_hab[i].nb_habitants=10;
                if(tab_hab[i].niveau==2)
                    tab_hab[i].nb_habitants=50;
                if(tab_hab[i].niveau==3)
                    tab_hab[i].nb_habitants=100;
                if(tab_hab[i].niveau==4)
                    tab_hab[i].nb_habitants=1000;
            }
            distribution(nb_elec,nb_hab,tab_elec,tab_hab);
            *argent+= impots*tab_hab[i].nb_habitants;
        }
    }
}