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
                printf("---");
            }
        }
        printf("\n");
        for (int j = 0; j < taille; j++)
        {
            if (grille[i][j] != 0)
            {
                if(j < taille-1)
                {
                    printf(" %d |", grille[i][j]);
                }
                else
                {
                    printf(" %d ", grille[i][j]);
                }
                
            }
            else
            {
                if(j < taille -1 )
                {
                    printf("  |");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void modifier_grille(int ligne, int colonne, int grille[9][9], int nombre)
{
    if (ligne >= 0 && ligne < 9 && colonne >= 0 && colonne < 9)
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
        printf("Voulez vous changer une valeur de tableau (0 pour NON / 1 pour OUI) : ");
        scanf("%d", &envie);
        
        if (envie == 1)
        {
            int ligne;
            int colonne;
            int nombre;

            printf("Indiquez la ligne, colone et la nouvelle valeur que vous voulez modifier : ");
            scanf("%d %d %d", &ligne, &colonne, &nombre);
            modifier_grille(ligne-1, colonne-1, grille, nombre);
            printf("\nGrille apres modification:\n");
            afficher_grille(taille, grille);
        }
        else
        {
            break;
        }
    }

    return 0;
}
