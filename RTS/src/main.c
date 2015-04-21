#include <SDL2/SDL.h>
#include <stdio.h>
#include "jeu.h"
#include "define.h"

int main(int argc, char** argv)
{
    Jeu* j = (Jeu*) malloc(sizeof(Jeu));
    commencerPartie(j,1,"data/carte.txt","zuzu");
    return 0;
}
