
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

void initFile(File* file){
     setPremier(file, NULL);
     setDernier(file, NULL);
}

void initCellule (Cellule* cell, const UniteBase* element){
     cell=(Cellule*)malloc(sizeof(Cellule));
     setSuivant(cell, NULL);
     setElement(cell, NULL);
}

void detruireFile (File* file){
     Cellule* prem =  getPremier(file);

     while(prem)
     {
          defile(file);
          prem =  getPremier(file);
     }
     free(file);
     file=NULL;
}

void detruireCellule (Cellule* cell){
     free(cell);
     cell=NULL;
}

/* *************************************************************--GET--***************************************************************************** */

Cellule* getPremier(const File* file){
     return file->prem;
}

Cellule* getDernier(const File* file){
    return file->dernier;
}
UniteBase* getElement(Cellule* cell){
     return cell->element;
}

Cellule* getSuivant(Cellule* cell){
     return cell->suivant;
}

/* *************************************************************--SET--***************************************************************************** */

void setPremier (File* file, Cellule* premier){
     file->prem=premier;
}

void setDernier(File* file, Cellule* dernier){
    file->dernier = dernier;
}
void setElement(Cellule* cell, UniteBase* element){
     cell->element=element;
}

void setSuivant(Cellule* cell, Cellule* suiv){
     cell->suivant=suiv;
}

/* *************************************************************--FCT--***************************************************************************** */

void enfile(File* f, UniteBase* element){
     Cellule* cell = (Cellule*) malloc(sizeof(Cellule));
     setElement(cell, element);
     setSuivant(cell, NULL);
     if(getPremier(f) != NULL){
         setSuivant(getDernier(f), cell);
         setDernier(f,cell);
     }
     else{
        setDernier(f, cell);
        setPremier(f, cell);
     }
}

void defile(File* f){
     Cellule* prem =  getPremier(f);

     if(prem)
     {
        setPremier(f, getSuivant(prem));
        detruireCellule(prem);
     }
}

UniteBase* regardeTeteFile(const File* f){
    if(getPremier(f) != NULL){
        printf("NON NULL \n");
        return getElement(getPremier(f));
    }
    return NULL;
}
