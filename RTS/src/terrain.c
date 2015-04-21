/**
* \file terrain.c
* \brief structure Terrain
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 06/04/2015
*
*Structure representant un terrain.
*/

#include "terrain.h"


void setTailleX(Terrain* ter, int x){
    ter->tailleX = x;
}

void setTailleY(Terrain* ter, int y){
    ter->tailleY = y;
}

void setCarteTerrain(Terrain* ter, const char* colliCarte){
    ter->collisionCarte = colliCarte;
}

int getTailleX(const Terrain* ter){
    return ter->tailleX;
}


int getTailleY(const Terrain* ter){
    return ter->tailleY;
}


char* getCarteTerrain(const Terrain* ter){
    return ter->collisionCarte;
}

sCase* getCase(const Terrain* ter,int x, int y){
    return &ter->tabCase[y*(ter->tailleX)+x];
}

void initTerrain(Terrain* ter, const char* colliCarte){
    FILE* fp;
    int tailleX;
    int tailleY;
    int x,y,tile,p,m;
    setCarteTerrain(ter, colliCarte);
    fp = fopen(colliCarte,"r");
    if(fp != NULL){
        fscanf(fp,"%d %d", &tailleX, &tailleY);
        setTailleX(ter, tailleX);
        setTailleY(ter, tailleY);
        ter->tabCase = (sCase*) malloc(sizeof(sCase)*tailleX*tailleY);
        ter->tiles = (char*) malloc(sizeof(int)*tailleX*tailleY);
        for(y = 0; y < tailleY; y++){
            for(x = 0; x < tailleX; x++){
                fscanf(fp,"%d %d %d", &tile, &m, &p);
                ter->tiles[x+y*tailleX] = tile;
                if(tile > 5)
                    initCase(&ter->tabCase[tailleX*y+x],p,m,1);
                else
                    initCase(&ter->tabCase[tailleX*y+x],p,m,0);
            }
            printf("\n");
        }
        fclose(fp);
    }
    else{
        printf("impossible d'ouvrir le fichier !");
        exit(EXIT_FAILURE);
    }
}

void detruireTerrain(Terrain* ter){
    free(ter->tabCase);
}

