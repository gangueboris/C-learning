/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 100
#define NBRE 9

struct s_resto
{
    char nom[100];
    int qualite ;
    int distance;
    int temps ;
};

int main(){
    FILE* file ;
    char buffer[MAX_VALUE];
    struct s_resto resto1 ;

    

    file = fopen("file.txt","r");
    if(file == NULL){
        fprintf(stderr,"Erreur d'ouverture\n");
        exit(0);
     }
    buffer = (char*)malloc(MAX_VALUE * sizeof(char));
    while(fgets(buffer,MAX_VALUE,file) != NULL){
         size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        fgets(resto1.nom,sizeof(resto1.nom),buffer);
        printf("%s\n",resto1.nom);
       

    }

    free(buffer);
    fclose(file);
    
   
    file = fopen("file.txt","r");
    if(file == NULL){
        fprintf(stderr,"Erreur d'ouverture\n");
        exit(1);
     }
    char nom[100];
    int distance, duree;
/*
    // Lire le fichier ligne par ligne
    while (fscanf(file, "%s %d %d", nom, &distance, &duree) == 3) {
        // Traiter les données lues
        printf("Nom : %s\n", nom);
        printf("Distance : %d\n", distance);
        printf("Durée : %d\n", duree);
        printf("\n");
    }

    fclose(file);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 100

typedef struct {
    char nom[MAX_VALUE];
    int distance;
    int duree;
} Restaurant;

int main() {
    FILE *file = fopen("file.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Erreur d'ouverture\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_VALUE];
    Restaurant resto1;  // Assurez-vous de déclarer votre structure appropriée

    while (fgets(buffer, MAX_VALUE, file) != NULL) {
        
        // Utilisez sscanf pour extraire les valeurs de la ligne lue
        if (sscanf(buffer, "%s %d %d", resto1.nom, &resto1.distance, &resto1.duree) == 3) {
            printf("Nom : %s\n", resto1.nom);
            printf("Distance : %d\n", resto1.distance);
            printf("Durée : %d\n", resto1.duree);
            printf("\n");
        } else {
            fprintf(stderr, "Erreur de lecture de la ligne : %s\n", buffer);
        }
    }

    fclose(file);
    return 0;
}
