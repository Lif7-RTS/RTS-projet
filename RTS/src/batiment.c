/**
* \file batiment.h
* \brief structure Batiment
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 20/04/2015
*
*Structure representant un batiment.
*/

#include "batiment.h"

/* ***********************************************************--Init--*************************************************************************** */

void initBatiment(Batiment* bat, int id, BatBase* typeBat, int vieCourante, int enConstruction)
{
     setIdBat(bat, id);
     setTypeBat(bat, typeBat);
     setVieCouranteBat (bat, vieCourante);
     setEnConstruction (bat, enConstruction);
}

void detruireBatiment(Batiment** bat){

}

/* *************************************************************--GET--***************************************************************************** */

int getIdBat(const Batiment* bat){
     return bat->id;
}

BatBase* getTypeBat(const Batiment* bat){
     return bat->typeBat;
}

int getVieCouranteBat(const Batiment* bat){
     return bat->vieCourante;
}

int getEnConstruction(const Batiment* bat){
     return bat->enConstruction;
}

File* getTabAttente(const Batiment* bat){
     return bat->tabAttente;
}

int getPosXBat(const Batiment* bat){
    return bat->x;
}

int getPosYBat(const Batiment* bat){
    return bat->y;
}


clock_t getTimerBat(const Batiment* bat){
    return bat->timerBat;
}
/* *************************************************************--SET--***************************************************************************** */

void setIdBat(Batiment* bat, int id ){
     bat->id=id;
}

void setTypeBat(Batiment* bat, BatBase* typeBat){
     bat->typeBat=typeBat;
}

void setVieCouranteBat(Batiment* bat, int vieCourante){
     bat->vieCourante=vieCourante;
}

void setEnConstruction(Batiment* bat, int enConstruction){
     bat->enConstruction=enConstruction;
}

void setTabAttente(Batiment* bat, File* tabAttente){
     bat->tabAttente=tabAttente;
}

void setPosXBat(Batiment* bat,int x){
    bat->x = x;
}

void setPosYBat(Batiment* bat, int y){
    bat->y= y;
}


void setTimerBat(Batiment* bat, clock_t t){
    bat->timerBat= t;
}

/* *************************************************************--FCT--***************************************************************************** */

void verifierTimerBat(Batiment* bat){
    if(getTimerBat(bat) == NULL){
        if(regardeTeteFile(bat->tabAttente) != NULL){
            setTimerBat
        }
    }
}

void ajouterFileBat(Batiment* bat,Jeu* j,int i){
    if(i >= getNbUniteFormable(getTypeBat(bat)))
        return;
    enfile(bat->tabAttente,getUniteFormable(j,getUnitFormableBat(getTypeBat(bat), i)));
}
