/**
 * \file uniteBase.h
 * \brief module uniteBase
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module represantant un archetype d'unite
 *
 */

#include <stdlib.h>
#include <stdio.h>

#ifndef _UNITEBASE
#define _UNITEBASE

/**
 * \struct SUniteBase
 * \brief Objet UniteBase
 *
 * SUniteBase est un objet representant un archetype d'unite
 */
struct SUniteBase{
     int vieMax;/*!< point de vie maximum */
     int attaque;/*!< point de degat infliges a chaque attaque */
     char nom[25]; /*!< nom de l'unite */
     int ouvrier; /*!< 1 si ouvrier, 0 sinon */
     int tempsFormation;/*!< temps de formation en secondes*/
     int vitesseAttaque;/*!< vitesse d'attaque (ecart entre 2 attaques en ms) */
     int ressourceMax; /*!< ressource maximum que cette unite peut porter */
     char tile; /*!< numero de la tile de l'unite */
     int vitesse; /*!<temps qu'il faut à l'unite pour traverser une case en ms  */
     int coutPierre; /*!< cout en pierre du batiment */
     int coutMithril;/*!< cout en mithril du batiment */
     int portee; /*!< portee d'attaque de l'unité */
     unsigned char race; /*!< race capable de généré cette unité (1=blob, 2=Nain) */
};
typedef struct SUniteBase UniteBase;


/* *************************************************************--Init--***************************************************************************** */

/**
 * \fn void initUniteBase(UniteBase* unit, int vie, int atq, char* n,
                    int ouvr, int t, int vitesseAtq, int ressourceM, char* chemin, int v)
 * \brief accesseur vieMax
 * \param unit pointeur sur une unitBase
 * \param[in] vieM vie maximum de l'unite
 * \param[in] atq attaque de l'unite
 * \param[in,out] n pointeur sur un tableau de caracteres contenant le nom de l'unite
 * \param[in] ouvrier defini si l'unite est un ouvrier ou non
 * \param[in] t temps de formation de l'unite
 * \param[in] vitesseAtq  vitesse d'attaque de l'unite (ecart entre 2 attaques en ms)
 * \param[in] ressourceM maximum de ressource que cette unite peut transporter
 * \param[in] tile numero de la tile de l'unite
 * \param[in] v temps qu'il faut à l'unite pour traverser une case en ms
 */
 void initUniteBase(UniteBase* unit, int vie, int atq, char* n,
                     int ouvr, int t, int vitesseAtq, int ressourceM, char tile, int v);

/* *************************************************************--GET--***************************************************************************** */

/**
 * \fn int getVieMax (UniteBase* unit)
 * \brief accesseur vieMax
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return vieMax
 */
 int getVieMaxUnite(const UniteBase* unit);
 /**
 * \fn int getAttaque (UniteBase* unit)
 * \brief accesseur attaque
  *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return attaque
 */
 int getAttaque(const UniteBase* unit);
 /**
 * \fn char* getNom (UniteBase* unit)
 * \brief accesseur nom
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return nom
 */
 char* getNom(const UniteBase* unit);
 /**
 * \fn int getOuvrier (UniteBase* unit)
 * \brief accesseur ouvrier
  *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return ouvrier: 1 si ouvrier, 0 sinon
 */
 int getOuvrier(const UniteBase* unit);
  /**
 * \fn int getTempsFormation (UniteBase* unit)
 * \brief accesseur tempsFormation
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return tempsFormation
 */
 int getTempsFormation(const UniteBase* unit);
  /**
 * \fn int getVitesseAttaque (UniteBase* unit)
 * \brief accesseur VitesseAttaque
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return VitesseAttaque
 */
 int getVitesseAttaque(const UniteBase* unit);
  /**
 * \fn int getRessourceMax (UniteBase* unit)
 * \brief accesseur RessourceMax
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return ressourceMax
 */
 int getRessourceMax(const UniteBase* unit);
/**
 * \fn int getVitesse (UniteBase* unit)
 * \brief accesseur Vitesse
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return vitesse
 */
 int getVitesse(const UniteBase* unit);

 /**
 * \fn char getTile(UniteBase* unit)
 * \brief accesseur tile
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return tile
 */
 char getTileUnite(const UniteBase* unit);

 /**
 * \fn int getCoutPierreUnite(const UniteBase* unit)
 * \brief accesseur coutPierre
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \return un entier correspondant au cout en pierre de la formation d'une unité.
 */
