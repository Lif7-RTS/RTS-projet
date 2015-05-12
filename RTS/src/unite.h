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
#include <time.h>

#include "pile.h"
#include "uniteBase.h"




#ifndef _UNITE
#define _UNITE

typedef struct SUnite Unite;

#include "terrain.h"
/**
 * \struct SUnite
 * \brief Objet Unite
 *
 * SUnite objet representant une unite.
 */

struct SUnite{
    int id;/*!< id (unique) de l'unite*/
    int posX;/*!< position X de l'unite ( en case )*/
    int posY;/*!<position Y de l'unite ( en case ) */
    int vieCourante; /*!< vie de l'unite actuellement */
    int deplacement;/*!< 1 si l'unite est en deplacement, 0 sinon */
    UniteBase* type;/*!< archetype de l'unite */
    int posCibleX; /*!< X de la position cible par l'unite ( case )*/
    int posCibleY;/*!< Y de la position cible par l'unite ( case )*/
    int pierrePorte;/*!< pierre transporte par l'unite */
    int mithrilPorte;/*!< mithril tranporte par l'unite*/
    Pile* chemin; /*!< tableau de case que l'unite parcours */
    clock_t timerUnite; /*!< date du dernier deplacement de l'unite */
};

/* *************************************************************--Init--***************************************************************************** */

 /**
 * \fn  void initUnite(Unite* unit, const UniteBase* type)
 * \brief fonction d'initialisation de la structure Unite
 *
 * \param[in, out] unit pointeur sur Unite
 * \param[in, out] type pointeur sur UniteBase
 */
 void initUnite(Unite* unit, const UniteBase* type);

/* *************************************************************--GET--***************************************************************************** */

 /**
 * \fn int getId (Unite* unit)
 * \brief accesseur id
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant à un identifiant unique
 */
 int getId(const Unite* unit);

 /**
 * \fn int getPosX (Unite* unit)
 * \brief accesseur posX
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant à une coordonnée d'axe X
 */
 int getPosX(const Unite* unit);


 /**
 * \fn int getPosY (Unite* unit)
 * \brief accesseur posY
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant à une coordonnée d'axe Y
 */
 int getPosY(const Unite* unit);

 /**
 * \fn int getVieCouranteUnite(Unite* unit)
 * \brief accesseur vieCourante
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant au nombre de point de vie actuel de l'unite
 */
 int getVieCouranteUnite(const Unite* unit);


 /**
 * \fn int getDeplacement(Unite* unit,int d)
 * \brief accesseur deplacement
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant a l'etat de deplacement de l'unité (1 si en deplacement, 0 sinon)
 */
 int getDeplacement(const Unite* unit);

/**
 * \fn UniteBase* getTypeUnite(Unite* unit)
 * \brief accesseur type
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un pointeur sur UniteBase correspondant au type de l'unite
 */
 UniteBase* getTypeUnite(const Unite* unit);

/**
 * \fn int getPosCibleX(Unite* unit)
 * \brief accesseur posCibleX
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant à la coordonnée X de la cible de l'unité
 */
 int getPosCibleX(const Unite* unit);

 /**
 * \fn int getPosCibleY(Unite* unit)
 * \brief accesseur posCibleY
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant à la coordonnée Y de la cible de l'unité
 */
 int getPosCibleY(const Unite* unit);

  /**
 * \fn int getPierrePorte(Unite* unit)
 * \brief accesseur pierrePorte
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant au nombre de resource de pierre que porte l'unite
 */
 int getPierrePorte(const Unite* unit);

   /**
 * \fn int getMithrilPorte(Unite* unit)
 * \brief accesseur mithrilPorte
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant au nombre de ressource de mithril que porte l'unite
 */
 int getMithrilPorte(const Unite* unit);

 /**
 * \fn  int getChemin(const Unite* unit)
 * \brief accesseur chemin
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un poiteur sur une pile correspondant au chemin que doit parcourir l'unité
 */
 Pile* getChemin(const Unite* unit);

 /**
 * \fn  clock_t getTimerUnite(const Unite* unit)
 * \brief accesseur timerUnite
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un temps en nombre de tick d''horloge depuis le lancement du jeu, correspondant au deplacement de l'unité
 */
