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
#include "uniteBase.h"
#include "filePath.h"

#ifndef _UNITE
#define _UNITE

typedef struct SUnite Unite;

#include "terrain.h"
#include "jeu.h"

/**
 * \struct SUnite
 * \brief Objet Unite
 *
 * SUnite objet representant une unite.
 */

struct SUnite{
     int id; /*!< id (unique) de l'unite*/
     int idJoueur; /*!< id (unique) d'un joueur */
     int posX; /*!< position X de l'unite ( en case )*/
     int posY; /*!<position Y de l'unite ( en ca(se ) */
     int vieCourante; /*!< vie de l'unite actuellement */
     int deplacement;/*!< 1 si l'unite est en deplacement, 0 sinon */
     UniteBase* type;/*!< archetype de l'unite */
     int posCibleX; /*!< X de la position cible par l'unite ( case )*/
     int posCibleY;/*!< Y de la position cible par l'unite ( case )*/
     int posMineraiX; /*! < X de la position d'un minerai cibl� */
     int posMineraiY; /*! < Y de la position d'un minerai cibl� */
     char enTravail; /*! < avancement du travail de l'unit� (-1 au repos, 0 vide son sac, 1 recolte, 2 arrive au batiment principal, 3 pars � la mine) */
     int pierrePorte;/*!< pierre transporte par l'unite */
     int mithrilPorte;/*!< mithril tranporte par l'unite*/
     FilePath* chemin; /*!< File des direction que l'unite doit suivre */
     clock_t timerUnite; /*!< date du dernier deplacement de l'unite */
};

/* *************************************************************--Init--***************************************************************************** */

 /**
 * \fn  void initUnite(Unite* unit, const UniteBase* type, int idJ)
 * \brief fonction d'initialisation de la structure Unite
 *
 * \param[in, out] unit pointeur sur Unite
 * \param[in, out] type pointeur sur UniteBase
 * \param[in] idJ est une identifiant unique d'un Joueur
 */
 void initUnite(Unite* unit, const UniteBase* type, int idJ);

 /**
 * \fn  void detruireUnite(Unite** unit)
 * \brief fonction de destruction de la structure Unite
 *
 * \param[in, out] unit pointeur sur Unite
 */
void detruireUnite(Unite** unit);

/* *************************************************************--GET--***************************************************************************** */

 /**
 * \fn int getId (Unite* unit)
 * \brief accesseur id
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant � un identifiant unique
 */
 int getId(const Unite* unit);

 /**
 * \fn int getIdJoueurUnite(const Unite* unit)
 * \brief accesseur idJoueur
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant � un identifiant unique
 */
 int getIdJoueurUnite(const Unite* unit);

 /**
 * \fn int getPosX (Unite* unit)
 * \brief accesseur posX
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant � une coordonn�e d'axe X
 */
 int getPosX(const Unite* unit);

 /**
 * \fn int getPosY (Unite* unit)
 * \brief accesseur posY
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un entier correspondant � une coordonn�e d'axe Y
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
 * \return un entier correspondant a l'etat de deplacement de l'unit� (1 si en deplacement, 0 sinon)
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
 * \return un entier correspondant � la coordonn�e X de la cible de l'unit�
 */
 int getPosCibleX(const Unite* unit);

 /**
 * \fn int getPosCibleY(Unite* unit)
 * \brief accesseur posCibleY
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant � la coordonn�e Y de la cible de l'unit�
 */
 int getPosCibleY(const Unite* unit);

 /**
 * \fn int getPosMineraiX(const Unite* unit)
 * \brief accesseur posMineraiX
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant � la coordonn�e X du minerai cible de l'unit�
 */
int getPosMineraiX(const Unite* unit);

 /**
 * \fn int getPosMineraiY(const Unite* unit)
 * \brief accesseur posMineraiY
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant � la coordonn�e Y du minerai cible de l'unit�
 */
int getPosMineraiY(const Unite* unit);

/**
 * \fn char getEnTravail(const Unite* unit)
 * \brief accesseur enTravail
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un char correspondant a une etape precise du travail d'une unit�
 */
char getEnTravail(const Unite* unit);

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
 * \fn  FilePath* getChemin(const Unite* unit)
 * \brief accesseur chemin
 *
 * \param[in, out] unit pointeur sur Unite
 * \return pointeur sur la file des mouvements que l'unite a � faire pour aller a sa posCible
 */
