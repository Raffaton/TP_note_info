#include <stdio.h>

void creer_grille(int taille, int grille[9][9])
{
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            grille[i][j] = 0;
        }
    }
}

void afficher_grille(int taille, int grille[9][9])
{
    for (int i = 0; i < taille; i++)
    {
        if (i > 0)
        {
            for (int k = 0; k < taille; k++)
            {
                printf("--"); 
                if (k < taille - 1)
                    printf("+");
            }
            printf("\n");
        }
        for (int j = 0; j < taille; j++)
        {
            if (grille[i][j] != 0)
            {
                printf(" %d", grille[i][j]);
            }
            else
            {
                printf("  ");
            }
            if (j < taille - 1)
                printf("|");
        }
        printf("\n");
    }
}

int verification_grille(int ligne, int colonne, int grille[9][9], int taille, int nombre)
{
    int verif = 1;

    if (nombre < 0 || nombre > taille)
    {
        verif = 0;
        printf("Erreur : Le nombre ne doit pas etre plus grand que la taille de la grille.\n");
    }

    if (ligne < 0 || ligne >= taille || colonne < 0 || colonne >= taille && verif == 1)
    {
        verif = 0;
        printf("Erreur: Indices hors limites. Ligne %d, Colonne %d\n", ligne + 1, colonne + 1);
    }

    if (verif == 1)
    {
        for (int i = 0; i < taille; i++)
        {
            if (ligne != i && grille[i][colonne] == nombre)
            {
                verif = 0;
                printf("Erreur: Le nombre %d existe deja dans la colonne %d\n", nombre, colonne + 1);
                break;
            }
        }
    }

    if (verif == 1)
    {
        for (int j = 0; j < taille; j++)
        {
            if (colonne != j && grille[ligne][j] == nombre)
            {
                verif = 0;
                printf("Erreur: Le nombre %d existe deje dans la ligne %d\n", nombre, ligne + 1);
                break;
            }
        }
    }

    return verif;
}


void modifier_grille(int ligne, int colonne, int grille[9][9], int nombre, int taille)
{
    int erreur = 0;

        if (verification_grille(ligne, colonne, grille, taille, nombre))
        {
            grille[ligne][colonne] = nombre;
        }
}

int main()
{
    int taille = 10;
    int grille[9][9];
    int envie = 1;

    while (taille > 9 || taille < 1)
    {
        printf("Quelle est la taille du carre (entre 1 et 9) ? ");
        scanf("%d", &taille);
    }

    creer_grille(taille, grille);
    afficher_grille(taille, grille);

    while (1)
    {
        printf("Voulez-vous changer une valeur de tableau (0 pour NON / 1 pour OUI) : ");
        scanf("%d", &envie);

        if (envie == 1)
        {
            int ligne;
            int colonne;
            int nombre;

            printf("Indiquez la ligne, colonne et la nouvelle valeur que vous voulez modifier : ");
            scanf("%d %d %d", &ligne, &colonne, &nombre);
            modifier_grille(ligne - 1, colonne - 1, grille, nombre, taille); 
            printf("\nGrille apres modification :\n");
            afficher_grille(taille, grille);
        }
        else
        {
            break;
        }
    }

    return 0;
}
