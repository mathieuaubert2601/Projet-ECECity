#include "header.h"

int testSauvegarde()
{
    //Déclaration des variables
    int testOuverture;
    FILE* sauvegardeOuNon = fopen("Sauvegarde/sauvegardeOuNon.txt","r");

    //test d'ouverture du fichier
    if(sauvegardeOuNon == NULL)
    {
        printf("Erreur d'ouverture du fichier");
        exit(-1);
    }

    //lecture dans le fichier
    fscanf(sauvegardeOuNon,"%d",&testOuverture);

    //Fermeture du fichier
    fclose(sauvegardeOuNon);

    //On renvoie la valeur lue
    return testOuverture;
}