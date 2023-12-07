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
    //input = getchar();
    
    // Initialisation de la grille
    InitialiserGrille(grille);

   //Initialisation des positions du tresor 
   srand(time(NULL));
   positionX = rand()%TAILLE_GRILLE ;
   positionY = rand()%TAILLE_GRILLE ;
   // Utilisation de la fonction cacherTresor
   CacherTresor(grille,&positionX,&positionY);

   while (colonne != positionX && ligne!= positionY)
   {
    //Demande de la ligne et de la colonne
     DemanderLigneColonne(&ligne,&colonne);
        if (ligne == positionX && colonne == positionY)
        {
            grille[ligne][colonne] = TRESOR_DECOUVERT;
        }
        else
        {
            grille[ligne][colonne] = DECOUVERTE;
        }
        
    AffichageGrille(grille);
    // Utilisation de la fonction Afficher derection 
    AfficherInformations(colonne,ligne,positionX,positionY);

    // Affichage de la direction
     AfficherDistance(colonne,ligne,positionX,positionY);
   
   }
   

    return 0 ;
}