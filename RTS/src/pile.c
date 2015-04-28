/**
 * \file unite.h
 * \brief module unite
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module representant une unite
 *
 */

 #include "pile.h"

/* ***********************************************************--Init--*************************************************************************** */
void initPile(Pile* pile){
     pile=(Pile*)malloc(sizeof(Pile));
     pile->sommet=NULL;
}

void detruirePile(Pile* pile){
     while(pile->sommet)
     {
          depilePile(pile);
     }
}
/* *************************************************************--GET--***************************************************************************** */

/* *************************************************************--SET--***************************************************************************** */

/* *************************************************************--FCT en écriture--***************************************************************************** */

 void empilePile(Pile* pile,int valeur){
     Element* elem = (Element*)malloc(sizeof(Element));
     elem->valeur = valeur;
     elem->suivant=pile->sommet;
     pile->sommet = elem;
 }

 void depilePile(Pile* pile){
     Element* elem = pile->sommet;
     pile->sommet=elem->suivant;
     free(elem);
 }

 int regarderSommet(Pile* pile){
      return pile->sommet->valeur;
 }
