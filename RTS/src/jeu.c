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

void commencerPartie(Jeu* j, int raceJ, char* cheminCarte){
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
        initJoueur(&tabJ[i],i, raceJ, 0,0);
    }
    j->tableauJoueur = tabJ;
    initTerrain(ter,cheminCarte);
    setCarteJeu(j,ter);
    setIdSel(j,0);
    j->tabBatConstructible = chargementBatBase();
    j->tabUniteFormable = chargementUniteBase();
    initAffichage(j->aff,j,j->carte);
    boucleMenu(j);
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
         return getIdJoueurBat(getBat(jeu, -contenu));
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
    j->tableauUnite->tab[uNb-1] = (uintptr_t*) unit;
}

void setBat(const Jeu*  j, int bNb, Batiment* bat){
    j->tableauBat->tab[bNb-1] = (uintptr_t*) bat;
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
      initUnite(u, getUniteFormable(j,0), getVueJoueur(j));
      setNourritureCourante(joueur, 1);
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
            if(e.type == SDL_KEYDOWN){
                if(e.key.keysym.sym == SDLK_ESCAPE){
                    quit = boucleMenu2(j);
                }
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
                                    if(getNbUniteFormable(getBatConstruction(joueur)) == 0){
                                        setNourritureMax(joueur, getNourritureMax(joueur)+10);
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
                            if((xClick + yClick * 3) < NB_BAT_RACE-1){
                                setBatConstruction(joueur, getBatConstructible(j,xClick+yClick*3 + 1 + getIdRace(joueur)*NB_BAT_RACE));
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
        affiche(j->aff,x,y);
    }
}

void checkJeu(Jeu* jeu){

     int taille, i, egale, enConstru,j,k;
     sCase* place;
     Unite* soldat;
     Batiment* bat;

     /* Activité des Unités */

     taille = getUtiliseTabDyn(getTabUnite(jeu));
     for(i=1;i<taille+1;i++)
     {
          soldat = getUnite(jeu,i);
          if(soldat != NULL){
              if (getVieCouranteUnite(soldat) <= 0)
              {
                   setContenu(getCase(getCarteJeu(jeu), getPosX(soldat), getPosY(soldat)), 0);
                   detruireUnite(&soldat);
                   supprimerUnite(jeu, i);
                   if(getIdSel(jeu) == i){
                        setIdSel(jeu,0);
                   }
              }
              else
              {
                   egale = memeCase(getPosX(soldat), getPosY(soldat), getPosCibleX(soldat), getPosCibleY(soldat));

                   if(getOuvrier(getTypeUnite(soldat)) == 1) /* est un ouvrier */
                   {
                         char statut = getEnTravail(soldat);
                         if(statut == -1)
                         {
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
                             if(getRaceUnite(getTypeUnite(soldat)) == 0 && getNourritureCourante(getJoueur(jeu, getIdJoueurUnite(soldat))) > 25){
                                 setPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)),getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + (getPierrePorte(soldat)*80)/100);
                                 setPierrePorte(soldat, 0);
                                 setMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)), getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + (getMithrilPorte(soldat)*80)/100);
                                 setMithrilPorte(soldat, 0);
                             }else{
                                 setPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)),getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getPierrePorte(soldat));
                                 setPierrePorte(soldat, 0);
                                 setMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)), getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getMithrilPorte(soldat));
                                 setMithrilPorte(soldat, 0);
                             }
                             setEnTravail(soldat, -1);
                         }
                         if( statut == 1) /* phase de récolte */
                         {
                             if(getRessourceMax(getTypeUnite(soldat)) - (getPierrePorte(soldat) + getMithrilPorte(soldat)) == 0)
                             {
                                  setEnTravail(soldat,2);
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
                                    if(getRaceUnite(getTypeUnite(soldat)) == 0 && getNourritureCourante(getJoueur(jeu, getIdJoueurUnite(soldat))) > 25){
                                         setPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)),getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + (getPierrePorte(soldat)*80)/100);
                                         setPierrePorte(soldat, 0);
                                         setMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)), getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + (getMithrilPorte(soldat)*80)/100);
                                         setMithrilPorte(soldat, 0);
                                     }else{
                                         setPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)),getPierreJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getPierrePorte(soldat));
                                         setPierrePorte(soldat, 0);
                                         setMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat)), getMithrilJoueur(getJoueur(jeu,getIdJoueurUnite(soldat))) + getMithrilPorte(soldat));
                                         setMithrilPorte(soldat, 0);
                                     }
                                   setPosCibleX(soldat,getPosMineraiX(soldat));
                                   setPosCibleY(soldat, getPosMineraiY(soldat));
                                   setEnTravail(soldat, 3);
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
                   else
                   {
                        if( egale != 1)
                        {
                             place = getCase(getCarteJeu(jeu), getPosCibleX(soldat), getPosCibleY(soldat));
                             if(getIdJoueurCase(jeu, place) != getIdJoueurUnite(soldat)  && getIdJoueurCase(jeu, place) != -1)
                             {
                                   if (aPortee(soldat, jeu )== 1)
                                   {
                                        attaque(soldat,jeu);
                                   }
                                   else
                                   {
                                        surveille(soldat,jeu);
                                        int cibleX = getPosCibleX(soldat);
                                        int cibleY = getPosCibleY(soldat);

                                        deplacementUnite(soldat, getCarteJeu(jeu));

                                        setPosCibleX(soldat, cibleY);
                                   }
                             }
                             else
                             {
                                   surveille(soldat,jeu);
                                   deplacementUnite(soldat, getCarteJeu(jeu));
                             }

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
        if(bat != NULL){
            if(getVieCouranteBat(bat) <= 0){
                for(j = 0; j < getTailleCaseX(getTypeBat(bat)); j++){
                    for(k = 0; k < getTailleCaseY(getTypeBat(bat)); k++){
                         setContenu(getCase(getCarteJeu(jeu), getPosXBat(bat)+j, getPosYBat(bat))+k, 0);
                    }
                }
                detruireBatiment(&bat);
                supprimerBat(jeu, i);
                if(getIdSel(jeu) == -i){
                    setIdSel(jeu,0);
                }
            }else
                verifierTimerBat(bat,jeu);
        }
     }

}

