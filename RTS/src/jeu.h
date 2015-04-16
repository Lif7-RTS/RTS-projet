/**
 * \file  jeu.h
 * \brief module  jeu
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module du coeur du  jeu (boucle de  jeu/ affichage/gestion evenement)
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef _JEU
#define _JEU
#include "uniteBase.h"
#include "unite.h"
#include "case.h"
#include "terrain.h"
#include "batimentBase.h"
#include "batiment.h"
#include "joueur.h"
#include "tabDyn.h"


/**
 * \struct SJeu
 * \brief Objet Jeu
 *
 * SJeu objet representant une partie en cours
 */
struct SJeu{
    int nbJoueur;/*!< nombre de joueur dans la partie */
    Joueur* tableauJoueur;/*!< tableau contenant des pointeurs vers tout les joueurs de la partie*/
    Terrain* carte;/*!< pointeur sur la carte de la partie*/
    TabDyn* tableauUnite;/*!< tableau de pointeur sur toute les unites existante dans la partie*/
    TabDyn* tableauBat;/*!< Tableau de pointeur sur tout les batiments construits*/
    BatBase* tabBatConstructible;/*!< Tableau de pointeurs sur tous les batiments constructibles */
    UniteBase* tabUniteFormable;/*!< Tableau de pointeurs sur toutes les unites formables*/
    int vueJoueur;/*!< joueur que la camera suit */
};

typedef struct SJeu Jeu;
/**
 * \fn int getNbJoueur ( jeu*  j)
 * \brief accesseur NbJoueur
 * \param j pointeur sur un Jeu
 * \return NbJoueur
 */
int getNbJoueur(const Jeu*  j);

 /**
 * \fn int getVueJoueur ( jeu* j)
 * \brief accesseur vueJoueur
 * \param j pointeur sur un Jeu
 * \return vueJoueur
 */
 int getVueJoueur(const Jeu*  j);

 /**
 * \fn Joueur* getJoueur ( jeu* j, int jNb)
 * \brief accesseur tableauJoueur[jNb]
 * \param j pointeur sur un Jeu
 * \return tableauJoueur[jNb]
 */
 Joueur* getJoueur(const Jeu*  j,int jNb);

 /**
 * \fn Terrain*  getCarte ( jeu* j)
 * \brief accesseur carte
 * \param j pointeur sur un Jeu
 * \return pointeur sur carte
 */
Terrain* getCarte(const Jeu*  j);

  /**
 * \fn Unite* getUnite ( jeu* j, int uNb)
 * \brief accesseur tableauUnite
 * \param j pointeur sur un Jeu
 * \return pointeur sur tableauUnite[uNb]
 */
Unite* getUnite(const Jeu*  j, int uNb);

  /**
 * \fn Batiment* getBat(jeu*  j, int bNb)
 * \brief accesseur tableauBatiment
 * \param j pointeur sur un Jeu
 * \return pointeur sur tableauBatiment[bNb]
 */
Batiment* getBat(const Jeu*  j, int bNb);

  /**
 * \fn  UniteBase* getUniteFormable(jeu*  j, int uNb)
 * \brief accesseur TabUniteFormable
 * \param j pointeur sur une  jeu
 * \return pointeur sur tabUniteFormable[uNb]
 */
 UniteBase* getUniteFormable(const Jeu*  j, int uNb);

/**
 * \fn BatBase* getBatConstructible(jeu*  j,int bNb)
 * \brief accesseur tabBatConstructible
 * \param j pointeur sur une  jeu
 * \return pointeur sur tabBatConstructible[bNb]
 */
BatBase* getBatConstructible(const Jeu*  j,int bNb);


 /**
 * \fn void setNbJoueur ( jeu* j,int nb)
 * \brief mutateur NbJoueur
 *
 * \param[in, out] j pointeur sur  jeu
 * \param[in] nb nombre de joueur
 */
 void setNbJoueur( Jeu*  j, int nb);

  /**
 * \fn void setAttaque ( jeu* j,int atq)
 * \brief mutateur vueJoueur
 *
 * \param[in, out] j pointeur sur  jeu
 * \param[in] jNb id d'un joueur
 */
 void setVueJoueur( Jeu*  j, int jNb);

 /**
 * \fn  void setCarteJeu( jeu*  j, Terrain* c)
 * \brief mutateur carte
 * \param[in, out] j pointeur sur  jeu
 * \param[in] c pointeur sur la nouvelle carte
 */
 void setCarteJeu( Jeu*  j, Terrain* c);

/**
 * \fn  void ajouterUnite( jeu*  j, Unite* unit)
 * \brief mutateur tabUnite
 * \param[in, out] j pointeur sur  jeu
 * \param[in] unit pointeur sur une nouvelle unite
 */
 void ajouterUnite( Jeu*  j, Unite* unit);

  /**
 * \fn  void ajouterBat(jeu*  j, Batiment* bat)
 * \brief mutateur tabBatiment
 * \param[in, out] j pointeur sur  jeu
 * \param[in] bat pointeur sur un nouveau batiment
 */
 void ajouterBat( Jeu*  j, Batiment* bat);

/** \fn void commencerPartie(Jeu* j, int raceJ, char* cheminCarte, char* nomJ)
 * \brief fonction d'initialisation de jeu, cree jeu puis lance la boucle de jeu
 * \param [in,out] j pointeur sur jeu
 * \param [in] raceJ race du joueur 1 ( controle par l'utilisateur)
 * \param [in, out] cheminCarte chemin ( relatif ou absolu) vers la carte sur la quel la partie va etre lance
 *
 */
void commencerPartie(Jeu* j, int raceJ, char* cheminCarte, char* nomJ);

/** \fn void boucleJeu(Jeu* j)
 * \brief function de boucle de jeu
 * \param j pointeur sur jeu
 */
 void boucleJeu(Jeu* j);

 /** \fn void afficheJeu(Jeu* j)
 * \brief function d'affichage du jeu
 * \param j pointeur sur jeu
 */
 void afficheJeu(Jeu* j);

 /** \fn void afficheHUD(Jeu* j)
 * \brief function d'affichage de l'interface
 * \param j pointeur sur jeu
 */
 void afficheHUD(Jeu* j);

 /** \fn void detruireJeu(Jeu* j)
 * \brief function de destruction du module jeu
 * \param j pointeur sur jeu
 */
 void detruireJeu(Jeu* j);



#endif
