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
        if(TTF_Init() != 0){
            fprintf(stderr, "SDL_TTF n'as pas pu etre initialisee! SDL_TTF Erreur: %s\n", TTF_GetError() );
            exit(EXIT_FAILURE);
        }
        aff->font  = TTF_OpenFont("data/arial.ttf", 25);
        aff->tileSet_Texture = SDL_CreateTextureFromSurface(aff->renderer,image);
        SDL_FreeSurface(image);
        image = NULL;
        aff->tileSet = (Tile*) malloc(sizeof(Tile)*NB_TILEX*NB_TILEY);
        for(i= 0; i < NB_TILEY; i++){
            for(k=0; k < NB_TILEX; k++){
                aff->tileSet[k+i*NB_TILEX].r.w = TILE_TAILLE;
                aff->tileSet[k+i*NB_TILEX].r.h = TILE_TAILLE;
                aff->tileSet[k+i*NB_TILEX].r.x = k*TILE_TAILLE;
                aff->tileSet[k+i*NB_TILEX].r.y = i*TILE_TAILLE;
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
	SDL_Surface* texte;
	SDL_Color blanc ={255,255,255};
	int num_tile;
	tX = aff->carte->tailleX;
	camX = aff->jeu->tableauJoueur[aff->jeu->vueJoueur].cameraX;
	camY = aff->jeu->tableauJoueur[aff->jeu->vueJoueur].cameraY;
	SDL_RenderClear(aff->renderer);
    rect_Dest.w = TILE_TAILLE;
    rect_Dest.h = TILE_TAILLE;
	for(i=0;i<aff->nbTileCamX;i++){
		for(j=0;j<aff->nbTileCamY-(HUD_H/TILE_TAILLE);j++)
		{
			rect_Dest.x = i*TILE_TAILLE;
			rect_Dest.y = j*TILE_TAILLE;
			num_tile = aff->carte->tiles[camX+i+(camY+j)*tX];
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            id = aff->carte->tabCase[camX+i+(camY+j)*tX].idContenu;
            if(id != 0){
                if(id > 0){
                    id--;
                    num_tile = getTileUnite(getTypeUnite((Unite*)(aff->jeu->tableauUnite->tab[id])));
                }
                else{
                    id++;
                    num_tile = getTileBat(getTypeBat((Batiment*)(aff->jeu->tableauBat->tab[-id])));
                    num_tile += (i+camX)-getPosXBat((Batiment*)(aff->jeu->tableauBat->tab[-id]));
                    num_tile += ((j+camY)-getPosYBat((Batiment*)(aff->jeu->tableauBat->tab[-id])))*getTailleCaseX(getTypeBat((Batiment*)(aff->jeu->tableauBat->tab[-id])));
                }
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            }

		}
		for(j=aff->nbTileCamY-(HUD_H/TILE_TAILLE); j < aff->nbTileCamY; j++){
            num_tile = 3;
            rect_Dest.x = i*TILE_TAILLE;
			rect_Dest.y = j*TILE_TAILLE;
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            if(j == aff->nbTileCamY-(HUD_H/TILE_TAILLE)){
                num_tile = 4;
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);

            }
		}
	}
	id = getIdSel(aff->jeu);
	if(id != 0){
        if(id < 0){
            BatBase* b = getTypeBat(getBat(aff->jeu,-getIdSel(aff->jeu)-1));
            texte = TTF_RenderText_Solid(aff->font,getNomBat(b),blanc);
            SDL_Texture * texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            for(j = 0; j < getNbUniteFormable(b);j++){
                num_tile = getTileUnite(getUniteFormable(aff->jeu,getUnitFormableBat(b,j)));
                rect_Dest.x = SCREEN_W+(j%3-3)*TILE_TAILLE;
                rect_Dest.y = SCREEN_H+(j/3-3)*TILE_TAILLE+5;
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            }
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            rect_Dest.x = (SCREEN_W-tX)/2;
            rect_Dest.y = (SCREEN_H-HUD_H+tY+10);
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
        }
        else{
            UniteBase* u = getTypeUnite(getUnite(aff->jeu,getIdSel(aff->jeu)-1));
            texte = TTF_RenderText_Solid(aff->font,getNom(u),blanc);
            SDL_Texture * texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            rect_Dest.x = (SCREEN_W-tX)/2;
            rect_Dest.y = (SCREEN_H-HUD_H+tY+10);
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
        }
	}

    SDL_RenderPresent(aff->renderer);
    SDL_Delay(1000/60);
}
