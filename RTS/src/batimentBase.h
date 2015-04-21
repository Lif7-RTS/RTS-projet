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
     char* nomBat; /*!< le nom du batiment */
     char niveau;  /*!< c'est le niveau d'amelioration du batiment */
     char tile;/*!< un chemin vers l'image d'un batiment*/
     int vieMax; /*!< la vie maximum d'un batiment */
     int ameliorable;/*!< 1 si le batiment est ameliorable 0 sinon */
     int tempsConstruct;/*!< temps en seconde necessaire a la construction d'un batiment */
     int tailleCaseY;/*!< taille en case d'un batiment suivant sa coordonée y */
     int tailleCaseX;/*!< taille en case d'un batiment suivant sa coordonée x */
     UniteBase* tabUnitFormable;/*!< tableau des unite formable par un batiment */
};
typedef struct SBatBase BatBase;

/* ***********************************************************--Init--*************************************************************************** */

/**
* \fn void initBatBase(BatBase* bat, char* nomBat, char tile, int vieMax,int ameiorable, int tempsConstruct, int tailleCaseY, int tailleCaseX, UniteBase* tabUnitFormable)
* \brief initialise un batiment de base.
*
* \param[in, out] bat pointeur sur BatBase
* \param[in, out] nomBat est une chaine de caractere contennat le nom d'un batiment.
* \param[in] niveau est le niveau d'amelioration du batiment.
* \param[in, out] cheminImage est une chaine de caractere contenant le chemin vers une image de batiment.
* \param[in] vieMax est un entier correspondant a la vie maximum d'un batiment.
* \param[in] ameliorable est un entier jugeant de la capacité d'amelioration d'un batiment.
* \param[in] tempsConstruct est un entier correspondant au temps necessaire pour la construction d'un batiment.
* \param[in] tailleCaseY est la taille d'un batiment en case suivant sa coordonee y.
* \param[in] tailleCaseX est la taille d'un batiment en case suivant sa coordonee x.
* \param[in, out] tabUniteFormable est un tableau des troupe constructible par le batiment en question.
* \param[in, out] tabAttente est la file d'attente des unite en construction dans le batiment en question.
*/
void initBatBase(BatBase* bat, const char* nomBat,char niveau, char tile, int vieMax,int ameliorable, int tempsConstruct,
                 int tailleCaseY, int tailleCaseX, const UniteBase* tabUnitFormable);


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
* \fn void getNiveau(BatBase* bat)
* \brief accesseur niveau
*
* \param[in, out] bat pointeur sur BatBase
* \return le niveau actuel du batiment en question.
*/
char getNiveau(const BatBase* bat);

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
* \fn int getAmeliorable(const BatBase* bat)
* \brief accesseur ameliorable
*
* \param[in, out] bat pointeur sur BatBase
* \return entier jugeant de la capacite d'amelioration d'un batiment.
*/
int getAmeliorable(const BatBase* bat);

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
* \fn void getTailleCaseY(BatBase* bat)
* \brief accesseur tailleCaseY
*
* \param[in, out] bat pointeur sur BatBase
* \return taille d'un batiment en case suivant sa coordonee y.
*/
int getTailleCaseY(const BatBase* bat);

/**
* \fn void getTabUnitFormable(BatBase* bat)
* \brief accesseur TabUnitFormable
*
* \param[in, out] bat pointeur sur BatBase
* \return tableau des troupe constructible par le batiment en question.
*/
UniteBase* getTabUnitFormable(const BatBase* bat);

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
* \fn void setNiveau(BatBase* bat, char niveau)
* \brief mutateur niveau
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] niveau d'amelioration du batiment.
*/
void setNiveau(BatBase* bat, char niveau);

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
* \fn void setAmeliorable(BatBase* bat, int ameliorable)
* \brief mutateur ameliorable
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] ameliorable est un entier jugeant de la capacite d'amelioration d'un batiment.
*/
void setAmeliorable(BatBase* bat, int ameliorable);

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
* \param[in] tailleCaseX est la taille d'un batiment en case suivant sa coordonee x
*/
void setTailleCaseX(BatBase* bat, int tailleCaseX);

/**
* \fn void setTailleCaseY(int tailleCaseY, BatBase* bat)
* \brief mutateur tailleCaseY
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tailleCaseY est la taille d'un batiment en case suivant sa coordonee y.
*/
void setTailleCaseY(BatBase* bat, int tailleCaseY);

/**
* \fn void setTabUnitFormable(BatBase* bat, UniteBase* tabUnitFormable)
* \brief mutateur TabUnitFormable
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] TabUniteFormable est un tableau des troupe constructible par le batiment en question.
*/
void setTabUnitFormable(BatBase* bat, UniteBase* tabUnitFormable);

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
