#include "header.h"

//Sous programme pour voir si une file est vide ou non
int estVide(t_file* fAttente)
{
    if (fAttente->tete == NULL && fAttente->queueFile == NULL)
        return 1;
    else
        return 0;
}

//Sous programme pour enfiler un élement dans une file
void enfiler(t_file * ptAlignement, int valeurX,int valeurY)
{
    t_maillon * nouveau;

    //creation d'un nouveau maillon
    nouveau = (t_maillon*)malloc(sizeof(t_maillon));
    if (nouveau == NULL)
    {
        printf("pb d'allocation Dyn. de maillon\n");
    }
    else
    {
        //affectation de la valeur du maillon
        nouveau->X= valeurX;
        nouveau->Y = valeurY;
        nouveau->next=NULL;
        //ajout du maillon dans la liste
        if (estVide(ptAlignement) == 1)
        {
            //liste vide
            ptAlignement->queueFile= nouveau;
            ptAlignement->tete = nouveau;
        }
        else
        {
            //liste non vide donc ajout en tete et mise à jour du pointeur
            nouveau->next = ptAlignement->queueFile;
            ptAlignement->queueFile = nouveau;
        }
    }
}

//Sous programme pour défiler un élement
int* defiler(t_file * ptAlignement)
{

    t_maillon* ptcourant = NULL;
    t_maillon* ptprecedent = NULL;
    int* tableauCo = (int*)malloc(2*sizeof(int));

    if (estVide(ptAlignement) == 1)
    {
        printf("il n'y a aucun element à supprimer. La file est vide\n");
        return -2;     //renvoie un nombre erreur au programme appelant
    }
    else
    {
        ptcourant = ptAlignement->tete;
        tableauCo[0] = ptcourant->X;
        tableauCo[1] = ptcourant->Y;

        //il faut regarder s'il n'y a plus qu'un seul element qui rendra apres cette operation de suppression la liste vide
        if (ptAlignement->tete != ptAlignement->queueFile)
        {
            //parcourir la liste pour atteindre l'avant dernier maillon
            ptcourant = ptAlignement->queueFile;
            ptprecedent = ptcourant;
            while(ptcourant->next!=NULL)
            {
                ptprecedent = ptcourant;
                ptcourant=ptcourant->next;
            }
            ptprecedent->next = NULL;
            ptAlignement->tete = ptprecedent;

        }
        else
        {

            ptAlignement->tete = NULL;
            ptAlignement->queueFile= NULL;

        }
        free(ptcourant);

        return tableauCo;
    }
}
void chercherCheminPlusCourtEau(int maisonRefX,int maisonRefY,int chateauEauRefX, int chateauEauRefY,int** matriceMap)
{
    //Déclaration des variables
    /*int matriceCouleur[35][45];
    int xFile = 0, yFile= 0;
    int* tableauCoordonnee = NULL;
    t_kase** tableauPred = (t_kase**)malloc(35 * sizeof(t_kase*));
    for(int i = 0 ; i<35 ; i++)
    {
        tableauPred[i] = (t_kase*)malloc(45 * sizeof(t_kase));
    }
    t_file fileBfs;

    //Initialisation de la file
    fileBfs.queueFile = fileBfs.tete = NULL;

    //On met toutes les cases de la matrice à 0 (pas découvert)ù
    //On met tout les prédécesseur sur -1
    for(int y = 0 ; y = 35 ; y++)
    {
        for(int x = 0 ; x = 45 ; x++)
        {
            matriceCouleur[y][x] = 0;
            tableauPred[y][x].coordX = -1;
            tableauPred[y][x].coordY = -1;
        }
    }
/*
    //On met la case du chateau d'eau de départ à 1 : découverte
    matriceCouleur[chateauEauRefY][chateauEauRefX] = 1;

    //On enfile le premier élement dans la file
    enfiler(&fileBfs,chateauEauRefX,chateauEauRefY);

    //On va faire une boucle dans que la file n'est pas vide
    while(fileBfs.tete != NULL)
    {
        //On défile le numéro du sommet suivant
        tableauCoordonnee = defiler(&fileBfs);
        xFile = tableauCoordonnee[0];
        yFile = tableauCoordonnee[1];
        //On recherche les cases à coté
        if(matriceCouleur[yFile+1][xFile] == 0 && matriceMap[yFile + 1][xFile] == 1)
        {
            enfiler(&fileBfs,xFile,yFile + 1);
            matriceCouleur[yFile + 1][xFile] = 1;
            tableauPred[yFile + 1][xFile].coordY = yFile;
            tableauPred[yFile + 1][xFile].coordY = xFile;
        }
        if(matriceCouleur[yFile-1][xFile] == 0 && matriceMap[yFile - 1][xFile] == 1)
        {
            enfiler(&fileBfs,xFile,yFile - 1);
            matriceCouleur[yFile - 1][xFile] = 1;
            tableauPred[yFile - 1][xFile].coordY = yFile;
            tableauPred[yFile - 1][xFile].coordY = xFile;
        }
        if(matriceCouleur[yFile][xFile+1] == 0 && matriceMap[yFile][xFile+1] == 1)
        {
            enfiler(&fileBfs,xFile + 1,yFile);
            matriceCouleur[yFile][xFile + 1] = 1;
            tableauPred[yFile][xFile + 1].coordY = yFile;
            tableauPred[yFile][xFile + 1].coordY = xFile;
        }
        if(matriceCouleur[yFile][xFile+1] == 0 && matriceMap[yFile][xFile-1] == 1)
        {
            enfiler(&fileBfs,xFile - 1,yFile);
            matriceCouleur[yFile][xFile - 1] = 1;
            tableauPred[yFile][xFile - 1].coordY = yFile;
            tableauPred[yFile][xFile - 1].coordY = xFile;
        }
    }

    while(!key[KEY_ESC])
    {
        for(int y = 0 ; y = 35 ; y++)
        {
            for(int x = 0 ; x = 45 ; x++)
            {
               if(tableauPred[y][x].coordX < 10)
               {
                   printf("%d  ",tableauPred[y][x].coordX);
               }
               else
               {
                   printf("%d ",tableauPred[y][x].coordX);
               }

                if(tableauPred[y][x].coordY < 10)
                {
                    printf("%d  ",tableauPred[y][x].coordY);
                }
                else
                {
                    printf("%d ",tableauPred[y][x].coordY);
                }
            }
        }

    }
    */
}