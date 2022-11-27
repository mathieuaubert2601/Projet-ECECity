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

void sauvegarderTableauHabitation(char* nomFichier, t_habitation tableau[],int nombreBatiments)
{
    FILE* fichier = fopen(nomFichier,"wb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : %s",nomFichier);
    }

    //Enregistrement du nombre de batiment
    fwrite(&nombreBatiments,sizeof(int),1,fichier);

    //Enregistrement des habitations
    for(int i = 0 ; i<nombreBatiments ; i++)
    {
        fwrite(&tableau[i],sizeof(t_habitation),1,fichier);
    }

    //Fermeture du fichier
    fclose(fichier);
}

void sauvegarderTableauChateauEau(char* nomFichier, t_chateauEau tableau[],int nombreBatiments)
{
    FILE* fichier = fopen(nomFichier,"wb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : %s",nomFichier);
    }

    //Enregistrement du nombre de batiment
    fwrite(&nombreBatiments,sizeof(int),1,fichier);

    //Enregistrement des habitations
    for(int i = 0 ; i<nombreBatiments ; i++)
    {
        fwrite(&tableau[i],sizeof(t_chateauEau),1,fichier);
    }

    //Fermeture du fichier
    fclose(fichier);
}

void sauvegarderTableauCentrale(char* nomFichier, t_centrales tableau[],int nombreBatiments)
{
    FILE* fichier = fopen(nomFichier,"wb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : %s",nomFichier);
    }

    //Enregistrement du nombre de batiment
    fwrite(&nombreBatiments,sizeof(int),1,fichier);

    //Enregistrement des habitations
    for(int i = 0 ; i<nombreBatiments ; i++)
    {
        fwrite(&tableau[i],sizeof(t_centrales),1,fichier);
    }

    //Fermeture du fichier
    fclose(fichier);
}
int chargerTableauHabitation(t_habitation tableauHabitation[], char* nomFichier)
{
    //Déclaration des variables
    int nombreBatiment = 0;
    FILE* fichier = fopen(nomFichier,"rb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : %s",nomFichier);
    }

    //Lecture du nombre de batiment
    fread(&nombreBatiment,sizeof(int),1,fichier);

    //Lecture des structure
    for(int i = 0 ; i<nombreBatiment ; i++)
    {
        fread(&tableauHabitation[i],sizeof(t_habitation),1,fichier);
        //printf("%d %d %d %d\n",i,tableauHabitation[i].nb_habitants,tableauHabitation[i].niveau,tableauHabitation[i].numero);
    }

    /*for(int i=0 ; i<nombreBatiment ; i++)
    {
        printf("%d %d %d %d\n",i,tableauHabitation[i].nb_habitants,tableauHabitation[i].niveau,tableauHabitation[i].numero);
    }*/

    //Fermeture du fichier
    fclose(fichier);

    return nombreBatiment;
}

int chargerTableauChateauEau(t_chateauEau tableauHabitation[], char* nomFichier)
{
    //Déclaration des variables
    int nombreBatiment = 0;
    FILE* fichier = fopen(nomFichier,"rb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : %s",nomFichier);
    }

    //Lecture du nombre de batiment
    fread(&nombreBatiment,sizeof(int),1,fichier);

    //Lecture des structure
    for(int i = 0 ; i<nombreBatiment ; i++)
    {
        fread(&tableauHabitation[i],sizeof(t_chateauEau),1,fichier);
    }

    //Fermeture du fichier
    fclose(fichier);

    return nombreBatiment;
}

int chargerTableauCentrale(t_centrales tableauHabitation[], char* nomFichier)
{
    //Déclaration des variables
    int nombreBatiment = 0;
    FILE* fichier = fopen(nomFichier,"rb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : %s",nomFichier);
    }

    //Lecture du nombre de batiment
    fread(&nombreBatiment,sizeof(int),1,fichier);

    //Lecture des structure
    for(int i = 0 ; i<nombreBatiment ; i++)
    {
        fread(&tableauHabitation[i],sizeof(t_centrales),1,fichier);
    }

    //Fermeture du fichier
    fclose(fichier);

    return nombreBatiment;
}

