
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

/* ***********************************************************--Init--*************************************************************************** */

void initBatBase(BatBase* bat, const char* nomBat,char niveau, char tile, int vieMax,int ameliorable,
                 int tempsConstruct, int tailleCaseY, int tailleCaseX, const UniteBase* tabUnitFormable){

     setNomBat(bat, nomBat);
     setNiveau(bat, niveau);
     setTileBat(bat, tile);
     setVieMaxBat(bat, vieMax);
     setAmeliorable(bat, ameliorable);
     setAmeliorable(bat, ameliorable);
     setTailleCaseX(bat, tailleCaseX);
     setTailleCaseY(bat, tailleCaseY);
     setTabUnitFormable(bat, tabUnitFormable);
}

/* *************************************************************--GET--***************************************************************************** */

char* getNomBat(const BatBase* bat){
     return bat->nomBat;
}

char getNiveau(const BatBase* bat){
     return bat->niveau;
}

char getTileBat(const BatBase* bat){
     return bat->tile;
}

int getVieMaxBat(const BatBase* bat){
     return bat->vieMax;
}

int getAmeliorable(const BatBase* bat){
     return bat->ameliorable;
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

UniteBase* getTabUnitFormable(const BatBase* bat){
     return bat->tabUnitFormable;
}

/* *************************************************************--SET--***************************************************************************** */

void setNomBat(BatBase* bat, char* nomBat){
     bat->nomBat=nomBat;
}

void setNiveau(BatBase* bat, char niveau){
     bat->niveau=niveau;
}

void setTileBat(BatBase* bat, char tile){
     bat->tile=tile;
}

void setVieMaxBat(BatBase* bat,int vieMax){
     bat->vieMax=vieMax;
}

void setAmeliorable(BatBase* bat, int ameliorable){
     bat->ameliorable=ameliorable;
}

void setTailleCaseX(BatBase* bat, int tailleCaseX){
     bat->tailleCaseX=tailleCaseX;
}

void setTailleCaseY(BatBase* bat, int tailleCaseY){
     bat->tailleCaseY=tailleCaseY;
}

void setTabUnitFormable(BatBase* bat, UniteBase* tabUnitFormable){
     bat->tabUnitFormable=tabUnitFormable;
}

/* *************************************************************--FCT--***************************************************************************** */

BatBase* chargementBatBase(void){
     FILE* fish;
     int nbBat, nbUnite;
     BatBase* tabBat;
     BatBase bat;
     int i, j;

     fish=fopen("batiment.txt","r");
     if(fish)
     {
          fscanf(fish,"%d", &nbBat);
          tabBat=(BatBase*)malloc(nbBat*sizeof(BatBase*));

          for(i=0;i<nbBat;i++)
          {
               tabBat[i]=bat;

               /*Nom*/
               fscanf(fish, "nom=%s", bat.nomBat);
               /*Niveau*/
               fscanf(fish, "niveau=%d", &(bat.niveau));
               /*Niveau*/
               fscanf(fish, "niveau=%d", &(bat.tile));
               /*vieMax*/
               fscanf(fish, "vieMax=%d",&(bat.vieMax));
               /* ameliorable */
               fscanf(fish, "ameliorable=%d", &(bat.ameliorable));
               /* tempsConstruct */
               fscanf(fish, "tempsConstruct=%d", &(bat.tempsConstruct));
               /* tailleCaseX */
               fscanf(fish, "tailleCaseX=%d", &(bat.tailleCaseX));
               /* tailleCaseY */
               fscanf(fish, "tailleCaseY=%d", &(bat.tailleCaseY));

               /* tabUniteFormable */
               fscanf(fish, "nombreUnite=%d", &nbUnite);
               if(nbUnite > 0 )
               {
                    fscanf(fish,"tabUniteFormable=");
                    bat.tabUnitFormable=(UniteBase*) malloc(nbUnite*sizeof(UniteBase*));
                    for(j=0; j<nbUnite; j++)
                    {
                         fscanf(fish,"%d ", &(bat.tabUnitFormable[i]));
                    }
               }
          }
     }
     else
     {
          printf("impossible d'ouvrir le fichier !");
          exit(EXIT_FAILURE);
     }
}
