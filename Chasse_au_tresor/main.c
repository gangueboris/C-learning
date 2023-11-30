#include "header.h"
#include "game.c"
#include <time.h>




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
   AfficherInformations(8,9,positionX,positionY);



   
    



    return 0 ;
}