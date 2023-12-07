#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_VALUE 100
#define N 20
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))


struct s_resto{
    char nom[MAX_VALUE];
    int qualite;
    int distance;
    int temps;
};
// Lecture des informations du restaurant
struct s_resto SaisirResto(){
       struct s_resto new_resto ;
       printf("Saisir le nom du restaurant: \n");
       fgets(new_resto.nom,MAX_VALUE,stdin);
       new_resto.nom[strlen(new_resto.nom) - 1] = '\0';
       
       do{
       printf("Saisir la qualite du restaurant (1 - 10):\n");
       scanf(" %d",&new_resto.qualite);
       break;
       }while(new_resto.qualite < 1 || new_resto.qualite > 10);

       do{
       printf("Saisir la distance qui vous separe du restaurant en km:\n");
       scanf(" %d",&new_resto.distance) ;
       break ;
       }while(new_resto.distance < 0);
       new_resto.temps = 999; 
    return new_resto ;     
}
// Lecture de la liste des restaurants
void SaisirRestos(struct s_resto tableauRestos[N], int* nombreRestos){
      for(int i = 0 ; i < *nombreRestos ; i++){
          tableauRestos[i] = SaisirResto() ;
        }     
}

//Affichage des restaurant
void AfficherRestos (struct s_resto tableauRestos[N], int nombreRestos){
    for(int i = 0 ; i < nombreRestos ; i++){
        printf("____RESTAURANT____\n");
        printf("Nom: %s\n",tableauRestos[i].nom);
        printf("Qualite: %d\n",tableauRestos[i].qualite);
        printf("Distance: %d\n",tableauRestos[i].distance);
        printf("Temps :%d\n",tableauRestos[i].temps);
    }

}
//
int chercherRestos(struct s_resto tableauRestos[N], int nombreRestos){

}
int min(int x, int y){
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int main(){
    struct s_resto tableauRestos[N];
    int nombreRestos;

    printf("Saisir le nombre de restaurant:\n");
    scanf(" %d",&nombreRestos);
    SaisirRestos(tableauRestos,&nombreRestos);
    AfficherRestos(tableauRestos,nombreRestos);
     






    return 0;
}