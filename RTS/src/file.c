
/**
* \file file.c
* \brief structure file et structure cellule
* \author Adrien Baud & Diego Roussel
* \version 1.1
* \date 07/04/2015
*
* Structure representant une file.
*/


#include"file.h"

/* ************************************************************--INIT--***************************************************************************** */

void initFile (File* file, const UniteBase* element){
     file=(File*)malloc(sizeof(File*));
     setPremier(file,NULL);
}

void initCellule (Cellule* cell, const UniteBase* element){
     cell=(Cellule*)malloc(sizeof(File*));
     setSuivant(cell, NULL);
     setPrecedent(cell, NULL);
     setElement(cell, NULL);
}

void detruireFile (File** file){
     Cellule* prem =  getPremier(*file);

     while(prem)
     {
          defile(*file);
          prem =  getPremier(*file);
     }
     free(*file);
     *file=NULL;
}

void detruireCellule (Cellule** cell){
     free(*cell);
     *cell=NULL;
}

/* *************************************************************--GET--***************************************************************************** */

Cellule* getPremier(const File* file){
     return file->prem;
}

UniteBase* getElement(Cellule* cell){
     return cell->element;
}

Cellule* getSuivant(Cellule* cell){
     return cell->suivant;
}

Cellule* getPrecedent(Cellule* cell){
     return cell->precedent;
}

/* *************************************************************--SET--***************************************************************************** */

void setPremier (File* file, Cellule* premier){
     file->prem=premier;
}

void setElement(Cellule* cell, UniteBase* element){
     cell->element=element;
}

void setSuivant(Cellule* cell, Cellule* suiv){
     cell->suivant=suiv;
}

void setPrecedent(Cellule* cell, Cellule* prece){
     cell->precedent=prece;
}

/* *************************************************************--FCT--***************************************************************************** */

void enfile(File* f, UniteBase* element){
     Cellule* cell = (Cellule*) malloc(sizeof(Cellule*));
     setElement(cell, element);
     setSuivant(cell, getPremier(f));
     setPrecedent(cell, getPrecedent(getPremier(f)));
     setPrecedent(getPremier(f), cell);
     setSuivant(getPrecedent(cell), cell);
}

void defile(File* f){
     Cellule* prem =  getPremier(f);

     if(prem)
     {
          Cellule* dern = getPrecedent(prem);
          if(prem == dern)
          {
               setPremier(f, NULL);
          }
          else
          {
               setSuivant(getPrecedent(dern),prem);
               setPrecedent(prem, getPrecedent(dern));
          }
          detruireCellule(&dern);
     }
}

UniteBase* regardeTeteFile(const File* f){
    if(getPremier(f) != NULL)
        return getElement(getPremier(f));
    return NULL;
}
