/**
 * \file uniteBase.c
 * \brief module uniteBase
 * \author Adrien Baud & Diego Roussel
 * \date 31/03/15
 *
 * Module represantant un archetype d'unite
 *
 */
 #include "uniteBase.h"


void initUniteBase(UniteBase* unit, int vie, int atq, char* n,
                     int ouvr, int t, int vitesseAtq, int ressourceM, char* chemin, int v){
    setVieMaxUnite(unit, vie);
    setAttaque(unit, atq);
    setNom(unit, n);
    setOuvrier(unit, ouvr);
    setTempsFormation(unit, t);
    setVitesseAttaque(unit, vitesseAtq);
    setRessourceMax(unit, ressourceM);
    setImage(unit, chemin);
    setVitesse(unit, v);
}


int getVieMaxUnite(const UniteBase* unit){
    return unit->vieMax;
}

int getAttaque(const UniteBase* unit){
    return unit->attaque;
}

char* getNom(const UniteBase* unit){
    return unit->nom;
}

int getOuvrier(const UniteBase* unit){
    return unit->ouvrier;
}

int getTempsFormation(const UniteBase* unit){
    return unit->tempsFormation;
}

int getVitesseAttaque(const UniteBase* unit){
    return unit->vitesseAttaque;
}

int getRessourceMax(const UniteBase* unit){
    return unit->ressourceMax;
}

int getVitesse(const UniteBase* unit){
    return unit->vitesse;
}

char* getImage(const UniteBase* unit){
    return unit->cheminImage;
}

void setVieMaxUnite(UniteBase* unit, int vieM){
    unit->vieMax = vieM;
}

void setAttaque(UniteBase* unit, int atq){
     unit->attaque = attaque;
}

void setNom(UniteBase* unit, char* n){
     unit->nom = n;
}

void setOuvrier(UniteBase* unit, int ouvr){
     unit->ouvrier = ouvr;
}

void setTempsFormation(UniteBase* unit, int t){
     unit->tempsFormation = t;
}

void setVitesseAttaque(UniteBase* unit, int vitesseAtq){
    unit->vitesseAttaque = vitesseAtq;
}

void setRessourceMax(UniteBase* unit, int ressourceM){
    unit->ressourceMax = ressourceM;
}

void setVitesse(UniteBase* unit, int v){
    unit->vitesse = v;
}

void setImage(UniteBase* unit, char* chemin){
    unit->cheminImage = chemin;
}
