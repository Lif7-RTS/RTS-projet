/**
 * \file unite.c
 * \brief module unite
 * \author Adrien Baud & Diego Roussel
 * \date 05/04/15
 *
 * Module representant une unite
 *
 */

#include "case.h"

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)


/* *************************************************************--Init--***************************************************************************** */

void initUnite(Unite* unit, const UniteBase* type){
    setTypeUnite(unit, type);
    setDeplacement(unit, 0);
    setVieCouranteUnite(unit, getVieMaxUnite(type));
    setPierrePorte(unit, 0);
    setMithrilPorte(unit, 0);
    setTimerUnite(unit, NULL);
    unit->chemin = (Pile*) malloc(sizeof(Pile));
    initPile(unit->chemin);
}

/* *************************************************************--GET--***************************************************************************** */

int getId(const Unite* unit){
    return unit->id;
}

Pile* getChemin(const Unite* unit){
     return unit->chemin;
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

UniteBase* getTypeUnite(const Unite* unit){
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

/* *************************************************************--SET--***************************************************************************** */

void setId(Unite* unit, int id){
    unit->id = id;
}

void setTimerUnite(Unite* unit, clock_t time){
     unit->timerUnite = time;
}

void setPosX(Unite* unit, int x){
    unit->posX = x;
}

void setPosY(Unite* unit, int y){
    unit->posY = y;
}

void setVieCouranteUnite(Unite* unit, int vie){
    unit->vieCourante = vie;
}

void setDeplacement(Unite* unit, int deplac){
    unit->deplacement = deplac;
}

void setTypeUnite(Unite* unit, const UniteBase* type){
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


/* *************************************************************--FCT--***************************************************************************** */

void avanceUnite(Unite* homme, Terrain* terrain){
     clock_t tempo;

     sCase* caseActuel=getCase(terrain, getPosX(homme), getPosY(homme));

     int x = regarderSommet(getChemin(homme));
     depilePile(getChemin(homme));
     int y = regarderSommet(getChemin(homme));
     depilePile(getChemin(homme));

     sCase* caseSuivante=getCase(terrain, x, y);

     if(getContenu(caseSuivante) != 0 || getAcces(caseSuivante)!=1)
     {
          detruirePile(getChemin(homme));
          deplacementUnite(homme,terrain);

     }
     else     {
          setPosX(homme,x);
          setPosY(homme,y);
          setContenu(caseActuel,0);
          setContenu(caseSuivante,getId(homme));
     }

     tempo=clock();
     if(tempo == -1)
     {
          printf("Problème d'horloge");
          exit(EXIT_FAILURE);
     }
     setTimerUnite(homme, tempo);
}

void deplacementUnite(Unite* homme, Terrain* terrain){ /*posCible doit etre entré avant */

     if(homme->chemin->sommet)
     {
          clock_t tempo=clock();
          float temps;
          if(tempo == -1)
          {
               printf("Problème d'horloge");
               exit(EXIT_FAILURE);
          }
          temps= (float)(tempo-homme->timerUnite)/CLOCKS_PER_SEC;
          if( temps >= (float) homme->type->vitesse/1000)
          {
               avanceUnite(homme, terrain);
          }
     }
     else
     {
          if(getPosX(homme) != getPosCibleX(homme)|| getPosY(homme) != getPosCibleY(homme))
          {
               sCase* place = getCase(terrain, getPosCibleX(homme), getPosCibleY(homme));
               if(place->acces == 0 || place->idContenu != 0 ){
                    trouverAcces(homme, terrain );
               }
               trouveChemin(homme);
               deplacementUnite(homme, terrain);

          }
     }
}

int testCase(int x, int y, Terrain* terrain){
     if(x<0 || y < 0)
     {
          return 0;
     }
     else if(getContenu(getCase(terrain,x,y)) != 0)
     {
          return 0;
     }
     else if(getAcces(getCase(terrain,x,y)) != 1)
     {
          return 0;
     }
     else
     {
          return 1;
     }
}


/* *************************************************************--FCT en écriture--***************************************************************************** */

void trouverAcces(Unite* homme, Terrain* terrain){
     int fin=0; /* fin de boucle si fin=1 */
     int caseCibleX=getPosCibleX(homme);
     int caseCibleY=getPosCibleY(homme);
     int caseX=getPosX(homme);
     int caseY=getPosY(homme);
     int caseTestX, caseTestY;
     int vide =0;
     int egale =0;
     int i=1;

     while (fin == 0)
     {
          caseTestX=caseCibleX+i;
          caseTestY=caseCibleY;
          /*vide= testCase(caseTestX, caseTestY, Terrain* terrain);*/
          egale = memeCase(caseTestX, caseTestY, caseX, caseY);
          fin = vide + egale;
          printf("\n\n(%d; %d) -> %d",caseTestX,caseTestY,fin);

          while(fin ==0 && caseTestX!=caseCibleX)
          {
               caseTestX--;
               caseTestY--;
               /*vide= testCase(caseTestX, caseTestY, Terrain* terrain);*/
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          while(fin==0 && caseTestY!=caseCibleY)
          {
               caseTestX--;
               caseTestY++;
               /*vide= testCase(caseTestX, caseTestY, Terrain* terrain);*/
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          while(fin ==0 && caseTestX!=caseCibleX)
          {
               caseTestX++;
               caseTestY++;
               /*vide= testCase(caseTestX, caseTestY, Terrain* terrain);*/
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          while(fin ==0 && caseTestY!=caseCibleY+1)
          {
               caseTestX++;
               caseTestY--;
               /*vide= testCase(caseTestX, caseTestY, Terrain* terrain);*/
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          i++;
     }
     setPosCibleX(homme,caseTestX);
     setPosCibleY(homme,caseTestY);
}

void trouveChemin(Unite* homme){

}
