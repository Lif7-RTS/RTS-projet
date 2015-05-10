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


/* ***********************************************************--Init--*************************************************************************** */

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

/* *************************************************************--GET--***************************************************************************** */

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

/* *************************************************************--SET--***************************************************************************** */

void setVieMaxUnite(UniteBase* unit, int vieM){
    unit->vieMax = vieM;
}

void setAttaque(UniteBase* unit, int atq){
     unit->attaque = atq;
}

void setNom(UniteBase* unit, char* n){
    int i;
    for(i = 0; i<24;i++){
        if(n[i] == NULL)
            break;
        unit->nom[i] = n[i];
    }
    unit->nom[i] = '\0';
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

/* *************************************************************--FCT--***************************************************************************** */

UniteBase* chargementUniteBase(void){
     FILE* fish;
     int nbUnite;
     UniteBase* tabUnite;
     UniteBase* unit;
     char nom[25];
     int i;

     fish=fopen("data/unite.txt","r");
     if(fish)
     {
          fscanf(fish,"%d\n\n", &nbUnite);
          tabUnite=(UniteBase*)malloc(nbUnite*sizeof(UniteBase));

          for(i=0;i<nbUnite;i++)
          {
               unit=tabUnite+i;

               /*Nom*/
               fscanf(fish, "nom=%s\n",unit->nom);
               /*vieMax*/
               fscanf(fish, "vieMax=%d\n",&(unit->vieMax));
               /* attaque */
               fscanf(fish, "attaque=%d\n",&(unit->attaque));
               /* vitesseAttaque */
               fscanf(fish, "vitesseAttaque=%d\n",&(unit->vitesseAttaque));
               /* ouvrier */
               fscanf(fish, "ouvrier=%d\n",&(unit->ouvrier));
               /* tempsFormation */
               fscanf(fish, "tempsFormation=%d\n",&(unit->tempsFormation));
               /* ressourceMax */
               fscanf(fish, "ressourceMax=%d\n",&(unit->ressourceMax));
               /* tile */
               fscanf(fish, "tile=%d\n",&(unit->tile));
               /* vitesse */
               fscanf(fish, "vitesse=%d\n",&(unit->vitesse));
          }
     }
     else
     {
          printf("impossible d'ouvrir le fichier !");
          exit(EXIT_FAILURE);
     }
     return tabUnite;
}
