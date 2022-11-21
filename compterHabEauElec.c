//
// Created by thiba on 05/11/2022.
//

int compterHab(int map[35][45])
{
    int nb_habitants = 0;
    int nb_cabanes = 0;
    int nb_maisons = 0;
    int nb_immeuble = 0;
    int nb_gratte_ciel = 0;

    for (int i=0;i<35;i++)
    {
        for (int j=0; j<45;j++)
        {
            if (map[i][j]==4)
                nb_cabanes++;
            if (map[i][j]==5)
                nb_maisons++;
            if (map[i][j]==6)
                nb_immeuble++;
            if (map[i][j]==7)
                nb_gratte_ciel++;
        }
    }

    nb_habitants = nb_cabanes*10+nb_maisons*50+nb_immeuble*100+nb_gratte_ciel*1000;

    return nb_habitants;
}

int compterElec(int map[35][45])
{
    int nb_elec=0;
    int nb_centrales=0;

    for (int i=0;i<35;i++)
    {
        for (int j=0; j<45;j++)
        {
            if (map[i][j]==15)
                nb_centrales++;
        }
    }

    nb_elec=nb_centrales*5000;

    return nb_elec;
}

int compterEau(int map[35][45])
{
    int nb_eau=0;
    int nb_chateaux=0;

    for (int i=0;i<35;i++)
    {
        for (int j=0; j<45;j++)
        {
            if (map[i][j]==14)
                nb_chateaux++;
        }
    }

    nb_eau= nb_chateaux*5000;

    return nb_eau;
}