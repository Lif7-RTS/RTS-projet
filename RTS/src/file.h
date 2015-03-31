/**
* \file file.h
* \brief structure file et structure cellule
* \author Adrien Baud & Diego Roussel
* \version 1.1
* \date 31/03/2015
*
*Structure representant une file.
*/

#include <stdio.h>
#include <stdlib.h>
#include "uniteBase.h"
#ifndef _FILE
#define _FILE

struct SCellule{
     UniteBase* element; /*!< element dans la cellule */
     Cellule* suivant; /*!< poiteur sur la cellule suivante */
     Cellule* precedent; /*!<pointeur sur la cellule précédente */
};
typedef struct SCellule Cellule;

struct SFile{
     CelluleUB* prem; /*!< première element de la file d'attente */
};
typedef struct SFile File;

/* ************************************************************--INIT--***************************************************************************** */

/**
* \fn void initFile (File* file, const UniteBase* element)
* \brief initialise une file
*
* \param[in, out] file pointeur sur une structure File
* \param[in, out] premier est un pointeur sur une UniteBase.
*/
void initFile (File* file, const UniteBase* element);

/**
* \fn void initCellule (File* file, const UniteBase* element)
* \brief initialise une cellule
*
* \param[in, out] cell pointeur sur une structure Cellule
* \param[in, out] un pointeur sur la première cellule de la file d'attente.
*/
void initCellule (Cellule* cell, const UniteBase* element);

/**
* \fn void detruireFile (File** file)
* \brief detruit une file et libere ses élements
*
* \param[in, out] file pointeur sur une structure File.
*/
void detruireFile (File** file);

/**
* \fn void detruireCellule (Cellule** cell)
* \brief detruit une cellule.
*
* \param[in, out] cell est un  pointeur sur une structure Cellule
*/
void detruireCellule (Cellule** cell);

/* *************************************************************--GET--***************************************************************************** */

/**
* \fn int getIdBat(Batiment* bat)
* \brief accesseur prem
*
* \param[in, out] file pointeur sur une structure File
* \return un pointeur sur la première cellule de la file d'attente.
*/
CelluleUB* getPremier(const File* file);

/**
* \fn void getElement(Cellule* cell)
* \brief mutateur element
*
* \param[in, out] cell est un pointeur sur une cellule
* \return un pointeur sur un element UniteBase.
*/
UniteBase* getElement(Cellule* cell);

/**
* \fn void getSuivant(Cellule* cell)
* \brief mutateur suivant
*
* \param[in, out] cell est un pointeur sur une cellule
* \return un pointeur sur une structure Cellule.
*/
Cellule* getSuivant(Cellule* cell);

/**
* \fn void setPrecedent(Cellule* cell, const Cellule* prece)
* \brief mutateur suivant
*
* \param[in, out] cell est un pointeur sur une cellule
* \return un pointeur sur une structure Cellule.
*/
Cellule* getPrecedent(Cellule* cell);

/* *************************************************************--SET--***************************************************************************** */

/**
* \fn void setPremier (File* file, const CelluleUB* premier)
* \brief mutateur prem
*
* \param[in, out] file pointeur sur une structure File
* \param[in, out] premier est un pointeur sur un element UniteBase.
*/
void setPremier (File* file, const UniteBase* premier);

/**
* \fn void setElement(File* file, const UniteBase* element)
* \brief mutateur element
*
* \param[in, out] cell est un pointeur sur une cellule
* \param[in, out] element est un pointeur sur un element UniteBase.
*/
void setElement(Cellule* cell, const UniteBase* element);

/**
* \fn void setSuivant(Cellule* cell, const Cellule* suiv)
* \brief mutateur suivant
*
* \param[in, out] cell est un pointeur sur une cellule
* \param[in, out] suiv est un pointeur sur une structure Cellule.
*/
void setSuivant(Cellule* cell, const Cellule* suiv);

/**
* \fn void setPrecedent(Cellule* cell, const Cellule* prece)
* \brief mutateur suivant
*
* \param[in, out] cell est un pointeur sur une cellule
* \param[in, out] prece est un pointeur sur une structure Cellule.
*/
void setPrecedent(Cellule* cell, const Cellule* prece);

/* *************************************************************--FCT--***************************************************************************** */

/**
* \fn void enfile(File* f, const Unite* element)
* \brief positione un nouvel element en fin de file d'attente
*
* \param[in, out] file pointeur sur une structure File
* \param[in, out] element est un pointeur sur une UniteBase.
*/
void enfile(File* f, const UniteBase* element);

/**
* \fn void defile(File* f)
* \brief suprime le premier element de la file
*
* \param[in, out] file pointeur sur une structure File.
*/
void defile(File* f);

/**
* \fn void defile(File* f)
* \brief renvoi le premier element de la file
*
* \param[in, out] file pointeur sur une structure File
* \return un poiteur sur une UniteBase.
*/
UniteBase* regardeTeteFile(const File* f);

#endif /* _FILE */
