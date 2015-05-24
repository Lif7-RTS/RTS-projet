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
#include "filePath.h"
#ifndef _TABDYN
#define _TABDYN

struct STabDyn{
    uintptr_t* tab; /*!< tableau dynamique de pointeur */
    int taille;/*!< taille du tableau */
    int utilisee;/*!< nombre de case du tableau utilisee*/
    FilePath* caseARemplir; /*!< File des prochaines cases a remplir, si vide, remplit à la fin du tableau */
};
typedef struct STabDyn TabDyn;

/* *************************************************************--Init--***************************************************************************** */

/**
 * \fn void initTabDyn(TabDyn* t,int taille)
 * \brief  initialisation d'un tableau dynamique
 * \param[in,out] t pointeur sur un tabDyn
 * \param taille taille de départ du tableau
 */
void initTabDyn(TabDyn* t,int taille);

/**
 * \fn int supprimerElemTabDyn(TabDyn* t, int index)
 * \brief supprime un element dans le tableau
 * \param[in,out] t pointeur sur un tabDyn
 * \param index position du pointeur a supprimer
 * \return 1 si la suppression, 0 sinon (tab[index] déjà == NULL ou non existant)
 */
int supprimerElemTabDyn(TabDyn* t, int index);


/**
 * \fn void detruireTabDyn(TabDyn* t)
 * \brief detruit le tableau dynamique
 * \param[in,out] t pointeur sur un tabDyn
 */
void detruireTabDyn(TabDyn* t);

/* *************************************************************--GET--***************************************************************************** */

/**
 * \fn uintptr_t getElemTabDyn(TabDyn* t, int i)
 * \brief renvoi le i-ieme element du tableau
 * \param[in,out] t pointeur sur un tabDyn
 * \param i element a renvoyer
 * \return t->tab[i]
 */
uintptr_t getElemTabDyn(TabDyn* t, int i);

/**
 * \fn int getTailleTabDyn(TabDyn* t)
 * \brief accesseur sur Taille
 *
 * \param[in,out] t pointeur sur un tabDyn
 * \return un entier correspondant à la taille maximal du TabDyn
 */
int getTailleTabDyn(TabDyn* t);

/**
 * \fn int getUtiliseTabDyn(TabDyn* t)
 * \brief accesseur sur utilisee
 *
 * \param[in,out] t pointeur sur un tabDyn
 * \return un entier correspondant à l'espace utilisé dans le TabDyn
 */
int getUtiliseTabDyn(TabDyn* t);

/**
 * \fn FilePath* getFileCaseARemplir(TabDyn* t)
 * \brief accesseur sur CaseARemplir
 *
 * \param[in,out] t pointeur sur un tabDyn
 * \return la file des prochaines Cases a remplir.
 */
FilePath* getFileCaseARemplir(TabDyn* t);

/* *************************************************************--SET--***************************************************************************** */

/**
 * \fn void setTailleTabDyn(TabDyn* t, int taille)
 * \brief mutateur sur Taille
 *
 * \param[in,out] t pointeur sur un tabDyn
 * \param[in] un entier
 */
void setTailleTabDyn(TabDyn* t, int taille);

/**
 * \fn void setUtiliseTabDyn(TabDyn* t, int utilisee)
 * \brief mutateur sur utilisee
 *
 * \param[in,out] t pointeur sur un tabDyn
 * \param[in] un entier
 */
void setUtiliseTabDyn(TabDyn* t, int utilisee);

/**
 * \fn void setFileCaseARemplir(TabDyn* t, FilePath* f)
 * \brief mutateur sur CaseARemplir
 *
 * \param[in,out] t pointeur sur un tabDyn
 * \param la file des prochaines Cases a remplir.
 */
void setFileCaseARemplir(TabDyn* t, FilePath* f);

/* *************************************************************--FCT--***************************************************************************** */

/**
 * \fn int ajouterTabDyn(TabDyn* t, uintptr_t ptr)
 * \brief  ajoute un element dans le tableau
 * \param[in,out] t pointeur sur un tabDyn
 * \param ptr pointeur a ajouter dans le tableau
 * \return 1 si l'ajout a reussi, 0 sinon (erreur de realloc)
 */
int ajouterTabDyn(TabDyn* t, uintptr_t ptr);

#endif /* _TABDYN */
