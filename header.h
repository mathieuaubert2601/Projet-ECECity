#ifndef PROJET_ECECITY_HEADER_H
#define PROJET_ECECITY_HEADER_H
///Declaration des bibliotheques
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


#define impots 10
#define banqueDep 500000
#define CAPACITE_CHATEAU 5000

//Structure habitation
typedef struct habitation
{
    int niveau;
    int nb_habitants;
    int x;
    int y;
    int XRef;
    int YRef;
    int quantiteeEau;
    int chateau_Eau_Affilie;
    int chateauEauNCR[15];
    int distance;
    int numero;
    int elec;
    time_t tempsCrea;

}t_habitation;

//Structure chateau d'eau
typedef struct chateauEau
{
    int x;
    int y;
    int XRef;
    int YRef;
    int capaciteRestante;
    int num;
}t_chateauEau;

typedef struct centrales
{
    int x;
    int y;
    int capaciteRestante;
    int num;
}t_centrales;


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
    int distance; //utilisé pour eau;
    int numMaison; //utilisé pour eau;
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
void AffichageIcone(BITMAP* bouton,BITMAP* boutonInv,BITMAP* infos, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int destxi, int destyi,int longueur,int hauteur,int longueurinfos,int hauteurinfos);


//Fonctions pour le menu
int menuJeu(BITMAP* bmpAffichage);
void actionChoixMenu(int choixDuMenu,BITMAP* bmpAffichage);
int choixModeJeu(BITMAP* bmpAffichage);
void affichageregles(BITMAP* bmpAffichage);

//Fonctions pour la map
void afficher_map(BITMAP* page, int map[35][45]);
void creer_map(BITMAP* page, int map[35][45]);
void lireFichierMap(int matrice_a_remplir[35][45],char* nomFichier);
void afficher_matrice_cases_vertes(BITMAP* page);

//Constructions
void route (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab, int nb_elec, t_centrales tab_elec[20],int nbChateau,t_chateauEau*  tabEau);
void habitation (BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, int* nb_hab, t_habitation tab_hab[50], t_centrales tab_elec[20], int nb_elec,int nbChateau,t_chateauEau* tabEau);
void chateau_eau(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab, t_chateauEau tab_eau[20], int* nb_chateau, int nb_elec, t_centrales tab_elec[20]);
void centrale(BITMAP* page, int map[35][45],time_t tempsdepart, int* banque, t_habitation tab_hab[50], int nb_hab, int* nb_elec, t_centrales tab_elec[20],int nbChateau,t_chateauEau* tabEau);

void test_temps(int map[35][45], t_habitation tab_hab[50], int* argent, int nb_hab, int nb_elec, t_centrales tab_elec[20],int nbchateau,t_chateauEau* tabEau);

//Interfaces
void afficherInterface(BITMAP* page,int map[35][45], time_t tempsdepart, int argent);
void interfaceRoute(BITMAP* page, int type, time_t tempsdepart, int argent, int map[35][45]);
void interfaceMaisons(BITMAP* page, time_t tempsdepart, int argent, int map[35][45]);
void interfaceChateaux(BITMAP* page,time_t tempsdepart, int argent, int map[35][45]);
void interfaceCentrales(BITMAP* page,time_t tempsdepart, int argent, int map[35][45]);
void interfaceNiveau(BITMAP* page, int type);
int compterHab(int map[35][45]);
int compterEau(int map[35][45]);
int compterElec(int map[35][45]);


//Sauvegarde
int testSauvegarde();
void indiquerSauvegarde(int ouvertureOuNon);
void sauvegarderMatriceFichier(int matrice[35][45], char* nomFichier);
int chargerTableauHabitation(t_habitation tableauHabitation[], char* nomFichier);
void sauvegarderTableauHabitation(char* nomFichier, t_habitation tableau[],int nombreBatiments);
int chargerTableauCentrale(t_centrales tableauHabitation[], char* nomFichier);
int chargerTableauChateauEau(t_chateauEau tableauHabitation[], char* nomFichier);
void sauvegarderTableauCentrale(char* nomFichier, t_centrales tableau[],int nombreBatiments);
void sauvegarderTableauChateauEau(char* nomFichier, t_chateauEau tableau[],int nombreBatiments);

//Case
void affichagecasefree(BITMAP* page,int map[35][45],int type);

//Gestion Eau

int** chercherCheminPlusCourtEau(int matriceMap[35][45],int nombreHabitation,t_habitation* tabHab,t_chateauEau* tabEau,int nombreChateauEau);
int* defiler(t_file * ptAlignement);
void enfiler(t_file * ptAlignement, int valeurX,int valeurY);
int estVide(t_file* fAttente);

//Gestion Elec
int calculCapaciteElec(int nb_elec);
int distribution(int nb_elec, int nb_hab, t_centrales tab_elec[20], t_habitation tab_hab[50]);

//Niveau
void canalisations (BITMAP* page, int map[35][45],t_habitation maison[50]);
void lignes(BITMAP* page, int map[35][45],t_habitation maison[50], int nb_maison, t_centrales tab_elec[20], int nb_centrales);
void afficher_niveau(BITMAP* page, int map[35][45],int test,t_habitation maison[50]);
void afficher_niveau2(BITMAP* page, int map[35][45],t_habitation maison[50], int nb_maison, t_centrales tab_elec[20], int nb_centrales);

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