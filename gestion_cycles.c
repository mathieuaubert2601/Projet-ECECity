//
// Created by thiba on 05/11/2022.
//


#include "header.h"
///Test si evolution ou regression///
void test_temps(int map[35][45], t_habitation tab_hab[50], int* argent, int nb_hab, int nb_elec, t_centrales tab_elec[20],int nbchateau,t_chateauEau* tabEau, int pause, unsigned long tempsPause, unsigned long tempsChrono)
{
    time_t tempsact = time(NULL);//On récupere le temps actuel
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);

    unsigned long diff;
    int x;
    int y;
    for (int i=0; i<nb_hab; i++)    //On parcourt toutes les habitations crées
    {
        int avant = 0, apres = 0;
        diff = difftime(tempsact,
                        tab_hab[i].tempsCrea); //On calcule le temps depuis la création ou depuis la derniere evolution
        if (pause == 0) {
            if (diff >= 15 && nb_hab > 0 && nbchateau > 0) //Si le temps est sup ou egal a 15
            {
                x = tab_hab[i].x;
                y = tab_hab[i].y;
                tab_hab[i].tempsCrea = tempsact;  //On remet le temps actuel comme nouveau temps pour l'habitation
                if (tab_hab[i].elec == 1 && tab_hab[i].quantiteeEau ==
                                            tab_hab[i].nb_habitants) //Si la maison est alimentée, on augmente de niveau
                {
                    if (tab_hab[i].niveau < 4) {
                        tab_hab[i].niveau++;
                        map[y][x]++;
                    }
                    if (tab_hab[i].niveau == 1)
                        tab_hab[i].nb_habitants = 10;
                    if (tab_hab[i].niveau == 2)
                        tab_hab[i].nb_habitants = 50;
                    if (tab_hab[i].niveau == 3)
                        tab_hab[i].nb_habitants = 100;
                    if (tab_hab[i].niveau == 4)
                        tab_hab[i].nb_habitants = 1000;
                    apres = distribution(nb_elec, nb_hab, tab_elec,
                                         tab_hab); //On lance une distribution electrique pour réactualiser les valeurs
                    chercherCheminPlusCourtEau(map, nb_hab, tab_hab, tabEau, nbchateau);
                    if (tab_hab[i].elec != 1 || tab_hab[i].quantiteeEau <
                                                tab_hab[i].nb_habitants) //Si apres amelioration, la maison n'est plus alimentée on la remet comme elle était, car cela signifie qu'on ne dispose pas d'assez de ressources pour evoluer
                    {
                        if (tab_hab[i].niveau > 0) {
                            tab_hab[i].niveau--;
                            map[y][x]--;
                        }
                        if (tab_hab[i].niveau == 0)
                            tab_hab[i].nb_habitants = 0;
                        if (tab_hab[i].niveau == 1)
                            tab_hab[i].nb_habitants = 10;
                        if (tab_hab[i].niveau == 2)
                            tab_hab[i].nb_habitants = 50;
                        if (tab_hab[i].niveau == 3)
                            tab_hab[i].nb_habitants = 100;
                        if (tab_hab[i].niveau == 4)
                            tab_hab[i].nb_habitants = 1000;
                    }
                } else if (tab_hab[i].elec == 0 || tab_hab[i].quantiteeEau <
                                                   tab_hab[i].nb_habitants)//Si la maison n'est pas alimentée,on régresse
                {
                    if (tab_hab[i].niveau > 0) {
                        tab_hab[i].niveau--;
                        map[y][x]--;
                    }
                    if (tab_hab[i].niveau == 0)
                        tab_hab[i].nb_habitants = 0;
                    if (tab_hab[i].niveau == 1)
                        tab_hab[i].nb_habitants = 10;
                    if (tab_hab[i].niveau == 2)
                        tab_hab[i].nb_habitants = 50;
                    if (tab_hab[i].niveau == 3)
                        tab_hab[i].nb_habitants = 100;
                    if (tab_hab[i].niveau == 4)
                        tab_hab[i].nb_habitants = 1000;
                }
                distribution(nb_elec, nb_hab, tab_elec, tab_hab);// On réactualise la distribution
                chercherCheminPlusCourtEau(map, nb_hab, tab_hab, tabEau, nbchateau);
                *argent += impots * tab_hab[i].nb_habitants;// on paie les impots
            }
        }
    }
}