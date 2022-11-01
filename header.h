//
// Created by thiba on 29/10/2022.
//

#ifndef PROJET_ECECITY_HEADER_H
#define PROJET_ECECITY_HEADER_H

///Declaration des biblioth�ques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

//Prototype des fonctions
void initialisationAllegro();
void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur);
int menuJeu(BITMAP* bmpAffichage);
void actionChoixMenu(int choixDuMenu);

#endif //PROJET_ECECITY_HEADER_H
