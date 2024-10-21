#include <stdio.h>

void creer_grille(int taille, int grille[9][9])
{
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j ++)
        {
            grille[i][j] = 0;
        }
    }
}

void afficher_grille(int taille, int grille[9][9])
{
    for (int i = 0; i < taille; i ++)
    {
        for (int j = 0; j < taille; j++)
        {
            printf("%d ", grille[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int taille = 10;
    int grille[9][9];
    while (taille > 9)
    {
        printf("Quel est la taille du carre ? ");
        scanf("%d", &taille);
    }
    creer_grille(taille, grille);
    afficher_grille(taille, grille);

    return 0;
}
#include <stdio.h>

void creer_grille(int taille, int grille[9][9])
{
    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j ++)
        {
            grille[i][j] = 0;
        }
    }
}

void afficher_grille(int taille, int grille[9][9])
{
    for (int i = 0; i < taille; i ++)
    {
        for (int j = 0; j < taille; j++)
        {
            printf("%d ", grille[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int taille = 10;
    int grille[9][9];
    while (taille > 9)
    {
        printf("Quel est la taille du carre ? ");
        scanf("%d", &taille);
    }
    creer_grille(taille, grille);
    afficher_grille(taille, grille);

    return 0;
}
