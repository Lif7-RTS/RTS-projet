/**
 * \file uniteBase.h
 * \brief module unite
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
    char* nom; /*!< nom de l'unite */
    int ouvrier; /*!< 1 si ouvrier, 0 sinon */
    int tempsFormation;/*!< temps de formation en secondes*/
    int vitesseAttaque;/*!< vitesse d'attaque (ecart entre 2 attaques en ms) */
    int ressourceMax; /*!< ressource maximum que cette unite peut porter */
    char* cheminImage; /*!< chemin de l'image de l'unite */
    int vitesse; /*!<temps qu'il faut à l'unite pour traverser une case en ms  */
};

typedef struct SUniteBase UniteBase;
/**
 * \fn void initUniteBase(UniteBase* unit, int vie, int atq, char* n,
                    int ouvr, int t, int vitesseAtq, int ressourceM, char* chemin, int v)
 * \brief accesseur vieMax
 * \param unit pointeur sur une unitBase
 * \param[in] vieM vie maximum de l'unite
 * \param[in] atq attaque de l'unite
 * \param[in,out] n pointeur sur un tableau de caracteres contenant le nom de l'unite
 * \param[in] Ouvrier defini si l'unite est un ouvrier ou non
 * \param[in] t temps de formation de l'unite
 * \param[in] vitesseAtq  vitesse d'attaque de l'unite (ecart entre 2 attaques en ms)
 * \param[in] ressourceM maximum de ressource que cette unite peut transporter
 * \param[in] vitesse temps qu'il faut à l'unite pour traverser une case en ms
 */
 void initUniteBase(UniteBase* unit, int vie, int atq, char* n,
                    int ouvr, int t, int vitesseAtq, int ressourceM, char* chemin, int v){
 }
/**
 * \fn int getVieMax (UniteBase* unit)
 * \brief accesseur vieMax
 * \param unit pointeur sur une unitBase
 * \return vieMax
 */
 int getVieMax(UniteBase* unit);
 /**
 * \fn int getAttaque (UniteBase* unit)
 * \brief accesseur attaque
 * \param unit pointeur sur une unitBase
 * \return attaque
 */
 int getVieMax(UniteBase* unit);
 /**
 * \fn char* getNom (UniteBase* unit)
 * \brief accesseur nom
 * \param unit pointeur sur une unitBase
 * \return nom
 */
 char* getNom(UniteBase* unit);
 /**
 * \fn int getOuvrier (UniteBase* unit)
 * \brief accesseur ouvrier
 * \param unit pointeur sur une unitBase
 * \return ouvrier: 1 si ouvrier, 0 sinon
 */
 int getOuvrier(UniteBase* unit);
  /**
 * \fn int getTempsFormation (UniteBase* unit)
 * \brief accesseur tempsFormation
 * \param unit pointeur sur une unitBase
 * \return tempsFormation
 */
 int getTempsFormation(UniteBase* unit);
  /**
 * \fn int getVitesseAttaque (UniteBase* unit)
 * \brief accesseur VitesseAttaque
 * \param unit pointeur sur une unitBase
 * \return VitesseAttaque
 */
 int getVitesseAttaque(UniteBase* unit);
  /**
 * \fn int getRessourceMax (UniteBase* unit)
 * \brief accesseur RessourceMax
 * \param unit pointeur sur une UniteBase
 * \return ressourceMax
 */
 int getRessourceMax(UniteBase* unit);
/**
 * \fn int getVitesse (UniteBase* unit)
 * \brief accesseur Vitesse
 * \param unit pointeur sur une UniteBase
 * \return vitesse
 */
 int getVitesse(UniteBase* unit);

 /**
 * \fn void setVieMax (UniteBase* unit,int vieM)
 * \brief mutateur vieMax
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] vieM vie maximum de l'unite
 */
 void setVieMax(UniteBase* unit, int vieM);

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
 * \param[in] Ouvrier defini si l'unite est un ouvrier ou non
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
 * \param[in] vitesse temps qu'il faut à l'unite pour traverser une case en ms
 */
 void setOuvrier(UniteBase* unit, int ouvr);

#endif /* _UNITEBASE */
