#ifndef CREATURES_H
#define CREATURES_H

typedef struct {
    int id;
    char nom[30];
    int points_de_vie_max;
    int points_de_vie_actuels;
    int attaque_minimale;
    int attaque_maximale;
    int defense;
    int vitesse;
    char effet_special[20];
    int est_vivant;
} CreatureMarine;

void generer_creatures(CreatureMarine creatures[], int *nb_creatures, int profondeur);
void afficher_creatures(const CreatureMarine creatures[], int nb_creatures);

#endif
