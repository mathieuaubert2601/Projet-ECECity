//
// Created by thiba on 29/10/2022.
//

#include "header.h"

void initialisationAllegro()
{
    allegro_init();

    set_color_depth(desktop_color_depth());

    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0))!= 0)

    {
        allegro_message("Pb de mode graphique") ;

        allegro_exit();

        exit(EXIT_FAILURE); }
}
