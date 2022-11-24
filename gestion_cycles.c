//
// Created by thiba on 05/11/2022.
//


#include "header.h"

void test_temps(int map[35][45], t_habitation tab_hab[50], int* argent, int nb_hab)
{
    time_t tempsact = time(NULL);
    unsigned long diff;
    int x;
    int y;
    for (int i=0; i<nb_hab; i++)
    {
        diff=difftime(tempsact,tab_hab[i].tempsCrea);
        if (diff>=15 && tab_hab[i].elec==1)
        {
            x=tab_hab[i].x;
            y=tab_hab[i].y;
            tab_hab[i].tempsCrea=time(NULL);
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

            *argent+= impots*tab_hab[i].nb_habitants;
        }
    }
}