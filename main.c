//
// Created by thiba on 29/10/2022.
//


#include "header.h"

int main()
{
    initialisationAllegro();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    srand(time(NULL));

    return 0;
}
END_OF_MAIN();
