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

void indiquerSauvegarde(int ouvertureOuNon)
{
    //Déclaration d'ouverture
    FILE* indiquerEtatSauvegarde = fopen("Sauvegarde/sauvegardeOuNon.txt","w+");

    //test d'ouverture du fichier
    if(indiquerEtatSauvegarde == NULL)
    {
        printf("Erreur d'ouverture du fichier : indiquerEtatSauvegarde");
        exit(-1);
    }

    //Ecriture dans le fichier
    fprintf(indiquerEtatSauvegarde,"%d",ouvertureOuNon);

    //Fermeture Fichier
    fclose(indiquerEtatSauvegarde);
}
void sauvegarderMatriceFichier(int matrice[35][45], char* nomFichier)
{
    //Déclaration des variables
    FILE* fichierEnregistrement = fopen(nomFichier,"w+");

    //test ouverture du fichier
    if(fichierEnregistrement == NULL)
    {
        printf("Erreur ouverture fichier : %s",nomFichier);
        exit(EXIT_FAILURE);
    }

    //Boucle pour enregistrer la matrice dans le fichier
    for(int i=0 ; i<35 ; i++)
    {
        for(int j=0 ; j<45 ; j++)
        {
            if(matrice[i][j] == 0)
            {
                fputc('0',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 1)
            {
                fputc('1',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 2)
            {
                fputc('2',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 3)
            {
                fputc('3',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 4)
            {
                fputc('4',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 5)
            {
                fputc('5',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 6)
            {
                fputc('6',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 7)
            {
                fputc('7',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 8)
            {
                fputc('8',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 9)
            {
                fputc('9',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 10)
            {
                fputc('1',fichierEnregistrement);
                fputc('0',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 11)
            {
                fputc('1',fichierEnregistrement);
                fputc('1',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 12)
            {
                fputc('1',fichierEnregistrement);
                fputc('2',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 13)
            {
                fputc('1',fichierEnregistrement);
                fputc('3',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 14)
            {
                fputc('1',fichierEnregistrement);
                fputc('4',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 15)
            {
                fputc('1',fichierEnregistrement);
                fputc('5',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 16)
            {
                fputc('1',fichierEnregistrement);
                fputc('6',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 17)
            {
                fputc('1',fichierEnregistrement);
                fputc('7',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 18)
            {
                fputc('1',fichierEnregistrement);
                fputc('8',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
            else if(matrice[i][j] == 19)
            {
                fputc('1',fichierEnregistrement);
                fputc('9',fichierEnregistrement);
                fputc(' ',fichierEnregistrement);
            }
        }
        fputc('\n',fichierEnregistrement);
    }

    //Fermeture du fichier
    fclose(fichierEnregistrement);

    //On indique que la sauvegarde a été faite
    indiquerSauvegarde(1);
}