void supprimerUnite(Jeu* jeu, int index){
    supprimerElemTabDyn(jeu->tableauUnite, index-1);
}


void supprimerBat(Jeu* jeu, int index){
    supprimerElemTabDyn(jeu->tableauBat, index-1);
}


/* *************************************************************--FCT--***************************************************************************** */

void sauvegarder(Jeu* jeu, unsigned char numSauvegarde){
     int i,j;
     FILE* fish;
     Unite* u;
     Cellule* c;
     Batiment* bat;
     if(numSauvegarde==1)
          fish=fopen("data/save/sauvegarde01.sav","w+");
     else if(numSauvegarde==2)
          fish=fopen("data/save/sauvegarde02.sav","w+");
     else if (numSauvegarde==3)
          fish=fopen("data/save/sauvegarde03.sav","w+");
     else
     {
          fprintf(stderr, "La sauvegarde à échouée");
          return;
     }
     if(fish){
         fprintf(fish,"nbJoueur=%d\n\n", getNbJoueur(jeu));

         /*tabJoueur*/
         for(i=0; i<getNbJoueur(jeu);i++)
         {
              Joueur* joueur =getJoueur(jeu,i);
              fprintf(fish,"%d\n", getIdJoueur(joueur));
              fprintf(fish,"%d\n", getPierreJoueur(joueur));
              fprintf(fish,"%d\n",getMithrilJoueur(joueur));
              fprintf(fish,"%d\n",getIdRace(joueur));
              fprintf(fish,"%d\n",getNourritureMax(joueur));
              fprintf(fish,"%d\n",getNourritureCourante(joueur));
              fprintf(fish,"%d\n",getCameraX(joueur));
              fprintf(fish,"%d\n",getCameraY(joueur));
              fprintf(fish,"%d\n",getPosBatPX(joueur));
              fprintf(fish,"%d\n",getPosBatPY(joueur));
              fprintf(fish,"\n");
         }
         /*le terrain*/
         fprintf(fish,"%d\n%d\n", getTailleX(getCarteJeu(jeu)), getTailleY(getCarteJeu(jeu)));
         for(i=0; i< getTailleX(getCarteJeu(jeu))* getTailleY(getCarteJeu(jeu)); i++)
         {
              fprintf(fish,"%d ",getAcces(&getCarteJeu(jeu)->tabCase[i]));
              fprintf(fish,"%d ",getPierreCase(&getCarteJeu(jeu)->tabCase[i]));
              fprintf(fish,"%d ",getMithrilCase(&getCarteJeu(jeu)->tabCase[i]));
              fprintf(fish,"%d ",getContenu(&getCarteJeu(jeu)->tabCase[i]));
              fprintf(fish,"%d\n",getTileCase(&getCarteJeu(jeu)->tabCase[i]));
         }

         /*TabUnite*/
         printf("TABUNITE");
         fprintf(fish, "nbUnite=%d\n", getUtiliseTabDyn(getTabUnite(jeu)));
        for(i=1; i<=getUtiliseTabDyn(getTabUnite(jeu)); i++){
            printf("%d\n",i);
            u = getUnite(jeu, i);
            if(u == NULL){
                fprintf(fish,"id=-1\n");
                fprintf(fish,"idJ=0\n");
                fprintf(fish,"posX=0\n");
                fprintf(fish,"posY=0\n");
                fprintf(fish,"vie=0\n");
                fprintf(fish,"pierrePorte=0\n");
                fprintf(fish,"MithrilPorte=0\n");
                fprintf(fish,"type=0\n");
            }else{
                fprintf(fish,"id=%d\n", i);
                fprintf(fish,"idJ=%d\n",  getIdJoueurUnite(u));
                fprintf(fish,"posX=%d\n", getPosX(u));
                fprintf(fish,"posY=%d\n", getPosY(u));
                fprintf(fish,"vie=%d\n", getVieCouranteUnite(u));
                fprintf(fish,"pierrePorte=%d\n", getPierrePorte(u));
                fprintf(fish,"MithrilPorte=%d\n", getMithrilPorte(u));
                fprintf(fish,"type=%d\n", getTileUnite(getTypeUnite(u))-12);
            }
            fprintf(fish,"\n");
         }

         /*TabBat*/
          printf("TABBAT");
         fprintf(fish, "nbBatiment=%d\n", getUtiliseTabDyn(getTabBat(jeu)));
        for(i=1; i<=getUtiliseTabDyn(getTabBat(jeu)); i++){
             bat = getBat(jeu, i);
             j=0;
             if(bat == NULL){
                fprintf(fish,"id=1\n");
                fprintf(fish,"idJ=0\n");
                fprintf(fish,"posX=0\n");
                fprintf(fish,"posY=0\n");
                fprintf(fish,"vie=0\n");
                fprintf(fish,"enConstruction=0\n");
             }
             else{
                fprintf(fish,"id=%d\n", -i);
                fprintf(fish,"idJ=%d\n",  getIdJoueurBat(bat));
                fprintf(fish,"posX=%d\n", getPosXBat(bat));
                fprintf(fish,"posY=%d\n", getPosYBat(bat));
                fprintf(fish,"vie=%d\n", getVieCouranteBat(bat));
                fprintf(fish,"enConstruction=%d\n", getEnConstruction(bat));
                while(getTypeBat(bat) != getBatConstructible(jeu, j)){
                  j++;
                }
                fprintf(fish,"type=%d\n",j);
                j = 0;
                c = getPremier(getTabAttente(bat));
                while(c != NULL){
                  j++;
                  c = getSuivant(c);
                }
                fprintf(fish,"tailleTabAttente=%d\n", j);
                while(regardeTeteFile(getTabAttente(bat)) != NULL){
                  j=0;
                  while(regardeTeteFile(getTabAttente(bat)) != getUniteFormable(jeu, j)){
                      j++;
                  }
                  fprintf(fish, "%d\n", j);
                  defile(getTabAttente(bat));
                }
             }
        }

         /* vueJoueur */
         fprintf(fish, "\nvueJoueur=%d\n", getVueJoueur(jeu));
         /*mettre l'id à NULL*/
         fclose(fish);
     }
}

