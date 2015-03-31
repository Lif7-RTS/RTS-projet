/**
 * \file case.h
 * \brief module case
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module represantant une case de la carte.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#ifndef _CASE
#define _CASE

/**
 * \struct sCase
 * \brief Objet Case
 *
 * sCase est un objet case, composant le terrain
 */
struct SCase{
    int acces; /*!< 1 si case accessible, 0 sinon */
    int pierre; /*!< nombre de ressource pierre disponible */
    int mithril; /*!< nombre de ressource mithril disponible */
    int idContenu; /*!< id (unique) du contenu de la case */
}
typedef struct SCase sCase;

/**
 * \fn void init(sCase* c,int p, int m, int acc)
 * \brief initialise une case
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in] p pierre dans la case
 * \param[in] m mithril dans la case
 * \param[in] acc 1 si case accessible, 0 sinon
 */

void init(sCase* c,int p, int m, int acc);
/**
 * \fn int getContenu (sCase* c)
 * \brief accesseur idContenu
 *
 * \param c pointeur sur sCase
 * \return idContenu
 */
int getContenu(sCase* c);

/**
 * \fn int getPierre (sCase* c)
 * \brief accesseur pierre
 *
 * \param c pointeur sur sCase
 * \return pierre
 */
 int getPierre(sCase* c);

 /**
 * \fn int getMithril (sCase* c)
 * \brief accesseur Mithril
 *
 * \param c pointeur sur sCase
 * \return mithril
 */
 int getMithril(sCase* c);

 /**
 * \fn bool getAcces (sCase* c)
 * \brief accesseur pierre
 *
 * \param[in, out] c pointeur sur sCase
 * \return access
 */
 int getAcces(sCase* c);

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
 void setPierre(sCase* c, int p);

 /**
 * \fn void setMithril (sCase* c,int m)
 * \brief mutateur mithril
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in] m mithril dans la case
 */
 void setMithril(sCase* c, int m);

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

void prendrePierre(sCase* c, unite* ouvrier);

/**
 * \fn void prendreMithril(sCase* c, unite* ouvrier)
 * \brief retire de la ressource mithril de la case et la donne a l'unite
 *
 * \param[in, out] c pointeur sur sCase
 * \param[in, out] ouvrier pointeur sur l'unite qui mine
 */

void prendreMithril(sCase* c, unite* ouvrier);

#endif /* _CASE */

