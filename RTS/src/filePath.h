/**
 * \file filePath.h
 * \brief module unite
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * une File utilisée pour le Pathfinding des unités
 *
 */


#include <stdlib.h>
#include <stdio.h>
#ifndef _FILEPATH
#define _FILEPATH

typedef struct SCellulePath CellulePath;
struct SCellulePath{
     int element; /*!< element dans la cellule */
     CellulePath* suivant; /*!< pointeur sur la cellule suivante */
};


struct SFilePath{
     CellulePath* prem; /*!< première element de la file d'attente */
     CellulePath* dernier; /*!< dernier element de la file d'attente */
};
typedef struct SFilePath FilePath;

/* ************************************************************--INIT--***************************************************************************** */

/**
* \fn void initFile (FilePath* file)
* \brief initialise une file
*
* \param[in, out] file pointeur sur une structure File
*/
void initFilePath(FilePath* file);

/**
* \fn void initCellule (FilePath* file)
* \brief initialise une cellule
*
* \param[in, out] cell pointeur sur une structure Cellule
*/
void initCellulePath(CellulePath* cell);

/**
* \fn void detruireFile (FilePath** file)
* \brief detruit une file et libere ses élements
*
* \param[in, out] file pointeur sur une structure File.
*/
void detruireFilePath(FilePath* file);

/**
* \fn void detruireCellule (CellulePath** cell)
* \brief detruit une cellule.
*
* \param[in, out] cell est un  pointeur sur une structure Cellule
*/
void detruireCellulePath(CellulePath* cell);

/* *************************************************************--GET--***************************************************************************** */

/**
* \fn CellulePath* getPremier(const FilePath* file)
* \brief accesseur prem
*
* \param[in, out] file pointeur sur une structure File
* \return un pointeur sur la première cellule de la file d'attente.
*/
CellulePath* getPremierPath(const FilePath* file);

/**
* \fn int getElement(CellulePath* cell)
* \brief mutateur element
*
* \param[in, out] cell est un pointeur sur une cellule
* \return un entier
*/
int getElementPath(CellulePath* cell);

/**
* \fn CellulePath* getSuivant(CellulePath* cell)
* \brief mutateur suivant
*
* \param[in, out] cell est un pointeur sur une cellule
* \return un pointeur sur une structure Cellule.
*/
CellulePath* getSuivantPath(CellulePath* cell);


/**
* \fn CellulePath* getDernier(const FilePath* file)
* \brief accesseur prem
*
* \param[in, out] file pointeur sur une structure File
* \return un pointeur sur la Dernière cellule de la file d'attente.
*/
CellulePath* getDernierPath(const FilePath* file);

/* *************************************************************--SET--***************************************************************************** */

/**
* \fn setPremier (FilePath* file, CellulePath* premier)
* \brief mutateur prem
*
* \param[in, out] file pointeur sur une structure File
* \param[in, out] premier est un pointeur sur une Cellule.
*/
void setPremierPath(FilePath* file, CellulePath* premier);

/**
* \fn void setElement(FilePath* file, int element)
* \brief mutateur element
*
* \param[in, out] cell est un pointeur sur une cellule
* \param[in, out] element est un pointeur sur un element UniteBase.
*/
void setElementPath(CellulePath* cell, int element);

/**
* \fn void setSuivant(CellulePath* cell, CellulePath* suiv)
* \brief mutateur suivant
*
* \param[in, out] cell est un pointeur sur une cellule
* \param[in, out] suiv est un pointeur sur une structure Cellule.
*/
void setSuivantPath(CellulePath* cell, CellulePath* suiv);

/**
* \fn setDernier(FilePath* file, CellulePath* dernier)
* \brief mutateur prem
*
* \param[in, out] file pointeur sur une structure File
* \param[in, out] dernier est un pointeur sur une Cellule.
*/
void setDernierPath(FilePath* file, CellulePath* Dernier);

/* *************************************************************--FCT--***************************************************************************** */

/**
* \fn void enfilePath(FilePath* f, int element)
* \brief positione un nouvel element en fin de file d'attente
*
* \param[in, out] file pointeur sur une structure File
* \param[in, out] element est un pointeur sur une UniteBase.
*/
void enfilePath(FilePath* f, int element);

/**
* \fn void defilePath(FilePath* f)
* \brief suprime le premier element de la file
*
* \param[in, out] file pointeur sur une structure File.
*/
void defilePath(FilePath* f);

/**
* \fn int regardeTetefilePath(const FilePath* f)
* \brief renvoi le premier element de la file
*
* \param[in, out] file pointeur sur une structure File
* \return un entier
*/
int regardeTeteFilePath(const FilePath* f);

#endif /* _FILEPATH */
