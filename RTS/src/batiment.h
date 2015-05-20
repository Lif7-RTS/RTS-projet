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
#include <time.h>
#include "batimentBase.h"
#include "file.h"
#ifndef _BAT
#define _BAT

typedef struct SBatiment Batiment;
#include "jeu.h"

struct SBatiment{
     int id;  /*!< identifiant unique corespondant a un batiment precis dans le jeu */
     BatBase* typeBat;  /*!< type de base du batiment en question */
     int vieCourante;  /*!< nombre de point de vie actuel du batiment */
     int enConstruction;  /*!< 1 si le batiment en construction 0 sinon */
     File* tabAttente;/*!< une file d'attente de construction d'unite en cours */
     int x; /*!< position x du batiment (haut-gauche du batiment) */
     int y; /*!< position y du batiment (haut-gauche du batiment) */
     clock_t timerBat;/*!< timer du batiment, pour la formation d'unite */
     int idJoueur; /*!< id du joueur controleur */
};

/* ***********************************************************--Init--*************************************************************************** */

/**
* \fn void initBatiment (Batiment* bat)
* \brief initialise un Batiment
*
* \param[in, out] bat pointeur sur Batiment
* \param[in] id est un identifiant unique
* \param[in, out] typeBat pointeur sur un batiment de base
* \param[in] enConstruction est un entier jugeant de l'avancement de la construction du batiment.
* \param[in] idJ id du joueur controlant ce batiment.
*/
void initBatiment(Batiment* bat, int id, BatBase* typeBat, int enConstruction, int idJ);

/**
* \fn void detruireBatiment (Batiment** bat)
* \brief detruit et libère la structure batiment
*
* \param[in, out] bat pointeur sur Batiment.
*/
void detruireBatiment(Batiment** bat);

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
* \fn int getIdJoueurBat(Batiment* bat)
* \brief accesseur idJ
*
* \param[in, out] bat pointeur sur Batiment.
*\return idJ,id du joueur controleur
*/
int getIdJoueurBat(const Batiment* bat);

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
File* getTabAttente(const Batiment* bat);

/**
* \fn int getPosXBat(Batiment* bat)
* \brief accesseur x
*
* \param[in, out] bat pointeur sur Batiment.
*\return x
*/
int getPosXBat(const Batiment* bat);

/**
* \fn int getPosXBat(Batiment* bat)
* \brief accesseur y
*
* \param[in, out] bat pointeur sur Batiment.
*\return y
*/
int getPosYBat(const Batiment* bat);


/**
* \fn clock_t getTimerBat(Batiment* bat)
* \brief accesseur timerBat
*
* \param[in, out] bat pointeur sur Batiment.
*\return timerBat
*/
clock_t getTimerBat(const Batiment* bat);

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
* \fn int setIdJoueurBat(Batiment* bat, int idJ)
* \brief mutateur idJoueur
*
* \param[in, out] bat pointeur sur Batiment.
* \param idJ, l'id du joueur controleur
*/
void setIdJoueurBat(Batiment* bat, int idJ);

/**
* \fn vvoid setTypeBat(Batiment* bat, BatBase* typeBat)
* \brief mutateur typeBat
*
* \param[in, out] bat pointeur sur Batiment.
* \param[in, out] typeBat pointeur sur un batiment de base.
*/
void setTypeBat(Batiment* bat, BatBase* typeBat);

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
void setEnConstruction(Batiment* bat, int enConstruction);

/**
* \fn void setTabAttente(Batiment* bat, File* tabAttente)
* \brief mutateur tabAttente
*
* \param[in, out] bat pointeur sur BatBase
* \param[in] tabAttente est la file d'attente des unite en construction dans le batiment en question.
*/
void setTabAttente(Batiment* bat, File* tabAttente);

/**
* \fn void setPosXBat(Batiment* bat, int x)
* \brief mutateur x
*
* \param[in, out] bat pointeur sur Batiment.
* \param[in] x la coordonnees x du bat
*/
void setPosXBat(Batiment* bat, int x );

/**
* \fn void setPosYBat(Batiment* bat, int y)
* \brief mutateur y
*
* \param[in, out] bat pointeur sur Batiment.
* \param[in] y la coordonnees y du bat
*/
void setPosYBat(Batiment* bat, int y);


/**
* \fn void setTimerBat(Batiment* bat, clock_t t)
* \brief mutateur timerBat
*
* \param[in, out] bat pointeur sur Batiment.
* \param t nouveau timer du bat
*/
void setTimerBat(Batiment* bat, clock_t t);

/* *************************************************************--FCT--***************************************************************************** */


/**
* \fn void verifierTimerBat(Batiment* bat)
* \brief verifie si une action est a faire (cree unite,finir creation du bat)
*
* \param[in, out] bat pointeur sur Batiment
*/
void verifierTimerBat(Batiment* bat, Jeu* j);


/**
* \fn void ajouterFileBat(Batiment* bat, int i)
* \brief ajoute la creation d'une unite a la file d'attente
*
* \param[in, out] bat pointeur sur Batiment
* \param i unite a cree (bat->type->uniteFormable[i])
*/
void ajouterFileBat(Batiment* bat,Jeu* j,int i);


#endif /* _BAT */

