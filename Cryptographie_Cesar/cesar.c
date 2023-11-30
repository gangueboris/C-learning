# include<stdio.h>
# include<string.h>
# include"cesar.h"
#define NB_LETTRES 26

 
 // Fonction chiffrement 
char chiffrement(char carac, int cle) {
     if ((65 <= (int)carac) && ((int)carac <= 90)){
        int position_carac = carac - 65; // valeur entre 0 et 25
        int nouvelle_position = (position_carac + cle )%26;
        char resultat = nouvelle_position + 65;
        return resultat;
    }
}

// Fonction dechiffrement
char dechiffrement(char caractere ,int cle){

return chiffrement(caractere, -cle) ;
}


// Fonction analyse frequence

void analyserFrequence(char*text ,int*tabFrequence){
    char tabChar [] = "ABCDEFGHIJKLMNOPKRSTUVWXYZ" ;
    int textLen = strlen(text);
    int compteur = 0 ;
    for(int i = 0 ; i < NB_LETTRES ;i++){
        for(int j = 0; j < textLen; j++){
            if(tabChar[i] == text[j]) compteur++ ;
        }
        tabFrequence[i] = compteur ;
        compteur = 0 ;  
    }
}


// Fonction calculer cle

int calculerCle(int*tabFrequence){
    int valMax = 0 ;
    int indexVal = 0 ;
    int cleDecalage ;
    // Trouver l'indice de la lettre la plus fréquente dans le tableau de fréquence
    for(int i  = 0 ; i < NB_LETTRES; i++){
        if(valMax < tabFrequence[i]){
            valMax = tabFrequence[i] ;
            indexVal = i ;
        }
    }
    cleDecalage = (indexVal - 4 + 26) % 26;
    return  cleDecalage ;
}
 