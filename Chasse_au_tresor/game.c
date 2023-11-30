#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
            grille[i][j] = 0;
            
        }
    }
}

//Fonction d'affichage de la grille
void AffichageGrille(int grille[TAILLE_GRILLE][TAILLE_GRILLE])
{
    for(int i = 0 ; i < TAILLE_GRILLE; i++)
    {
        for(int j = 0;  j < TAILLE_GRILLE ; j++)
        {
            switch (grille[i][j])
            {
            case 0:
                printf("X ");
                if(j == 19) printf("\n");
                break;
            case 1:
                printf("  ");
                if(j == 19) printf("\n");
                break;
            case 2:
                printf("X ");
                if(j == 19) printf("\n");
                break;
            case 3:
                printf("$ ");
                if(j == 19) printf("\n");
                break;
            
            default:
                break;
            }

        }
    }
}

// Fonction de demande de coordonnees
void DemanderLigneColonne(int* ligne, int* colonne)
{
    do
    {
        printf("Entrer la prochaine colonne a jouer ? ");
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
    printf("---------------\n");
    printf("| Distance: %d |\n",distance);    
}

// Fonction d’affichage des informations de direction
void AfficherInformations(int x1, int y1, int x2, int y2){
    int x1x2 ,y1y2;
    x1x2 = x2 - x1 ;
    y1y2 = y2 - y1;
   
    if(x1x2 > 0) printf("Le tresor se trouve a droite\n");
    else printf("Le tresor se trouve a gauche\n");
    if(y1y2 > 0) printf("Le tresor se trouve en bas\n");
    else printf("Le tresor se trouve en haut\n");
    if(x1x2 > 0 && y1y2 > 0) printf("Le tresor se trouve en haut à droite");
    else printf("Le tresor se trouve en bas à gauche");
    
    
}



int main()
{
    int grille[TAILLE_GRILLE][TAILLE_GRILLE] ;
    int ligne;
    int colonne;
    int positionX;
    int positionY;
    InitialiserGrille(grille);
   // AffichageGrille(grille);
   //DemanderLigneColonne(&ligne,&colonne);
   //printf("ligne:%d \n colonne:%d\n",ligne,colonne);

   // Initialisation des positions
   srand(time(NULL));
   positionX = rand()%20 ;
   positionY = rand()%20 ;
   //printf("%d %d",positionX,positionY);
   
   // Utilisation de la fonction cacherTresor
   CacherTresor(grille,&positionX,&positionY);
   // Utilisation de la fonction AfficherDistance
   AfficherDistance(1,8,7,5);
   AfficherInformations(3,4,1,1);



   
    



    return 0 ;
}