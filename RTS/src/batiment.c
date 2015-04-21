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

void initBatiment (Batiment* bat, int id, const BatBase* typeBat, int vieCourante, int enConstruction)
{
     setIdBat(bat, id);
     setTypeBat(bat, typeBat);
     setVieCourante (bat, vieCourante);
     setEnConstruction (bat, enConstruction);
}

void detruirBatiment (Batiment** bat)
{

}

/* *************************************************************--GET--***************************************************************************** */

int getIdBat(const Batiment* bat){
     return bat->id;
}

BatBase* getTypeBat(const Batiment* bat){
     return bat->typeBat;
}

int getVieCouranteBat (const Batiment* bat){
     return bat->vieCourante;
}

int getEnConstruction (const Batiment* bat){
     return bat->enConstruction;
}

File* getTabAttente(const Batiment* bat){
     return bat->tabAttente;
}

/* *************************************************************--SET--***************************************************************************** */

void setIdBat(Batiment* bat, int id ){
     bat->id=id;
}

void setTypeBat(Batiment* bat, const BatBase* typeBat){
     bat->typeBat=typeBat;
}

void setVieCouranteBat (Batiment* bat, int vieCourante){
     bat->vieCourante=vieCourante;
}

void setEnConstruction (Batiment* bat, int enConstruction){
     bat->enConstruction=enConstruction;
}

void setTabAttente(Batiment* bat, const File* tabAttente){
     bat->tabAttente=tabAttente;
}
