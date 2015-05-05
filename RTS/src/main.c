#include <SDL2/SDL.h>
#include <stdio.h>
#include "jeu.h"
#include "define.h"

int main(int argc, char** argv)
{
     /*Jeu* j=(Jeu*)malloc(sizeof(Jeu));
     commencerPartie(j, 1, "data/carte.txt", "zub" );*/

     Unite* homme=(Unite*) malloc (sizeof(Unite));
     int x=0;
     setPosX(homme,0);
     setPosY(homme,0);
     setPosCibleX(homme,3);
     setPosCibleY(homme,2);
     trouverAcces(homme);

     return 0;
}
