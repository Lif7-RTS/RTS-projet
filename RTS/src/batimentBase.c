
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

void initBatBase(BatBase* bat, const char* nomBat,char niveau, const char* cheminImage, int vieMax,int ameliorable,
                 int tempsConstruct, int tailleCaseY, int tailleCaseX, const UniteBase* tabUnitFormable){

     setNomBat(bat, nomBat);
     setNiveau(bat, niveau);
     setCheminImage(bat, cheminImage);
     setVieMax(bat, vieMax);
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

char* getCheminImage(const BatBase* bat){
     return bat->cheminImage;
}

int getVieMax(const BatBase* bat){
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

void setNomBat(BatBase* bat, const char* nomBat){
     bat->nomBat=nomBat;
}

void setNiveau(BatBase* bat, char niveau){
     bat->niveau=niveau;
}

void setCheminImage(BatBase* bat, const char* cheminImage){
     bat->cheminImage=cheminImage;
}

void setVieMax(BatBase* bat,int vieMax){
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

void setTabUnitFormable(BatBase* bat, const UniteBase* tabUnitFormable){
     bat->tabUnitFormable=tabUnitFormable;
}

/* *************************************************************--FCT--***************************************************************************** */

BatBase* chargementBatBase(void){
     FILE* fish;
     int nbBat;
     char nom[20];
     BatBase* tabBat;
     int i;

     fish=fopen("batiment.txt","r");
     if(fish)
     {
          fscanf(fish,"%d", &nbBat);
          tabBat=(BatBase*)malloc(nbBat*sizeof(BatBase*));

          for(i=0;i<nbBat;i++)
          {
               fscanf(fish,"nom=%s", &(bat->nom));
               setNomBat(tabBat[i], bat->nom);
               fcanf(fish,"niveau=%d", &niveau);
               setNiveau(tabBat[i], nom);


          }
     }
     else
     {
          printf("impossible d'ouvrir le fichier !");
          EXIT_FAILURE;
     }
}
