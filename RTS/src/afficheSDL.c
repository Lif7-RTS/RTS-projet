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
        fprintf(stderr,"Echec de l'initialisation de la SDL (%s)\n",SDL_GetError());
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

void affiche(const Affichage* aff, int xSouris, int ySouris){
    int i,j,id,camX,camY,tX,tY;
	SDL_Rect rect_Dest;
	SDL_Surface* texte;
	SDL_Color blanc ={255,255,255};
	SDL_Color rouge ={255,0,0};
	SDL_Color vert  ={0,255,0};
	int num_tile;
	tX = getTailleX(getCarteJeu(aff->jeu));
	camX = getCameraX(getJoueur(aff->jeu, getVueJoueur(aff->jeu)));
	camY = getCameraY(getJoueur(aff->jeu, getVueJoueur(aff->jeu)));
	SDL_RenderClear(aff->renderer);
    rect_Dest.w = TILE_TAILLE;
    rect_Dest.h = TILE_TAILLE;
    /*Affichage de la map vue par le joueur*/
	for(i=0;i<aff->nbTileCamX;i++){
		for(j=0;j<aff->nbTileCamY-(HUD_H/TILE_TAILLE);j++)
		{
			/*Affichage du Tile de la case (i;j)*/
			rect_Dest.x = i*TILE_TAILLE;
			rect_Dest.y = j*TILE_TAILLE;
			num_tile = getTileCase(getCase(aff->carte,camX+i,camY+j));
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            id = aff->carte->tabCase[camX+i+(camY+j)*tX].idContenu;
            /*Affichage du batiment ou de l'unite */
            if(id != 0){
                if(id > 0){
                    num_tile = getTileUnite(getTypeUnite((getUnite(aff->jeu,id))));
                }
                else{
                    num_tile = getTileBat(getTypeBat(getBat(aff->jeu, -id)));
                    num_tile += (i+camX)-getPosXBat(getBat(aff->jeu, -id));
                    num_tile += ((j+camY)-getPosYBat(getBat(aff->jeu, -id)))*getTailleCaseX(getTypeBat(getBat(aff->jeu, -id)));
                }
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            }

		}
		/*Affichage HUD: Fond et barre du haut du HUD*/
		for(j=aff->nbTileCamY-(HUD_H/TILE_TAILLE); j < aff->nbTileCamY; j++){
            if(i < 3 || i >= (SCREEN_W/TILE_TAILLE - 3))
                num_tile = 98;
            else if(i == 3)
                num_tile = 96;
            else if(i == 4)
                num_tile = 97;
            else
                num_tile = 99;
            rect_Dest.x = i*TILE_TAILLE;
			rect_Dest.y = j*TILE_TAILLE;
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            if(j == aff->nbTileCamY-(HUD_H/TILE_TAILLE)){
                num_tile = 95;
                rect_Dest.y -= 6;
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);

            }
		}
	}
	/*Affichage HUD des batiments constructible */
	for(j = 1; j < NB_BAT_RACE;j++){
                num_tile = j+ICON;
                rect_Dest.x = ((j-1)%3)*TILE_TAILLE;
                rect_Dest.y = SCREEN_H+((j-1)/3-3)*TILE_TAILLE;
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
    }
	id = getIdSel(aff->jeu);
	char str[15];
    SDL_Texture * texture;
	if(id != 0){
        if(id < 0){
            /*Affichage unite formable par le batiment */
            Batiment* b = getBat(aff->jeu,-getIdSel(aff->jeu));
            BatBase* type = getTypeBat(b);
            for(j = 0; j < getNbUniteFormable(type);j++){
                num_tile = getTileUnite(getUniteFormable(aff->jeu,getUnitFormableBat(type,j)));
                rect_Dest.x = SCREEN_W+(j%3-3)*TILE_TAILLE;
                rect_Dest.y = SCREEN_H+(j/3-3)*TILE_TAILLE+5;
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
                num_tile = 91 + getOuvrier(getUniteFormable(aff->jeu,getUnitFormableBat(type,j)));
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
            }
            /* affichage nom */
            texte = TTF_RenderText_Solid(aff->font,getNomBat(type),blanc);
            texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_FreeSurface(texte);
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            rect_Dest.x = (SCREEN_W-tX)/2;
            rect_Dest.y = (SCREEN_H-HUD_H+tY);
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
            SDL_DestroyTexture(texture);
            /*affichage vie */
            sprintf(str, "%d / %d",getVieCouranteBat(b),getVieMaxBat(type));
            texte = TTF_RenderText_Solid(aff->font,str,rouge);
            texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_FreeSurface(texte);
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            rect_Dest.x = (SCREEN_W-2*tX)/2;
            rect_Dest.y = (SCREEN_H-HUD_H+2*tY);
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
            SDL_DestroyTexture(texture);
            if(regardeTeteFile(getTabAttente(b)) != NULL){
                /*affichage file d'attente */
                Cellule* c = getPremier(getTabAttente(b));
                i = 0;
                texte = TTF_RenderText_Solid(aff->font,"En Formation:",blanc);
                texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
                SDL_FreeSurface(texte);
                rect_Dest.x += tX+TILE_TAILLE/2;
                SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
                rect_Dest.w = tX;
                rect_Dest.h = tY;
                SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
                SDL_DestroyTexture(texture);
                rect_Dest.w = TILE_TAILLE;
                rect_Dest.h = TILE_TAILLE;
                rect_Dest.x += tX;
                rect_Dest.y -= TILE_TAILLE/2;
                num_tile = getTileUnite(getElement(c));
                SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
                rect_Dest.y += TILE_TAILLE;
                while(getSuivant(c) != NULL && i < 8){
                    c = getSuivant(c);
                    num_tile = getTileUnite(getElement(c));
                    rect_Dest.x = SCREEN_W/2-3*TILE_TAILLE + i*TILE_TAILLE;
                    SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
                    i++;
                }
            }
        }
        else{
            /* Affichage Nom */
            Unite* u = getUnite(aff->jeu,getIdSel(aff->jeu));
            UniteBase* type = getTypeUnite(u);
            texte = TTF_RenderText_Solid(aff->font,getNom(type),blanc);
            texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_FreeSurface(texte);
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            rect_Dest.x = (SCREEN_W-tX)/2;
            rect_Dest.y = (SCREEN_H-HUD_H+tY);
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
            SDL_DestroyTexture(texture);

            /* Affichage vie*/
            sprintf(str, "%d / %d",getVieCouranteUnite(u),getVieMaxUnite(type));
            texte = TTF_RenderText_Solid(aff->font,str,rouge);
            texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_FreeSurface(texte);
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            rect_Dest.x = (SCREEN_W-2*tX)/2;
            rect_Dest.y = (SCREEN_H-HUD_H+2*tY);
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
            SDL_DestroyTexture(texture);

            /*Affichage pierre Porte*/
            sprintf(str, "Pierre : %d / %d",getPierrePorte(u),getRessourceMax(type));
            texte = TTF_RenderText_Solid(aff->font,str,blanc);
            texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_FreeSurface(texte);
            rect_Dest.x += tX + TILE_TAILLE/2;
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            rect_Dest.y = (SCREEN_H-HUD_H+2*tY);
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
            SDL_DestroyTexture(texture);

            /*Affichage mithril Porte*/
            sprintf(str, "Mithril : %d / %d",getMithrilPorte(u),getRessourceMax(type));
            texte = TTF_RenderText_Solid(aff->font,str,blanc);
            texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
            SDL_FreeSurface(texte);
            rect_Dest.y += tY;
            SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
            rect_Dest.w = tX;
            rect_Dest.h = tY;
            SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
            SDL_DestroyTexture(texture);
        }
	}

    /*Affichage nom joueur */
    texte = TTF_RenderText_Solid(aff->font,getNomJoueur(getJoueur(aff->jeu, getVueJoueur(aff->jeu))),vert);
    texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
    SDL_FreeSurface(texte);
    SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
    if(tX > (TILE_TAILLE*2-4)){
        tY *= ((TILE_TAILLE*200)/tX);
        tY /= 100;
        tX = TILE_TAILLE*2 - 8;
    }
    rect_Dest.w = tX;
    rect_Dest.h = tY;
    rect_Dest.x = TILE_TAILLE*4-tX/2;
    rect_Dest.y = (SCREEN_H-HUD_H+tY/2);
    SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
    SDL_DestroyTexture(texture);

    /*affichage pierre du joueur */
    sprintf(str,"pierre: %d", getPierreJoueur(getJoueur(aff->jeu, getVueJoueur(aff->jeu))));
    texte = TTF_RenderText_Solid(aff->font,str,blanc);
    texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
    SDL_FreeSurface(texte);
    rect_Dest.y += tY;
    SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
    if(tX > (TILE_TAILLE*2-4)){
        tY *= ((TILE_TAILLE*200)/tX);
        tY /= 100;
        tX = TILE_TAILLE*2 - 8;
    }
    rect_Dest.w = tX;
    rect_Dest.h = tY;
    rect_Dest.x = TILE_TAILLE*4-tX/2;
    SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
    SDL_DestroyTexture(texture);

    /*affichage mithril du joueur */
    sprintf(str,"mithril: %d", getMithrilJoueur(getJoueur(aff->jeu, getVueJoueur(aff->jeu))));
    texte = TTF_RenderText_Solid(aff->font,str,blanc);
    texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
    SDL_FreeSurface(texte);
    rect_Dest.y += tY;
    SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
    if(tX > (TILE_TAILLE*2-4)){
        tY *= ((TILE_TAILLE*200)/tX);
        tY /= 100;
        tX = TILE_TAILLE*2 - 8;
    }
    rect_Dest.w = tX;
    rect_Dest.h = tY;
    rect_Dest.x = TILE_TAILLE*4-tX/2;
    SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
    SDL_DestroyTexture(texture);

     /*affichage nourriture du joueur */
    sprintf(str,"armée: %d/%d", getNourritureCourante(getJoueur(aff->jeu, getVueJoueur(aff->jeu))), getNourritureMax(getJoueur(aff->jeu, getVueJoueur(aff->jeu))));
    texte = TTF_RenderUTF8_Solid(aff->font,str,blanc);
    texture = SDL_CreateTextureFromSurface(aff->renderer,texte);
    SDL_FreeSurface(texte);
    rect_Dest.y += tY;
    SDL_QueryTexture(texture, NULL, NULL, &tX, &tY);
    if(tX > (TILE_TAILLE*2-4)){
        tY *= ((TILE_TAILLE*200)/tX);
        tY /= 100;
        tX = TILE_TAILLE*2 - 8;
    }
    rect_Dest.w = tX;
    rect_Dest.h = tY;
    rect_Dest.x = TILE_TAILLE*4-tX/2;
    SDL_RenderCopy(aff->renderer,texture,NULL,&rect_Dest);
    SDL_DestroyTexture(texture);
    if(getBatConstruction(getJoueur(aff->jeu, getVueJoueur(aff->jeu))) != NULL){
        if(ySouris < (SCREEN_H-HUD_H)){
                rect_Dest.w = TILE_TAILLE;
                rect_Dest.h = TILE_TAILLE;
            for(i= 0; i < getTailleCaseX(getBatConstruction(getJoueur(aff->jeu, getVueJoueur(aff->jeu)))); i++){
                for(j= 0; j < getTailleCaseY(getBatConstruction(getJoueur(aff->jeu, getVueJoueur(aff->jeu)))); j++){
                    rect_Dest.x = (xSouris/TILE_TAILLE + i)*TILE_TAILLE;
                    rect_Dest.y = (ySouris/TILE_TAILLE + j)*TILE_TAILLE;
                    if(rect_Dest.x > 0 && rect_Dest.x < SCREEN_W
                    && rect_Dest.y > 0 && rect_Dest.y < (SCREEN_H-HUD_H)){
                        num_tile = getTileBat(getBatConstruction(getJoueur(aff->jeu, getVueJoueur(aff->jeu))));
                        num_tile += i+j*getTailleCaseX(getBatConstruction(getJoueur(aff->jeu, getVueJoueur(aff->jeu))));
                        SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
                    }
                }
            }
        }
    }
    SDL_RenderPresent(aff->renderer);
    SDL_Delay(1000/60);
}

