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

t_kase** chercherCheminPlusCourtEau(int chateauEauRefX, int chateauEauRefY,int matriceMap[35][45])
{
    //Déclaration des variables
    int matriceCouleur[35][45];
    int xFile = 0, yFile= 0;
    int* tableauCoordonnee = NULL;
    t_kase** tableauPred = (t_kase**)malloc(35 * sizeof(t_kase*));
    t_file fileBfs;

    //Initialisation de la file
    fileBfs.queueFile = fileBfs.tete = NULL;

    //On met toutes les cases de la matrice à 0 (pas découvert)
    //On met tout les prédécesseur sur -1
    for(int y = 0 ; y < 35 ; y++)
    {
        tableauPred[y] = (t_kase*)malloc(45 * sizeof(t_kase));
        for(int x = 0 ; x < 45 ; x++)
        {
            matriceCouleur[y][x] = 0;
            tableauPred[y][x].coordX = -1;
            tableauPred[y][x].coordY = -1;
        }
    }

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
            tableauPred[yFile + 1][xFile].coordX = xFile;
        }
        if(matriceCouleur[yFile-1][xFile] == 0 && matriceMap[yFile - 1][xFile] == 1)
        {
            enfiler(&fileBfs,xFile,yFile - 1);
            matriceCouleur[yFile - 1][xFile] = 1;
            tableauPred[yFile - 1][xFile].coordY = yFile;
            tableauPred[yFile - 1][xFile].coordX = xFile;
        }
        if(matriceCouleur[yFile][xFile+1] == 0 && matriceMap[yFile][xFile+1] == 1)
        {
            enfiler(&fileBfs,xFile + 1,yFile);
            matriceCouleur[yFile][xFile + 1] = 1;
            tableauPred[yFile][xFile + 1].coordY = yFile;
            tableauPred[yFile][xFile + 1].coordX = xFile;
        }
        if(matriceCouleur[yFile][xFile-1] == 0 && matriceMap[yFile][xFile-1] == 1)
        {
            enfiler(&fileBfs,xFile - 1,yFile);
            matriceCouleur[yFile][xFile - 1] = 1;
            tableauPred[yFile][xFile - 1].coordY = yFile;
            tableauPred[yFile][xFile - 1].coordX = xFile;
        }
    }
    return tableauPred;
}

int tailleChemin(t_kase** matriceAnalyse, int maisonX, int maisonY,int chateauEauX, int chateauEauY)
{
    //Déclaration des variables
    int tailleChemin = 1, xTmp = maisonX , yTmp = maisonY;

    //Trouver la taille du chemin
    while(xTmp != chateauEauX && yTmp != chateauEauY)
    {
        xTmp = matriceAnalyse[yTmp][xTmp].coordX;
        yTmp = matriceAnalyse[yTmp][xTmp].coordY;
        tailleChemin ++;
    }
    return tailleChemin;
}

int** creerMatriceEau(t_habitation* tableauHabitation, int nombreHabitation, t_chateauEau* tableauChateauEau,int nombreChateauEau,int map[35][45])
{
    //déclaration des variables
    t_kase*** tableauCheminPlusCourtChateauEau = (t_kase***) malloc(nombreChateauEau * sizeof(t_kase**));
    t_kase ** distanceChateauEau = (t_kase**)malloc(nombreChateauEau * sizeof(t_kase*));
    int** matriceEau = (int**)malloc(35*sizeof(int*));
    int* minChateauEau = (int*) malloc(nombreChateauEau * sizeof(int));
    int* cmtChatEau = (int*) calloc(nombreChateauEau,sizeof(int));
    int index,tmpX,tmpY,tmpDist,tmpNumM,saturationChateau = 0;

    for(int i = 0; i < nombreChateauEau; i++)
    {
        distanceChateauEau[i] = (t_kase*) malloc((nombreHabitation)*sizeof(t_kase));
        minChateauEau[i] = 500;
        tableauCheminPlusCourtChateauEau[i] = chercherCheminPlusCourtEau(tableauChateauEau[i].x,tableauChateauEau[i].y,map);
    }

    for(int i = 0 ; i<35 ; i++)
    {
        matriceEau[i] = (int*)malloc(45*sizeof(int));
        for(int j = 0 ; j<45 ; j++)
        {
            matriceEau[i][j] = 0;
        }
    }

    for(int i=0 ; i<nombreChateauEau ; i++)
    {
        for(int j=0 ; j<nombreHabitation ; j++)
        {
            distanceChateauEau[i][j].distance = tailleChemin(tableauCheminPlusCourtChateauEau[i],tableauHabitation[j].x,tableauHabitation[j].x,tableauChateauEau[i].x,tableauChateauEau[i].y);
            distanceChateauEau[i][j].coordX = tableauHabitation[j].x;
            distanceChateauEau[i][j].coordY = tableauHabitation[j].y;
            distanceChateauEau[i][j].numMaison = j;
        }
    }

    for(int z=0 ; z < nombreChateauEau ; z++)
    {
        for(int i=0 ; i< (nombreHabitation-1) ; i++)
        {
            index = i;
            for(int j=(i+1) ; j < nombreHabitation ; j++)
            {
                if (distanceChateauEau[z][index].distance > distanceChateauEau[z][j].distance)
                {
                    index = j;
                }
            }
            if (index != i)
            {
                tmpDist= distanceChateauEau[z][i].distance;
                tmpX= distanceChateauEau[z][i].coordX;
                tmpY= distanceChateauEau[z][i].coordY;
                tmpNumM = distanceChateauEau[z][i].numMaison;

                distanceChateauEau[z][i].distance = distanceChateauEau[z][index].distance;
                distanceChateauEau[z][i].coordX = distanceChateauEau[z][index].coordX;
                distanceChateauEau[z][i].coordY = distanceChateauEau[z][index].coordY;
                distanceChateauEau[z][i].numMaison = distanceChateauEau[z][index].numMaison;

                distanceChateauEau[z][index].distance = tmpDist;
                distanceChateauEau[z][index].coordX = tmpX;
                distanceChateauEau[z][index].coordY = tmpY;
                distanceChateauEau[z][index].numMaison = tmpNumM;
            }
        }
    }

    while(saturationChateau == 0)
    {
        //Test de sortie de boucle
        for(int i=0 ; i<nombreChateauEau ; i++)
        {
            if(tableauChateauEau[i].capaciteRestante == 0 || cmtChatEau[i] == nombreHabitation)
            {
                saturationChateau = 1;
            }
            else
            {
                saturationChateau = 0;
            }
        }
    }
}