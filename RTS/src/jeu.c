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

void commencerPartie(Jeu* j, int raceJ, char* cheminCarte, char* nomJ){
    int i;
    Joueur* tabJ;
    Terrain* ter;
    TabDyn* tabUnite;
    TabDyn* tabBat;
    BatBase* tabBatConstr;
    UniteBase* tabUniteForm;
    char imageCarte[128];
    char colliCarte[128];
    setNbJoueur(j,1);
    tabUnite = (TabDyn*)malloc(sizeof(TabDyn));
    tabBat = (TabDyn*)malloc(sizeof(TabDyn));
    tabJ = (Joueur*) malloc(sizeof(Joueur)*getNbJoueur(j));
    ter = (Terrain*) malloc(sizeof(Terrain));
    setVueJoueur(j, 0);
    for(i = 0;i < getNbJoueur(j); i++){
        initJoueur(&tabJ[i],i,nomJ, raceJ, 0,0);
    }
    strcat(imageCarte, cheminCarte);
    strcat(imageCarte,"image.png");
    strcat(colliCarte,cheminCarte);
    strcat(colliCarte,"carte.txt");
    j->tableauJoueur = tabJ;
    initTerrain(ter,colliCarte,imageCarte);
    setCarteJeu(j,ter);
    tabBatConstr = chargementBatBase();
    tabUniteForm = chargementUniteForm();
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
