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
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
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
    Tile* tileSet;/*!< tableau contenant de SDL_rect de la position du tile i */
    SDL_Texture* tileSet_Texture; /*!< texture de l'image du tileSet*/
    int nbTileCamX; /*!< largeur de l'écran en nombre de tile*/
    int nbTileCamY; /*!< hauteur de l'écran en nombre de tile */
    Jeu* jeu;/*!< pointeur sur le jeu du quel dépend l'affichage */
    Terrain* carte; /*!< carte du jeu, qui sera donc affiché*/
    SDL_Window* pFenetre;/*!< pointeur sur la fenètre du jeu*/
    SDL_Renderer* renderer;/*!< pointeur sur le renderer utilisé pour afficher dans la fenètre*/
    TTF_Font* font;/*!< police utilisé pour l'affichage des textes*/
};

/**
* \fn void initAffichage(Affichage* aff, Jeu* j, Terrain* ter)
* \brief initialise l'affichage pour le Jeu j
*
* \param[in, out] aff pointeur sur l' Affichage à initialisé
* \param j pointeur sur le jeu du quel l'affichage dépend
*/
void initAffichage(Affichage* aff, Jeu* j);

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
* \fn void afficheMenu(const Affichage* aff, int menu, int xSouris, int ySouris)
* \brief affiche le menu du jeu, menu différent en fonction du paramètre menu
* \param[in, out] aff pointeur sur l' Affichage
* \param menu menu à afficher
* \param xSouris pos X de la souris
* \param ySouris pos Y de la souris
*/
void afficheMenu(const Affichage* aff, int menu, int xSouris, int ySouris);

/**
* \fn void detruireAffichage(Affichage* aff)
* \brief detruit l'affichage
*
* \param[in, out] aff pointeur sur l' Affichage à detruire
*/
void detruireAffichage(Affichage* aff);

void affichageFinPartie(Affichage* aff, int race);
#endif
