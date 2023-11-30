#ifndef CESAR_H
#define CESAR_H

char chiffrement(char carac, int cle) ;

char dechiffrement(char caractere ,int cle) ;

void analyserFrequence(char*text ,int*tabFrequence);

int calculerCle(int*tabFrequence) ;

#endif