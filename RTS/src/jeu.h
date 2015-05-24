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
#include "define.h"
#include "uniteBase.h"
#include "unite.h"
#include "case.h"
#include "terrain.h"
#include "batimentBase.h"
#include "joueur.h"
#include "tabDyn.h"

#ifndef _JEU
#define _JEU

#include "batiment.h"

typedef struct SAffichage Affichage;
/**
 * \struct SJeu
 * \brief Objet Jeu
 *
 * SJeu objet representant une partie en cours
 */

typedef struct SJeu Jeu;
struct SJeu{
    Affichage* aff;
    int nbJoueur;/*!< nombre de joueur dans la partie */
    Joueur* tableauJoueur;/*!< tableau contenant des pointeurs vers tout les joueurs de la partie*/
    Terrain* carte;/*!< pointeur sur la carte de la partie*/
    TabDyn* tableauUnite;/*!< tableau de pointeur sur toute les unites existante dans la partie*/
    TabDyn* tableauBat;/*!< Tableau de pointeur sur tout les batiments construits*/
    BatBase* tabBatConstructible;/*!< Tableau de pointeurs sur tous les batiments constructibles */
    UniteBase* tabUniteFormable;/*!< Tableau de pointeurs sur toutes les unites formables*/
    int vueJoueur;/*!< joueur que la camera suit */
    int idSel; /*!< id de l'unite selectionnee par le joueur[vueJoueur] */
};


/* *************************************************************--Init--***************************************************************************** */


/** \fn void commencerPartie(Jeu* j, int raceJ, char* cheminCarte, char* nomJ)
 * \brief fonction d'initialisation de jeu, cree jeu puis lance la boucle de jeu
 * \param [in,out] j pointeur sur jeu
 * \param [in] raceJ race du joueur 1 ( controle par l'utilisateur)
 * \param [in, out] cheminCarte chemin ( relatif ou absolu) vers la carte sur la quel la partie va etre lance
 *
 */
void commencerPartie(Jeu* j, int raceJ, char* cheminCarte, char* nomJ);

 /** \fn void detruireJeu(Jeu* j)
 * \brief function de destruction du module jeu
 * \param j pointeur sur jeu
 */
 void detruireJeu(Jeu* j);

/* *************************************************************--GET--***************************************************************************** */

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
 * \fn Terrain*  getCarteJeu( jeu* j)
 * \brief accesseur carte
 * \param j pointeur sur un Jeu
 * \return pointeur sur carte
 */
Terrain* getCarteJeu(const Jeu*  j);

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
 * \fn int getIdSel( jeu*  j)
 * \brief accesseur IdSel
 * \param j pointeur sur un Jeu
 * \return idSel
 */
int getIdSel(const Jeu*  j);

/**
 * \fn TabDyn* getTabUnite(Jeu* j)
 * \brief accesseur sur TabUnite
 *
 * \param j pointeur sur un Jeu
 * \return une tableau dynamique
 */
TabDyn* getTabUnite(Jeu* j);

/**
 * \fn TabDyn* getTabBat(Jeu* j)
 * \brief accesseur sur TabBat
 *
 * \param j pointeur sur un Jeu
 * \return une tableau dynamique
 */
TabDyn* getTabBat(Jeu* j);

/**
 * \fn int getIdJoueurCase(const jeu* jeu,const sCase* place)
 * \brief renvoi l'id du joueur a qui apartien le contenu de la case (-1 si aucun joueur ne possède la case)
 *
 * \param[in, ou] jjeu un poiteur sur Jeu
 * \param[in, ou] place un pointeur sur une case
 * \return un identifiant unique de joueur.
 */
int getIdJoueurCase(const Jeu* jeu, const sCase* place);

/* *************************************************************--SET--***************************************************************************** */

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
 * \fn void setIdSel( jeu*  j,int id)
 * \brief mutateur IdSel
 * \param[in,out] j pointeur sur un Jeu
 * \param  id nouvel id selectionnee
 */
 void setIdSel(Jeu*  j, int id);

/**
 * \fn  void ajouterUnite( jeu*  j, Unite* unit)
 * \brief mutateur tabUnite
 * \param[in, out] j pointeur sur  jeu
 * \param[in] unit pointeur sur une nouvelle unite
 */
 void ajouterUnite( Jeu*  j, Unite* unit);

/**
 * \fn Unite* getUnite ( jeu* j, int uNb)
 * \brief mutateur tableauUnite
 * \param[in, ou] j pointeur sur un Jeu
 * \param[in] placement de l'unite dans le tableau d'unite.
 * \param[in, out] pointeur sur une unite.
*/
void setUnite(const Jeu*  j, int uNb, Unite* unit);

/**
 * \fn Unite* getUnite ( jeu* j, int uNb)
 * \brief mutateur tableauUnite
 * \param[in, ou] j pointeur sur un Jeu
 * \param[in] bNb index du placement de l'unite dans le tableau de batiment.
 * \param[in, out] pointeur sur un batiment.
*/
void setBat(const Jeu*  j, int bNb, Batiment* bat);

  /**
 * \fn  void ajouterBat(jeu*  j, Batiment* bat)
 * \brief mutateur tabBatiment
 * \param[in, out] j pointeur sur  jeu
 * \param[in] bat pointeur sur un nouveau batiment
 */
 void ajouterBat( Jeu*  j, Batiment* bat);

/* *************************************************************--FCT--***************************************************************************** */

/**
* \fn void boucleJeu(Jeu* j)
* \brief function de boucle de jeu
*
* \param[in, out] j pointeur sur jeu
*/
 void boucleJeu(Jeu* j);

/**
* \fn void checkJeu(Jeu* jeu)
* \brief verifie et réalise toute les action a faire sur/par les batiment et les Unites
*
* \param[in, out] j pointeur sur jeu
*/
void checkJeu(Jeu* jeu);

/**
* \fn int supprimerUnite(Jeu* jeu, int index)
* \brief supprime l'unite d'id == index du tableau des unites
*
* \param[in, out] j pointeur sur jeu
* \param index position dans le tableau tabUnite de l'unite a supprimer.
*/
int supprimerUnite(Jeu* jeu, int index);

/**
* \fn int supprimerBat(Jeu* jeu, int index)
* \brief supprime le bat d'id == -index du tableau des bat
*
* \param[in, out] j pointeur sur jeu
* \param index position dans le tableau tableauBat du batiment a supprimer.
*/
int supprimerBat(Jeu* jeu, int index);

/**
* \fn void sauvegarder(Jeu* jeu, unsigned char numSauvegarde))
* \brief sauvegarde l'ensemble du jeu à l'emplacement choisi
*
* \params[in, out] j pointeur sur jeu
* \param[in] un entier compris entre 1 et 3 correspondant à l'emplacement de la sauvegarde a faire
*/
void sauvegarder(Jeu* jeu, unsigned char numSauvegarde);

/**
* \fn void sauvegarder(Jeu* jeu, unsigned char numSauvegarde))
* \brief charge uen partie du jeu sauvegardée à l'emplacement choisi
*
* \params[in, out] j pointeur sur jeu
* \param[in] un entier compris entre 1 et 3 correspondant à l'emplacement de la sauvegarde a faire
*/
void charger(Jeu* jeu, unsigned char numSauvegarde);

void boucleMenu(Jeu* jeu);

int boucleMenu2(Jeu* jeu);

#endif