clock_t getTimerUnite(const Unite* unit);

/* *************************************************************--SET--***************************************************************************** */
  /**
 * \fn void setId (Unite* unit,int id)
 * \brief mutateur id
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 void setId(Unite* unit, int id);

 /**
 * \fn void setPosX (Unite* unit,int x)
 * \brief mutateur posX
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] posX position X de l'unite
 */
 void setPosX(Unite* unit, int posX);

 /**
 * \fn void setPosY (Unite* unit,int y)
 * \brief mutateur posY
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] posY position Y de l'unite
 */
 void setPosY(Unite* unit, int posY);

 /**
 * \fn void setVieCouranteUnite(Unite* unit,int vie)
 * \brief mutateur vieCourante
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] vie vie actuelle de l'unite
 */
 void setVieCouranteUnite(Unite* unit, int vie);


 /**
 * \fn void setDeplacement(Unite* unit,int d)
 * \brief mutateur deplacement
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] deplacement 1 si l'unite est en deplacement, 0 sinon
 */
 void setDeplacement(Unite* unit, int d);

  /**
 * \fn void setType(Unite* unit,UniteBase* t)
 * \brief mutateur type
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] t type de l'unite
 */
 void setTypeUnite(Unite* unit, const UniteBase* type);

/**
 * \fn void setPosCibleX(Unite* unit,int x)
 * \brief mutateur posCibleX
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] x position cible de l'unite
 */
 void setPosCibleX(Unite* unit, int x);

 /**
 * \fn void setPosCibleY(Unite* unit,int y)
 * \brief mutateur posCibleY
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] y position cible de l'unite
 */
 void setPosCibleY(Unite* unit, int y);

   /**
 * \fn int setPierrePorte(Unite* unit,int p)
 * \brief mutateur pierrePorte
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] p pierre porte par l'unite
 */
 void setPierrePorte(Unite* unit, int p);

   /**
 * \fn void setMithrilPorte(Unite* unit, int m)
 * \brief mutateur mithrilPorte
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] m mithril porte par l'unite
 */
 void setMithrilPorte(Unite* unit, int m);

/**
 * \fn void setMithrilPorte(Unite* unit, int m)
 * \brief mutateur chemin
 *
 * \param[in, out] unit pointeur sur Unite
 * \param[in, out] pile pointeur sur une pile
 */
void  setChemin(Unite* unit, Pile* pile);

 /**
 * \fn void setTimerUnite(Unite* unit, clock_t time)
 * \brief mutateur Timer
 *
 * \param[in, out] unit pointeur sur Unite
 * \param[in] time nombe de tick d'horloge
 */
 void setTimerUnite(Unite* unit, clock_t time);


 /* *************************************************************--FCT--***************************************************************************** */

 /**
 * \fn void avanceUnite(Unite* homme, Terrain* terrain)
 * \brief fait avancer une unite d'une case
 *
 * \param[in, out] homme pointeur sur Unite
 * \param[in, out] terrain est le terrain de jeu
 */
void avanceUnite(Unite* homme, Terrain* terrain);

 /**
 * \fn void deplacementUnite(Unite* homme, Terrain* terrain)
 * \brief gère le deplacement d'une unite
 *
 * \param[in, out] homme pointeur sur Unite
 * \param[in, out] terrain est le terrain de jeu
 */
void deplacementUnite(Unite* homme, Terrain* terrain);
 /**
 * \fn void trouverAcces(Unite* homme, Terrain* terrain)
 * \brief cherche une case accessible autour de la case cible d'une unité
 *
 * \param[in, out] homme pointeur sur Unite
 * \param[in, out] terrain est le terrain de jeu
 */
void trouverAcces(Unite* homme, Terrain* terrain);

/**
 * \fn int testCase(int x, int y, Terrain* terrain)
 * \brief regarde si une unite peu aller sur une case
 *
 * \param[in] x est un entier coordonée d'une case
 * \param[in] y est un entier coordonée d'une case
 * \param[in, out] terrain est le terrain de jeu
 * \return un entier (1 si l'unite peut aller sur la case, 0 sinon)
 */
int testCase(int x, int y, Terrain* terrain);

#endif /* _UNITE */
