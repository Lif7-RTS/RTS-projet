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

int getTailleX(const Terrain* ter){
    return ter->tailleX;
}


int getTailleY(const Terrain* ter){
    return ter->tailleY;
}

sCase* getCase(const Terrain* ter,int x, int y){
    return &ter->tabCase[y*(ter->tailleX)+x];
}

void initTerrain(Terrain* ter, const char* colliCarte){
    FILE* fp;
    int tailleX;
    int tailleY;
    int x,y,tile;
    fp = fopen(colliCarte,"r");
    if(fp != NULL){
        fscanf(fp,"%d %d", &tailleX, &tailleY);
        setTailleX(ter, tailleX);
        setTailleY(ter, tailleY);
        ter->tabCase = (sCase*) malloc(sizeof(sCase)*tailleX*tailleY);
        for(y = 0; y < tailleY; y++){
            for(x = 0; x < tailleX; x++){
                fscanf(fp,"%d ", &tile);
                setTileCase(getCase(ter,x,y),tile);
                if(tile >= 1 && tile <= 11){
                    if(tile == 10)
                        initCase(&ter->tabCase[tailleX*y+x],200,0,0);
                    else if(tile == 11)
                        initCase(&ter->tabCase[tailleX*y+x],0,200,0);
                    else
                        initCase(&ter->tabCase[tailleX*y+x],0,0,0);
                }
                else
                    initCase(&ter->tabCase[tailleX*y+x],0,0,1);
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

void detruireTerrain(Terrain** ter){
    free((*ter)->tabCase);
    free(*ter);
    *ter = NULL;
}

