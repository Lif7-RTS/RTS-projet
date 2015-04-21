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
static Race races = {{10,11},{50,75},{100,120}};
void initJoueur (Joueur* joue, int idJoueur, char* nomJouer,
                 int idRace, int cameraX, int cameraY){
    setIdJoueur(joue,idJoueur);
    setNomJoueur(joue,nomJouer);
    setIdRace(joue, idRace);
    setCameraX(joue, cameraX);
    setCameraY(joue, cameraY);
    setNourritureMax(joue, races.nourritureMax[idRace]);
    setMithrilJoueur(joue, races.mithril[idRace]);
    setPierreJoueur(joue, races.pierre[idRace]);
    joue->tabBatiment = (TabDyn*) malloc(sizeof(TabDyn));
    joue->tabTroupe = (TabDyn*) malloc(sizeof(TabDyn));
    initTabDyn(joue->tabBatiment,10);
    initTabDyn(joue->tabTroupe,races.nourritureMax[idRace]);
}

void detruireJoueur(Joueur* joue){
    detruireTabDyn(joue->tabBatiment);
    detruireTabDyn(joue->tabTroupe);
}

int getIdJoueur(const Joueur* joue){
    return joue->idJoueur;
}

int getPierreJoueur(const Joueur* joue){
    return joue->pierre;
}

int getMithrilJoueur(const Joueur* joue){
    return joue->mithril;
}

char* getNomJoueur(const Joueur* joue){
    return joue->nomJoueur;
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

Unite* choisiUnite(const Joueur* joue, int numLigne){
    return (Unite*) getElemTabDyn(joue->tabTroupe, numLigne);
}

Batiment* choisiBatiment(const Joueur* joue, int numLigne){
    return (Batiment*) getElemTabDyn(joue->tabBatiment, numLigne);
}

void setIdJoueur(Joueur* joue, int idJoueur){
    joue->idJoueur = idJoueur;
}

void setPierreJoueur(Joueur* joue, int pierre){
    joue->pierre = pierre;
}

void setMithrilJoueur(Joueur* joue, int mithril){
    joue->mithril = mithril;
}

void setNomJoueur(Joueur* joue, char* nomJoueur){
    joue->nomJoueur = nomJoueur;
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

void ajouteUnite(Joueur* joue, const Unite* unite){
    ajouterTabDyn(joue->tabTroupe, (uintptr_t) unite);
}

void ajouteBat(Joueur* joue, const Batiment* bat){
    ajouterTabDyn(joue->tabBatiment, (uintptr_t) bat);
}
