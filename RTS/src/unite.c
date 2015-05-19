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

typedef struct{
    int distance;
    char precedent;
}CellDjikstra;

/* *************************************************************--Init--***************************************************************************** */

void initUnite(Unite* unit, const UniteBase* type, int idJoueur){
    setTypeUnite(unit, type);
    setIdJoueur(unit, idJoueur);
    setDeplacement(unit, 0);
    setVieCouranteUnite(unit, getVieMaxUnite(type));
    setPierrePorte(unit, 0);
    setMithrilPorte(unit, 0);
    setTimerUnite(unit, NULL);
    unit->chemin = (FilePath*)malloc(sizeof(FilePath));
    initFilePath(unit->chemin);
}

/* *************************************************************--GET--***************************************************************************** */

int getId(const Unite* unit){
    return unit->id;
}

int getIdJoueurUnite(const Unite* unit){
     return unit->idJoueur;
}

FilePath* getChemin(const Unite* unit){
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

void setIdJoueurUnite(Unite* unit, int idJoueur){
     unit->idJoueur = idJoueur;
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
     int x = getPosX(homme);
     int y = getPosY(homme);
     int xSuiv, ySuiv;
     int deplacement = regardeTeteFilePath(getChemin(homme));
     switch (deplacement){
     case GAUCHE:
        xSuiv = x - 1;
        ySuiv = y;
        break;
     case DROITE:
        xSuiv = x + 1;
        ySuiv = y;
        break;
     case HAUT:
        xSuiv = x;
        ySuiv = y - 1;
        break;
     case BAS:
        xSuiv = x;
        ySuiv = y + 1;
        break;
     }


     if(getContenu(getCase(terrain,xSuiv,ySuiv)) != 0 || getAcces(getCase(terrain,xSuiv,ySuiv))!=1)
     {
          detruireFilePath(getChemin(homme));
          deplacementUnite(homme,terrain);

     }
     else     {
          setPosX(homme,xSuiv);
          setPosY(homme,ySuiv);
          setContenu(getCase(terrain,xSuiv, ySuiv),getContenu(getCase(terrain, x, y)));
          setContenu(getCase(terrain,x,y),0);
          defilePath(getChemin(homme));
     }

     tempo=clock();
     if(tempo == -1)
     {
          printf("Problème d'horloge");
          exit(EXIT_FAILURE);
     }
     setTimerUnite(homme, tempo);
}

void deplacementUnite(Unite* homme, Terrain* terrain){ /*posCible doit etre entrée avant */

     if(regardeTeteFilePath(getChemin(homme)) != -1){
          clock_t tempo=clock();
          float temps;
          if(tempo == -1)
          {
               printf("Problème d'horloge");
               exit(EXIT_FAILURE);
          }
          temps= ((float)tempo-(float)homme->timerUnite)/CLOCKS_PER_SEC;
          if( temps >= (float) homme->type->vitesse/1000)
          {
               avanceUnite(homme, terrain);
          }
     }
     else{
          if(getPosX(homme) != getPosCibleX(homme) || getPosY(homme) != getPosCibleY(homme))
          {
               sCase* place = getCase(terrain, getPosCibleX(homme), getPosCibleY(homme));
               if( getAcces(place) == 0 || getContenu(place) != 0 ){
                    trouverAcces(homme, terrain );
               }
               trouveChemin(homme, terrain);
               deplacementUnite(homme, terrain);

          }
     }
}

int testCase(int x, int y, Terrain* terrain){
     if(x<0 || y < 0 || x >= getTailleX(terrain) || y >= getTailleY(terrain))
     {
          printf("en dehors de la map: ");
          return 0;
     }
     else if(getContenu(getCase(terrain,x,y)) != 0)
     {
          printf("contenu = %d ", getContenu(getCase(terrain, x, y)));
          return 0;
     }
     else if(getAcces(getCase(terrain,x,y)) != 1)
     {
          printf("acces = %d ", getAcces(getCase(terrain, x, y)));
          return 0;
     }
     else
     {
          printf("OK");
          return 1;
     }
}

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
          vide= testCase(caseTestX, caseTestY, terrain);
          egale = memeCase(caseTestX, caseTestY, caseX, caseY);
          fin = vide + egale;
          printf("\n\n(%d; %d) -> %d",caseTestX,caseTestY,fin);

          while(fin ==0 && caseTestX!=caseCibleX)
          {
               caseTestX--;
               caseTestY--;
               vide= testCase(caseTestX, caseTestY, terrain);
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          while(fin==0 && caseTestY!=caseCibleY)
          {
               caseTestX--;
               caseTestY++;
               vide= testCase(caseTestX, caseTestY, terrain);
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          while(fin ==0 && caseTestX!=caseCibleX)
          {
               caseTestX++;
               caseTestY++;
               vide= testCase(caseTestX, caseTestY, terrain);
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          while(fin ==0 && caseTestY!=caseCibleY+1)
          {
               caseTestX++;
               caseTestY--;
               vide= testCase(caseTestX, caseTestY, terrain);
               egale = memeCase(caseTestX, caseTestY, caseX, caseY);
               fin = vide + egale;
               printf("\n(%d; %d) -> %d",caseTestX,caseTestY,fin);
          }
          i++;
     }
     setPosCibleX(homme,caseTestX);
     setPosCibleY(homme,caseTestY);
}

static void djikstra(int x, int y,CellDjikstra* tabD, Terrain* terrain){
     int tailleX = getTailleX(terrain);
     int tailleY = getTailleY(terrain);
     char selectionne[tailleX*tailleY];
     int i;
     for(i = 0; i< tailleX*tailleY; i++){
        selectionne[i] = 0;
     }
     int distance = 0;
     tabD[x+y*tailleX].distance = 0;
     FilePath* file = (FilePath*)malloc(sizeof(FilePath));
     initFilePath(file);
     enfilePath(file,x);
     enfilePath(file,y);
     while(regardeTeteFilePath(file) != -1){
        x = regardeTeteFilePath(file);
        defilePath(file);
        y = regardeTeteFilePath(file);
        defilePath(file);
        selectionne[x+y*tailleX] = 1;
        distance = tabD[x+y*tailleX].distance + 1;
        if(x-1 >= 0){
            if((getContenu(getCase(terrain, x-1, y)) == 0) && (getAcces(getCase(terrain, x-1, y)) == 1)){
                if(selectionne[x-1+y*tailleX] == 0){
                    if(tabD[x-1+y*tailleX].distance > distance){
                        tabD[x-1+y*tailleX].distance = distance;
                        tabD[x-1+y*tailleX].precedent = DROITE;
                        enfilePath(file, x-1);
                        enfilePath(file, y);
                    }
                }
            }
        }
        if(x+1 < tailleX){
            if((getContenu(getCase(terrain, x+1, y)) == 0) && (getAcces(getCase(terrain, x+1, y)) == 1)){
                if(selectionne[x+1+y*tailleX] == 0){
                    if(tabD[x+1+y*tailleX].distance > distance){
                        tabD[x+1+y*tailleX].distance = distance;
                        tabD[x+1+y*tailleX].precedent = GAUCHE;
                        enfilePath(file, x+1);
                        enfilePath(file, y);
                    }
                }
            }
        }
        if(y-1 >= 0){
            if((getContenu(getCase(terrain, x, y-1)) == 0) && (getAcces(getCase(terrain, x, y-1)) == 1)){
                if(selectionne[x+(y-1)*tailleX] == 0){
                    if(tabD[x+(y-1)*tailleX].distance > distance){
                        tabD[x+(y-1)*tailleX].distance = distance;
                        tabD[x+(y-1)*tailleX].precedent = BAS;
                        enfilePath(file, x);
                        enfilePath(file, y-1);
                    }
                }
            }
        }
        if(y+1 < tailleY){
            if((getContenu(getCase(terrain, x, y+1)) == 0) && (getAcces(getCase(terrain, x, y+1)) == 1)){
                if(selectionne[x+(y+1)*tailleX] == 0){
                    if(tabD[x+(y+1)*tailleX].distance > distance){
                        tabD[x+(y+1)*tailleX].distance = distance;
                        tabD[x+(y+1)*tailleX].precedent = HAUT;
                        enfilePath(file, x);
                        enfilePath(file, y+1);
                    }
                }
            }
        }
     }
}

void trouveChemin(Unite* homme, Terrain* terrain){
    CellDjikstra* tabD = (CellDjikstra*)malloc(sizeof(CellDjikstra)*getTailleX(terrain)*getTailleY(terrain));
    int i;
    int x,y;
    int prec;
    for(i = 0; i < getTailleX(terrain)*getTailleY(terrain); i++){
        tabD[i].distance = INFINI;
        tabD[i].precedent = 0;
    }
    x = getPosX(homme);
    y = getPosY(homme);
    i = getContenu(getCase(terrain,x,y));
    setContenu(getCase(terrain, x,y), 0);
    djikstra(getPosCibleX(homme),getPosCibleY(homme), tabD,terrain);
    setContenu(getCase(terrain,x,y),i);
    prec = tabD[x+getTailleX(terrain)*y].precedent;
    while((x != getPosCibleX(homme) || y != getPosCibleY(homme)) && prec != 0){
        prec = tabD[x+getTailleX(terrain)*y].precedent;
        switch (tabD[x+getTailleX(terrain)*y].precedent){
        case DROITE :
            enfilePath(getChemin(homme), DROITE);
            x++;
            break;
        case GAUCHE :
            enfilePath(getChemin(homme), GAUCHE);
            x--;
            break;
        case HAUT :
            enfilePath(getChemin(homme), HAUT);
            y--;
            break;
        case BAS :
            enfilePath(getChemin(homme), BAS);
            y++;
        }

    }
    if(prec == 0) {
        setPosCibleX(homme, x);
        setPosCibleY(homme, y);
    }

}

/* *************************************************************--FCT en écriture--***************************************************************************** */

void Recolte(Unite* homme, Jeu* jeu){
     clock_t tempo=clock();
     float temps;
     int finRecolte = 0;
     int quantite = getRessourceMax(homme) - (getPierrePorte(homme) + getMithrilCase(homme));

     if(tempo == -1)
     {
          printf("Problème d'horloge");
          exit(EXIT_FAILURE);
     }

     temps= ((float)tempo-(float)homme->timerUnite)/CLOCKS_PER_SEC;

     if( temps >= (float) vitesseRecolte/1000)
     {
          if (quantite != 0 )
          {
                sCase* place = getCase(getCarteJeu(jeu), , y);

               if(getPierreCase(place)!= 0)
               {
                    if( quantite < quantiteRecolte)
                    else if( getPierreCase(place) < quantiteRecolte))
                              quantite=getPierreCase(place);
                    else  quantite=quantiteRecolte;

                    setPierrePorte(homme, getPierrePorte(homme) + quantite);
                    setPierreCase(place, getPierreCase(place) - quantite);
               }
               else if(getMithrilCase(place) != 0)
               {
                    if( quantite < quantiteRecolte)
                    else if( getMithrilCase(place) < quantiteRecolte))
                              quantite=getMithrilCase(place);
                    else  quantite=quantiteRecolte;

                    setMithrilPorte(homme, getMithrilPorte(homme) + quantite);
                    setMithrilCase(place, getMithrilCase(place) - quantite);
               }
               else
               {
                    trouverMinerai(homme, jeu);
               }
          }
          else
          {
               setPosCibleX(homme,getPosBatPX(getJoueur(jeu, getIdJoueurUnite(homme)));
               setPosCibleY(homme,getPosBatPY(getJoueur(jeu, getIdJoueurUnite(homme)));
          }
     }
}

void trouverMinerais(Unite* homme, Jeu* jeu){
     4
}
