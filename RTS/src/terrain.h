/**
* \file terrain.h
* \brief structure Terrain
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 24/03/2015
*
*Structure representant un terrain.
*/

#include <stdio.h>
#include <stdlib.h>
#include "case.h"
#ifndef _TERRAIN
#define _TERRAIN

struct STerrain{
     sCase* tabCase; /*!< un tableau de case représentant le terrain*/
     char* nomCarte;/*!< nom de la carte*/
     int tailleX;/*!< taille de la carte en coordonee X */
     int tailleY;/*!< taille de la carte en coordonée Y */
};
typedef struct STerrain Terrain;

/**
* \fn void setTailleX(Terrain* ter, int x)
* \brief mutateur tailleX
*
* \param[in, out] ter pointeur sur Terrain
* \param[in] x taille de la carte
*/
void setTailleX(Terrain* ter, int x);

/**
* \fn void setTailleX(int y, Terrain* ter)
* \brief mutateur tailleY
*
* \param[in, out] ter pointeur sur Terrain
* \param[in] y taille de la carte
*/
void setTailleY(Terrain* ter, int y);

/**
* \fn void setCarte(char* dossierCarte, Terrain* ter)
* \brief mutateur nomCarte
*
* \param[in, out] ter pointeur sur Terrain
* \param[in, out]  dossierCarte chaine de caractère contenant le chemin de la carte
*/
void setCarte(Terrain* ter, char* dossierCarte);

/**
* \fn int getTailleX(Terrain* ter);
* \brief accesseur tailleX
*
* \param[in, out] ter pointeur sur Terrain
* \return la taille de la carte
*/
int getTailleX(Terrain* ter);

/**
* \fn int getTailleY(Terrain* ter);
* \brief accesseur tailleY
*
* \param[in, out] ter pointeur sur Terrain
* \return la taille de la carte
*/
int getTailleY(Terrain* ter);

/**
* \fn sCase* getCase(int x, int y, Terrain* ter)
* \brief accesseur case
*
* \param[in, out] ter pointeur sur Terrain
* \param[in] coordonée x d'une case
* \param[in] coordonée y d'une case
* \return un pointeur sur un case de coordonées choisies
*/
sCase* getCase(Terrain* ter,int x, int y);

/**
* \fn void initTerrain(char* dossierCarte, Terrain* ter)
* \brief initialisation d'un Terrain
*
* \param[in, out] ter pointeur sur Terrain
* \param[in, out] dossierCarte chaine de caractère contenant le chemin de la carte
*/
void initTerrain(Terrain* ter, char* dossierCarte);

/**
* \fn void detruireTerrain(Terrain** ter)
* \brief detruit un Terrain
*
* \param[in, out] ter pointeur sur pointeur sur Terrain
*/
void detruireTerrain(Terrain** ter);

#endif /* _TERRAIN */
