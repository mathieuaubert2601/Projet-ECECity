#include "header.h"

time_t modificationTemps(time_t tempsAModifier,int ajouterEnlever,int nombreSecondes)
{
    //Déclaration des variables
    struct tm * tempsModification = localtime( & tempsAModifier);
    int nombreS,nombreM,nombreH;

    if(nombreSecondes >= 60)
    {
        nombreS = nombreSecondes%60;
        nombreM = nombreSecondes / 60;
        nombreH=0;
    }
    else
    {
        nombreS = nombreSecondes;
        nombreM = 0;
        nombreH=0;
    }

    //On enlève ou rajoute du temps
    if(ajouterEnlever == 1)
    {
        if(nombreS >= (60 - tempsModification->tm_sec))
        {
            nombreS = nombreS - (60 - tempsModification->tm_sec);
            nombreM ++;

            if(nombreM >= (60 - tempsModification->tm_min))
            {
                nombreM = nombreM - (60 - tempsModification->tm_min);
                nombreH ++;
                tempsModification->tm_sec = nombreS;
                tempsModification->tm_min = nombreM;
                tempsModification->tm_hour = tempsModification->tm_hour + nombreH;
            }
            else
            {
                tempsModification->tm_sec  = tempsModification->tm_sec + nombreS;
                tempsModification->tm_min = tempsModification->tm_min + nombreM;
                tempsModification->tm_hour = tempsModification->tm_hour + nombreH;
            }
        }
        else
        {
            tempsModification->tm_sec  = tempsModification->tm_sec + nombreS;
            tempsModification->tm_min = tempsModification->tm_min + nombreM;
            tempsModification->tm_hour = tempsModification->tm_hour + nombreH;
        }

    }
    else if(ajouterEnlever == 0)
    {
        if(nombreS >= tempsModification->tm_sec)
        {
            nombreS = 60 -(nombreS - tempsModification->tm_sec);
            nombreM ++;

            if(nombreM >= (nombreM - tempsModification->tm_min))
            {
                nombreM = 60 - (nombreM - tempsModification->tm_min);
                nombreH ++;
                tempsModification->tm_sec = nombreS;
                tempsModification->tm_min = nombreM;
                tempsModification->tm_hour = tempsModification->tm_hour - nombreH;
            }
            else
            {
                tempsModification->tm_sec  = tempsModification->tm_sec - nombreS;
                tempsModification->tm_min = tempsModification->tm_min - nombreM;
                tempsModification->tm_hour = tempsModification->tm_hour - nombreH;
            }
        }
        else
        {
            tempsModification->tm_sec = tempsModification->tm_sec - nombreS;
            tempsModification->tm_min = tempsModification->tm_min - nombreM;
            tempsModification->tm_hour = tempsModification->tm_hour - nombreH;
        }
    }
    return mktime(tempsModification);
}