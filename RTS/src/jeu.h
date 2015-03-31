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
#include "uniteBase.h"
#include "unite.h"
#include "case.h"
#include "terrain.h"
#include "batimentBase.h"
#include "batiment.h"
#include "tabUnite.h"
#include "tabBat.h"

#ifndef
#define _JEU


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
    TabUnite* tableauUnite;/*!< tableau de pointeur sur toute les unites existante dans la partie*/
    TabBat* tableauBat;/*!< Tableau de pointeur sur tout les batiments construits*/
    BatBase* tabBatConstructible;/*!< Tableau de pointeurs sur tous les batiments constructibles */
    Jeu* tabUniteFormable;/*!< Tableau de pointeurs sur toutes les unites formables*/
    int vuejoueur;/*!< joueur que la camera suit */
};

typedef struct SJeu  Jeu;
/**
 * \fn int getNbJoueur ( jeu*  j)
 * \brief accesseur NbJoueur
 * \param j pointeur sur un Jeu
 * \return NbJoueur
 */
int getNbJoueur( jeu*  j);

 /**
 * \fn int getVueJoueur ( jeu* j)
 * \brief accesseur vueJoueur
 * \param j pointeur sur un Jeu
 * \return vueJoueur
 */
 int getVueJoueur( jeu*  j);

 /**
 * \fn Joueur* getJoueur ( jeu* j, int jNb)
 * \brief accesseur tableauJoueur[jNb]
 * \param j pointeur sur un Jeu
 * \return tableauJoueur[jNb]
 */
 Joueur* getJoueur(jeu*  j,int jNb);

 /**
 * \fn Terrain*  getCarte ( jeu* j)
 * \brief accesseur carte
 * \param j pointeur sur un Jeu
 * \return pointeur sur carte
 */
Terrain* getCarte( jeu*  j);

  /**
 * \fn Unite* getUnite ( jeu* j, int uNb)
 * \brief accesseur tableauUnite
 * \param j pointeur sur un Jeu
 * \return pointeur sur tableauUnite[uNb]
 */
Unite* getUnite( jeu*  j, int uNb);

  /**
 * \fn Batiment* getBat(jeu*  j, int bNb)
 * \brief accesseur tableauBatiment
 * \param j pointeur sur un Jeu
 * \return pointeur sur tableauBatiment[bNb]
 */
Batiment* getBat(jeu*  j, int bNb);

  /**
 * \fn  UniteBase* getUniteFormable(jeu*  j, int uNb)
 * \brief accesseur TabUniteFormable
 * \param j pointeur sur une  jeu
 * \return pointeur sur tabUniteFormable[uNb]
 */
 UniteBase* getUniteFormable(jeu*  j, int uNb);

/**
 * \fn BatBase* getBatConstructible(jeu*  j,int bNb)
 * \brief accesseur tabBatConstructible
 * \param j pointeur sur une  jeu
 * \return pointeur sur tabBatConstructible[bNb]
 */
BatBase* getBatConstructible(jeu*  j,int bNb);


 /**
 * \fn void setNbJoueur ( jeu* j,int nb)
 * \brief mutateur NbJoueur
 *
 * \param[in, out] j pointeur sur  jeu
 * \param[in] nb nombre de joueur
 */
 void setNbJoueur( jeu*  j, int nb);

  /**
 * \fn void setAttaque ( jeu* j,int atq)
 * \brief mutateur vueJoueur
 *
 * \param[in, out] j pointeur sur  jeu
 * \param[in] jNb id d'un joueur
 */
 void setVueJoueur( jeu*  j, int jNb);

 /**
 * \fn  void ajouterJoueur( jeu*  j, Joueur* pJoueur)
 * \brief mutateur tabJoueur
 *
 * \param[in, out] j pointeur sur  jeu
 * \param[in,out] pJoueur pointeur sur joueur a ajouter dans tabJoueur
 */
 void ajouterJoueur( jeu*  j, Joueur* pJoueur);

 /**
 * \fn  void setCarte( jeu*  j, Terrain* c)
 * \brief mutateur carte
 * \param[in, out] j pointeur sur  jeu
 * \param[in] c pointeur sur la nouvelle carte
 */
 void setCarte( jeu*  j, Terrain* c);

/**
 * \fn  void ajouterUnite( jeu*  j, Unite* unit)
 * \brief mutateur tabUnite
 * \param[in, out] j pointeur sur  jeu
 * \param[in] unit pointeur sur une nouvelle unite
 */
 void ajouterUnite( jeu*  j, Unite* unit);

  /**
 * \fn  void ajouterBat(jeu*  j, Batiment* bat)
 * \brief mutateur tabBatiment
 * \param[in, out] j pointeur sur  jeu
 * \param[in] bat pointeur sur un nouveau batiment
 */
 void ajouterBat( jeu*  j, Batiment* bat);

  /**
 * \fn  void ajouterUniteFormable( jeu*  j, UniteBase* unit)
 * \brief mutateur tabUniteFormable
 * \param[in, out] j pointeur sur  jeu
 * \param[in] unit pointeur sur UniteBase a ajouter dans tabUniteFormable
 */
 void ajouterUniteFormable( jeu*  j, UniteBase* unit);

  /**
 * \fn  void ajouterBatConstructible( jeu*  j, BatBase* bat)
 * \brief mutateur tabBatConstructible
 * \param[in, out] j pointeur sur  jeu
 * \param[in] bat pointeur sur BatBase* a ajouter dans tabBatConstructible
 */
 void ajouterBatConstructible( jeu*  j, BatBase* bat);

/** \fn void commencerPartie(jeu* j,int raceJ, char* cheminCarte)
 * \brief fonction d'initialisation de jeu, cree jeu puis lance la boucle de jeu
 * \param [in,out] j pointeur sur jeu
 * \param [in] raceJ race du joueur 1 ( controle par l'utilisateur)
 * \param [in, out] cheminCarte chemin ( relatif ou absolu) vers la carte sur la quel la partie va etre lance
 *
 */
 void commencerPartie(Jeu* j,int raceJ, char* cheminCarte);

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

 /** \fn void boucleHUD(Jeu* j)
 * \brief function d'affichage de l'interface
 * \param j pointeur sur jeu
 */
 void boucleJeu(Jeu* j);

 /** \fn void detruireJeu(Jeu* j)
 * \brief function de destruction du module jeu
 * \param j pointeur sur jeu
 */
 void detruireJeu(Jeu* j);



#endif
