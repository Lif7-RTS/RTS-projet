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
#include "define.h"
#ifndef _TERRAIN
#define _TERRAIN

struct STerrain{
     sCase* tabCase; /*!< un tableau de case représentant le terrain*/
     char* collisionCarte;/*!< fichier de collision de la carte*/
     char* imageCarte;/*!<image de la carte */
     int tailleX;/*!< taille de la carte en coordonee X */
     int tailleY;/*!< taille de la carte en coordonée Y */
     char* tiles;
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
* \fn void setCarteTerrain(Terrain* ter, const char* colliCarte)
* \brief mutateur collisionCarte
*
* \param[in, out] ter pointeur sur Terrain
* \param[in, out]  colliCarte chaine de caractère contenant le chemin du fichier de collision la carte
*/
void setCarteTerrain(Terrain* ter, const char* colliCarte);

/**
* \fn void setCarte(char* dossierCarte, Terrain* ter)
* \brief mutateur collisionCarte
*
* \param[in, out] ter pointeur sur Terrain
* \param[in, out]  colliCarte chaine de caractère contenant le chemin du fichier de collision la carte
*/
void setImageCarte(Terrain* ter, const char* carte);

/**
* \fn int getTailleX(Terrain* ter);
* \brief accesseur tailleX
*
* \param[in, out] ter pointeur sur Terrain
* \return la taille de la carte
*/
int getTailleX(const Terrain* ter);

/**
* \fn int getTailleY(Terrain* ter);
* \brief accesseur tailleY
*
* \param[in, out] ter pointeur sur Terrain
* \return la taille de la carte
*/
int getTailleY(const Terrain* ter);

/**
* \fn sCase* getCase(int x, int y, Terrain* ter)
* \brief accesseur case
*
* \param[in, out] ter pointeur sur Terrain
* \param[in] coordonée x d'une case
* \param[in] coordonée y d'une case
* \return un pointeur sur un case de coordonées choisies
*/
sCase* getCase(const Terrain* ter,int x, int y);

/**
* \fn void initTerrain(Terrain* ter, char* colliCarte)
* \brief initialisation d'un Terrain
*
* \param[in, out] ter pointeur sur Terrain
* \param[in, out] colliCarte chaine de caractère contenant le chemin du fichier de collision de la carte
*/
void initTerrain(Terrain* ter, const char* colliCarte, const char* imageCarte);

/**
* \fn void detruireTerrain(Terrain* ter)
* \brief detruit un Terrain
*
* \param[in, out] ter pointeur sur Terrain
*/
void detruireTerrain(Terrain* ter);

#endif /* _TERRAIN */
