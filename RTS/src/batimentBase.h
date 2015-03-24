/**
* \file batimentBase.h
* \brief structure BatBase
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 24/03/2015
*
*Structure representant un archetype de batiment.
*/

#include <stdio.h>
#include <stdlib.h>
#include "uniteBase.h"
#include "file.h"
#ifndef _BATBASE
#define _BATBASE

struct SBatBase{
     char* nomBat; /*!< le nom du batiment */
     char niveau;  /*!< c'est le niveau d'amelioration du batiment */
     char* cheminImage;/*!< un chemin vers l'image d'un batiment*/
     int vieMax; /*!< la vie maximum d'un batiment */
     int ameliorable;/*!< 1 si le batiment est ameliorable 0 sinon */
     int tempsConstruct;/*!< temps en seconde necessaire a la construction d'un batiment */
     int tailleCaseY;/*!< taille en case d'un batiment suivant sa coordonée y */
     int tailleCaseX;/*!< taille en case d'un batiment suivant sa coordonée x */
     UniteBase* tabUnitFormable;/*!< tableau des unite formable par un batiment */
     File* tabAttente;/*!< une file d'attente de construction d'unite en cours */
};
typedef struct SBatBase BatBase;

/**
* \fn void setNomBat(char* nomBat, BatBase* bat)
* \brief mutateur nomBat
*
* \param[in, out] bat pointeur sur BatBase
* \param[in, out] nomBat chaine de caractere contenant le nom du batiment.
*/
void setNomBat(char* nomBat, BatBase* bat);

/**
* \fn void setNiveau(char niveau, BatBase* bat)
* \brief mutateur niveau
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] niveau d'amelioration du batiment.
*/
void setNiveau(char niveau, BatBase* bat);

/**
* \fn void setCheminImage(char* cheminImage, BatBase* bat)
* \brief mutateur cheminImage
*
* \param[in, out] bat pointeur sur BatBase
* \param[in, out] cheminImage chaine de caractere contenant le chemin vers l'image du batiment.
*/
void setCheminImage(char* cheminImage, BatBase* bat);

/**
* \fn void setCheminImage(char* cheminImage, BatBase* bat)
* \brief mutateur vieMax
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] vieMax est un entier representant la vie maximum d'un batiment.
*/
void setVieMax(int vieMax, BatBase* bat);

/**
* \fn void setAmeliorable(int ameliorable, BatBase* bat)
* \brief mutateur ameliorable
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] ameliorable est un entier jugeant de la capacite d'amelioration d'un batiment.
*/
void setAmeliorable(int ameliorable, BatBase* bat);

/**
* \fn void setTempsConstruct(int tempsConstruct BatBase* bat)
* \brief mutateur tempsConstruct
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tempsConstruction est un entier contennat le temps en seconde necessaire a la construction d'un batiment.
*/
void setTempsConstruct(int tempsConstruct BatBase* bat);

/**
* \fn void setTaileCaseX(int tailleCaseX, BatBase* bat)
* \brief mutateur tailleCaseX
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tailleCaseX est la taille d'un batiment en case suivant sa coordonee x.
*/
void setTaileCaseX(int tailleCaseX, BatBase* bat);

/**
* \fn void setTaileCaseY(int tailleCaseY, BatBase* bat)
* \brief mutateur tailleCaseY
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tailleCaseY est la taille d'un batiment en case suivant sa coordonee y.
*/
void setTaileCaseY(int tailleCaseY, BatBase* bat);

/**
* \fn void setTabUnitFormable(UniteBase* tabUnitFormable, BatBase* bat)
* \brief mutateur TabUnitFormable
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] TabUniteFormable est un tableau des troupe constructible par le batiment en question.
*/
void setTabUnitFormable(UniteBase* tabUnitFormable, BatBase* bat);

/**
* \fn void setTabAttente(File* tabAttente, BatBase* bat)
* \brief mutateur tabAttente
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tabAttente est la file d'attente des unite en construction dans le batiment en question.
*/
void setTabAttente(File* tabAttente, BatBase* bat);

/**
* \fn void getNomBat(BatBase* bat)
* \brief accesseur nomBat
*
* \param[in, out] bat pointeur sur BatBase
* \return chaine de caractere contenant le nom du batiment.
*/
char* getNomBat(BatBase* bat);

/**
* \fn void setNiveau(BatBase* bat)
* \brief accesseur niveau
*
* \param[in, out] bat pointeur sur BatBase
* \return le niveau actuel du batiment en question.
*/
char setNiveau(BatBase* bat);

/**
* \fn void getCheminImage(BatBase* bat)
* \brief accesseur cheminImage
*
* \param[in, out] bat pointeur sur BatBase
* \return chaine de caractere contenant le chemin vers l'image du batiment.
*/
char* getCheminImage(BatBase* bat);

/**
* \fn void getCheminImage(BatBase* bat)
* \brief accesseur vieMax
*
* \param[in, out] bat pointeur sur BatBase
* \return entier representant la vie maximum d'un batiment.
*/
int getVieMax(BatBase* bat);

/**
* \fn void getAmeliorable(BatBase* bat)
* \brief accesseur ameliorable
*
* \param[in, out] bat pointeur sur BatBase
* \return entier jugeant de la capacite d'amelioration d'un batiment.
*/
int getAmeliorable(BatBase* bat);

/**
* \fn void getTempsConstruct(BatBase* bat)
* \brief accesseur tempsConstruct
*
* \param[in, out] bat pointeur sur BatBase
* \return entier contennat le temps en seconde necessaire a la construction d'un batiment.
*/
int getTempsConstruct(BatBase* bat);

/**
* \fn void getTaileCaseX(BatBase* bat)
* \brief accesseur tailleCaseX
*
* \param[in, out] bat pointeur sur BatBase
* \return la taille d'un batiment en case suivant sa coordonee x.
*/
int getTaileCaseX(BatBase* bat);

/**
* \fn void getTaileCaseY(BatBase* bat)
* \brief accesseur tailleCaseY
*
* \param[in, out] bat pointeur sur BatBase
* \return taille d'un batiment en case suivant sa coordonee y.
*/
int getTaileCaseY(int tailleCaseY, BatBase* bat);

/**
* \fn void getTabUnitFormable(BatBase* bat)
* \brief accesseur TabUnitFormable
*
* \param[in, out] bat pointeur sur BatBase
* \return tableau des troupe constructible par le batiment en question.
*/
UniteBase* getTabUnitFormable(BatBase* bat);

/**
* \fn void getTabAttente(BatBase* bat)
* \brief accesseur tabAttente
*
* \param[in, out] bat pointeur sur BatBase
* \return la file d'attente des unite en construction dans le batiment en question.
*/
File* getTabAttente(BatBase* bat);

/**
* \fn void initBatBase(BateBase* bat, char* nomBat, char* cheminImage, int vieMax,int ameiorable, int tempsConstruct, int tailleCaseY, int tailleCaseX, UniteBase* tabUnitFormable, File* tabAttente)
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
void initBatBase(BateBase* bat, char* nomBat,char niveau, char* cheminImage, int vieMax,int ameliorable, int tempsConstruct,
                 int tailleCaseY, int tailleCaseX, UniteBase* tabUnitFormable, File* tabAttente);

/**
* \fn void setTaileCaseY(int tailleCaseY, BatBase* bat)
* \brief detruit un batiment de base.
*
* \param[in, out] bat pointeur sur BatBase
*/
void detruireBatBase(BatBase* bat);

#endif /* _BATBASE */
