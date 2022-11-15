#ifndef PROJET_ECECITY_HEADER_H
#define PROJET_ECECITY_HEADER_H
///Declaration des bibliotheques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


#define impots 10
#define banqueDep 500000


typedef struct habitation
{
    int niveau;
    int nb_habitants;
    int x;
    int y;
    time_t tempsCrea;

}t_habitation;

///Prototype des fonctions
void initialisationAllegro();
void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur);
void AffichageIcone(BITMAP* bouton,BITMAP* boutonInv,BITMAP* infos, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int destxi, int destyi,int longueur,int hauteur,int longueurinfos,int hauteurinfos);


//Fonctions pour le menu
int menuJeu(BITMAP* bmpAffichage);
void actionChoixMenu(int choixDuMenu,BITMAP* bmpAffichage);
int choixModeJeu(BITMAP* bmpAffichage);
void affichageregles(BITMAP* bmpAffichage);

//Fonctions pour la map
void afficher_map(BITMAP* page, int map[35][45]);
void creer_map(BITMAP* page, int map[35][45]);
void afficherInterface(BITMAP* page,int map[35][45], time_t tempsdepart, int argent);
int compterHab(int map[35][45]);
int compterEau(int map[35][45]);
int compterElec(int map[35][45]);
void lireFichierMap(int matrice_a_remplir[35][45],char* nomFichier);

//Constructions
void route (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque,t_habitation tab_hab[50], int nb_hab);
void interfaceRoute(BITMAP* page,int type);
void habitation (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, int* nb_hab, t_habitation* tab_hab);
void chateau_eau(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque,t_habitation tab_hab[50], int nb_hab);
void centrale(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab);

void test_temps(int map[35][45], t_habitation tab_hab[50], int* argent, int nb_hab);

//Sauvegarde
int testSauvegarde();
void indiquerSauvegarde(int ouvertureOuNon);
void sauvegarderMatriceFichier(int matrice[35][45], char* nomFichier);
int chargerTableauHabitation(t_habitation tableauHabitation[], char* nomFichier);
void sauvegarderTableauBatiment(char* nomFichier, t_habitation tableau[],int nombreBatiments);

//Case
void affichagecasefree(BITMAP* page,int map[35][45],int type);

/*typedef struct batiment
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

}t_batiment;*/


#endif //PROJET_ECECITY_HEADER_H