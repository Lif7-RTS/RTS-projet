/**
* \file tabDyn.c
* \brief structure tabDyn
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 16/04/2015
*
* tableau Dynamique de pointeur
*/

#include "tabDyn.h"


void initTabDyn(TabDyn* t,int taille){
    t->utilisee = 0;
    t->taille = taille;
    t->tab = (uintptr_t*) malloc(sizeof(uintptr_t)*taille);
    return;
}

int ajouterTabDyn(TabDyn* t, uintptr_t ptr){
    if(t->utilisee == t->taille){
        uintptr_t* ptr_realloc;
        ptr_realloc = realloc(t->tab, sizeof(uintptr_t)*(t->taille)*2);
        if(ptr_realloc == NULL){
            printf("erreur realloc !");
            return 0;
        }
        t->tab = ptr_realloc;
        t->taille *= 2;
    }
    t->tab[t->utilisee] = ptr;
    t->utilisee++;
    return 1;

}

int supprimerElemTabDyn(TabDyn* t, uintptr_t ptr){
    int i;
    int k = 0;
    uintptr_t* ptr_realloc;
    for(i = 0; i < t->utilisee; i++){
        if(t->tab[i] != ptr){
            t->tab[k] = t->tab[i];
            k++;
        }
    }
    if(t->utilisee < (t->taille)/3){
        ptr_realloc = realloc(t->tab,sizeof(uintptr_t)/2);
        if(ptr_realloc == NULL){
            printf("erreur realloc !");
            return 0;
        }
        t->tab = ptr_realloc;
        t->taille /= 2;
    }
    return 1;
}

void detruireTabDyn(TabDyn* t){
    free(t->tab);
    t->taille = 0;
    t->utilisee = 0;
}

uintptr_t getElemTabDyn(TabDyn* t, int i){
    if(i < t->utilisee)
        return t->tab[i];
    return (uintptr_t)(void*)NULL;
}
