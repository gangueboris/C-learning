#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_VALUE 100
#define N 20


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
       fgetc(stdin);
       break;
       }while(new_resto.qualite < 1 || new_resto.qualite > 10);

       do{
       printf("Saisir la distance qui vous separe du restaurant en km:\n");
       scanf(" %d",&new_resto.distance) ;
       fgetc(stdin);
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

int min(int x, int y){
    return x < y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}
// 4 -
int chercherRestos(struct s_resto tableauRestos[N], int nombreRestos){
    int q ,d,t ,id ;
    float attraitMax = 0 ,attrait;
    for(int i = 0 ; i < nombreRestos; i++){
        q = tableauRestos[i].qualite ;
        d = tableauRestos[i].distance ;
        t = tableauRestos[i].temps ;
        attrait = max(0,q - pow(d,2) + pow(min(t, 10),2));
        if (attrait > attraitMax){ // Verifier quelle est la valeur la plus grande dans un tableau
            id = i;
            attraitMax = attrait;
        }
    }
     return id ;
}

// 5 - Etablissement du planning
void planning(struct s_resto tableauRestos[N], int nombreRestos){;
     int id ;
      printf("_________Planning________\n");
    //printf("\nPlanning des prochains restaurants sur 20 jours :\n");
    for (int i = 0; i < 20; i++) {
        int id_ = chercherRestos(tableauRestos, nombreRestos);
        printf("%d %s\n", i, tableauRestos[id_].nom);
		tableauRestos[id_].temps = 0;

		for (int j = 0; j < nombreRestos; j++) {
			if (j != id_ ) {
				tableauRestos[j].temps++;
			}
    	}
    }
}

int main(){
    struct s_resto tableauRestos[N];
    int nombreRestos, id;

    printf("Saisir le nombre de restaurant:\n");
    scanf(" %d",&nombreRestos);
    fgetc(stdin);
    SaisirRestos(tableauRestos,&nombreRestos);
    AfficherRestos(tableauRestos,nombreRestos);
    id = chercherRestos(tableauRestos,nombreRestos) ;
    printf("nb : %d\n",nombreRestos );
    //printf("id : %d\n",id);
    printf("Le prochain restaurant a visiter est:%s\n",tableauRestos[id].nom);
    planning(tableauRestos,nombreRestos);
     
    return 0;
}