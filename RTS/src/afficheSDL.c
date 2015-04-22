/**
 * \file afficheSDL.c
 * \brief module d'affichage en SDL
 * \author Adrien Baud & Diego Roussel
 * \date 17/04/15
 *
 * Module permettant d'afficher le jeu en mode graphique par la bibliotheque SDL
 *
 */


#include "afficheSDL.h"
#include "jeu.h"

void initAffichage(Affichage* aff, Jeu* j, Terrain* ter){
    int i,k;
    SDL_Surface* image;
    aff->nbTileCamX = SCREEN_W/TILE_TAILLE;
    aff->nbTileCamY = SCREEN_H/TILE_TAILLE;
    aff->jeu = j;
    aff->carte = ter;
    aff->pFenetre = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        fprintf(stdout,"Echec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit);
    aff->pFenetre = SDL_CreateWindow("Panique à la mine !", SDL_WINDOWPOS_CENTERED,
                                                            SDL_WINDOWPOS_CENTERED,
                                                            SCREEN_W,
                                                            SCREEN_H,
                                                            SDL_WINDOW_SHOWN);
    if(aff->pFenetre){
        aff->renderer = SDL_CreateRenderer(aff->pFenetre, -1,SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(aff->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        int imgFlags = IMG_INIT_PNG;
        if( !(IMG_Init(imgFlags) & imgFlags) ){
            fprintf(stderr, "SDL_image n'as pas pu etre initialisee! SDL_image Erreur: %s\n", IMG_GetError() );
            exit(EXIT_FAILURE);
        }
        image = IMG_Load("data/tileset.png");
        if(image == NULL){
            fprintf(stderr,"erreur chargement tileset ! SDL Erreur: %s \n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        aff->tileSet_Texture = SDL_CreateTextureFromSurface(aff->renderer,image);
        SDL_FreeSurface(image);
        image = NULL;
        aff->tileSet = (Tile*) malloc(sizeof(Tile)*NB_TILE);
        for(i= 0; i < NB_TILEX; i++){
            for(k=0; k < NB_TILEY; k++){
                aff->tileSet[i+k*NB_TILEX].r.w = TILE_TAILLE;
                aff->tileSet[i+k*NB_TILEX].r.h = TILE_TAILLE;
                aff->tileSet[i+k*NB_TILEX].r.x = i*TILE_TAILLE;
                aff->tileSet[i+k*NB_TILEX].r.y = k*TILE_TAILLE;
            }
        }
    }
    else{
        fprintf(stderr,"Erreur à la creation de la fenetre: %s \n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

}

void affiche(const Affichage* aff){
    int i,j,id,camX,camY,tX,tY;
	SDL_Rect rect_Dest;
	int num_tile;
	tX = aff->carte->tailleX;
	tY = aff->carte->tailleY;
	camX = aff->jeu->tableauJoueur[aff->jeu->vueJoueur].cameraX;
	camY = aff->jeu->tableauJoueur[aff->jeu->vueJoueur].cameraY;
	SDL_RenderClear(aff->renderer);
	for(i=0;i<aff->nbTileCamX;i++)
	{
		for(j=0;j<aff->nbTileCamY;j++)
		{
			rect_Dest.x = i*TILE_TAILLE;
			rect_Dest.y = j*TILE_TAILLE;
			rect_Dest.w = TILE_TAILLE;
			rect_Dest.h = TILE_TAILLE;
			num_tile = aff->carte->tiles[camX+i+(camY+j)*tX];
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            id = aff->carte->tabCase[camX+i+(camY+j)*tX].idContenu;
            if(id != 0){
                if(id > 0){
                    id--;
                    num_tile = getTileUnite(((Unite*)(aff->jeu->tableauUnite->tab[id]))->type);
                }
                else{
                    id++;
                   /* num_tile = getTileBat(((Unite*)(aff->jeu->tableauBat->tab[-id]))->type); */
                }
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            }

		}
	}
    SDL_RenderPresent(aff->renderer);
    SDL_Delay(1000/30);
}
