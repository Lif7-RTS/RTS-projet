/**
 * \file filePath.c
 * \brief module unite
 * \author Adrien Baud & Diego Roussel
 * \date 24/03/15
 *
 * une File utilisée pour le Pathfinding des unités
 *
 */

 #include "filePath.h"

/* ***********************************************************--Init--*************************************************************************** */
void initFilePath(FilePath* file){
     file->prem=NULL;
     file->dernier = NULL;
}
void initCellulePath(CellulePath* cell){
     cell=(CellulePath*)malloc(sizeof(CellulePath));
     setSuivant(cell, NULL);
     setElement(cell, NULL);
}

void detruireFilePath(FilePath* file){
     CellulePath* prem =  getPremierPath(file);

     while(prem)
     {
          defilePath(file);
          prem =  getPremierPath(file);
     }
     free(file);
     file=NULL;
}

void detruireCellulePath(CellulePath* cell){
     free(cell);
     cell=NULL;
}

/* *************************************************************--GET--***************************************************************************** */

CellulePath* getPremierPath(const FilePath* file){
     return file->prem;
}

CellulePath* getDernierPath(const FilePath* file){
    return file->dernier;
}
int getElementPath(CellulePath* cell){
     return cell->element;
}

CellulePath* getSuivantPath(CellulePath* cell){
     return cell->suivant;
}

/* *************************************************************--SET--***************************************************************************** */

void setPremierPath(FilePath* file, CellulePath* premier){
     file->prem=premier;
}

void setDernierPath(FilePath* file, CellulePath* dernier){
    file->dernier = dernier;
}
void setElementPath(CellulePath* cell, int element){
     cell->element=element;
}

void setSuivantPath(CellulePath* cell, CellulePath* suiv){
     cell->suivant=suiv;
}

/* *************************************************************--FCT--***************************************************************************** */

void enfilePath(FilePath* f, int element){
     CellulePath* cell = (CellulePath*) malloc(sizeof(CellulePath));
     setElementPath(cell, element);
     setSuivantPath(cell, NULL);
     if(getPremierPath(f) != NULL){
         setSuivantPath(getDernier(f), cell);
         setDernierPath(f,cell);
     }
     else{
        setDernierPath(f, cell);
        setPremierPath(f, cell);
     }
}

void defilePath(FilePath* f){
     CellulePath* prem =  getPremierPath(f);

     if(prem)
     {
        setPremierPath(f, getSuivantPath(prem));
        detruireCellulePath(prem);
     }
}

int regardeTeteFilePath(const FilePath* f){
    if(getPremierPath(f) != NULL){
        return getElementPath(getPremierPath(f));
    }
    return -1;
}

