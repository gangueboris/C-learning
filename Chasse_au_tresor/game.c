#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#define VIDE 0
#define DECOUVERTE 1
#define TRESOR_CACHE 2
#define TRESOR_DECOUVERT 3
#define TAILLE_GRILLE 20

// Fonction d'initialisation de la grille
void InitialiserGrille(int grille[TAILLE_GRILLE][TAILLE_GRILLE])
{
    for(int i = 0 ; i < TAILLE_GRILLE; i++)
    {
        for(int j = 0;  j < TAILLE_GRILLE ; j++)
        {
            grille[i][j] = VIDE;
            
        }
    }
}

//Fonction d'affichage de la grille
void AffichageGrille(int grille[TAILLE_GRILLE][TAILLE_GRILLE])
{   printf(" --------------\n");
    printf("| Grille de jeu |\n");
    printf(" --------------\n");
    for(int i = 0 ; i < TAILLE_GRILLE; i++)
    {
        for(int j = 0;  j < TAILLE_GRILLE ; j++)
        {
            switch (grille[i][j])
            {
            case VIDE:
                printf("X ");
                if(j == 19) ;
                break;
            case DECOUVERTE:
                printf("  ");
                if(j == 19) ;
                break;
            case TRESOR_CACHE:
                printf("X ");
                if(j == 19) ;
                break;
            case TRESOR_DECOUVERT:
                printf("$ ");
                if(j == 19) ;
                break;
            
            default:
                break;
            }
        }
        printf("\n");
    }
}

// Fonction de demande de coordonnees
void DemanderLigneColonne(int* ligne, int* colonne)
{
    do
    {
        printf("\nEntrer la prochaine colonne a jouer ? ");
        scanf(" %d",colonne);
        printf("Entrer la prochaine ligne a jouer ? ");
        scanf(" %d",ligne);
       
    } while (*ligne < 0 || *ligne > TAILLE_GRILLE - 1 || *colonne < 0 || *colonne > TAILLE_GRILLE - 1);
    
}

// Fonction d'initialisation du tresor
void CacherTresor(int grille[TAILLE_GRILLE][TAILLE_GRILLE], int* positionX, int* positionY)
{
    grille[*positionX][*positionY] = 2;
    AffichageGrille(grille); 
}
// Fonction d'affichage de la distance
void AfficherDistance(int x1, int y1, int x2, int y2){
    int distance = abs(x2 - x1) + abs(y2 - y1);
    printf(" ------------\n");
    printf("| Distance: |\n");  
    printf(" ------------\n");
    printf("Le tresor se trouve a une distance d'environ %d cases.\n",distance);
  
}

// Fonction d’affichage des informations de direction
void AfficherInformations(int x1, int y1, int x2, int y2)
{
    int x_diff = x2 - x1;
    int y_diff = y2 - y1;

    printf(" -----------\n");
    printf("| Direction |\n");
    printf(" -----------\n");

    if (x_diff > 0 && x2 < TAILLE_GRILLE && y_diff == 0) {
        printf("Le tresor se trouve a droite\n");
    } else if (x_diff < 0 && x2 < TAILLE_GRILLE && y_diff == 0) {
        printf("Le tresor se trouve a gauche\n");
    }

    if (y_diff > 0 && y2 < TAILLE_GRILLE && x_diff == 0) {
        printf("Le tresor se trouve en bas\n");
    } else if (y_diff < 0 && y2 < TAILLE_GRILLE && x_diff == 0) {
        printf("Le tresor se trouve en haut\n");
    }

    if (x_diff > 0 && y_diff > 0) {
        printf("Le tresor se trouve en bas a droite\n");
    } else if (x_diff < 0 && y_diff > 0 && x2 < TAILLE_GRILLE && y2 < TAILLE_GRILLE) {
        printf("Le tresor se trouve en bas a gauche\n");
    } else if (x_diff < 0 && y_diff < 0 && x2 < TAILLE_GRILLE && y2 < TAILLE_GRILLE) {
        printf("Le tresor se trouve en haut a gauche\n");
    }
}
