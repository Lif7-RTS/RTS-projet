/**
 * \file case.h
 * \brief module case
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module representant une case de la carte.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "uniteBase.h"
#include "unite.h"


#ifndef _CASE
#define _CASE


/**
 * \struct SCase
 * \brief Objet Case
 *
 * sCase est un objet case, composant le terrain
 */
struct SCase{
    int acces; /*!< 1 si case accessible, 0 sinon */
    int pierre; /*!< nombre de ressource pierre disponible */
    int mithril; /*!< nombre de ressource mithril disponible */
    int idContenu; /*!< id (unique) du contenu de la case (positif unite, negatif batiment, 0 vide) */
};

typedef struct SCase sCase;


/**
 * \fn void initCase(sCase* c,int p, int m, int acc)
 * \brief initialise une case
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in] p pierre dans la case
 * \param[in] m mithril dans la case
 * \param[in] acc 1 si case accessible, 0 sinon
 */
void initCase(sCase* c,int p, int m, int acc);
/**
 * \fn int getContenu (sCase* c)
 * \brief accesseur idContenu
 *
 * \param c pointeur sur sCase
 * \return idContenu
 */
int getContenu(const sCase* c);

/**
 * \fn int getPierre (sCase* c)
 * \brief accesseur pierre
 *
 * \param c pointeur sur sCase
 * \return pierre
 */
 int getPierreCase(const sCase* c);

 /**
 * \fn int getMithril (sCase* c)
 * \brief accesseur Mithril
 *
 * \param c pointeur sur sCase
 * \return mithril
 */
 int getMithrilCase(const sCase* c);

 /**
 * \fn bool getAcces (sCase* c)
 * \brief accesseur pierre
 *
 * \param[in, out] c pointeur sur sCase
 * \return access
 */
 int getAcces(const sCase* c);

 /**
 * \fn void setContenu (sCase* c,int id)
 * \brief mutateur idContenu
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in] id id unique du contenu de la case
 */
 void setContenu(sCase* c, int id);

  /**
 * \fn void setPierre (sCase* c,int p)
 * \brief mutateur pierre
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in] p pierre dans la case
 */
 void setPierreCase(sCase* c, int p);

 /**
 * \fn void setMithril (sCase* c,int m)
 * \brief mutateur mithril
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in] m mithril dans la case
 */
 void setMithrilCase(sCase* c, int m);

/**
 * \fn void setAcces (sCase* c,int m)
 * \brief mutateur acces
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in] acc 1 si case accessible, 0 sinon
 */
 void setAcces(sCase* c, int acc);

/**
 * \fn void prendrePierre(sCase* c, unite* ouvrier)
 * \brief retire de la ressource pierre de la case et la donne a l'unite
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in, out] ouvrier pointeur sur l'unite qui mine
 */

void prendrePierre(sCase* c, Unite* ouvrier);

/**
 * \fn void prendreMithril(sCase* c, unite* ouvrier)
 * \brief retire de la ressource mithril de la case et la donne a l'unite
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in, out] ouvrier pointeur sur l'unite qui mine
 */

void prendreMithril(sCase* c, Unite* ouvrier);


/* *************************************************************--FCT--***************************************************************************** */

/**
 * \fn int memeCase(int x1, int y1, int x2, int y2)
 * \brief compare deux case
 *
 * \param[in] x1 est un entier coordonée d'une case
 * \param[in] y1 est un entier coordonée d'une case
 * \param[in] x2 est un entier coordonée d'une case
 * \param[in] y2 est un entier coordonée d'une case
 * \return un entier (1 si les case sont égale, 0 sinon)
 */
int memeCase(int x1, int y1, int x2, int y2);

#endif /* _CASE */

