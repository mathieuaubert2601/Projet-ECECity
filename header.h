#ifndef PROJET_ECECITY_HEADER_H
#define PROJET_ECECITY_HEADER_H
///Declaration des bibliotheques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


#define impots 10
#define banqueDep 500000

//Structure habitation
typedef struct habitation
{
    int niveau;
    int nb_habitants;
    int x;
    int y;
    time_t tempsCrea;

}t_habitation;

//Structure Maillon
typedef struct maillon
{
    int X;
    int Y;
    struct maillon* next;
}t_maillon;

//Structure case
typedef struct kase
{
    int coordX;
    int coordY;
}t_kase;

//Structure file
typedef struct file
{
    t_maillon* tete;
    t_maillon* queueFile;
}t_file;

///Prototype des fonctions
void initialisationAllegro();
void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur);
void AffichageIcone(BITMAP* bouton,BITMAP* boutonInv,BITMAP* infos, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur,int hauteur,int longueurinfos,int hauteurinfos);


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
void interfaceRoute(BITMAP* page);
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

//Gestion Eau
void chercherCheminPlusCourtEau(int maisonRefX,int maisonRefY,int chateauEauRefX, int chateauEauRefY,int matriceMap[35][45]);
int* defiler(t_file * ptAlignement);
void enfiler(t_file * ptAlignement, int valeurX,int valeurY);
int estVide(t_file* fAttente);
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