FilePath* getChemin(const Unite* unit);

 /**
 * \fn  clock_t getTimerUnite(const Unite* unit)
 * \brief accesseur timerUnite
 *
 * \param[in, out] unit pointeur sur Unite
 * \return un temps en nombre de tick d''horloge depuis le lancement du jeu, correspondant au deplacement de l'unit�
 */
clock_t getTimerUnite(const Unite* unit);

/* *************************************************************--SET--***************************************************************************** */

 /**
 * \fn void setId (Unite* unit,int id)
 * \brief mutateur id
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] id un identifiant d'unit� unique
 */
 void setId(Unite* unit, int id);

  /**
 * \fn void setIdJoueurUnite(Unite* unit, int idJoueur)
 * \brief mutateur id
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] un entier correspondant a un identifiant joueur unique
 */
 void setIdJoueurUnite(Unite* unit, int idJoueur);

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
 * \fn  void setPosMineraiX(Unite* unit, int x)
 * \brief mutateur de posMineraiX
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] x coordonn�e d'un minerai cibl� par une unit�
 */
 void setPosMineraiX(Unite* unit, int x);

 /**
 * \fn  void setPosMineraiY(Unite* unit, int y)
 * \brief mutateur posMineraiY
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] y coordonn�e d'un minerai cibl� par une unit�
 */
void setPosMineraiY(Unite* unit, int y);

/**
 * \fn void setEnTravail(Unite* unit, char enT)
 * \brief mutateur enTravail
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] enT etat de l'avance de travail d'une unit�
 */
void setEnTravail(Unite* unit, char enT);

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
void  setChemin(Unite* unit, FilePath* file);

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
 * \brief g�re le deplacement d'une unite
 *
 * \param[in, out] homme pointeur sur Unite
 * \param[in, out] terrain est le terrain de jeu
 */
void deplacementUnite(Unite* homme, Terrain* terrain);
 /**
 * \fn void trouverAcces(Unite* homme, Terrain* terrain)
 * \brief cherche une case accessible autour de la case cible d'une unit�
 *
 * \param[in, out] homme pointeur sur Unite
 * \param[in, out] terrain est le terrain de jeu
 */
void trouverAcces(Unite* homme, Terrain* terrain);

/**
 * \fn int aPortee(Unite* homme, Jeu* jeu)
 * \brief verifi si l'unit� est a port�e d'attque de sa cible 1 si oui 0 sinon
 *
 * \param[in, out] homme est un pointeur sur une unit�
 * \param[in, out] jeu est un pointeur sur jeu
 */
int aPortee(Unite* homme, Jeu* jeu);

/**
 * \fn void trouveChemin(Unite* homme, Terrain* terrain)
 * \brief trouve un chemin pour deplac� le bonhomme
 *
 * \param[in, out] homme est un pointeur sur une unit�
 * \param[in, out] jeu est un pointeur sur jeu
 */
void trouveChemin(Unite* homme, Terrain* terrain);

/**
 * \fn void recolte(Unite* homme, Jeu* jeu)
 * \brief l'homme recole le minerais qu'il a en cible
 *
 * \param[in, out] homme est un pointeur sur une unit�
 * \param[in, out] jeu est un pointeur sur jeu
 */
void recolte(Unite* homme, Jeu* jeu);

/**
 * \fn void trouverMinerai(Unite* homme, Jeu* jeu)
 * \brief trouve un minerais proche du dernier minerais �puis�
 *
 * \param[in, out] homme est un pointeur sur une unit�
 * \param[in, out] jeu est un pointeur sur jeu
 */
void trouverMinerai(Unite* homme, Jeu* jeu);

/**
 * \fn void attaque(Unite* homme, Jeu* jeu)
 * \brief l'unit� attaque sa cible
 *
 * \param[in, out] homme est un pointeur sur une unit�
 * \param[in, out] jeu est un pointeur sur jeu
 */
void attaque(Unite* homme, Jeu* jeu);

/**
 * \fn void surveille(Unite* homme, Jeu* jeu)
 * \brief l'unit� monte la garde et attaque toute personne trop proche d'elle
 *
 * \param[in, out] homme est un pointeur sur une unit�
 * \param[in, out] jeu est un pointeur sur jeu
 */
void surveille(Unite* homme, Jeu* jeu);

#endif /* _UNITE */
