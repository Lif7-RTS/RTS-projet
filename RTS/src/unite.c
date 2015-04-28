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
#include "terrain.h"
#include "case.h"
#include <math.h>

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


/* *************************************************************--FCT en écriture--***************************************************************************** */

void deplacementUnite(Unite* homme, int x, int y, Terrain* terrain){

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
               avanceUnite(homme);
          }
     }
     else
     {
          sCase* place=getCase(terrain,x,y);

          if(getPosX(homme)!=x || getPosY(homme)!=y)
          {
               if(place->acces == 0){
                    trouverAcces(homme,&x,&y);
               }
               else if(place->idContenu != 0){
                    trouverVide(homme,&x,&y);
               }
               setPosCibleX(homme,x);
               setPosCibleY(homme,y);
               trouveChemin(homme, x, y);
               deplacementUnite(homme,getPosCibleX(homme),getPosCibleY(homme),terrain);

          }
     }
}

void avanceUnite(Unite* homme, Terrain* terrain){
     clock_t tempo;

     sCase* caseActuel=getCase(terrain, getPosX(homme), getPosY(homme));

     int x = regarderSommet(getChemin(homme));
     depilePile(getChemin(homme));
     int y = regarderSommet(getChemin(homme));
     depilePile(getChemin(homme));

     sCase* caseSuivante=getCase(terrain, x, y);

     if(getContenu(caseSuivante) != 0)
     {
          detruirePile(getChemin(homme));
          deplacementUnite(homme,getPosCibleX(homme),getPosCibleY(homme), terrain);

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

void trouverAcces(Unite* homme,int* x, int* y){
     int distX= abs(x-getPosX(homme));
     int distY= abs(y-getPosY(homme));
     int i,j;
     for(i=x;i<i-distX,i--)
     {
          for(j=y+i; j<i; j--)
     }


}

void trouverVide(Unite* homme,int* x,int* y){

}

void trouveChemin(Unite* homme, int x, int y){

}