void sauvegardeTempsCycle(int nombreHabitation, t_habitation tableauHab[],unsigned long tempsPause, unsigned long tempsChrono)
{
    //Calcul du temps actuel
    unsigned long diff;
    time_t tempsact = time(NULL);//On récupere le temps actuel
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);

    //Ouverture du fichier
    FILE* fichier = fopen("Sauvegarde/fichierTemps.bin","wb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : temps");
    }

    for(int i=0 ; i<nombreHabitation ; i++)
    {
        diff = difftime(tempsact,tableauHab[i].tempsCrea);
        fwrite(&diff,sizeof(unsigned long),1,fichier);
    }

    //Fermeture du fichier
    fclose(fichier);
}

void chargementTempsCycle(int nombreMaison,t_habitation tableauHab[],unsigned long tempsPause, unsigned long tempsChrono)
{
    //Calcul du temps Actuel
    unsigned long diff;
    time_t tempsdep = time(NULL);
    tempsdep= modificationTemps(tempsdep,0,tempsPause);
    tempsdep= modificationTemps(tempsdep,1,tempsChrono);

    //Ouverture fichier
    FILE* fichier = fopen("Sauvegarde/fichierTemps.bin","rb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : temps");
    }

    //Chargement des temps de cycle
    for(int i=0 ; i<nombreMaison ;i++)
    {
        fread(&diff,sizeof(unsigned long),1,fichier);
        tableauHab[i].tempsCrea = modificationTemps(tempsdep,0,diff);
    }

    //Fermeture du fichier
    fclose(fichier);
}

void sauvegardeChrono(time_t tempsdepart,unsigned long tempsPause, unsigned long tempsChrono)
{
    time_t tempsact = time(NULL);
    tempsact= modificationTemps(tempsact,0,tempsPause);
    tempsact= modificationTemps(tempsact,1,tempsChrono);
    unsigned long diff=difftime(tempsact,tempsdepart);

    //Ouverture du fichier
    FILE* fichier = fopen("Sauvegarde/fichierTempsChrono.bin","wb+");
    printf("%d %d \n",tempsPause,tempsChrono);

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : tempsChrono");
    }

    //Enregistement du temps
    fwrite(&diff,sizeof(unsigned long),1,fichier);
    fwrite(&tempsPause,sizeof(unsigned long),1,fichier);
    fwrite(&tempsChrono,sizeof(unsigned long),1,fichier);

    //fermeture du fichier
    fclose(fichier);
}

void chargementTempsChrono(unsigned long* tempsChrono,unsigned long* tempsPause)
{
    //Déclaration variables
    unsigned long diff,tempsChronoFichier ;
    //Ouverture du fichier
    FILE* fichier = fopen("Sauvegarde/fichierTempsChrono.bin","rb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : tempsChrono");
    }

    fread(&diff,sizeof(unsigned long),1,fichier);
    //fread(tempsPause,sizeof(unsigned long),1,fichier);
    fread(&tempsChronoFichier,sizeof(unsigned long),1,fichier);

    *tempsChrono = diff;


    //Fermeture du fichier
    fclose(fichier);

}

void sauvegardeArgent(int argent)
{
    //Ouverture du fichier
    FILE* fichier = fopen("Sauvegarde/fichierArgent.bin","wb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : argent");
    }

    printf("%d \n",argent);
    fwrite(&argent,sizeof(int),1,fichier);

    //Fermeture du fichier
    fclose(fichier);
}

int chargementArgent()
{
    //Déclaration des variables
    int argent;
    //Ouverture du fichier
    FILE* fichier = fopen("Sauvegarde/fichierArgent.bin","rb+");

    //test ouverture fichier
    if(fichier == NULL)
    {
        printf("Erreur ouverture fichier : argent");
    }

    fread(&argent,sizeof(int),1,fichier);

    //Fermeture du fichier
    fclose(fichier);
    printf("%d \n",argent);
    return argent;
}