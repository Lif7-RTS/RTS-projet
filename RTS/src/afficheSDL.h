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


void initAffichage(Affichage* aff, Jeu* j, Terrain* ter);

void affiche(const Affichage* aff, int xSouris, int ySouris);

void afficheMenu(const Affichage* aff, int menu);


#endif
