#include "header.h"

void AffichageBouton(BITMAP* bouton,BITMAP* boutonInv, BITMAP* page,int sourcex,int sourcey,int destx,int desty,int longueur, int hauteur)
{
    if((mouse_x>=(destx)&& mouse_x<=(destx+longueur))&& (mouse_y)>=(desty)&& mouse_y<=(desty+hauteur))
    {
        masked_blit(boutonInv,page,sourcex,sourcey,destx,desty,longueur,hauteur);
    }
    else
        masked_blit(bouton,page,sourcex,sourcey,destx,desty,longueur,hauteur);
}