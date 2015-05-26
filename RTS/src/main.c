#include <SDL2/SDL.h>
#include <stdio.h>
#include "jeu.h"
#include "define.h"
#include <time.h>

int main(int argc, char** argv)
{
     Jeu* j=(Jeu*)malloc(sizeof(Jeu));
     commencerPartie(j);

     return 0;
}
