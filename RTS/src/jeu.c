/**
 * \file  jeu.c
 * \brief module  jeu
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module du coeur du  jeu (boucle de  jeu/ affichage/gestion evenement)
 *
 */

#include "jeu.h"
#include "afficheSDL.h"

/* *************************************************************--Init--***************************************************************************** */

void commencerPartie(Jeu* j, int raceJ, char* cheminCarte, char* nomJ){
    int i;
    Joueur* tabJ;
    Terrain* ter;
    TabDyn* tabUnite;
    TabDyn* tabBat;
    setNbJoueur(j,1);
    j->aff = (Affichage*) malloc((sizeof(Affichage)));
    tabUnite = (TabDyn*)malloc(sizeof(TabDyn));
    tabBat = (TabDyn*)malloc(sizeof(TabDyn));
    tabJ = (Joueur*) malloc(sizeof(Joueur)*getNbJoueur(j));
    ter = (Terrain*) malloc(sizeof(Terrain));
    initTabDyn(tabUnite,2);
    j->tableauUnite = tabUnite;
    initTabDyn(tabBat,2);
    j->tableauBat = tabBat;
    setVueJoueur(j, 0);
    for(i = 0;i < getNbJoueur(j); i++){
        initJoueur(&tabJ[i],i,nomJ, raceJ, 0,0);
    }
    j->tableauJoueur = tabJ;
    initTerrain(ter,cheminCarte);
    setCarteJeu(j,ter);
    setIdSel(j,0);
    j->tabBatConstructible = chargementBatBase();
    j->tabUniteFormable = chargementUniteBase();
    initAffichage(j->aff,j,j->carte);
    boucleJeu(j);
}

void detruireJeu(Jeu* j){
    detruireTerrain(&(j->carte));
    free(j->tableauJoueur);
    detruireTabDyn(j->tableauUnite);
    free(j->tableauUnite);
    detruireTabDyn(j->tableauBat);
    free(j->tableauBat);
    free(j->tabBatConstructible);
    free(j->tabUniteFormable);
}

/* *************************************************************--GET--***************************************************************************** */

int getNbJoueur(const Jeu* j){
    return j->nbJoueur;
}


int getVueJoueur(const Jeu* j){
    return j->vueJoueur;
}

Joueur* getJoueur(const Jeu* j, int jNb){
    return &(j->tableauJoueur[jNb]);
}

Terrain* getCarteJeu(const Jeu* j){
    return j->carte;
}

Unite* getUnite(const Jeu* j, int uNb){
    return (Unite*) getElemTabDyn(j->tableauUnite, uNb);
}

Batiment* getBat(const Jeu* j, int bNb){
    return (Batiment*) getElemTabDyn(j->tableauBat, bNb);
}

UniteBase* getUniteFormable(const Jeu* j, int uNb){
    return &(j->tabUniteFormable[uNb]);
}


BatBase* getBatConstructible(const Jeu* j, int bNb){
    return &(j->tabBatConstructible[bNb]);
}

int getIdSel(const Jeu* j){
    return j->idSel;
}

int getIdJoueurCase(const Jeu* jeu, const sCase* place){
     int contenu = getContenu(place);
     if (contenu == 0)
     {
          return -1;
     }
     else if(contenu > 0)
     {
         return getIdJoueurUnite(getUnite(jeu, contenu));
     }
     else
     {
         return getIdJoueurBat(getBat(jeu, contenu));
     }
}

TabDyn* getTabUnite(Jeu* j){
     return j->tableauUnite;
}

TabDyn* getTabBat(Jeu* j){
     return j->tableauBat;
}

/* *************************************************************--SET--***************************************************************************** */

void setNbJoueur(Jeu* j, int nb){
    j->nbJoueur = nb;
}

void setVueJoueur(Jeu* j, int jNb){
    j->vueJoueur = jNb;
}

void setCarteJeu(Jeu* j, Terrain* c){
    j->carte = c;
}

void ajouterUnite(Jeu* j, Unite* unit){
    ajouterTabDyn(j->tableauUnite, (uintptr_t)unit);
}

void setUnite(const Jeu*  j, int uNb, Unite* unit){
    j->tableauUnite->tab[uNb] = (uintptr_t*) unit;
}

void ajouterBat(Jeu* j, Batiment* bat){
    ajouterTabDyn(j->tableauBat, (uintptr_t)bat);
}

void setIdSel(Jeu* j,int id){
    j->idSel = id;
}

