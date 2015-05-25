
/**
* \file batimentBase.c
* \brief structure BatBase
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 07/04/2015
*
* Structure representant un archetype de batiment.
*/

#include "batimentBase.h"

/* *************************************************************--GET--***************************************************************************** */

char* getNomBat(const BatBase* bat){
     return bat->nomBat;
}

char getTileBat(const BatBase* bat){
     return bat->tile;
}

int getVieMaxBat(const BatBase* bat){
     return bat->vieMax;
}

int getTempsConstruct(const BatBase* bat){
     return bat->tempsConstruct;
}

int getTailleCaseX(const BatBase* bat){
     return bat->tailleCaseX;
}

int getTailleCaseY(const BatBase* bat){
     return bat->tailleCaseY;
}

int getUnitFormableBat(const BatBase* bat,int i){
     return bat->tabUnitFormable[i];
}

int getNbUniteFormable(const BatBase* bat){
     return bat->nbUnitFormable;
}

int getCoutPierreBat(const BatBase* bat){
     return bat->coutPierre;
}

int getCoutMithrilBat(const BatBase* bat){
     return bat->coutMithril;
}

unsigned char getRaceBat(const BatBase* bat){
     return bat->race;
}

/* *************************************************************--SET--***************************************************************************** */

void setNomBat(BatBase* bat, char* nomBat){
    int i;
    for(i = 0; i<24;i++){
        if(nomBat[i] == NULL)
            break;
        bat->nomBat[i] = nomBat[i];
    }
    bat->nomBat[i] = '\0';
}

void setTileBat(BatBase* bat, char tile){
     bat->tile=tile;
}

void setVieMaxBat(BatBase* bat,int vieMax){
     bat->vieMax=vieMax;
}

void setTailleCaseX(BatBase* bat, int tailleCaseX){
     bat->tailleCaseX=tailleCaseX;
}

void setTailleCaseY(BatBase* bat, int tailleCaseY){
     bat->tailleCaseY=tailleCaseY;
}

void setTabUnitFormable(BatBase* bat, int* tabUnitFormable){
     bat->tabUnitFormable=tabUnitFormable;
}

void setNbUniteFormable(BatBase* bat, int nb){
     bat->nbUnitFormable = nb;
}

void setCoutPierreBat(BatBase* bat, int coutP){
     bat->coutPierre= coutP;
}

void setCoutMithrilBat(BatBase* bat, int coutM){
     bat->coutPierre=coutM;
}

void setRaceBat(BatBase* bat, unsigned char race){
     bat->race=race;
}

/* *************************************************************--FCT--***************************************************************************** */

BatBase* chargementBatBase(void){
     FILE* fish;
     int nbBat, nbUnite;
     BatBase* tabBat;
     BatBase* bat;
     int i, j;

     fish=fopen("data/batiment.txt","r");
     if(fish)
     {
          fscanf(fish,"%d\n\n", &nbBat);
          tabBat=(BatBase*)malloc(nbBat*sizeof(BatBase));

          for(i=0;i<nbBat;i++)
          {
               bat= tabBat+i;

               /*Nom*/
               fscanf(fish, "nom=%24[^\n]\n", bat->nomBat);
               /* tile */
               fscanf(fish, "tile=%d\n", &(bat->tile));
               /*vieMax*/
               fscanf(fish, "vieMax=%d\n",&(bat->vieMax));
               /* tempsConstruct */
               fscanf(fish, "tempsConstruct=%d\n", &(bat->tempsConstruct));
               /* tailleCaseX */
               fscanf(fish, "tailleCaseX=%d\n", &(bat->tailleCaseX));
               /* tailleCaseY */
               fscanf(fish, "tailleCaseY=%d\n", &(bat->tailleCaseY));
               /* tabUniteFormable */
               fscanf(fish, "nombreUnite=%d\n", &nbUnite);
               setNbUniteFormable(bat, nbUnite);
               fscanf(fish,"tabUniteFormable=");
               if(nbUnite > 0 )
               {
                    fscanf(fish,"tabUniteFormable=");
                    bat->tabUnitFormable=(int*) malloc(nbUnite*sizeof(int));
                    for(j=0; j<nbUnite; j++)
                    {
                         fscanf(fish,"%d ", &(bat->tabUnitFormable[j]));
                    }
               }
               fscanf(fish, "\n");
                /* coutPierre */
               fscanf(fish, "coutPierre=%d\n", &(bat->coutPierre));
               /* coutMithril */
               fscanf(fish, "coutMithril=%d\n", &(bat->coutMithril));
               /* race */
               fscanf(fish, "race=%d\n", &(bat->race));

               fscanf(fish, "\n");
          }
     }
     else
     {
          fprintf(stderr,"impossible d'ouvrir le fichier !");
          exit(EXIT_FAILURE);
     }
     fclose(fish);
     return tabBat;
}