void charger(Jeu* jeu, unsigned char numSauvegarde){
     int i, compteur,j,k,l;
     Unite* u;
     Batiment* bat;
     FILE* fish;
     FilePath* fileP;
     File* fileBat;
     if(numSauvegarde==1)
          fish=fopen("data/save/sauvegarde01.txt","r");
     else if(numSauvegarde==2)
          fish=fopen("data/save/sauvegarde02.txt","r");
     else if (numSauvegarde==3)
          fish=fopen("data/save/sauvegarde03.txt","r");
     else
     {
          printf("La chargement de la partie a échoué");
          return;
     }
    if(fish){
         free(jeu->tableauJoueur);
         fscanf(fish,"nbJoueur=%d\n\n", &(jeu->nbJoueur));

         /*tabJoueur*/
         for(i=0; i<getNbJoueur(jeu); i++)
         {
              Joueur* joueur = getJoueur(jeu,i);
              fscanf(fish,"%d\n", &(joueur->idJoueur));
              fscanf(fish,"%d\n", &(joueur->pierre));
              fscanf(fish,"%d\n",&(joueur->mithril));
              fscanf(fish,"%d\n",&(joueur->idRace));
              fscanf(fish,"%d\n",&(joueur->nourritureMax));
              fscanf(fish,"%d\n",&(joueur->nourritureCourante));
              fscanf(fish,"%d\n",&(joueur->cameraX));
              fscanf(fish,"%d\n",&(joueur->cameraY));
              fscanf(fish,"%d\n",&(joueur->posBatPX));
              fscanf(fish,"%d\n",&(joueur->posBatPY));
              fscanf(fish,"\n");
         }

         /*le terrain*/
         fscanf(fish,"%d\n%d\n", &(jeu->carte->tailleX), &(jeu->carte->tailleY));
         for(i=0; i< getTailleX(getCarteJeu(jeu))* getTailleY(getCarteJeu(jeu)); i++)
         {
              fscanf(fish,"%d ",&(jeu->carte->tabCase[i].acces));
              fscanf(fish,"%d ",&(jeu->carte->tabCase[i].pierre));
              fscanf(fish,"%d ",&(jeu->carte->tabCase[i].mithril));
              fscanf(fish,"%d ",&(jeu->carte->tabCase[i].idContenu));
              fscanf(fish,"%d\n",&(jeu->carte->tabCase[i].tile));
         }

         /*TabUnite*/
         fscanf(fish, "nbUnite=%d\n", &compteur);
         for(i=0; i<compteur; i++){
            u = (Unite*)malloc(sizeof(Unite));
            fscanf(fish,"id=%d\n", &(u->id));
            fscanf(fish,"idJ=%d\n",  &(u->idJoueur));
            fscanf(fish,"posX=%d\n", &(u->posX));
            fscanf(fish,"posY=%d\n", &(u->posY));
            fscanf(fish,"vie=%d\n", &(u->vieCourante));
            fscanf(fish,"pierrePorte=%d\n", &(u->pierrePorte));
            fscanf(fish,"MithrilPorte=%d\n",&(u->mithrilPorte));
            fscanf(fish,"type=%d\n", &j);
            printf("%d\n", j);
            setTypeUnite(u, getUniteFormable(jeu, j));
            setDeplacement(u, 0);
            setPosCibleX(u, getPosX(u));
            setPosCibleY(u, getPosY(u));
            setPosMineraiX(u, -1);
            setPosMineraiY(u, -1);
            setEnTravail(u, -1);
            fileP = (FilePath*) malloc(sizeof(FilePath));
            initFilePath(fileP);
            setChemin(u, fileP);
            j = clock();
            if(j == -1){
              fprintf(stderr, "Problème d'horloge");
              exit(EXIT_FAILURE);
            }
            setTimerUnite(u, j);
            ajouterUnite(jeu, u);
            fscanf(fish,"\n");
         }
         for(i=1; i<=compteur; i++){
            if(getId(getUnite(j, i)) == -1){
              supprimerUnite(jeu,i);
            }
         }

         /*TabBat*/
         fscanf(fish, "nbBatiment=%d\n", &compteur);
         for(i=0; i<compteur; i++)
         {
              bat = (Batiment*)malloc(sizeof(Batiment));
              fscanf(fish,"id=%d\n", &(bat->id));
              fscanf(fish,"idJ=%d\n", &(bat->idJoueur));
              fscanf(fish,"posX=%d\n", &(bat->x));
              fscanf(fish,"posY=%d\n", &(bat->y));
              fscanf(fish,"vie=%d\n", &(bat->vieCourante));
              fscanf(fish,"enConstruction=%d\n", &(bat->enConstruction));
              fscanf(fish,"type=%d\n",j);
              setTypeBat(bat, getBatConstructible(jeu,j));
              fscanf(fish,"tailleTabAttente=%d\n", j);
              fileBat = (File*)malloc(sizeof(File));
              initFile(fileBat);
              setTabAttente(bat, fileBat);
              for(l = 0; l < j; l++){
                fscanf(fish,"%d\n", &k);
                enfile(fileBat, getUniteFormable(jeu,k));
              }
              j = clock();
              if(j == -1){
                fprintf(stderr, "Problème d'horloge");
                exit(EXIT_FAILURE);
              }
              setTimerBat(bat,j);
              ajouterBat(jeu,bat);

         }
         for(i=1; i<=compteur; i++){
            if(getIdBat(getBat(jeu, i)) == 1){
                supprimerBat(jeu, i);
            }
         }
         /* vueJoueur */
         fscanf(fish,"\nvueJoueur=%d\n", &(jeu->vueJoueur));

         setIdSel(jeu,0); /* à verifier*/
         fclose(fish);
         boucleJeu(jeu);
    }else{
         fprintf(stderr,"La chargement de la partie a échoué");
          return;
    }
}