/* *************************************************************--FCT--***************************************************************************** */

void boucleJeu(Jeu* j){
      int quit = 0;
      int ok;
      int i,k;
      int x,y;
      int xClick,yClick;
      SDL_Event e;
      Joueur* joueur = getJoueur(j,getVueJoueur(j));
      Unite* u;
      Batiment* b;
      b = (Batiment*) malloc(sizeof(Batiment));
      u = (Unite*) malloc(sizeof(Unite));
      initBatiment(b,0,getBatConstructible(j,0),0,getVueJoueur(j));
      setPosXBat(b,8);
      setPosYBat(b,2);
      printf("%d\n",getVueJoueur(j));
      initUnite(u, getUniteFormable(j,0), getVueJoueur(j));
      setNourritureCourante(joueur, 1);
      printf("%d \n",getTileUnite(getTypeUnite(u)));
      ajouterTabDyn(j->tableauBat, (uintptr_t) b);
      ajouterTabDyn(j->tableauUnite, (uintptr_t) u);
      setPosX(u,6);
      setPosY(u,1);
      setPosCibleX(u,6);
      setPosCibleY(u,1);
      u = (Unite*) malloc(sizeof(Unite));
      initUnite(u, getUniteFormable(j,0), getVueJoueur(j)+1);
      ajouterTabDyn(j->tableauUnite, (uintptr_t) u);
      setPosX(u,10);
      setPosY(u,5);
      setPosCibleX(u,10);
      setPosCibleY(u,5);
      setPosBatPX(joueur,8);
      setPosBatPY(joueur,2);
      j->carte->tabCase[6+getTailleX(j->carte)].idContenu = 1;
      j->carte->tabCase[10+5*getTailleX(j->carte)].idContenu = 2;
      j->carte->tabCase[8+2*getTailleX(j->carte)].idContenu = -1;
      j->carte->tabCase[9+2*getTailleX(j->carte)].idContenu = -1;
      j->carte->tabCase[8+3*getTailleX(j->carte)].idContenu = -1;
      j->carte->tabCase[9+3*getTailleX(j->carte)].idContenu = -1;
      while( !quit ){
            checkJeu(j);
            SDL_PumpEvents();
            SDL_GetMouseState(&x,&y);
        while( SDL_PollEvent(&e) != 0 ){
             if( e.type == SDL_QUIT ){
                quit = 1;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN){
                xClick = e.button.x;
                yClick = e.button.y;
                if(yClick < SCREEN_H-HUD_H){
                    xClick = xClick/TILE_TAILLE + getCameraX(joueur);
                    yClick = yClick/TILE_TAILLE + getCameraY(joueur);
                    if(e.button.button == SDL_BUTTON_LEFT){
                        if(getBatConstruction(joueur) == NULL)
                            setIdSel(j,getContenu(getCase(getCarteJeu(j),xClick,yClick)));
                        else{
                            if(xClick + 1 < getTailleX(getCarteJeu(j)) && yClick + 1 < getTailleY(getCarteJeu(j))){
                                ok = 1;
                                for(i = 0; i < getTailleCaseX(getBatConstruction(joueur)); i++){
                                    for(k = 0; k < getTailleCaseY(getBatConstruction(joueur)); k++){
                                        if(getAcces(getCase(getCarteJeu(j), xClick+i, yClick+k)) != 1 || getContenu(getCase(getCarteJeu(j), xClick+i, yClick+k)) != 0)
                                           ok = 0;
                                    }
                                }
                                if(getPierreJoueur(joueur) < getCoutPierreBat(getBatConstruction(joueur))
                                   || getMithrilJoueur(joueur) < getCoutMithrilBat(getBatConstruction(joueur))){
                                    ok = 0;
                                    setBatConstruction(joueur, NULL);
                                   }
                                if(ok){

                                    b = (Batiment*)malloc(sizeof(Batiment));
                                    int race = getIdRace(joueur);
                                    initBatiment(b,ajouterTabDyn(getTabBat(j),(uintptr_t)b), getBatConstruction(joueur),1,getVueJoueur(j));
                                    setPosXBat(b, xClick);
                                    setPosYBat(b, yClick);
                                    setPierreJoueur(joueur, getPierreJoueur(joueur) - getCoutPierreBat(getTypeBat(b)));
                                    setMithrilJoueur(joueur, getMithrilJoueur(joueur) - getCoutMithrilBat(getTypeBat(b)));
                                    for(i = 0; i < getTailleCaseX(getTypeBat(b)); i++){
                                        for(k = 0; k < getTailleCaseY(getTypeBat(b)); k++){
                                            setContenu(getCase(getCarteJeu(j),xClick+i, yClick+k),-getIdBat(b));
                                        }
                                    }
                                    setBatConstruction(joueur, NULL);
                                }
                            }
                        }
                    }
                    else if(e.button.button == SDL_BUTTON_RIGHT){
                        if(getIdSel(j) < 0){

                        }
                        else if(getIdSel(j) > 0){
                            if(getIdJoueurUnite(getUnite(j, getIdSel(j))) == getVueJoueur(j)){
                                u = getUnite(j,getIdSel(j));
                                setPosCibleX(u, xClick);
                                setPosCibleY(u, yClick);
                            }
                        }
                    }
                }
               else{
                    if(e.button.button == SDL_BUTTON_LEFT){
                        if(xClick > (SCREEN_W - 3*TILE_TAILLE) && xClick < SCREEN_W){
                            if(getIdSel(j) < 0){
                                if( getIdJoueurBat(getBat(j,-getIdSel(j))) == getVueJoueur(j)){
                                    b = getBat(j, -getIdSel(j));
                                    xClick -= (SCREEN_W - 3*TILE_TAILLE);
                                    xClick = xClick /TILE_TAILLE;
                                    yClick -= (SCREEN_H-HUD_H);
                                    yClick = yClick /TILE_TAILLE;
                                    if((yClick*3+xClick) < getNbUniteFormable(getTypeBat(b))){
                                        ajouterFileBat(b,j,yClick*3+xClick);
                                    }
                                }
                            }
                        }
                        else if(xClick > 0 && xClick < 3*TILE_TAILLE){
                            xClick = xClick / TILE_TAILLE;
                            yClick = (yClick-SCREEN_H+HUD_H) / TILE_TAILLE;
                            if((xClick + yClick * 3) < NB_BAT_RACE){
                                setBatConstruction(joueur, getBatConstructible(j,xClick+yClick*3 + getIdRace(joueur)*NB_BAT_RACE));
                            }
                        }
                    }
                }
            }

        }
        if( x >= SCREEN_W-20){
            if(((j->tableauJoueur[j->vueJoueur].cameraX) + 1) <= j->carte->tailleX - SCREEN_W/TILE_TAILLE)
                (j->tableauJoueur[j->vueJoueur].cameraX)++;
        }
        if( x < 20 ){
            if(((j->tableauJoueur[j->vueJoueur].cameraX) - 1) >= 0)
                (j->tableauJoueur[j->vueJoueur].cameraX)--;
        }
        if( y >= SCREEN_H-20){
            if(((j->tableauJoueur[j->vueJoueur].cameraY) + 1) <= j->carte->tailleY - (SCREEN_H-HUD_H)/TILE_TAILLE)
                (j->tableauJoueur[j->vueJoueur].cameraY)++;
        }
        if( y < 20 ){
            if(((j->tableauJoueur[j->vueJoueur].cameraY) - 1) >= 0)
                (j->tableauJoueur[j->vueJoueur].cameraY)--;


        }
        affiche(j->aff);
    }
}

