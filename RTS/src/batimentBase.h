/**
* \file batimentBase.h
* \brief structure BatBase
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 24/03/2015
*
* Structure representant un archetype de batiment.
*/

#include <stdio.h>
#include <stdlib.h>
#include "uniteBase.h"
#ifndef _BATBASE
#define _BATBASE

struct SBatBase{
     char nomBat[25]; /*!< le nom du batiment */
     char tile;/*!< un chemin vers l'image d'un batiment*/
     int vieMax; /*!< la vie maximum d'un batiment */
     int tempsConstruct;/*!< temps en seconde necessaire a la construction d'un batiment */
     int tailleCaseY;/*!< taille en case d'un batiment suivant sa coordonée y */
     int tailleCaseX;/*!< taille en case d'un batiment suivant sa coordonée x */
     int* tabUnitFormable;/*!< tableau d'identifiant d'unite formable par un batiment */
     int nbUnitFormable;/*!< nombre d'unite formable par ce batiment */
     int coutPierre; /*!< cout en pierre du batiment */
     int coutMithril;/*!< cout en mithril du batiment */
     unsigned char race; /*!< race capable de généré ce batiment (1=blob, 2=Nain) */
};
typedef struct SBatBase BatBase;

/* *************************************************************--GET--***************************************************************************** */

/**
* \fn void getNomBat(BatBase* bat)
* \brief accesseur nomBat
*
* \param[in, out] bat pointeur sur BatBase
* \return chaine de caractere contenant le nom du batiment.
*/
char* getNomBat(const BatBase* bat);

/**
* \fn char getTileBat(const BatBase* bat)
* \brief accesseur cheminImage
*
* \param[in, out] bat pointeur sur BatBase
* \return un caractère correspond au tile d'un batiment.
*/
char getTileBat(const BatBase* bat);

/**
* \fn int getVieMaxBat(const BatBase* bat)
* \brief accesseur vieMax
*
* \param[in, out] bat pointeur sur BatBase
* \return entier representant la vie maximum d'un batiment.
*/
int getVieMaxBat(const BatBase* bat);

/**
* \fn void getTempsConstruct(BatBase* bat)
* \brief accesseur tempsConstruct
*
* \param[in, out] bat pointeur sur BatBase
* \return entier contennat le temps en seconde necessaire a la construction d'un batiment.
*/
int getTempsConstruct(const BatBase* bat);

/**
* \fn void getTaileCaseX(BatBase* bat)
* \brief accesseur tailleCaseX
*
* \param[in, out] bat pointeur sur BatBase
* \return la taille d'un batiment en case suivant sa coordonee x.
*/
int getTailleCaseX(const BatBase* bat);

/**
* \fn int getTailleCaseY(BatBase* bat)
* \brief accesseur tailleCaseY
*
* \param[in, out] bat pointeur sur BatBase
* \return taille d'un batiment en case suivant sa coordonee y.
*/
int getTailleCaseY(const BatBase* bat);

/**
* \fn int* getTabUnitFormable(const BatBase* bat)
* \brief accesseur TabUnitFormable
*
* \param[in, out] bat pointeur sur BatBase
* \param i index de l'unite voulu dans tabUniteFormable
* \return tabUnitFormable[i]
*/
int getUnitFormableBat(const BatBase* bat, int i);

/**
* \fn int getNbUniteFormable(const BatBase* bat)
* \brief accesseur nbUniteFormable
*
* \param[in, out] bat pointeur sur BatBase
* \return nbUniteFormable
*/
int getNbUniteFormable(const BatBase* bat);

 /**
 * \fn int getCoutPierreBat(const BatBase* bat)
 * \brief accesseur coutPierre
 *
 * \param[in, out] bat pointeur sur BatBase
 * \return un entier correspondant au cout en pierre de la création d'un batiment.
 */
int getCoutPierreBat(const BatBase* bat);

 /**
 * \fn int getCoutMithrilBat(const BatBase* bat)
 * \brief accesseur coutMithril
 *
 * \param[in, out] bat pointeur sur BatBase
 * \return un entier correspondant au cout en mithril de la création d'un batiment.
 */
