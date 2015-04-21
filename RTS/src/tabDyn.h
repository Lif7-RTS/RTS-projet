/**
* \file tabDyn.h
* \brief structure tabDyn
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 16/04/2015
*
* tableau Dynamique de pointeur
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#ifndef _TABDYN
#define _TABDYN

struct STabDyn{
    uintptr_t* tab; /*!< tableau dynamique de pointeur */
    int taille;/*!< taille du tableau */
    int utilisee;/*!< nombre de case du tableau utilisee*/
};

typedef struct STabDyn TabDyn;

/**
 * \fn void initTabDyn(TabDyn* t,int taille)
 * \brief  initialisation d'un tableau dynamique
 * \param[in,out] t pointeur sur un tabDyn
 * \param taille taille de départ du tableau
 */
void initTabDyn(TabDyn* t,int taille);


/**
 * \fn int ajouterTabDyn(TabDyn* t, uintptr_t ptr)
 * \brief  ajoute un element dans le tableau
 * \param[in,out] t pointeur sur un tabDyn
 * \param ptr pointeur a ajouter dans le tableau
 * \return 1 si l'ajout a reussi, 0 sinon (erreur de realloc)
 */
int ajouterTabDyn(TabDyn* t, uintptr_t ptr);

/**
 * \fn int supprimerElemTabDyn(TabDyn* t, uintptr_t ptr)
 * \brief supprime un element dans le tableau
 * \param[in,out] t pointeur sur un tabDyn
 * \param ptr pointeur a supprimer du tableau
 * \return 1 si l'ajout a reussi, 0 sinon (erreur de realloc)
 */
int supprimerElemTabDyn(TabDyn* t, uintptr_t ptr);

/**
 * \fn void detruireTabDyn(TabDyn* t)
 * \brief detruit le tableau dynamique
 * \param[in,out] t pointeur sur un tabDyn
 */
void detruireTabDyn(TabDyn* t);

/**
 * \fn uintptr_t getElemTabDyn(TabDyn* t, int i)
 * \brief renvoi le i-ieme element du tableau
 * \param[in,out] t pointeur sur un tabDyn
 * \param i element a renvoyer
 * \return t->tab[i]
 */
uintptr_t getElemTabDyn(TabDyn* t, int i);
#endif /* _TABDYN */
