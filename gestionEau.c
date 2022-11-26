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

int** chercherCheminPlusCourtEau(int matriceMap[35][45],int nombreHabitation,t_habitation* tabHab,t_chateauEau* tabEau,int nombreChateauEau)
{
    //Déclaration des variables
    int matriceCouleur[35][45];
    int** matriceEau = malloc(35*sizeof(int*));
    int index,XtriTmp,YtriTmp,distanceTriTmp,nbHabTriTmp,chatEauAffTriTmp,numeroTriTmp;
    int xFile = 0, yFile= 0,cmpt = 0,calculX,calculXtmp,calculY,distanceM = 0,testChateauEauNcr;
    int* tableauCoordonnee = NULL;
    t_habitation* tabHabChatEau = (t_habitation*)malloc((nombreHabitation*nombreChateauEau) * sizeof(t_habitation));
    t_kase*** tableauPred = (t_kase***)malloc(nombreChateauEau * sizeof(t_kase**));
    t_file fileBfs;

    //Initialisation de la file
    fileBfs.queueFile = fileBfs.tete = NULL;

    for(int i = 0 ; i<nombreHabitation ;i++)
    {
        for(int j = 0 ; j < 15 ; j++)
        {
            tabHab[i].chateauEauNCR[j] = -1;
        }
    }
    for(int z = 0 ; z<nombreChateauEau ; z++)
    {
        tableauPred[z] = (t_kase**)malloc(35 * sizeof(t_kase*));
        for(int y=0 ;y<35 ; y++)
        {
            tableauPred[z][y] = (t_kase*)malloc(45 * sizeof(t_kase));
        }
    }

    //On met toutes les cases de la matrice à 0 (pas découvert)
    //On met tout les prédécesseur sur -1
    for(int z=0 ; z<nombreChateauEau ; z++)
    {
        for(int y = 0 ; y < 35 ; y++)
        {
            matriceEau[y] = malloc(45*sizeof(int));
            for(int x = 0 ; x < 45 ; x++)
            {
                matriceCouleur[y][x] = 0;
                tableauPred[z][y][x].coordX = -1;
                tableauPred[z][y][x].coordY = -1;
                matriceEau[y][x] = 0;
            }
        }
    }
    cmpt = 0;
    for(int c = 0 ; c<nombreChateauEau ; c++)
    {
        //On met la case du chateau d'eau de départ à 1 : découverte
        matriceCouleur[tabEau[c].YRef][tabEau[c].XRef] = 1;

        //On enfile le premier élement dans la file
        enfiler(&fileBfs,tabEau[c].XRef,tabEau[c].YRef);

        //On va faire une boucle dans que la file n'est pas vide
        while(fileBfs.tete != NULL && cmpt != (nombreChateauEau * nombreHabitation))
        {
            //On défile le numéro du sommet suivant
            tableauCoordonnee = defiler(&fileBfs);
            xFile = tableauCoordonnee[0];
            yFile = tableauCoordonnee[1];

            for(int i=0 ; i<nombreHabitation ;i++)
            {
                if(tabHab[i].XRef == xFile && tabHab[i].YRef == yFile)
                {
                    distanceM = 1;
                    tabHabChatEau[cmpt].XRef = xFile;
                    tabHabChatEau[cmpt].YRef = yFile;
                    tabHabChatEau[cmpt].chateau_Eau_Affilie = c;
                    tabHabChatEau[cmpt].nb_habitants = tabHab[i].nb_habitants;
                    tabHabChatEau[cmpt].numero = i;
                    calculX = xFile;
                    calculY = yFile;

                    while(calculX != tabEau[c].XRef || calculY != tabEau[c].YRef)
                    {
                        calculXtmp = calculX;
                        calculX = tableauPred[c][calculY][calculX].coordX;
                        calculY = tableauPred[c][calculY][calculXtmp].coordY;

                        distanceM ++;
                    }

                    tabHabChatEau[cmpt].distance = distanceM;
                    cmpt ++;
                }
            }
            //On recherche les cases à coté
            if(matriceCouleur[yFile+1][xFile] == 0 && (matriceMap[yFile + 1][xFile] == 1 || matriceMap[yFile + 1][xFile] == 2))
            {
                enfiler(&fileBfs,xFile,yFile + 1);
                matriceCouleur[yFile + 1][xFile] = 1;
                tableauPred[c][yFile + 1][xFile].coordY = yFile;
                tableauPred[c][yFile + 1][xFile].coordX = xFile;
            }
            if(matriceCouleur[yFile-1][xFile] == 0 && (matriceMap[yFile - 1][xFile] == 1 || matriceMap[yFile - 1][xFile] == 2))
            {
                enfiler(&fileBfs,xFile,yFile - 1);
                matriceCouleur[yFile - 1][xFile] = 1;
                tableauPred[c][yFile - 1][xFile].coordY = yFile;
                tableauPred[c][yFile - 1][xFile].coordX = xFile;
            }
            if(matriceCouleur[yFile][xFile+1] == 0 && (matriceMap[yFile][xFile+1] == 1 || matriceMap[yFile][xFile+1] == 2))
            {
                enfiler(&fileBfs,xFile + 1,yFile);
                matriceCouleur[yFile][xFile + 1] = 1;
                tableauPred[c][yFile][xFile + 1].coordY = yFile;
                tableauPred[c][yFile][xFile + 1].coordX = xFile;
            }
            if(matriceCouleur[yFile][xFile-1] == 0 && (matriceMap[yFile][xFile-1] == 1 || matriceMap[yFile][xFile-1] == 2 ))
            {
                enfiler(&fileBfs,xFile - 1,yFile);
                matriceCouleur[yFile][xFile - 1] = 1;
                tableauPred[c][yFile][xFile - 1].coordY = yFile;
                tableauPred[c][yFile][xFile - 1].coordX = xFile;
            }
        }
        for(int i=0 ; i<35 ; i++)
        {
            for(int j=0 ; j<45 ; j++)
            {
                matriceCouleur[i][j] = 0;
            }
        }

    }


    for(int i=0 ; i < (cmpt - 1) ; i++)
    {
        index = i;

        for(int j=i + 1; j < cmpt ; j++)
        {
            if(tabHabChatEau[index].distance>tabHabChatEau[j].distance)
            {
                index = j;
            }
        }
        if(index != i)
        {
            XtriTmp = tabHabChatEau[i].XRef;
            YtriTmp = tabHabChatEau[i].YRef;
            distanceTriTmp = tabHabChatEau[i].distance;
            nbHabTriTmp = tabHabChatEau[i].nb_habitants;
            chatEauAffTriTmp = tabHabChatEau[i].chateau_Eau_Affilie;
            numeroTriTmp = tabHabChatEau[i].numero;

            tabHabChatEau[i].numero = tabHabChatEau[index].numero;
            tabHabChatEau[i].XRef = tabHabChatEau[index].XRef;
            tabHabChatEau[i].YRef =tabHabChatEau[index].YRef;
            tabHabChatEau[i].distance =tabHabChatEau[index].distance;
            tabHabChatEau[i].nb_habitants = tabHabChatEau[index].nb_habitants;
            tabHabChatEau[i].chateau_Eau_Affilie = tabHabChatEau[index].chateau_Eau_Affilie;

            tabHabChatEau[index].XRef = XtriTmp;
            tabHabChatEau[index].YRef = YtriTmp;
            tabHabChatEau[index].distance =distanceTriTmp;
            tabHabChatEau[index].nb_habitants =nbHabTriTmp;
            tabHabChatEau[index].chateau_Eau_Affilie =chatEauAffTriTmp;
            tabHabChatEau[index].numero = numeroTriTmp;
        }
    }

    for(int m=0 ; m<nombreHabitation ; m++)
    {
        tabHab[m].quantiteeEau = 0;
    }
    for(int k=0 ; k<nombreChateauEau ; k++)
    {
        tabEau[k].capaciteRestante = 5000;
    }

    for(int i=0 ; i<cmpt ; i++)
    {
        if(tabHab[tabHabChatEau[i].numero].quantiteeEau < tabHab[tabHabChatEau[i].numero].nb_habitants && tabEau[tabHabChatEau[i].chateau_Eau_Affilie].capaciteRestante > 0)
        {
            testChateauEauNcr = 0;
            if(((tabHab[tabHabChatEau[i].numero].nb_habitants - tabHab[tabHabChatEau[i].numero].quantiteeEau) <= tabEau[tabHabChatEau[i].chateau_Eau_Affilie].capaciteRestante) && tabEau[tabHabChatEau[i].chateau_Eau_Affilie].capaciteRestante>0 )
            {
                tabEau[tabHabChatEau[i].chateau_Eau_Affilie].capaciteRestante = tabEau[tabHabChatEau[i].chateau_Eau_Affilie].capaciteRestante - (tabHab[tabHabChatEau[i].numero].nb_habitants - tabHab[tabHabChatEau[i].numero].quantiteeEau);
                tabHab[tabHabChatEau[i].numero].quantiteeEau = tabHab[tabHabChatEau[i].numero].nb_habitants;
                for(int h = 0 ; h<15 ; h++)
                {
                    if(tabHab[tabHabChatEau[i].numero].chateauEauNCR[h] == -1 && testChateauEauNcr == 0)
                    {
                        tabHab[tabHabChatEau[i].numero].chateauEauNCR[h] = tabHabChatEau[i].chateau_Eau_Affilie;
                        testChateauEauNcr =  1;
                    }
                }
            }
            else
            {
                tabEau[tabHabChatEau[i].chateau_Eau_Affilie].capaciteRestante = 0;
                tabHab[tabHabChatEau[i].numero].quantiteeEau = tabHab[tabHabChatEau[i].numero].quantiteeEau + tabEau[tabHabChatEau[i].chateau_Eau_Affilie].capaciteRestante;
                for(int h = 0 ; h<15 ; h++)
                {
                    if(tabHab[tabHabChatEau[i].numero].chateauEauNCR[h] == -1 && testChateauEauNcr == 0)
                    {
                        tabHab[tabHabChatEau[i].numero].chateauEauNCR[h] = tabHabChatEau[i].chateau_Eau_Affilie;
                        testChateauEauNcr =  1;
                    }
                }
            }

            calculY = tabHabChatEau[i].YRef;
            calculX = tabHabChatEau[i].XRef;

            while(calculY != tabEau[tabHabChatEau[i].chateau_Eau_Affilie].YRef || calculX != tabEau[tabHabChatEau[i].chateau_Eau_Affilie].XRef)
            {
                matriceEau[calculY][calculX] = 1;
                calculXtmp = calculX;
                calculX = tableauPred[tabHabChatEau[i].chateau_Eau_Affilie][calculY][calculX].coordX;
                calculY = tableauPred[tabHabChatEau[i].chateau_Eau_Affilie][calculY][calculXtmp].coordY;
            }
            matriceEau[tabEau[tabHabChatEau[i].chateau_Eau_Affilie].YRef][tabEau[tabHabChatEau[i].chateau_Eau_Affilie].XRef] = 1;


        }
    }

    /*printf("\n\n\n");
    for(int i = 0 ; i < 35 ; i++)
    {
        for(int j = 0 ; j<45 ; j++)
        {
            printf("%d ",matriceEau[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");*/

    //Libération de la mémoire
    for(int z = 0 ; z<nombreChateauEau ; z++)
    {
        for(int y=0 ; y<35 ; y++)
        {
            free(tableauPred[z][y]);
        }
    }
    free(tableauPred);
    free(tableauCoordonnee);
    free(tabHabChatEau);

    return matriceEau;
}
