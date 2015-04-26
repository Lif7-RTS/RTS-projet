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


void commencerPartie(Jeu* j, int raceJ, char* cheminCarte, char* nomJ){
    int i;
    Joueur* tabJ;
    Terrain* ter;
    TabDyn* tabUnite;
    TabDyn* tabBat;
    BatBase* tabBatConstr;
    UniteBase* tabUniteForm;
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
    /* tabBatConstr = chargementBatBase();
    tabUniteForm = chargementUniteForm(); */
    initAffichage(j->aff,j,j->carte);
    boucleJeu(j);
}

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


void boucleJeu(Jeu* j){
      int quit = 0;
      int x,y;
      int* v;
      v = (int*) malloc(sizeof(int));
      SDL_Event e;
      UniteBase* ub;
      Unite* u;
      BatBase* bb;
      Batiment* b;
      b = (Batiment*) malloc(sizeof(Batiment));
      bb = (BatBase*) malloc(sizeof(BatBase));
      u = (Unite*) malloc(sizeof(Unite));
      ub = (UniteBase*) malloc(sizeof(UniteBase));
      initBatBase(bb,"lel", 0, 4,100,1,20,2,2,v);
      initUniteBase(ub,10,10,"lol", 0, 1, 10, 10, 3, 5);
      setTypeBat(b, bb);
      setPosXBat(b,6);
      setPosYBat(b,0);
      setTypeUnite(u,ub);
      ajouterTabDyn(j->tableauBat, (uintptr_t) b);
      ajouterTabDyn(j->tableauUnite, (uintptr_t) u);
      j->carte->tabCase[5].idContenu = 1;
      j->carte->tabCase[6].idContenu = -1;
      j->carte->tabCase[7].idContenu = -1;
      j->carte->tabCase[6+(j->carte->tailleX)].idContenu = -1;
      j->carte->tabCase[7+(j->carte->tailleX)].idContenu = -1;
      while( !quit ){
            SDL_PumpEvents();
            SDL_GetMouseState(&x,&y);
        while( SDL_PollEvent(&e) != 0 ){
             if( e.type == SDL_QUIT ){
                quit = 1;
            }
            if(e.type == SDL_KEYDOWN)
            {
               if(e.key.keysym.sym == SDLK_RIGHT)
                    (j->tableauJoueur[j->vueJoueur].cameraX)++;
               if(e.key.keysym.sym == SDLK_DOWN)
                    (j->tableauJoueur[j->vueJoueur].cameraY)++;
            }

        }
        if( x >= SCREEN_W-TILE_TAILLE ){
            if(((j->tableauJoueur[j->vueJoueur].cameraX) + 1) <= j->carte->tailleX - SCREEN_W/TILE_TAILLE)
                (j->tableauJoueur[j->vueJoueur].cameraX)++;
        }
        if( x < TILE_TAILLE ){
            if(((j->tableauJoueur[j->vueJoueur].cameraX) - 1) >= 0)
                (j->tableauJoueur[j->vueJoueur].cameraX)--;
        }
        if( y >= SCREEN_H-TILE_TAILLE ){
            if(((j->tableauJoueur[j->vueJoueur].cameraY) + 1) <= j->carte->tailleY - SCREEN_H/TILE_TAILLE)
                (j->tableauJoueur[j->vueJoueur].cameraY)++;
        }
        if( y < TILE_TAILLE ){
            if(((j->tableauJoueur[j->vueJoueur].cameraY) - 1) >= 0)
                (j->tableauJoueur[j->vueJoueur].cameraY)--;


        }
        affiche(j->aff);
    }
}

void afficheJeu(Jeu* j){

}

void afficheHUD(Jeu* j){

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
