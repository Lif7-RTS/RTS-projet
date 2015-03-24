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
     Case* tabCase; /*!< un tableau de case repr�sentant le terrain*/
     char* nomCarte;/*!< nom de la carte*/
     int tailleX;/*!< taille de la carte en coordonee X */
     int tailleY;/*!< taille de la carte en coordon�e Y */
};
typedef struct STerrain Terrain;

/**
* \fn void setTailleX(int x, Terrain* ter)
* \brief mutateur tailleX
*
* \param[in, out] ter pointeur sur Terrain
* \param[in] x taille de la carte
*/
void setTailleX(int x, Terrain* ter);

/**
* \fn void setTailleX(int y, Terrain* ter)
* \brief mutateur tailleY
*
* \param[in, out] ter pointeur sur Terrain
* \param[in] y taille de la carte
*/
void setTailleY(int y, Terrain* ter);

/**
* \fn void setCarte(char* dossierCarte, Terrain* ter)
* \brief mutateur nomCarte
*
* \param[in, out] ter pointeur sur Terrain
* \param[in, out]  dossierCarte chaine de caract�re contenant le chemin de la carte
*/
void setCarte(char* dossierCarte, Terrain* ter);

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
* \param[in] coordon�e x d'une case
* \param[in] coordon�e y d'une case
* \return un pointeur sur un case de coordon�es choisies
*/
sCase* getCase(int x, int y, Terrain* ter);

/**
* \fn void initTerrain(char* dossierCarte, Terrain* ter)
* \brief initialisation d'un Terrain
*
* \param[in, out] ter pointeur sur Terrain
* \param[in, out] dossierCarte chaine de caract�re contenant le chemin de la carte
*/
void initTerrain(char* dossierCarte, Terrain* ter);

/**
* \fn void detruireLibere(Terrain** ter)
* \brief detruit un Terrain
*
* \param[in, out] ter pointeur sur pointeur sur Terrain
*/
void detruireLibere(Terrain** ter);

#endif /* _TERRAIN */
