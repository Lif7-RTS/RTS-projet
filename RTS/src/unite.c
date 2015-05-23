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

/**
 * \fn static int testMinerai(int x, int y, CellDjikstra* tabD, Terrain* terrain)
 * \brief regarde si une unite peu exploiter les ressource d'un case
 *
 * \param[in] x est un entier coordonée d'une case
 * \param[in] y est un entier coordonée d'une case
 * \param[in] tabD est un tableau de CellDjikstra
 * \param[in, out] terrain est le terrain de jeu
 * \return renvoi le nombre de ressource sur une case si elle est exploitable par un ouvrier.
 */
static int testMinerai(int x, int y, CellDjikstra* tabD, Terrain* terrain);

/**
 * \fn static int testCase(int x, int y, Terrain* terrain)
 * \brief regarde si une unite peu aller sur une case
 *
 * \param[in] x est un entier coordonée d'une case
 * \param[in] y est un entier coordonée d'une case
 * \param[in, out] terrain est le terrain de jeu
 * \return un entier (1 si l'unite peut aller sur la case, 0 sinon)
 */
static int testCase(int x, int y, Terrain* terrain);

/**
 * \fn static int testCase(int x, int y, Terrain* terrain)
 * \brief rempli un tableau de Djikstra avec la distance des toutes les case par rapport a une case fixé.
 *
 * \param[in] x est un entier coordonée d'une case
 * \param[in] y est un entier coordonée d'une case
 * \param[in] tabD est un tableau de CellDjikstra
 * \param[in, out] terrain est le terrain de jeu
 */
static void djikstra(int x, int y,CellDjikstra* tabD, Terrain* terrain);

/* *************************************************************--Init--***************************************************************************** */

void initUnite(Unite* unit, const UniteBase* type, int idJoueur){
     FilePath* chemin = (FilePath*)malloc(sizeof(FilePath));
     initFilePath(chemin);
     clock_t tempo=clock();

     if(tempo == -1)
     {
          printf("Problème d'horloge");
          exit(EXIT_FAILURE);
     }

     /* id */
     printf("id= %d \n", idJoueur);
     setIdJoueurUnite(unit, idJoueur);
     printf("idJUnit= %d \n", getIdJoueurUnite(unit));
     /* posX et posY */
     setVieCouranteUnite(unit, getVieMaxUnite(type));
     setDeplacement(unit, 0);
     setTypeUnite(unit, type);
     /* posCibleX et posCibleY */
     /* posMineraiX posMineraiY */
     setEnTravail(unit, -1);
     setPierrePorte(unit, 0);
     setMithrilPorte(unit, 0);
     setChemin(unit, chemin);
     setTimerUnite(unit, tempo);
}

