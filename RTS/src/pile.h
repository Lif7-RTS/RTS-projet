/**
 * \file unite.h
 * \brief module unite
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module representant une unite
 *
 */

#include <stdlib.h>
#include <stdio.h>
#ifndef _PILE
#define _PILE


/**
 * \struct Pile
 * \brief Objet Pile
 *
 * Pile est une pile d'entier
 */

struct SElement{
     int valeur; /*!< valeur d'un element de la pile */
     struct SElement* suivant; /*!< element suivant dans la pile */
};
typedef struct SElement Element;
struct SPile{
     Element* sommet; /*!< premier element de la pile */
};
typedef struct SPile Pile;

/* ***********************************************************--Init--*************************************************************************** */

/**
* \fn void initPile (Pile* pile)
* \brief initialise une pile
*
* \param[in, out] pile pointeur sur une structure Pile
*/
void initPile(Pile* pile);

/**
* \fn void detruirePile(Pile* pile)
* \brief detruit et libère tout les élément d'une pile
*
* \param[in, out] pile pointeur sur une structure Pile
*/
void detruirePile(Pile* pile);
/* *************************************************************--GET--***************************************************************************** */

/* *************************************************************--SET--***************************************************************************** */

/* *************************************************************--FCT en écriture--***************************************************************************** */

/**
* \fn void empilePile(Pile* pile,int valeur)
* \brief empile un element au sommet d'une pile
*
* \param[in, out] pile pointeur sur une structure Pile
* \param[in] valeur est la valeur de l'element à emplier
*/
 void empilePile(Pile* pile,int valeur);

 /**
* \fn  void depilePile(Pile* pile)
* \brief depile un element du sommet d'une pile
*
* \param[in, out] pile pointeur sur une structure Pile
*/
 void depilePile(Pile* pile);

 /**
* \fn  void depilePile(Pile* pile)
* \brief depile un element du sommet d'une pile
*
* \param[in, out] pile pointeur sur une structure Pile
* \return la valeur de l'element au sommet de la pile
*/
int regarderSommet(Pile* pile);

#endif /* _PILE */
