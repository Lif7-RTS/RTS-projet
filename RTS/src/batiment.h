/**
* \file batiment.h
* \brief structure Batiment
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 24/03/2015
*
*Structure representant un batiment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "batimentBase.h"
#include "file.h"
#ifndef _BAT
#define _BAT

struct SBatiment{
     int id;  /*!< identifiant unique corespondant a un batiment precis dans le jeu */
     BatBase* typeBat;  /*!< type de base du batiment en question */
     int vieCourante;  /*!< nombre de point de vie actuel du batiment */
     int enConstruction;  /*!< 1 si le batiment en construction 0 sinon */
     File* tabAttente;/*!< une file d'attente de construction d'unite en cours */
};
typedef struct SBatiment Batiment;

/* ***********************************************************--Init--*************************************************************************** */

/**
* \fn void detruirBatiment (Batiment* bat)
* \brief initialise un Batiment
*
* \param[in, out] bat pointeur sur Batiment
* \param[in] id est un identifiant unique
* \param[in, out] typeBat pointeur sur un batiment de base
* \param[in] vieCourante est le nombre de point de vie actuel du batiment
* \param[in] enConstruction est un entier jugeant de l'avancement de la construction du batiment.
*/
void initBatiment (Batiment* bat, int id, const BatBase* typeBat, int vieCourante, int enConstruction);

/**
* \fn void detruirBatiment (Batiment** bat)
* \brief detruit et libère la structure batiment
*
* \param[in, out] bat pointeur sur Batiment.
*/
void detruirBatiment (Batiment** bat);

/* *************************************************************--GET--***************************************************************************** */

/**
* \fn int getIdBat(Batiment* bat)
* \brief accesseur id
*
* \param[in, out] bat pointeur sur Batiment.
*\return id, un identifiant unique
*/
int getIdBat(const Batiment* bat);

/**
* \fn BatBase getTypeBat(Batiment* bat)
* \brief accesseur typeBat
*
* \param[in, out] bat pointeur sur Batiment.
* \return typeBat pointeur sur un batiment de base.
*/
BatBase* getTypeBat(const Batiment* bat);

/**
* \fn int getVieCouranteBat(Batiment* bat)
* \brief accesseur vieCourante
*
* \param[in, out] bat pointeur sur Batiment.
* \return vieCourante est le nombre de point de vie actuel du batiment.
*/
int getVieCouranteBat(const Batiment* bat);

/**
* \fn int getEnConstruction (Batiment* bat)
* \brief accesseur vieCourante
*
* \param[in, out] bat pointeur sur Batiment.
* \return enConstruction est un entier jugeant de l'avancement de la construction du batiment.
*/
int getEnConstruction (const Batiment* bat);

/**
* \fn void getTabAttente(BatBase* bat)
* \brief accesseur tabAttente
*
* \param[in, out] bat pointeur sur BatBase
* \return la file d'attente des unite en construction dans le batiment en question.
*/
File* getTabAttente(const BatBase* bat);

/* *************************************************************--SET--***************************************************************************** */

/**
* \fn void setIdBat(int id , Batiment* bat)
* \brief mutateur id
*
* \param[in, out] bat pointeur sur Batiment.
* \param[in] id est un identifiant unique.
*/
void setIdBat(Batiment* bat, int id );

/**
* \fn void setTypeBat(BatBase* typeBat, Batiment* bat)
* \brief mutateur typeBat
*
* \param[in, out] bat pointeur sur Batiment.
* \param[in, out] typeBat pointeur sur un batiment de base.
*/
void setTypeBat(Batiment* bat, const BatBase* typeBat);

/**
* \fn void setVieCouranteBat(int vieCourante , Batiment* bat)
* \brief mutateur vieCourante
*
* \param[in, out] bat pointeur sur Batiment.
* \param[in] vieCourante est le nombre de point de vie actuel du batiment.
*/
void setVieCouranteBat(Batiment* bat, int vieCourante);

/**
* \fn void setEnConstruction (int enConstruction , Batiment* bat)
* \brief mutateur vieCourante
*
* \param[in, out] bat pointeur sur Batiment.
* \param[in] enConstruction est un entier jugeant de l'avancement de la construction du batiment.
*/
void setEnConstruction (Batiment* bat, int enConstruction);

/**
* \fn void setTabAttente(File* tabAttente, BatBase* bat)
* \brief mutateur tabAttente
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tabAttente est la file d'attente des unite en construction dans le batiment en question.
*/
void setTabAttente(BatBase* bat, const File* tabAttente);

#endif /* _BAT */

