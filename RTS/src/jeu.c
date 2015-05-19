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
    detruireTerrain(j->carte);
    free(j->carte);
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
    return (Unite*) j->tableauUnite->tab[uNb];
}

Batiment* getBat(const Jeu* j, int bNb){
    return (Batiment*) j->tableauBat->tab[bNb];
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


void ajouterBat(Jeu* j, Batiment* bat){
    ajouterTabDyn(j->tableauBat, (uintptr_t)bat);
}

void setIdSel(Jeu* j,int id){
    j->idSel = id;
}

TabDyn* getTabUnite(Jeu* j){
     return j->tableauUnite;
}

TabDyn* getTabBat(Jeu* j){
     return j->tableauBat;
}

/* *************************************************************--FCT--***************************************************************************** */

void boucleJeu(Jeu* j){
      int quit = 0;
      int x,y;
      int xClick,yClick;
      SDL_Event e;
      Unite* u;
      Batiment* b;
      b = (Batiment*) malloc(sizeof(Batiment));
      u = (Unite*) malloc(sizeof(Unite));
     /* initBatiment(b,0,getBatConstructible(j,0),100,0);
      setPosXBat(b,6);
      setPosYBat(b,0);*/
      initUnite(u, getUniteFormable(j,0), getVueJoueur(j));
      printf("%d \n",getTileUnite(getTypeUnite(u)));
    /*  ajouterTabDyn(j->tableauBat, (uintptr_t) b);*/
      ajouterTabDyn(j->tableauUnite, (uintptr_t) u);
      setPosX(u,7);
      setPosY(u,1);
      setPosCibleX(u,7);
      setPosCibleY(u,1);
      j->carte->tabCase[7+getTailleX(j->carte)].idContenu = 1;
   /*   j->carte->tabCase[6].idContenu = -1;
      j->carte->tabCase[7].idContenu = -1;
      j->carte->tabCase[6+(j->carte->tailleX)].idContenu = -1;
      j->carte->tabCase[7+(j->carte->tailleX)].idContenu = -1;*/
      while( !quit ){
           /* verifierTimerBat(getBat(j,0),j);*/
            deplacementUnite(getUnite(j,0),j->carte);
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
                    xClick = xClick/TILE_TAILLE + getCameraX(getJoueur(j,getVueJoueur(j)));
                    yClick = yClick/TILE_TAILLE + getCameraY(getJoueur(j,getVueJoueur(j)));
                    printf("x: %d y: %d ",xClick,yClick);
                    if(e.button.button == SDL_BUTTON_LEFT){
                        setIdSel(j,getContenu(getCase(getCarteJeu(j),xClick,yClick)));
                         printf("id: %d \n",getContenu(getCase(getCarteJeu(j),xClick,yClick)));
                    }
                    else if(e.button.button == SDL_BUTTON_RIGHT){
                        if(getIdSel(j) < 0){

                        }
                        else if(getIdSel(j) > 0){
                            u = getUnite(j,getIdSel(j)-1);
                            setPosCibleX(u, xClick);
                            setPosCibleY(u, yClick);
                            deplacementUnite(u,j->carte);
                        }
                    }
                }
               else{
                    if(e.button.button == SDL_BUTTON_LEFT){
                        if(xClick > SCREEN_W - 3*TILE_TAILLE && xClick < SCREEN_H){
                            if(getIdSel(j) < 0){
                                b = getBat(j, -getIdSel(j)-1);
                                xClick -= (SCREEN_W - 3*TILE_TAILLE);
                                xClick = xClick % TILE_TAILLE;
                                yClick -= (SCREEN_H-HUD_H);
                                yClick = yClick % TILE_TAILLE;
                                if((yClick*3+xClick) < getNbUniteFormable(getTypeBat(bat)))){
                                    ajouterFileBat(b,j,yClick*3+xClick);
                                }
                            }
                        }
                        else if(xClick > 0 && xClick < 3*TILE_TAILLE){
                            xClick = xClick % TILE_TAILLE;
                            yClick = yClick % TILE_TAILLE;
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
            if(((j->tableauJoueur[j->vueJoueur].cameraY) + 1) <= j->carte->tailleY - SCREEN_H/TILE_TAILLE)
                (j->tableauJoueur[j->vueJoueur].cameraY)++;
        }
        if( y < 20 ){
            if(((j->tableauJoueur[j->vueJoueur].cameraY) - 1) >= 0)
                (j->tableauJoueur[j->vueJoueur].cameraY)--;


        }
        affiche(j->aff);
    }
} */

void afficheJeu(Jeu* j){

}

void checkJeu(Jeu* jeu){

     int taille, i, egale, enConstru;
     sCase* place;
     Unite* soldat;
     Batiment* bat;

     /* Activité des Unités */

     taille = getUtiliseTabDyn(getTabUnite(jeu)); /*faire fonction TabDyn et tabUnite */
     for(i=0;i<taille;i++)
     {
          soldat = getUnite(jeu,i);
          if (getVieCouranteUnite(soldat) == 0)
          {
              /* detruireUnite(soldat); */
          }
          else
          {
               egale = memeCase(getPosX(soldat), getPosY(soldat), getPosCibleX(soldat), getPosCibleY(soldat));

               if(getOuvrier(getTypeUnite(soldat)) == 1) /* est un ouvrier */
               {
                    /* particulier*/
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
                         if(getContenu(place)) /* géré ennemi */
                         {
                              /* attaque */
                         }
                         else /* cas securitaire ne devrai pas arriver */
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
     for(i=0;i<taille;i++)
     {
          bat = getBat(jeu, i);
          if (getVieCouranteBat(bat)== 0)
          {
               /*detruireBatiment(bat*/
          }
          else
          {
               enConstru = getEnConstruction(bat);
               if(enConstru == 1)
               {
                    /* avancer construction */
               }
               else
               {
                    if(getPremier(getTabAttente(bat)))
                    {
                         /*avancer la file */
                    }
               }
          }
     }

}

void afficheHUD(Jeu* j){

}
