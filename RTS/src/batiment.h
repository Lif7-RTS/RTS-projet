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
#include "batimentBase.h"
#ifndef _BAT
#define _BAT

struct SBatiment{
     int id;  /*!< identifiant unique corespondant a un batiment precis dans le jeu */
     BatBase* typeBat;  /*!< type de base du batiment en question */
     int vieCourante;  /*!< nombre de point de vie actuel du batiment */
     int enConstruction;  /*!< 1 si le batiment en construction 0 sinon */
};
typedef SBatiment Batiment;

/**
* \fn int getIdBat(Batiment* bat)
* \brief accesseur id
*
* \param[in, out] bat pointeur sur Batiment.
*\return id, un identifiant unique
*/
int getIdBat(Batiment* bat);

/**
* \fn BatBase getTypeBat(Batiment* bat)
* \brief accesseur typeBat
*
* \param[in, out] bat pointeur sur Batiment.
* \return typeBat pointeur sur un batiment de base.
*/
BatBase* getTypeBat(Batiment* bat);

/**
* \fn int getVieCourante (Batiment* bat)
* \brief accesseur vieCourante
*
* \param[in, out] bat pointeur sur Batiment.
* \return vieCourante est le nombre de point de vie actuel du batiment.
*/
int getVieCourante (Batiment* bat);

/**
* \fn int getEnConstruction (Batiment* bat)
* \brief accesseur vieCourante
*
* \param[in, out] bat pointeur sur Batiment.
* \return enConstruction est un entier jugeant de l'avancement de la construction du batiment.
*/
int getEnConstruction (Batiment* bat);


/**
* \fn void setIdBat(int id , Batiment* bat)
* \brief mutateur id
*
* \param[in] id est un identifiant unique.
* \param[in, out] bat pointeur sur Batiment.
*/
void setIdBat(int id , Batiment* bat);

/**
* \fn void setTypeBat(BatBase* typeBat, Batiment* bat)
* \brief mutateur typeBat
*
* \param[in, out] typeBat pointeur sur un batiment de base.
* \param[in, out] bat pointeur sur Batiment.
*/
void setTypeBat(BatBase* typeBat, Batiment* bat);

/**
* \fn void setVieCourante (int vieCourante , Batiment* bat)
* \brief mutateur vieCourante
*
* \param[in] vieCourante est le nombre de point de vie actuel du batiment.
* \param[in, out] bat pointeur sur Batiment.
*/
void setVieCourante (int vieCourante , Batiment* bat);

/**
* \fn void setEnConstruction (int enConstruction , Batiment* bat)
* \brief mutateur vieCourante
*
* \param[in] enConstruction est un entier jugeant de l'avancement de la construction du batiment.
* \param[in, out] bat pointeur sur Batiment.
*/
void setEnConstruction (int enConstruction , Batiment* bat);

#endif /* _BAT */

