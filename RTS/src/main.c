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
     setPosX(homme,3);
     setPosY(homme,4);
     setPosCibleX(homme,0);
     setPosCibleY(homme,0);
     trouverAcces(homme);

     return 0;
}