void afficheMenu(const Affichage* aff, int menu){
    int i,j;
    SDL_Rect rect_Dest;
    int num_tile;
    rect_Dest.h = TILE_TAILLE;
    rect_Dest.w = TILE_TAILLE;
    for(i = 0; i < aff->nbTileCamX; i++){
        for(j = 0; j < aff->nbTileCamY; j++){
            num_tile = 99;
            rect_Dest.x = i*TILE_TAILLE;
            rect_Dest.y = j*TILE_TAILLE;
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
        }
    }
    for(i = 0; i < 3; i++){
        for(j=0; j < 3; j++){
            num_tile = (40+10*(menu%3))+i*3+j;
            if(menu == 2){
                num_tile = (63+i*3+j);
                if(i == 2)
                    num_tile = (46+j);
            }
            else if(menu == 3){
                if(i == 0)
                    num_tile = 60+j;
                else
                    num_tile = 66-i*10+j;
            }
            rect_Dest.x = (((SCREEN_W-3*TILE_TAILLE)/2))+j*TILE_TAILLE;
            rect_Dest.y = 3*TILE_TAILLE+i*TILE_TAILLE;
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
        }
    }
    for(i = 0; i < 10; i++){
        for(j = 0; j < 2; j++){
            num_tile = 70+j*10+i;
            rect_Dest.x = (((SCREEN_W-10*TILE_TAILLE)/2))+i*TILE_TAILLE;
            rect_Dest.y = j*TILE_TAILLE;
            SDL_RenderCopy(aff->renderer,aff->tileSet_Texture,&(aff->tileSet[num_tile].r),&rect_Dest);
        }
    }
    SDL_RenderPresent(aff->renderer);
    SDL_Delay(1000/60);
}
