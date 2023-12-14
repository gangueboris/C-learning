#include <stdlib.h>
#include "turtle.h"
#define COTE 30
#define NBBANDE 4

void carre(int x ,int y ,int cote,int color[3]){
    turtle_goto(x,y);
    turtle_pen_down();
    turtle_set_fill_color(color[0],color[1],color[2]);
    turtle_begin_fill(); // for the color
    for(int i = 0; i < 4 ; i++){
        turtle_forward(cote);
        turtle_turn_left(90);
    }
    turtle_end_fill();
    turtle_pen_up();
}
void escalier(int x, int y, int nb_carre,int mode_dessin){
    int colors[2][3] = {{255,0,0},{0,0,0}};
    switch (mode_dessin)
    {
    case 1:
        for(int i = 0 ; i < nb_carre/2 ; i++){
            carre(x,y,COTE,colors[0]);
            x -= COTE ;
            y -= COTE ;
            carre(x,y,COTE,colors[1]);
            x -= COTE ;
            y -= COTE ;
        }
    break;
    case 2:
     for(int i = 0 ; i < nb_carre/2 ; i++){
            carre(x,y,COTE,colors[1]);
            x -= COTE ;
            y -= COTE ;
            carre(x,y,COTE,colors[0]);
            x -= COTE ;
            y -= COTE ;
        }
    break ;
   case 3:
     for(int i = 0 ; i < nb_carre/2 ; i++){
            carre(x,y,COTE,colors[0]);
            x -= COTE ;
            y -= COTE ;
            carre(x,y,COTE,colors[0]);
            x -= COTE ;
            y -= COTE ;
        }
    break ;
    case 4:
     for(int i = 0 ; i < nb_carre/2 ; i++){
            carre(x,y,COTE,colors[1]);
            x -= COTE ;
            y -= COTE ;
            carre(x,y,COTE,colors[1]);
            x -= COTE ;
            y -= COTE ;
        }
    break ; 
    default:
    break;
    }

}

void bande(int x, int y ,int nbbande ,int color[2][3]){
    int couleur = 0 ;
    for(int j = 0 ; j < nbbande; j++){
        for(int i = 0 ; i < nbbande ;i++){
            if(i%2 == 0) couleur = 0 ;    
            else couleur = 1 ;
            carre(x,y,COTE,color[couleur]); 
            x += COTE ;
        }
        x = 0 ;
        y+= COTE ;
        
    }



}


int main() {
    //int color[3] = {255,0,0};
    //int color2[3] = {255,255,0};
    int colors[2][3] = {{255,0,0},{0,0,0}};
    turtle_init(500, 500);
   
    //carre(0,0,50,color);
    //carre(90,15,30,color2);
    bande(0,0,NBBANDE,colors);
    turtle_save_bmp("output.bmp");

    return EXIT_SUCCESS;
}
