/**
 * \file afficheSDL.h
 * \brief module d'affichage en SDL
 * \author Adrien Baud & Diego Roussel
 * \date 17/04/15
 *
 * Module permettant d'afficher le jeu en mode graphique par la bibliotheque SDL
 *
 */
#include <stdio.h>
#include <stdlib.h>
#ifdef WIN
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#endif // WIN
#ifdef LINUX
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif // LINUX
#include "terrain.h"
#include "define.h"
#ifndef _AFFICHAGE
#define _AFFICHAGE

typedef struct STile Tile;
struct STile{
    SDL_Rect r;
};

typedef struct SAffichage Affichage;
struct SAffichage{
    Tile* tileSet;
    SDL_Texture* tileSet_Texture;
    int nbTileCamX;
    int nbTileCamY;
    Jeu* jeu;
    Terrain* carte;
    SDL_Window* pFenetre;
    SDL_Renderer* renderer;
    TTF_Font* font;
};

/**
* \fn void initAffichage(Affichage* aff, Jeu* j, Terrain* ter)
* \brief initialise l'affichage pour le Jeu j
*
* \param[in, out] aff pointeur sur l' Affichage � initialis�
* \param j pointeur sur le jeu du quel l'affichage d�pend
* \param ter pointeur sur le terrain qui doit etre affich� tout le long de la partie
*/
void initAffichage(Affichage* aff, Jeu* j, Terrain* ter);

/**
* \fn void affiche(Affichage* aff, int xSouris, int ySouris)
* \brief affiche le jeu
*
* \param[in, out] aff pointeur sur l' Affichage
* \param xSouris position x de la souris
* \param ySouris position y de la souris
*/
void affiche(const Affichage* aff, int xSouris, int ySouris);

/**
* \fn void afficheMenu(Affichage* aff, int menu)
* \brief affiche le menu du jeu, menu diff�rent en fonction du param�tre menu
* \param[in, out] aff pointeur sur l' Affichage
* \param menu menu � afficher
*/
void afficheMenu(const Affichage* aff, int menu);


#endif
