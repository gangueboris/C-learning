#include <stdio.h>
#include <stdlib.h>
#include "turtle.h"
typedef struct s_point{
    int x ;
    int y ;
}point;

typedef struct polygone{
    point*tab ;
}poly;

int nbrePoint(){
    int nPoint = 0;
    printf("Entrer le nombre de point:\n");
    scanf(" %d",&nPoint);
 return nPoint;
}

poly definePoly(int nP) {
    poly tabPoly;
    tabPoly.tab = malloc(nP * sizeof(point));
    if(tabPoly.tab != NULL){
        for (int i = 0; i < nP; i++) {
            printf("Saisir les coordonnees du pt%d :\n", i + 1);
            scanf(" %d %d", &tabPoly.tab[i].x, &tabPoly.tab[i].y);
        }
    }
    return tabPoly;
}

int main(){
    poly taby ;
    int nP = nbrePoint();
    taby = definePoly(nP);
    //for(int i = 0 ; i < 3; i ++){
        //printf("x:%d, y:%d \n",taby.tab[i].x,taby.tab[i].y);
    //}
    turtle_init(500,500);
    turtle_pen_down();
    for(int i = 0 ; i < nP ; i++){
        turtle_goto(taby.tab[i].x,taby.tab[i].y);   
    }
    turtle_goto(taby.tab[0].x,taby.tab[0].y);   


   turtle_save_bmp("output.bmp");
   free(taby.tab);
   return 0;
}