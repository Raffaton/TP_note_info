#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creer_grille(int taille, int grille[9][9]) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grille[i][j] = 0;
        }
    }
}

void afficher_grille(int taille, int grille[9][9]) {
    for (int i = 0; i < taille; i++) {
        if (i > 0) {
            for (int k = 0; k < taille; k++) {
                printf("--");
                if (k < taille - 1)
                    printf("+");
            }
            printf("\n");
        }
        for (int j = 0; j < taille; j++) {
            if (grille[i][j] != 0) {
                printf(" %d", grille[i][j]);
            } else {
                printf("  ");
            }
            if (j < taille - 1)
                printf("|");
        }
        printf("\n");
    }
}


int grille_est_vide(int grille[9][9], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (grille[i][j] != 0) {
                return 0; 
            }
        }
    }
    return 1;
}

int grille_est_complete(int grille[9][9], int taille) {
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (grille[i][j] == 0) {
                return 0; 
            }
        }
    }
    return 1;
}

int verification_grille(int ligne, int colonne, int grille[9][9], int taille, int nombre, int choix) {
    // La variable choix sert à ce que je sache si la fonction est utilisée par l'ordinateur ou 
    // par l'utilisateur, si c'est par l'ordinateur, les messages d'erreur ne doivent pas être affichés

    int verif = 1;

    if (nombre < 1 || nombre > taille) 
    {
        verif = 0;
        if (choix == 1)
        {
            printf("Erreur : Le nombre ne doit pas etre plus grand que la taille de la grille.\n");
        }        
    } 

    else if (grille[ligne][colonne] != 0) 
    { 
        verif = 0;
        if (choix == 1)
        {
            printf("Erreur : Vous avez deja entre un nombre sur cette case.\n");
        }        
    } 

    else if (ligne < 0 || ligne >= taille || colonne < 0 || colonne >= taille) 
    { 
        verif = 0;
        if (choix == 1)
        {
            printf("Erreur : Indices hors limites. Ligne %d, Colonne %d\n", ligne + 1, colonne + 1);
        }
    } 

    else 
    { 
        for (int i = 0; i < taille; i++) {
            if (ligne != i && grille[i][colonne] == nombre) 
            {
                verif = 0;
                if (choix == 1)
                {
                    printf("Erreur : Le nombre %d existe deja dans la colonne %d\n", nombre, colonne + 1);
                }
                break;
            }
        }

        for (int j = 0; j < taille; j++) {
            if (colonne != j && grille[ligne][j] == nombre) 
            {
                verif = 0;
                if (choix == 1)
                {
                    printf("Erreur : Le nombre %d existe deja dans la ligne %d\n", nombre, ligne + 1);
                }
                break;
            }
        }
    }

    return verif;
}

int modifier_grille(int ligne, int colonne, int grille[9][9], int nombre, int taille, int choix) {
    if (verification_grille(ligne, colonne, grille, taille, nombre, choix)) {
        grille[ligne][colonne] = nombre;
        return 1; 
    }
    return 0; 
}

int completer_grille(int grille[9][9], int taille, int choix)
{
    // A nouveau la variable choix sert à ce que je sache si la fonction est utilisée pour remplir la grille 
    // au tout début ou pour la résoudre. Ce qui me permet d'adapter les dialogues !
    int vie = 3;
    int envie;
    if (choix == 1)
    {
        printf("\nVous allez tenter de resoudre le sudoku, attention, a chaque proposition incorrecte, 1 des 3 vies que vous possedez sera perdue !\n");
    }
    while (1) {
            printf("\nVoulez-vous ajouter une valeur au tableau (0 pour NON / 1 pour OUI) : ");
            scanf("%d", &envie);

            if (envie == 1) 
            {
                int ligne;
                int colonne;
                int nombre;

                printf("Indiquez la ligne, colonne et la nouvelle valeur que vous voulez modifier : ");
                scanf("%d %d %d", &ligne, &colonne, &nombre);
                if (modifier_grille(ligne - 1, colonne - 1, grille, nombre, taille, 1)) 
                {
                    printf("\nGrille apres modification :\n");
                    afficher_grille(taille, grille);
                }
                else
                {
                    if (choix == 1)
                        {
                            vie -= 1;
                            printf("\nAttention vous vous etes trompe, vous n'avez plus que %d vie !\n", vie);
                            printf("Reflechissez bien :\n");
                            afficher_grille(taille, grille);
                        }   
                }
            } else {
                break;
            }
            if (vie == 0)
            {
                printf("Malheursement vous avez use toutes vos vies... Reessayer une autre fois !");
                break;
            }
            else if (grille_est_complete(grille, taille)) 
            {
                printf("Felicitations ! Vous avez complete le Sudoku !!!\n");
                break;
            }
        }
}

void remplissage_auto(int niveau, int grille[9][9], int taille) {
    srand(time(NULL));
    int remplissage = taille*taille;

    switch (niveau) {
    case 1:
        remplissage = remplissage / 2; 
        break;
    case 2:
        remplissage = remplissage / 3; 
        break;
    case 3:
        remplissage = remplissage / 4; 
        break;
    }

    for (int i = 0; i < remplissage; i++) {
        int ligne = rand() % taille; 
        int colonne = rand() % taille; 
        int nombre = rand() % taille + 1; 

        if (modifier_grille(ligne, colonne, grille, nombre, taille, 0) == 0) {
            i -= 1; 
        }
    }
}

int main() {
    int taille = 0; 
    int grille[9][9];
    int choix;
    int choix_resolution;
    int niveau;

    while (taille < 1 || taille > 9) 
    { 
        printf("Quelle est la taille du carre (entre 1 et 9) ? ");
        scanf("%d", &taille);
    }

    creer_grille(taille, grille);
    afficher_grille(taille, grille);

    printf("Voulez-vous faire les modifications vous-meme (0 pour NON / 1 pour OUI) ? ");
    scanf("%d", &choix);

    if (choix == 1) 
    {
        completer_grille(grille, taille, 0);
    } 
    else 
    {
        printf("Quel niveau voulez-vous (1, 2 ou 3) ? ");
        scanf("%d", &niveau);
        remplissage_auto(niveau, grille, taille);
        printf("\nGrille apres remplissage automatique :\n");
        afficher_grille(taille, grille);
    }

    printf("Voulez-vous resoudre ce tableau (0 pour NON / 1 pour OUI) ? ");
    scanf("%d", &choix_resolution);

    if (choix_resolution == 1) 
    {
        if (grille_est_vide(grille, taille)) 
        {
            printf("Erreur : La grille est vide, il est donc impossible de la résoudre !\n");
        } else {
            completer_grille(grille, taille, 1);
        }
    }

    return 0;
}
