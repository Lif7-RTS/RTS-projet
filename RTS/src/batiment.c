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

void initBatiment(Batiment* bat, int id, BatBase* typeBat, int enConstruction, int idJ)
{
     setIdBat(bat, id);
     setTypeBat(bat, typeBat);
     setVieCouranteBat (bat, getVieMaxBat(typeBat));
     setEnConstruction (bat, enConstruction);
     setIdJoueurBat(bat, idJ);
     setTimerBat(bat, clock());
     setTabAttente(bat, (File*)malloc(sizeof(File)));
     initFile(bat->tabAttente);
}

void detruireBatiment(Batiment** bat){
     /* LOOOOL */
}

/* *************************************************************--GET--***************************************************************************** */

int getIdBat(const Batiment* bat){
     return bat->id;
}

int getIdJoueurBat(const Batiment* bat){
    return bat->idJoueur;
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

void setIdJoueurBat(Batiment* bat, int idJ){
     bat->idJoueur = idJ;
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

void verifierTimerBat(Batiment* bat, Jeu* j){
    if(getTimerBat(bat) == NULL){
        if(regardeTeteFile(getTabAttente(bat)) != NULL){
            setTimerBat(bat,clock());
        }
    }
    else{
        if(getEnConstruction(bat) == 1){
            if((clock() - getTimerBat(bat))/CLOCKS_PER_SEC >= getTempsConstruct(getTypeBat(bat))){
                setEnConstruction(bat, 0);
                setTimerBat(bat,NULL);
            }
        }
        else if((clock() - getTimerBat(bat))/CLOCKS_PER_SEC >= getTempsFormation(regardeTeteFile(getTabAttente(bat)))){
            printf("Création Unite ! \n");
            Unite* u = (Unite*) malloc(sizeof(Unite));
            initUnite(u, regardeTeteFile(getTabAttente(bat)), getIdJoueurBat(bat));
            int id = ajouterTabDyn(j->tableauUnite, (uintptr_t)u);
            setId(u, id);
            setPosX(u,-getTailleY(j->carte));
            setPosY(u,-getTailleY(j->carte));
            setPosCibleX(u,getPosXBat(bat)-1);
            setPosCibleY(u, getPosYBat(bat));
            trouverAcces(u, j->carte);
            setPosX(u,getPosCibleX(u));
            setPosY(u,getPosCibleY(u));
            setContenu(getCase(getCarteJeu(j),getPosX(u), getPosY(u)),id);
            defile(getTabAttente(bat));
            if(regardeTeteFile(getTabAttente(bat)) != NULL)
                setTimerBat(bat, clock());
            else
                setTimerBat(bat, NULL);
        }
    }
}

void ajouterFileBat(Batiment* bat,Jeu* j,int i){
    if(i >= getNbUniteFormable(getTypeBat(bat)))
        return;
    printf("%d \n", i);
    UniteBase* u = getUniteFormable(j,getUnitFormableBat(getTypeBat(bat), i));
    if(getCoutPierreUnite(u) <= getPierreJoueur(getJoueur(j,getIdJoueurBat(bat)))
       && getCoutMithrilUnite(u) <= getMithrilJoueur(getJoueur(j,getIdJoueurBat(bat)))){
        enfile(bat->tabAttente,u);
        setPierreJoueur(getPierreJoueur(getJoueur(j,getIdJoueurBat(bat))) - getCoutPierreUnite(u));
        setMithrilJoueur(getMithrilJoueur(getJoueur(j,getIdJoueurBat(bat))) - getCoutMithrilUnite(u));
    }
}
