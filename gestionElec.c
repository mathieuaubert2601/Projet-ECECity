#include "header.h"
int calculCapaciteElec(int nb_elec)
{
    int total = nb_elec*5000;
    return total;
}

void distribution(int nb_elec, int nb_hab, t_centrales tab_elec[20], t_habitation tab_hab[50])
{
    for (int e=0; e<nb_elec; e++)
    {
        tab_elec[e].capaciteRestante=5000;
    }

    for (int h=0; h<nb_hab; h++)
    {
        tab_hab[h].elec=0;
    }

    for (int i=0;i<nb_elec;i++)
    {
        int j=0;
        do {
            if ((tab_elec[i].capaciteRestante>=tab_hab[j].nb_habitants) && (tab_hab[j].elec==0))
            {
                tab_hab[j].elec=1;
                tab_elec[i].capaciteRestante-=tab_hab[j].nb_habitants;
            }
            j++;
        }while(j<nb_hab);
    }
    for(int p=0;p<nb_elec;p++)
    {
        printf("\n\n%d : %d ",p,tab_elec[p].capaciteRestante);
    }
}


int test_distribution(int nb_elec, int nb_hab, t_centrales tab_elec[20], t_habitation tab_hab[50])
{
    int somme=0;
    for (int e=0; e<nb_elec; e++)
    {
        tab_elec[e].capaciteRestante=5000;
    }

    for (int h=0; h<nb_hab; h++)
    {
        tab_hab[h].elec=0;
    }

    for (int i=0;i<nb_elec;i++)
    {
        int j=0;
        do {
            if ((tab_elec[i].capaciteRestante>=tab_hab[j].nb_habitants) && (tab_hab[j].elec==0))
            {
                tab_hab[j].elec=1;
                tab_elec[i].capaciteRestante-=tab_hab[j].nb_habitants;
            }
            j++;
        }while(j<nb_hab);
    }
    for (int t=0;t<nb_hab;t++)
    {
        if (tab_hab[t].elec==1)
        {
            somme++;
        }

    }
    for(int p=0;p<nb_elec;p++)
    {
        printf("\n\n%d : %d ",p,tab_elec[p].capaciteRestante);
    }
    printf("\nSomme : %d\n",somme);
    return somme;
}
//(tab_elec[i].capaciteRestante>tab_hab[j].nb_habitants)


//Comparer la capacité des centrales et le nombre d'habitants
//!\ Détails précis de la capacité fournie par une centrale
//Si capacité nouvelle construction > capacité centrale => pas alimentée