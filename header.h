//
// Created by thiba on 29/10/2022.
//

#ifndef PROJET_ECECITY_HEADER_H
#define PROJET_ECECITY_HEADER_H
///Declaration des bibliotheques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

///Prototype des fonctions
void initialisationAllegro();
void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur);

//Fonctions pour le menu
int menuJeu(BITMAP* bmpAffichage);
void actionChoixMenu(int choixDuMenu);

//Fonctions pour la map
void creer_map(BITMAP* page);


#endif //PROJET_ECECITY_HEADER_H
