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
                     int ouvr, int t, int vitesseAtq, int ressourceM, char tile, int v){
    setVieMaxUnite(unit, vie);
    setAttaque(unit, atq);
    setNom(unit, n);
    setOuvrier(unit, ouvr);
    setTempsFormation(unit, t);
    setVitesseAttaque(unit, vitesseAtq);
    setRessourceMax(unit, ressourceM);
    setTileUnite(unit, tile);
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

char getTileUnite(const UniteBase* unit){
    return unit->tile;
}

void setVieMaxUnite(UniteBase* unit, int vieM){
    unit->vieMax = vieM;
}

void setAttaque(UniteBase* unit, int atq){
     unit->attaque = atq;
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

void setTileUnite(UniteBase* unit, char tile){
    unit->tile = tile;
}

UniteBase* chargementUniteBase(void){
     FILE* fich;
     int nbUnite;
     UniteBase* tabUnite;
     UniteBase* unit;
     char nom[25];
     int i, j;

     fish=fopen("data/unite.txt","r");
     if(fish)
     {
          fscanf(fish,"%d", &nbUnite);
          tabBat=(BatBase*)malloc(nbBat*sizeof(BatBase*));

          for(i=0;i<nbBat;i++)
          {
               tabUnit[i]=unit;

               /*Nom*/
               fscanf(fish, "nom=%s\n", bat.nomBat);
               /*Niveau*/
               fscanf(fish, "niveau=%d", &(bat.niveau));
               /*Niveau*/
               fscanf(fish, "niveau=%d", &(bat.tile));
               /*vieMax*/
               fscanf(fish, "vieMax=%d",&(bat.vieMax));
               /* ameliorable */
               fscanf(fish, "ameliorable=%d", &(bat.ameliorable));
               /* tempsConstruct */
               fscanf(fish, "tempsConstruct=%d", &(bat.tempsConstruct));
               /* tailleCaseX */
               fscanf(fish, "tailleCaseX=%d", &(bat.tailleCaseX));
               /* tailleCaseY */
               fscanf(fish, "tailleCaseY=%d", &(bat.tailleCaseY));
          }
     }
     else
     {
          printf("impossible d'ouvrir le fichier !");
          exit(EXIT_FAILURE);
     }
}