int getCoutPierreUnite(const UniteBase* unit);

 /**
 * \fn int getCoutMithrilUnite(const UniteBase* unit)
 * \brief accesseur coutMithril
 *
 * \param[in, out] unitBase pointeur sur Unite
 * \return un entier correspondant au cout en mithril de la formation d'une unité.
 */
int getCoutMithrilUnite(const UniteBase* unit);

 /**
 * \fn int getPorteeUnite(const UniteBase* unit)
 * \brief accesseur portee
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return un entier correspondant a une portée.
 */
int getPorteeUnite(const UniteBase* unit);

 /**
 * \fn unsigned char getRaceUnite(const UniteBase* unit)
 * \brief accesseur race
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \return un entier représentant une race.
 */
unsigned char getRaceUnite(const UniteBase* unit);

/* *************************************************************--SET--***************************************************************************** */

 /**
 * \fn void setVieMax (UniteBase* unit,int vieM)
 * \brief mutateur vieMax
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] vieM vie maximum de l'unite
 */
 void setVieMaxUnite(UniteBase* unit, int vieM);

  /**
 * \fn void setAttaque (UniteBase* unit,int atq)
 * \brief mutateur attaque
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] atq attaque de l'unite
 */
 void setAttaque(UniteBase* unit, int atq);

 /**
 * \fn void setNom (UniteBase* unit,char* n)
 * \brief mutateur nom
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in,out] n pointeur sur un tableau de caracteres contenant le nom de l'unite
 */
 void setNom(UniteBase* unit, char* n);

 /**
 * \fn void setOuvrier (UniteBase* unit,int ouvr)
 * \brief mutateur ouvrier
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] ouvr defini si l'unite est un ouvrier ou non
 */
 void setOuvrier(UniteBase* unit, int ouvr);

/**
 * \fn void setTempsFormation (UniteBase* unit,int t)
 * \brief mutateur TempsFormation
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] t temps de formation de l'unite
 */
 void setTempsFormation(UniteBase* unit, int t);
  /**
 * \fn void setVitesseAttaque (UniteBase* unit,int vitesseAtq)
 * \brief mutateur vitesseAttaque
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] vitesseAtq  vitesse d'attaque de l'unite (ecart entre 2 attaques en ms)
 */
 void setVitesseAttaque(UniteBase* unit, int vitesseAtq);
  /**
 * \fn void setRessourceMax (UniteBase* unit,int ressourceM)
 * \brief mutateur ressourceMax
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] ressourceM maximum de ressource que cette unite peut transporter
 */
 void setRessourceMax(UniteBase* unit, int ressourceM);
  /**
 * \fn void setVitesse (UniteBase* unit,int v)
 * \brief mutateur vitesse
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] v temps qu'il faut à l'unite pour traverser une case en ms
 */
 void setVitesse(UniteBase* unit, int v);

  /**
 * \fn void setTile(UniteBase* unit, char tile)
 * \brief mutateur tile
 * \param unit pointeur sur une UniteBase
 * \param tile numero de la tile de l'unite
 */
 void setTileUnite(UniteBase* unit, char tile);

 /**
 * \fn void setCoutPierreUnite(UniteBase* unit, int coutP)
 * \brief mutateur coutPierre
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] coutP un entier correspondant au cout en pierre de la formation d'une unité.
 */
void setCoutPierreUnite(UniteBase* unit, int coutP);

 /**
 * \fn void setCoutMithrilUnite(UniteBase* unit, int coutM)
 * \brief mutateur coutMithril
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] coutM un entier correspondant au cout en mithril de la formation d'une unité.
 */
void setCoutMithrilUnite(UniteBase* unit, int coutM);

 /**
 * \fn void setPorteeUnite(const UniteBase* unit, int portee)
 * \brief mutateur portee
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \param[in] portee un entier correspondant a une portée.
 */
void setPorteeUnite(UniteBase* unit, int portee);

/**
 * \fn void setRaceUnite(UniteBase* unit, unsigned char race)
 * \brief mutateur race
 *
 * \param[in, out] unit pointeur sur une UniteBase
 * \param[in] un entier correspondant a une race.
 */
void setRaceUnite(UniteBase* unit, unsigned char race);

/* *************************************************************--FCT--***************************************************************************** */

 /**
* \fn UniteBase* chargementUniteBase(void)
* \brief charge en mémoire toutes les types d'unites
*
*
* \return un tableau regroupant l'ensemble des types d'unites
*/
UniteBase* chargementUniteBase();

#endif /* _UNITEBASE */
