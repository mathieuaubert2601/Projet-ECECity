#include "header.h"

void creer_map(BITMAP* page)
{
    BITMAP* tuile = load_bitmap("map/tuile_test.bmp",NULL);

    int map[35][45];

    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            map[i][j] = 1;
        }
    }

    for (int i = 0; i<35; i++) {
        for (int j = 0; j < 45; j++) {
            if (map[i][j] == 1) {
                masked_stretch_blit(tuile, page, 0, 0, 77, 77, j * 20, i * 20, 20, 20);
            }
        }
    }

    show_mouse(page);
    blit(page,screen,0,0,0,0,1024,768);
}