
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

void initBatBase(BatBase* bat,char* nomBat,char niveau, char tile, int vieMax,int ameliorable,
                 int tempsConstruct, int tailleCaseY, int tailleCaseX, int* tabUnitFormable){

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
               fscanf(fish, "nom=%s\n", bat->nomBat);
               printf("%s \n", bat->nomBat);
               /*Niveau*/
               fscanf(fish, "niveau=%d\n", &(bat->niveau));
               printf("%d \n", bat->niveau);
               /* tile */
               fscanf(fish, "tile=%d\n", &(bat->tile));
              printf("%d \n", bat->tile);
               /*vieMax*/
               fscanf(fish, "vieMax=%d\n",&(bat->vieMax));
               /* ameliorable */
               fscanf(fish, "ameliorable=%d\n", &(bat->ameliorable));
               /* tempsConstruct */
               fscanf(fish, "tempsConstruct=%d\n", &(bat->tempsConstruct));
               /* tailleCaseX */
               fscanf(fish, "tailleCaseX=%d\n", &(bat->tailleCaseX));
               /* tailleCaseY */
               fscanf(fish, "tailleCaseY=%d\n", &(bat->tailleCaseY));
                printf("tailleCaseY: %d \n", bat->tailleCaseY);
               /* tabUniteFormable */
               fscanf(fish, "nombreUnite=%d\n", &nbUnite);
               setNbUniteFormable(bat, nbUnite);
               printf("nbUniteFormable: %d \n", getNbUniteFormable(bat));
               if(nbUnite > 0 )
               {
                    fscanf(fish,"tabUniteFormable=");
                    bat->tabUnitFormable=(int*) malloc(nbUnite*sizeof(int));
                    for(j=0; j<nbUnite; j++)
                    {
                         fscanf(fish,"%d ", &(bat->tabUnitFormable[j]));
                         printf("id %d : %d \n", j, bat->tabUnitFormable[j]);
                    }
               }
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
          printf("impossible d'ouvrir le fichier !");
          exit(EXIT_FAILURE);
     }
     fclose(fish);
     return tabBat;
}