void checkJeu(Jeu* jeu){

     int taille, i, egale, enConstru;
     sCase* place;
     Unite* soldat;
     Batiment* bat;

     /* Activité des Unités */

     taille = getUtiliseTabDyn(getTabUnite(jeu)); /*faire fonction TabDyn et tabUnite */
     for(i=1;i<taille+1;i++)
     {
          soldat = getUnite(jeu,i);
          if (getVieCouranteUnite(soldat) <= 0)
          {
              detruireUnite(&soldat);
              printf("valeur du pointeur sur soldat: %d", (int) soldat);
              setUnite(jeu, i, soldat);
              /* enfiler I dans la file de case dispo */
          }
          else
          {
               egale = memeCase(getPosX(soldat), getPosY(soldat), getPosCibleX(soldat), getPosCibleY(soldat));

               if(getOuvrier(getTypeUnite(soldat)) == 1) /* est un ouvrier */
               {
                    char statut = getEnTravail(soldat);
                    if(statut == -1){
                        if(egale != 1){
                            if(getTileCase(getCase(getCarteJeu(jeu),getPosCibleX(soldat), getPosCibleY(soldat))) == PIERRE
                            || getTileCase(getCase(getCarteJeu(jeu),getPosCibleX(soldat), getPosCibleY(soldat))) == MITHRIL ){
                                setEnTravail(soldat, 3);
                                setPosMineraiX(soldat, getPosCibleX(soldat));
                                setPosMineraiY(soldat,getPosCibleY(soldat));
                               }
                            else
                                deplacementUnite(soldat, getCarteJeu(jeu));
                        }

                    }
                    if(statut == 0) /*vide son sac et pars en repos */
                    {
                         printf("\n\npierre %d \n", getPierrePorte(soldat));
                         setPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)),getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getPierrePorte(soldat));
                         setPierrePorte(soldat, 0);
                         printf("Mithril %d \n", getMithrilPorte(soldat));
                         setMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)), getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getMithrilPorte(soldat));
                         printf("le joueur possède maintenant %d mithril %d pierre", getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))), getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))));
                         setMithrilPorte(soldat, 0);
                         setEnTravail(soldat, -1);
                    }
                    if( statut == 1) /* phase de récolte */
                    {
                         if(getRessourceMax(getTypeUnite(soldat)) - (getPierrePorte(soldat) + getMithrilPorte(soldat)) == 0)
                         {
                              setEnTravail(soldat,2);
                              printf("%d",getIdJoueurUnite(soldat));
                              setPosCibleX(soldat,getPosBatPX(getJoueur(jeu, getIdJoueurUnite(soldat))));
                              setPosCibleY(soldat,getPosBatPY(getJoueur(jeu, getIdJoueurUnite(soldat))));
                              deplacementUnite(soldat, getCarteJeu(jeu));
                         }
                         else
                         {
                              Recolte(soldat,jeu);
                         }
                    }
                    else if( statut == 2) /*phase de "vidage" du sac */
                    {
                         if(egale ==1)
                         {
                              printf("\n\npierre %d \n", getPierrePorte(soldat));
                              setPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)),getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getPierrePorte(soldat));
                              setPierrePorte(soldat, 0);
                              printf("Mithril %d \n", getMithrilPorte(soldat));
                              setMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)), getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getMithrilPorte(soldat));
                              printf("le joueur possède maintenant %d mithril %d pierre", getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))), getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))));
                              setMithrilPorte(soldat, 0);
                              if(getPierreCase(getCase(getCarteJeu(jeu), getPosMineraiX(soldat), getPosMineraiY(soldat))) == 0 && getMithrilCase(getCase(getCarteJeu(jeu), getPosMineraiX(soldat), getPosMineraiY(soldat)))== 0)
                              {
                                   place = getCase(getCarteJeu(jeu), getPosMineraiX(soldat), getPosMineraiY(soldat));
                                   if(getTileCase(place) == PIERRE || getTileCase(place) == MITHRIL)
                                   {
                                        setTileCase(place, 0);
                                        setAcces(place, 1);
                                   }
                                   trouverMinerai(soldat, jeu); /*attention ajouter un teste pour minerais epuisé*/
                              }
                              else{
                                setPosCibleX(soldat,getPosMineraiX(soldat));
                                setPosCibleY(soldat, getPosMineraiY(soldat));
                                setEnTravail(soldat, 3);
                              }
                         }
                         else
                         {
                              deplacementUnite(soldat, getCarteJeu(jeu));
                         }
                    }
                    else if(statut == 3) /* phase de retour au travail */
                    {
                         if(egale == 1)
                         {
                              setEnTravail(soldat,1);
                              Recolte(soldat,jeu);

                         }
                         else
                         {
                              deplacementUnite(soldat, getCarteJeu(jeu));
                         }
                    }
               }
               else if( egale != 1)
               {
                    if(getDeplacement(soldat) == 1)
                    {
                         deplacementUnite(soldat, getCarteJeu(jeu));
                    }
                    else
                    {
                         place = getCase(getCarteJeu(jeu), getPosCibleX(soldat), getPosCibleY(soldat));

                         if(getIdJoueurCase(jeu, place) != getIdJoueurUnite(soldat)  && getIdJoueurCase(jeu, place) != -1)
                         {
                              attaque(soldat,jeu);
                         }
                         else
                         {
                              setDeplacement(soldat,1);
                              deplacementUnite(soldat, getCarteJeu(jeu));
                         }
                    }
               }
          }
     }

     /* Activité des batiment */

     taille = getUtiliseTabDyn(getTabBat(jeu));
     for(i=1;i<taille+1;i++)
     {
          bat = getBat(jeu, i);
          verifierTimerBat(bat,jeu);
     }

}
