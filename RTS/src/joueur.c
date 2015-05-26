/**
* \file joueur.c
* \brief structure joueur
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 16/04/2015
* Structure representant un joueur.
*/

#include "joueur.h"

typedef struct SRace Race;
struct SRace{
    int nourritureMax[2];
    int mithril[2];
    int pierre[2];
};
static Race races = {{11,10},{75,50},{100,75}};


/* ***********************************************************--INIT--*************************************************************************** */

void initJoueur (Joueur* joue, int idJoueur,
                 int idRace, int cameraX, int cameraY){
    setIdJoueur(joue,idJoueur);
    setIdRace(joue, idRace);
    setCameraX(joue, cameraX);
    setCameraY(joue, cameraY);
    setNourritureCourante(joue, 1);
    setNourritureMax(joue, races.nourritureMax[idRace]);
    setMithrilJoueur(joue, races.mithril[idRace]);
    setPierreJoueur(joue, races.pierre[idRace]);
    setBatConstruction(joue, NULL);
}

/* *************************************************************--GET--***************************************************************************** */

int getIdJoueur(const Joueur* joue){
    return joue->idJoueur;
}

int getPierreJoueur(const Joueur* joue){
    return joue->pierre;
}

int getMithrilJoueur(const Joueur* joue){
    return joue->mithril;
}

int getIdRace(const Joueur* joue){
    return joue->idRace;
}

int getNourritureMax(const Joueur* joue){
    return joue->nourritureMax;
}

int getNourritureCourante(const Joueur* joue){
    return joue->nourritureCourante;
}

int getCameraX(const Joueur* joue){
    return joue->cameraX;
}

int getCameraY(const Joueur* joue){
    return joue->cameraY;
}

int getPosBatPX(const Joueur* joue){
     return joue->posBatPX;
}

int getPosBatPY(const Joueur* joue){
     return joue->posBatPY;
}

BatBase* getBatConstruction(const Joueur* joue){
    return joue->batConstruction;
}
/* *************************************************************--SET--***************************************************************************** */

void setIdJoueur(Joueur* joue, int idJoueur){
    joue->idJoueur = idJoueur;
}

void setPierreJoueur(Joueur* joue, int pierre){
    joue->pierre = pierre;
}

void setMithrilJoueur(Joueur* joue, int mithril){
    joue->mithril = mithril;
}

void setIdRace(Joueur* joue, int idRace){
    joue->idRace = idRace;
}

void setNourritureMax(Joueur* joue, int nourMax){
    joue->nourritureMax = nourMax;
}

void setNourritureCourante(Joueur* joue, int nourActu){
    joue->nourritureCourante = nourActu;
}

void setCameraX(Joueur* joue, int camX){
    joue->cameraX = camX;
}

void setCameraY(Joueur* joue, int camY){
    joue->cameraY = camY;
}

void setPosBatPX(Joueur* joue,int x){
    joue->posBatPX = x;
}

void setPosBatPY(Joueur* joue,int y){
    joue->posBatPY = y;
}
void setBatConstruction(Joueur* joue,BatBase* bat){
    joue->batConstruction = bat;
}
