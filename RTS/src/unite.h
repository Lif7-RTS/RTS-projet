/**
 * \file unite.h
 * \brief module unite
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * Module represantant une unite
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "uniteBase.h"
#ifndef _UNITE
#define _UNITE

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
};
typedef SUnite Unite;

 /**
 * \fn int getId (Unite* unit,int id)
 * \brief accesseur id
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 int getId(Unite* unit, int id);

 /**
 * \fn int getPosX (Unite* unit,int x)
 * \brief accesseur posX
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 int getPosX(Unite* unit, int posX);


 /**
 * \fn int getPosY (Unite* unit,int y)
 * \brief accesseur posY
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 int getPosY(Unite* unit, int posY);

 /**
 * \fn int getVieCourante (Unite* unit,int vie)
 * \brief accesseur vieCourante
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 int getVieCourante(Unite* unit, int vie);


 /**
 * \fn int getDeplacement(Unite* unit,int d)
 * \brief accesseur deplacement
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 int getDeplacement(Unite* unit, int d);

/**
 * \fn UniteBase* getType(Unite* unit)
 * \brief accesseur type
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 UniteBase* getType(Unite* unit);

/**
 * \fn int getPosCibleX(Unite* unit,int x)
 * \brief accesseur posCibleX
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 int getPosCibleX(Unite* unit, int x);
 /**
 * \fn int getPosCibleY(Unite* unit,int y)
 * \brief accesseur posCibleY
 *
 * \param[in, out] unit pointeur sur UniteBase
 */
 int getPosCibleY(Unite* unit, int y);
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
 * \fn void setVieCourante (Unite* unit,int vie)
 * \brief mutateur vieCourante
 *
 * \param[in, out] unit pointeur sur UniteBase
 * \param[in] vie vie actuelle de l'unite
 */
 void setVieCourante(Unite* unit, int vie);


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
 void setType(Unite* unit, UniteBase* t);

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
#endif /* _UNITE */