void detruireUnite(Unite** unit){
     detruireFilePath(getChemin(*unit));
     free(*unit);
     *unit=NULL;
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

int getPosMineraiX(const Unite* unit){
     return unit->posMineraiX;
}

int getPosMineraiY(const Unite* unit){
     return unit->posMineraiY;
}

char getEnTravail(const Unite* unit){
     return unit->enTravail;
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

void setPosMineraiX(Unite* unit, int x){
    unit->posMineraiX=x;
}

void setPosMineraiY(Unite* unit, int y){
     unit->posMineraiY=y;
}

void setEnTravail(Unite* unit, char enT){
     unit->enTravail=enT;
}

void setPierrePorte(Unite* unit, int p){
    unit->pierrePorte = p;
}

void setMithrilPorte(Unite* unit, int m){
    unit->mithrilPorte = m;
}

void  setChemin(Unite* unit, FilePath* file){
     unit->chemin=file;
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
          viderFilePath(getChemin(homme));
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

static int testCase(int x, int y, Terrain* terrain){
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
    free(tabD);

}

/* *************************************************************--FCT à tester--***************************************************************************** */

void Recolte(Unite* homme, Jeu* jeu){
     clock_t tempo=clock();
     float temps;
     int finRecolte = 0;
     int quantite;

     if(tempo == -1)
     {
          printf("Problème d'horloge");
          exit(EXIT_FAILURE);
     }

     temps= ((float)tempo-(float)homme->timerUnite)/CLOCKS_PER_SEC;

     if( temps >= (float) vitesseRecolte/1000)
     {
          quantite = getRessourceMax(getTypeUnite(homme)) - (getMithrilPorte(homme) + getPierrePorte(homme));

          if (quantite != 0 )
          {
                sCase* place = getCase(getCarteJeu(jeu), getPosMineraiX(homme), getPosMineraiY(homme));
                int test;

               if(getPierreCase(place)!= 0)
               {
                    if( quantite < quantiteRecolte)
                    {
                         quantite=quantite;
                         test=1;
                    }
                    else if( getPierreCase(place) < quantiteRecolte)
                    {
                         quantite=getPierreCase(place);
                         test=2;
                    }
                    else
                    {
                         quantite=quantiteRecolte;
                         test = 3;
                    }

                    printf("\n boucle %d -> recolte %d pierre", test,quantite);

                    setPierrePorte(homme, getPierrePorte(homme) + quantite);
                    setPierreCase(place, getPierreCase(place) - quantite);
               }
               else if(getMithrilCase(place) != 0)
               {
                    if( quantite < quantiteRecolte)
                    {
                         quantite=quantite;
                         test=1;
                    }
                    else if( getMithrilCase(place) < quantiteRecolte)
                    {
                         quantite=getMithrilCase(place);
                         test=2;
                    }
                    else
                    {
                         quantite=quantiteRecolte;
                         test = 3;
                    }

                    printf("\n boucle %d -> recolte %d mithril.", test,quantite);

                    setMithrilPorte(homme, getMithrilPorte(homme) + quantite);
                    setMithrilCase(place, getMithrilCase(place) - quantite);
               }
               if(getPierreCase(place)== 0 && getMithrilCase(place) == 0)
               {
                    if(getTileCase(place) == PIERRE || getTileCase(place) == MITHRIL)
                    {
                         setTileCase(place, 0);
                         setAcces(place, 1);
                    }
                    trouverMinerai(homme, jeu); /* cherche un nouveau minerai */
               }
          }
          else
          {
               setEnTravail(homme, 2); /*retour au bat principal cas sécuritaire n'est pas sensé arriver */
          }

          tempo=clock();
          if(tempo == -1)
          {
               printf("Problème d'horloge");
               exit(EXIT_FAILURE);
          }
          setTimerUnite(homme, tempo);
     }
}

void trouverMinerai(Unite* homme, Jeu* jeu){

     Terrain* terrain=getCarteJeu(jeu);
     CellDjikstra* tabD = (CellDjikstra*)malloc(sizeof(CellDjikstra)*getTailleX(terrain)*getTailleY(terrain));
     int x = getPosX(homme);
     int y = getPosY(homme);
     int fin=0;
     int caseCibleX=getPosMineraiX(homme);
     int caseCibleY=getPosMineraiY(homme);
     int caseTestX, caseTestY;
     int id = getContenu(getCase(terrain,x,y));
     int i;

     for(i = 0; i < getTailleX(terrain)*getTailleY(terrain); i++){
          tabD[i].distance = INFINI;
          tabD[i].precedent = 0;
     }
     setContenu(getCase(terrain, x,y), 0);
     djikstra(x, y, tabD,terrain);
     setContenu(getCase(terrain,x,y),id);

     i=1;
     printf(" \n\n\nl'ancien minerais est à la acse (%d, %d)\n\n\n debut recherche:\n", caseCibleX, caseCibleY);
     while (fin == 0)
     {
          caseTestX=caseCibleX+i;
          caseTestY=caseCibleY;
          fin=testMinerai(caseTestX, caseTestY, tabD, getCarteJeu(jeu));
          printf("fin = %d\n\n",fin);

          while(fin <=0 && caseTestX!=caseCibleX)
          {
               caseTestX--;
               caseTestY--;
               fin = testMinerai(caseTestX, caseTestY, tabD, getCarteJeu(jeu));
               printf("fin = %d\n\n",fin);
          }
          while(fin <=0 && caseTestY!=caseCibleY)
          {
               caseTestX--;
               caseTestY++;
               fin=testMinerai(caseTestX, caseTestY, tabD, getCarteJeu(jeu));
               printf("fin = %d\n\n",fin);
          }
          while(fin <=0 && caseTestX!=caseCibleX)
          {
               caseTestX++;
               caseTestY++;
               fin=testMinerai(caseTestX, caseTestY, tabD, getCarteJeu(jeu));
               printf("fin = %d\n\n",fin);
          }
          while(fin <=0 && caseTestY!=caseCibleY+1)
          {
               caseTestX++;
               caseTestY--;
               fin=testMinerai(caseTestX, caseTestY, tabD, getCarteJeu(jeu));
               printf("fin = %d\n\n",fin);
          }

          if (i>=5){
               fin=-500;
               printf("pas de minerais autour du dernier épuisé");
          }
          i++;
     }
     if(fin>0)
     {
          setPosMineraiX(homme, caseTestX);
          setPosMineraiY(homme, caseTestY);
          setPosCibleX(homme, caseTestX);
          setPosCibleY(homme, caseTestY);
          setEnTravail(homme,3); /* pars à la recherche du minerai */
          printf("Minerai trouve case (%d, %d)\n\n", getPosMineraiX(homme), getPosMineraiY(homme));
     }
     else
     {
          setEnTravail(homme,0); /* en repos */
     }
      free(tabD);
}

static int testMinerai(int x, int y, CellDjikstra* tabD, Terrain* terrain){
      if(x<0 || y < 0 || x >= getTailleX(terrain) || y >= getTailleY(terrain))
     {
          printf(" -> en dehors de la map <- ");
          return 0;
     }
     else if( tabD[(x+1)+y*getTailleX(terrain)].distance != INFINI || tabD[(x-1)+y*getTailleX(terrain)].distance != INFINI || tabD[x+(y+1)*getTailleX(terrain)].distance != INFINI|| tabD[x+(y-1)*getTailleX(terrain)].distance != INFINI)
     {
          printf("-> Case exploitable: (%d, %d)\n", x, y);
          int quantite =getPierreCase(getCase(terrain, x, y)) + getMithrilCase(getCase(terrain, x, y));
          printf("la quatite est %d\n", quantite);
          return quantite;
     }
}


/* *************************************************************--FCT en écriture--***************************************************************************** */

void attaque(Unite* homme, Jeu* jeu){

          viderFilePath(getChemin(homme));
          clock_t tempo=clock();
          float temps;
          int contenu = getContenu(getCase(getCarteJeu(jeu),getPosCibleX(homme),getPosCibleY(homme)));

          if(tempo == -1)
          {
               printf("Problème d'horloge");
               exit(EXIT_FAILURE);
          }

          temps= ((float)tempo-(float)homme->timerUnite)/CLOCKS_PER_SEC;

          if( temps >= (float) getVitesseAttaque(getTypeUnite(homme))/1000) /* attaquer */
          {
               if(contenu > 0){
                    /* annimation */
                    Unite* ennemi = getUnite(jeu, contenu);
                    printf("\ntape du %d", getAttaque(getTypeUnite(homme)));
                    setVieCouranteUnite(ennemi, getVieCouranteUnite(ennemi) - getAttaque(getTypeUnite(homme))); /* frappe une foi */
                    printf(" -> %d HP restant", getVieCouranteUnite(ennemi));
               }
               else if(contenu < 0){
                    /* annimation */
                    Batiment* bat = getBat(jeu, -contenu);
                    setVieCouranteBat(bat, getVieCouranteBat(bat) - getAttaque(homme));
               }
               setTimerUnite(homme, tempo);
          }
}

int aPortee(Unite* homme, Jeu* jeu){
     int portee = getPorteeUnite(getTypeUnite(homme));
     int hommeX = getPosX(homme);
     int hommeY = getPosY(homme);
     int cibleX = getPosCibleX(homme);
     int cibleY = getPosCibleY(homme);

     if(hommeY < (cibleY - portee) || hommeY > (cibleY + portee))
     {
          return 0;
     }
     else if (hommeX < (cibleX - portee) || hommeX > (cibleX + portee))
     {
          return 0;
     }
     else
     {
          return 1;
     }
}

void surveille(Unite* homme, Jeu* jeu){
     int i,j, id;
     int x = getPosX(homme);
     int y = getPosY(homme);
          for (i=x-4; i<=x+4; i++)
          {
               for(j=y-4; j<=y+4; j++)
               {

                   if(i<0 || j < 0 || i >= getTailleX(getCarteJeu(jeu)) || j >= getTailleY(getCarteJeu(jeu)))
                    {

                    }
                    else
                    {
                         id=getIdJoueurCase(jeu, getCase(getCarteJeu(jeu), i, j));
                         if(id != getIdJoueurUnite(homme) && id != -1)
                         {
                              setPosCibleX(homme, i);
                              setPosCibleY(homme, j);
                         }
                    }
               }
          }
     }

