/**
 * \file case.c
 * \brief module case
 * \author Adrien Baud & Diego Roussel
 * \date 31/03/15
 *
 * Module represantant une case de la carte.
 *
 */
#include "unite.h"
#include "uniteBase.h"
#include "case.h"


void initCase(sCase* c,int p, int m, int acc){
    setPierre(c, p);
    setMithril(c, m);
    setAcces(c, acc);
    setContenu(c, 0);
}
int getContenu(const sCase* c){
    return c->idContenu;
}

int getPierre(const sCase* c){
    return c->pierre;
}

int getMithril(const sCase* c){
    return c->mithril;
}

int getAcces(const sCase* c){
    return c->acces;
}

void setContenu(sCase* c, int id){
    c->idContenu = id;
}

void setPierre(sCase* c, int p){
    c->pierre = p;
}
void setMithril(sCase* c, int m){
    c->mithril = m;
}
void setAcces(sCase* c, int acc){
    c->acces = acc;
}
void prendrePierre(sCase* c, Unite* ouvrier){
    UniteBase* type = getType(ouvrier);
    int rMax = getRessourceMax(type);
    int rCour = getPierre(c);
    if((rCour - rMax) < 0){
        setPierrePorte(ouvrier, getPierre(c));
        setPierre(c, 0);
        return;
    }
    setPierrePorte(ouvrier, rMax);
    setPierre(c,rCour - rMax);
    return;
}

void prendreMithril(sCase* c, Unite* ouvrier){
    int rMax = getRessourceMax(getType(ouvrier));
    int rCour = getMithril(c);
    if((rCour - rMax) < 0){
        setMithrilPorte(ouvrier, getPierre(c));
        setMithril(c, 0);
        return;
    }
    setMithrilPorte(ouvrier, rMax);
    setMithril(c,rCour - rMax);
    return;
}


