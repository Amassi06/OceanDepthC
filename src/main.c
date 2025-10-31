#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/creatures.h"

int main() {
    srand(time(NULL));

    CreatureMarine creatures[4];
    int nb_creatures;
    int profondeur = 150;

    generer_creatures(creatures, &nb_creatures, profondeur);
    afficher_creatures(creatures, nb_creatures);

    return 0;
}
