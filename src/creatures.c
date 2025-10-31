#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/creatures.h"

void generer_creatures(CreatureMarine creatures[], int *nb_creatures, int profondeur) {
    *nb_creatures = rand() % 4 + 1; // entre 1 et 4
    for (int i = 0; i < *nb_creatures; i++) {
        int type = rand() % 5; // 0 à 4
        creatures[i].id = i + 1;
        creatures[i].est_vivant = 1;

        switch (type) {
            case 0: // Kraken
                strcpy(creatures[i].nom, "Kraken");
                creatures[i].points_de_vie_max = rand() % 61 + 120; // 120-180
                creatures[i].attaque_minimale = 25;
                creatures[i].attaque_maximale = 40;
                creatures[i].defense = 8;
                creatures[i].vitesse = 2;
                strcpy(creatures[i].effet_special, "double_attaque");
                break;
            case 1: // Requin
                strcpy(creatures[i].nom, "Requin-Tigre");
                creatures[i].points_de_vie_max = rand() % 41 + 60; // 60-100
                creatures[i].attaque_minimale = 15;
                creatures[i].attaque_maximale = 25;
                creatures[i].defense = 4;
                creatures[i].vitesse = 8;
                strcpy(creatures[i].effet_special, "frenesie");
                break;
            case 2: // Méduse
                strcpy(creatures[i].nom, "Meduse Bleue");
                creatures[i].points_de_vie_max = rand() % 21 + 20; // 20-40
                creatures[i].attaque_minimale = 8;
                creatures[i].attaque_maximale = 15;
                creatures[i].defense = 2;
                creatures[i].vitesse = 6;
                strcpy(creatures[i].effet_special, "paralysie");
                break;
            case 3: // Poisson-Épée
                strcpy(creatures[i].nom, "Poisson-Epee");
                creatures[i].points_de_vie_max = rand() % 21 + 70; // 70-90
                creatures[i].attaque_minimale = 18;
                creatures[i].attaque_maximale = 28;
                creatures[i].defense = 5;
                creatures[i].vitesse = 7;
                strcpy(creatures[i].effet_special, "ignore_def");
                break;
            case 4: // Crabe géant
                strcpy(creatures[i].nom, "Crabe Geant");
                creatures[i].points_de_vie_max = rand() % 41 + 80; // 80-120
                creatures[i].attaque_minimale = 12;
                creatures[i].attaque_maximale = 20;
                creatures[i].defense = 10;
                creatures[i].vitesse = 3;
                strcpy(creatures[i].effet_special, "reduction_degats");
                break;
        }

        // Ajuster selon la profondeur (plus profond = plus fort)
        creatures[i].points_de_vie_max += profondeur / 10;
        creatures[i].points_de_vie_actuels = creatures[i].points_de_vie_max;
    }
}

void afficher_creatures(const CreatureMarine creatures[], int nb_creatures) {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for (int i = 0; i < nb_creatures; i++) {
        printf("🪸 %s (PV: %d/%d, ATK: %d-%d, DEF: %d, VIT: %d, Effet: %s)\n",
            creatures[i].nom,
            creatures[i].points_de_vie_actuels,
            creatures[i].points_de_vie_max,
            creatures[i].attaque_minimale,
            creatures[i].attaque_maximale,
            creatures[i].defense,
            creatures[i].vitesse,
            creatures[i].effet_special
        );
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
