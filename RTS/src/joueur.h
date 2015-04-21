/**
* \file joueur.h
* \brief structure joueur
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 31/03/2015
* Structure representant un joueur.
*/

#include <stdio.h>
#include <stdlib.h>
#include "unite.h"
#include "batiment.h"
#include "tabDyn.h"
#ifndef _JOUEUR
#define _JOUEUR
/* #include "race.h" */

struct SJoueur{
     int idJoueur; /*!< identifiant unique représentant un joueur */
     int pierre; /*!< quantite de pierre que possède le joueur */
     int mithril;  /*!< quantite de mithril que possède le joueur */
     char* nomJoueur; /*!< chaine de caractère contenant le nom d'un joueur */
     int idRace; /*!< un identifiant correspondant a une des races */
     int nourritureMax; /*!< la quantite maximum de nourriture que peu stocker un joueur */
     int nourritureCourante; /*!< la quantite actuel de nourriture dans le grenier du joueur */
     int cameraX; /*!< la position en coordonée x de la camera du joueur */
     int cameraY; /*!< la position en coordonée y de la camera du joueur */
     TabDyn* tabBatiment; /*!< un tableau contenant l'ensemble des batiments d'un joueur */
     TabDyn* tabTroupe; /*!< un tableau contenant l'ensemble des unites d'un joueur */
};
typedef struct SJoueur Joueur;

/* ***********************************************************--INIT--*************************************************************************** */

/**
* \fn void initJoueur (Joueur* joue, int idJoueur, char* nomJouer, int idRace, int cameraX, int cameraY)
* \brief initialise une structure joueur
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] idJoueur est un identifiant unique representant un joueur
* \param[in, out] nomJoueur ets le nom choisi par le joueur
* \param[in] idRace esr un identifiant unique representant la race du joueur
* \param[in] camX est la coordonee X de la camera du joueur
* \param[in] camY est la coordonee Y de la camera du joueur
*/
void initJoueur (Joueur* joue, int idJoueur,char* nomJouer, int idRace, int cameraX, int cameraY);
/**
* \fn void detruireJoueur(Joueur* joue)
* \brief detruit la structure joueur
*
* \param[in, out] joue est un pointeur sur Joueur
*/
void detruireJoueur(Joueur* joue);

/* *************************************************************--GET--***************************************************************************** */

/**
* \fn int getIdJoueur (const Joueur* joueur)
* \brief accesseur idJoueur
*
* \param[in, out] joue est un pointeur sur Joueur
* \return idJoueur est un identifiant unique representant un joueur.
*/
int getIdJoueur (const Joueur* joue);

/**
* \fn int getPierre (const Joueur* joue)
* \brief accesseur pierre
*
* \param[in, out] joue est un pointeur sur Joueur
* \return pierre est une quantite de pierre que possède le joueur.
*/
int getPierreJoueur(const Joueur* joue);

/**
* \fn int getMithril (const Joueur* joue)
* \brief accesseur mithril
*
* \param[in, out] joue est un pointeur sur Joueur
* \return mithril est une quantite de mithril que possède le joueur.
*/
int getMithrilJoueur(const Joueur* joue);

/**
* \fn char* getNomJoueur (const Joueur* joue)
* \brief accesseur nomJoueur
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in, out] nomJoueur est le nom choisi par le joueur.*/
char* getNomJoueur (const Joueur* joue);

/**
* \fn int getIdRace (const Joueur* joue)
* \brief accesseur idRace
*
* \param[in, out] joue est un pointeur sur Joueur
* \return idRace esr un identifiant unique representant la rcae du joueur.*/
int getIdRace (const Joueur* joue);

/**
* \fn int getNourritureMax (const Joueur* joue)
* \brief accesseur nourritureMax
*
* \param[in, out] joue est un pointeur sur Joueur
* \return nourMax est la quantite maximum de nourriture stockable par le joueur.*/
int getNourritureMax (const Joueur* joue);

/**
* \fn int getNourritureCourante (const Joueur* joue)
* \brief accesseur nourritureCourrante
*
* \param[in, out] joue est un pointeur sur Joueur
* \return nourActu est la quantite actuelle de nourriture stockee par le joueur.*/
int getNourritureCourante (const Joueur* joue);

