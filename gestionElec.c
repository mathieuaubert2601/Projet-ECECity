#include "header.h"

///Distribution d'electricité au plus d'habitations possible///
int distribution(int nb_elec, int nb_hab, t_centrales tab_elec[20], t_habitation tab_hab[50])
{
    int somme=0;

    //On remet toutes les centrales a leur capacité max
    for (int e=0; e<nb_elec; e++)
    {
        tab_elec[e].capaciteRestante=5000;
    }

    //Toutes les maisons sont remises a 0 electricité
    for (int h=0; h<nb_hab; h++)
    {
        tab_hab[h].elec=0;
    }

    ///On parcours le tableau de maison pour chaque centrale,///
    /// et des que la centrale a assez d'electricité pour une maison non marquée,///
    /// on marque cette maison et on enleve l'elec a la centrale///
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

    ///On calcule le nombre de maisons alimentées et on le renvoie
    for (int t=0;t<nb_hab;t++)
    {
        if (tab_hab[t].elec==1)
        {
            somme++;
        }
    }
    return somme;
}
