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
      initUnite(u, getUniteFormable(j,0));
      printf("%d \n",getTileUnite(getTypeUnite(u)));
    /*  ajouterTabDyn(j->tableauBat, (uintptr_t) b);*/
      ajouterTabDyn(j->tableauUnite, (uintptr_t) u);
      setPosX(u,5);
      setPosY(u,0);
      setPosCibleX(u,5);
      setPosCibleY(u,0);
      j->carte->tabCase[5].idContenu = 1;
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
            if(e.type == SDL_KEYDOWN){
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
                        if(xClick > SCREEN_W - 3*TILE_TAILLE && xClick < SCREEN_W - 2*TILE_TAILLE)
                            ajouterFileBat(getBat(j,-getIdSel(j)-1),j,0);
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