/**
* \fn int getCameraX (const Joueur* joue)
* \brief accesseur cameraX
*
* \param[in, out] joue est un pointeur sur Joueur
* \return camX est la coordonee X de la camera du joueur.*/
int getCameraX (const Joueur* joue);

/**
* \fn int getCameraY (const Joueur* joue)
* \brief accesseur cameraY
*
* \param[in, out] joue est un pointeur sur Joueur
* \return camX est la coordonee Y de la camera du joueur.*/
int getCameraY (const Joueur* joue);

/**
* \fn Unite* choisiUnite (const Joueur* joue, int numLigne)
* \brief renvoi l'unite de la ligne choisi.
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] numLigne est un entier corespondant a une ligne de tabUnite
* \return un poiteur sur une unite.
*/
Unite* choisiUnite (const Joueur* joue, int numLigne);

/**
* \fn Batiment* choisiBatiment (const Joueur* joue, int numLigne)
* \brief renvoi le batiment de la ligne choisi.
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] numLigne est un entier corespondant a une ligne de tabBatiment
* \return un poiteur sur un batiment.
*/
Batiment* choisiBatiment (const Joueur* joue, int numLigne);

/* *************************************************************--SET--***************************************************************************** */

/**
* \fn void setIdJoueur (Joueur* joueur, int idJoueur)
* \brief mutateur idJoueur
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] idJoueur est un identifiant unique representant un joueur.
*/
void setIdJoueur (Joueur* joue, int idJoueur);

/**
* \fn void setPierre (Joueur* joue, int pierre)
* \brief mutateur pierre
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] pierre est une quantite de pierre que possède le joueur.
*/
void setPierreJoueur(Joueur* joue, int pierre);

/**
* \fn void setMithril (Joueur* joue, int mithril)
* \brief mutateur mithril
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] mithril est une quantite de mithril que possède le joueur.
*/
void setMithrilJoueur(Joueur* joue, int mithril);

/**
* \fn void setNomJoueur (Joueur* joue, const char* nomJoueur)
* \brief mutateur nomJoueur
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in, out] nomJoueur ets le nom choisi par le joueur.*/
void setNomJoueur (Joueur* joue, char* nomJoueur);

/**
* \fn void setIdRace (Joueur* joue, int idRace)
* \brief mutateur idRace
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] idRace esr un identifiant unique representant la race du joueur.*/
void setIdRace (Joueur* joue, int idRace);

/**
* \fn void setNourritureMax (Joueur* joue, int nourMax)
* \brief mutateur nourritureMax
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] nourMax est la quantite maximum de nourriture stockable par le joueur.*/
void setNourritureMax (Joueur* joue, int nourMax);

/**
* \fn void setNourritureCourante (Joueur* joue, int nourActu)
* \brief mutateur nourritureCourrante
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] nourActu est la quantite actuelle de nourriture stockee par le joueur.*/
void setNourritureCourante (Joueur* joue, int nourActu);

/**
* \fn void setCameraX (Joueur* joue, int camX)
* \brief mutateur cameraX
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] camX est la coordonee X de la camera du joueur.*/
void setCameraX (Joueur* joue, int camX);

/**
* \fn void setCameraY (Joueur* joue, int camY)
* \brief mutateur cameraY
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in] camY est la coordonee Y de la camera du joueur.*/
void setCameraY (Joueur* joue, int camY);

/**
* \fn void ajouteUnite (Joueur* joue, const Unite* unite)
* \brief ajoute une unite a tabTroupe
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in, out] unite est un poiteur sur une unite.
*/
void ajouteUnite (Joueur* joue, const Unite* unite);

/**
* \fn void ajouteBat (Joueur* joue, const Batiment* bat)
* \brief ajoute un batiment a tabBatiment
*
* \param[in, out] joue est un pointeur sur Joueur
* \param[in, out] bat est un pointeur sur un batiment.
*/
void ajouteBat (Joueur* joue, const Batiment* bat);

#endif /*_JOUEUR */