int getCoutMithrilBat(const BatBase* bat);

 /**
 * \fn unsigned char getRaceBat(const BatBase* bat)
 * \brief accesseur race
 *
 * \param[in, out] bat pointeur sur BatBase
 * \return un entier représentant une race.
 */
unsigned char getRaceBat(const BatBase* bat);

/* *************************************************************--SET--***************************************************************************** */

/**
* \fn void setNomBat(BatBase* bat,char* nomBat)
* \brief mutateur nomBat
*
* \param[in, out] bat pointeur sur BatBase
* \param[in, out] nomBat chaine de caractere contenant le nom du batiment.
*/
void setNomBat(BatBase* bat,char* nomBat);

/**
* \fn void setTileBat(BatBase* bat, char tile);
* \brief mutateur cheminImage
*
* \param[in, out] bat pointeur sur BatBase
* \param[in, out] cheminImage chaine de caractere contenant le chemin vers l'image du batiment.
*/
void setTileBat(BatBase* bat, char tile);

/**
* \fn void setVieMaxBat(BatBase* bat,int vieMax)
* \brief mutateur vieMax
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] vieMax est un entier representant la vie maximum d'un batiment.
*/
void setVieMaxBat(BatBase* bat,int vieMax);

/**
* \fn void setTempsConstruct(BatBase* bat, int tempsConstruct)
* \brief mutateur tempsConstruct
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tempsConstruction est un entier contennat le temps en seconde necessaire a la construction d'un batiment.
*/
void setTempsConstruct(BatBase* bat, int tempsConstruct);

/**
* \fn void setTailleCaseX(BatBase* bat, int tailleCaseX)
* \brief mutateur tailleCaseX
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tailleCaseX est la taille d'un batiment en case suivant sa coordonnee x
*/
void setTailleCaseX(BatBase* bat, int tailleCaseX);

/**
* \fn void setTailleCaseY(int tailleCaseY, BatBase* bat)
* \brief mutateur tailleCaseY
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tailleCaseY est la taille d'un batiment en case suivant sa coordonnee y.
*/
void setTailleCaseY(BatBase* bat, int tailleCaseY);

/**
* \fn void setTabUnitFormable(BatBase* bat, int* tabUnitFormable)
* \brief mutateur TabUnitFormable
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] TabUniteFormable est un tableau des troupe constructible par le batiment en question.
*/
void setTabUnitFormable(BatBase* bat, int* tabUnitFormable);

/**
* \fn void setNbUniteFormable(BatBase* bat,int nb)
* \brief mutateur nbUniteFormable
*
* \param[in, out] bat pointeur sur BatBase
* \param nb nombre de type d'unite que le batiment peut forme
*/
void setNbUniteFormable(BatBase* bat,int nb);

 /**
 * \fn void setCoutPierreBat(BatBase* bat, int coutP)
 * \brief mutateur coutPierre
 *
 * \param[in, out] bat pointeur sur BatBase
 * \param[in] un entier correspondant au cout en pierre de la creation d'un batiment..
 */
void setCoutPierreBat(BatBase* bat, int coutP);

 /**
 * \fn void setCoutMithrilBat(BatBase* bat, int coutM)
 * \brief mutateur coutMithril
 *
 * \param[in, out] bat pointeur sur BatBase
 * \param[in] un entier correspondant au cout en mithril de la creation d'un batiment.
 */
void setCoutMithrilBat(BatBase* bat, int coutM);

 /**
 * \fn void getRaceBat(const BatBase* bat, unsigned char race)
 * \brief mutateur race
 *
 * \param[in, out] bat pointeur sur BatBase
 * \param[in] un entier représentant une race.
 */
void setRaceBat(BatBase* bat, unsigned char race);

/* *************************************************************--FCT--***************************************************************************** */

/**
* \fn BatBase* chargementBatBase(void)
* \brief charge en mémoire tout les batiment de base.
*
*
* \return un tableau regroupant l'ensemble des bâtiments de base.
*/
BatBase* chargementBatBase(void);

#endif /* _BATBASE */
