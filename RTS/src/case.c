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


/* *************************************************************--FCT--***************************************************************************** */

void initCase(sCase* c,int p, int m, int acc){
    setPierreCase(c, p);
    setMithrilCase(c, m);
    setAcces(c, acc);
    setContenu(c, 0);
}

/* *************************************************************--GET--***************************************************************************** */

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

unsigned char getTileCase(const sCase* c){
     return c->tile;
}

/* *************************************************************--SET--***************************************************************************** */

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

 void setTileCase(sCase* c, unsigned char tile){
     c->tile=tile;
 }


/* *************************************************************--FCT--***************************************************************************** */

 int memeCase(int x1, int y1, int x2, int y2){
     if(x1 != x2 || y1 !=y2)
     {
          return 0;
     }
     else
     {
          return 1;
     }
}


