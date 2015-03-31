#include <stdio.h>
#include "terrain.h"

void setTailleX(Terrain* ter, int x){
    ter->tailleX = x;
}

void setTailleY(Terrain* ter, int y){
    ter->tailleY = y;
}

void setCarte(Terrain* ter, char* dossierCarte){
    ter->nomCarte = dossierCarte;
}