void boucleMenu(Jeu* jeu){
    SDL_Event e;
    int quit=0;
    int menu = 0;
    int x,y;
    while(!quit){
        while( SDL_PollEvent(&e) != 0 ){
            afficheMenu(jeu->aff, menu);
            if( e.type == SDL_QUIT ){
                quit = 1;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN){
                if(e.button.button == SDL_BUTTON_LEFT){
                    x = e.button.x;
                    y = e.button.y;
                    x /= TILE_TAILLE;
                    y /= TILE_TAILLE;
                    if(x > (((SCREEN_W-3*TILE_TAILLE)/2)/TILE_TAILLE) && x < (((SCREEN_W-3*TILE_TAILLE)/2)/TILE_TAILLE)+3){
                        if( y == 3){
                            if(menu == 0){
                                menu = 2;
                            }else if(menu == 1){
                                charger(jeu, 1);
                            }else{
                                charger(jeu, 3);
                            }

                        }
                        if(y == 4){
                            if(menu == 0){
                                menu = 1;
                            }else if(menu == 1){
                                charger(jeu, 2);
                            }else{
                                charger(jeu, 4);
                            }
                        }
                        if(y == 5){
                            if(menu == 0){
                                quit = 1;
                                detruireJeu(jeu);
                                free(jeu);
                            }else{
                                menu = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

int boucleMenu2(Jeu* jeu){
    SDL_Event e;
    int pause=1;
    int quit = 0;
    int menu = 3;
    int x,y;
    while(pause){
        while( SDL_PollEvent(&e) != 0 ){
            afficheMenu(jeu->aff, menu);
            if( e.type == SDL_QUIT ){
                quit = 1;
                pause = 0;
            }
            if(e.type == SDL_MOUSEBUTTONDOWN){
                if(e.button.button == SDL_BUTTON_LEFT){
                    x = e.button.x;
                    y = e.button.y;
                    x /= TILE_TAILLE;
                    y /= TILE_TAILLE;
                    if(x > (((SCREEN_W-3*TILE_TAILLE)/2)/TILE_TAILLE) && x < (((SCREEN_W-3*TILE_TAILLE)/2)/TILE_TAILLE)+3){
                        if( y == 3){
                            if(menu == 3){
                                menu = 4;
                            }else{
                                 sauvegarder(jeu, 1);
                            }

                        }
                        if(y == 4){
                            if(menu == 3)
                                pause = 0;
                            else{
                                sauvegarder(jeu, 2);
                            }

                        }
                        if(y == 5){
                            if(menu == 3){
                                quit = 1;
                                pause = 0;
                            }else{
                                menu = 3;
                            }
                        }
                    }
                }
            }
        }
    }
    return quit;
}

