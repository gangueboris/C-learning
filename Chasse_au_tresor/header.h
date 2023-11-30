#ifndef GAME_H
#define GAME_H
#define TAILLE_GRILLE 20

void InitialiserGrille(int grille[TAILLE_GRILLE][TAILLE_GRILLE]);

void AffichageGrille(int grille[TAILLE_GRILLE][TAILLE_GRILLE]);

void DemanderLigneColonne(int* ligne, int* colonne);

void CacherTresor(int grille[TAILLE_GRILLE][TAILLE_GRILLE], int* positionX, int* positionY);

void AfficherInformations(int x1, int y1, int x2, int y2);





#endif