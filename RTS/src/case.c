/**
 * \file case.c
 * \brief module case
 * \author Adrien Baud & Diego Roussel
 * \date 31/03/15
 *
 * Module represantant une case de la carte.
 *
 */

#include "case.h"


int getContenu(sCase* c){
    return c->idContenu;
}

int getPierre(sCase* c){
    return c->pierre;
}

int getMithril(sCase* c){
    return c->mithril;
}

int getAcces(sCase* c){
    return c->acces;
}

void setContenu(sCase* c, int id){
    c->idContenu = id;
}

void setPierre(sCase* c, int p){
    c->pierre = p;
}



