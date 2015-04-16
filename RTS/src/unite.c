/**
 * \file unite.c
 * \brief module unite
 * \author Adrien Baud & Diego Roussel
 * \date 05/04/15
 *
 * Module representant une unite
 *
 */

#include "unite.h"

int getId(const Unite* unit){
    return unit->id;
}

int getPosX(const Unite* unit){
    return unit->posX;
}

int getPosY(const Unite* unit){
    return unit->posY;
}

int getVieCouranteUnite(const Unite* unit){
    return unit->vieCourante;
}

int getDeplacement(const Unite* unit){
    return unit->deplacement;
}

UniteBase* getType(const Unite* unit){
    return unit->type;
}

int getPosCibleX(const Unite* unit){
    return unit->posCibleX;
}

int getPosCibleY(const Unite* unit){
    return unit->posCibleY;
}

int getPierrePorte(const Unite* unit){
    return unit->pierrePorte;
}

int getMithrilPorte(const Unite* unit){
    return unit->mithrilPorte;
}

void setId(Unite* unit, int id){
    unit->id = id;
}

void setPosX(Unite* unit, int x){
    unit->posX = x;
}

void setPosY(Unite* unit, int y){
    unit->posX = y;
}

void setVieCouranteUnite(Unite* unit, int vie){
    unit->vieCourante = vie;
}

void setDeplacement(Unite* unit, int deplac){
    unit->deplacement = deplac;
}

void setType(Unite* unit, const UniteBase* type){
    unit->type = type;
}

void setPosCibleX(Unite* unit, int x){
    unit->posCibleX = x;
}

void setPosCibleY(Unite* unit, int y){
    unit->posCibleY = y;
}

void setPierrePorte(Unite* unit, int p){
    unit->pierrePorte = p;
}

void setMithrilPorte(Unite* unit, int m){
    unit->mithrilPorte = m;
}

