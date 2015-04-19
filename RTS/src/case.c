/**
 * \file case.c
 * \brief module case
 * \author Adrien Baud & Diego Roussel
 * \date 31/03/15
 *
 * Module representant une case de la carte.
 *
 */
#include "unite.h"
#include "uniteBase.h"
#include "case.h"


void initCase(sCase* c,int p, int m, int acc){
    setPierreCase(c, p);
    setMithrilCase(c, m);
    setAcces(c, acc);
    setContenu(c, 0);
}
int getContenu(const sCase* c){
    return c->idContenu;
}

int getPierreCase(const sCase* c){
    return c->pierre;
}

int getMithrilCase(const sCase* c){
    return c->mithril;
}

int getAcces(const sCase* c){
    return c->acces;
}

void setContenu(sCase* c, int id){
    c->idContenu = id;
}

void setPierreCase(sCase* c, int p){
    c->pierre = p;
}
void setMithrilCase(sCase* c, int m){
    c->mithril = m;
}
void setAcces(sCase* c, int acc){
    c->acces = acc;
}
void prendrePierre(sCase* c, Unite* ouvrier){
    UniteBase* type = getTypeUnite(ouvrier);
    int rMax = getRessourceMax(type);
    int rCour = getPierreCase(c);
    if((rCour - rMax) < 0){
        setPierrePorte(ouvrier, getPierreCase(c));
        setPierreCase(c, 0);
        return;
    }
    setPierrePorte(ouvrier, rMax);
    setPierreCase(c,rCour - rMax);
    return;
}

void prendreMithril(sCase* c, Unite* ouvrier){
    int rMax = getRessourceMax(getTypeUnite(ouvrier));
    int rCour = getMithrilCase(c);
    if((rCour - rMax) < 0){
        setMithrilPorte(ouvrier, getMithrilCase(c));
        setMithrilCase(c, 0);
        return;
    }
    setMithrilPorte(ouvrier, rMax);
    setMithrilCase(c,rCour - rMax);
    return;
}


