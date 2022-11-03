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
void actionChoixMenu(int choixDuMenu,BITMAP* bmpAffichage);
int choixModeJeu(BITMAP* bmpAffichage);

//Fonctions pour la map
void creer_map(BITMAP* page, int matriceMap[35][45]);
int afficher_interface(BITMAP* page);
void lireFichierMap(int matrice_a_remplir[35][45],char* nomFichier);

//Sauvegarde
int testSauvegarde();

typedef struct batiment
{
    char nom[15];
    int prix;
    int num_bat;
    int capacite_eau;
    int capacite_elec;
    int nb_hab;
    time_t tempsCrea;
    BITMAP* bouton;
    BITMAP* boutonInv;
    BITMAP* imageCarte;
    SAMPLE* sonBat;

}t_batiment;


//Interface
void afficherInterface(BITMAP* page);
void route (BITMAP* page, int retourInterface);

#endif //PROJET_ECECITY_HEADER_H
